<?php

require_once('includes/ExcelRange.inc');

define('EXCELSHEET_SEP', ',');
define('EXCELSHEET_RANGE', ':');

/**
 * Parses a given file as a Excel file.
 */
class FeedsExcelParser extends FeedsParser {

  /**
   * Implementation of FeedsParser::parse().
   */
  public function parse(FeedsImportBatch $batch, FeedsSource $source) {
    $filepath = $batch->getFilePath();
    _feeds_excel_get_libraries();

    // Read file to object
    $data = new Spreadsheet_Excel_Reader();
    $data->read($filepath);
    // Narrow down the sheets to the configured sheets, and set fixed ranges.
    $sheets = $this->getSheets($data);
    $items = $this->getItems($sheets);
    // Sheet information is stored in batch, for latter token replacement

    $batch->sheets = $this->cleanupSheetsForBatch($sheets);
    $batch->setItems($items);
  }

  /**
   * Retrieve all relevant sheets from dataset.
   */
  private function getSheets(&$data) {

    $sheet_config = $this->config['sheets'];
    $available_sheets = array_keys($data->sheets);

    $sheet_ids = array();
    if (strlen($sheet_config) < 1) {
      $sheet_ids = $available_sheets;
    }
    else {
      $sheet_expressions = explode(EXCELSHEET_SEP, $sheet_config);
      foreach($sheet_expressions as $expr) {
        list($from, $to) = explode(EXCELSHEET_RANGE, $expr);
        // Numeric Range
        if (is_numeric($from) && (!$to || is_numeric($to))) {
          if (!$to) {
            $to = $from;
          }
          // Add matching sheets to sheet ids
          foreach($available_sheets as $available_sheet) {
            if ($from <= $available_sheet && $available_sheet <= $to) {
              $sheet_ids[$available_sheet] = $available_sheet;
            }
          }
        }
        // Search for sheet name
        else {
          foreach ($data->boundsheets as $sheet_id => $boundsheet) {
            if ($boundsheet['name'] == $expr) {
              $sheet_ids[$sheet_id] = $sheet_id;
            }
          }
        }
      }
    }

    $sheets = array();
    // Run every sheet and populate it with its id, name and fixed cells
    foreach ($sheet_ids as $sheet_id) {

      $excel_sheet = $data->sheets[$sheet_id];
      $excel_sheet['boundsheet_offset'] =  $data->boundsheets[$sheet_id]['offset'];
      $excel_sheet['name'] =  $data->boundsheets[$sheet_id]['name'];
      $excel_sheet['id'] = $sheet_id;
      //$sheets[$sheet_id] = token_get_values('excel_sheet', $sheet);
      $excel_sheet['fixed_cells'] = $this->getFixed($data->sheets[$sheet_id]);
      $sheets[$sheet_id] = $excel_sheet;
    }
    return $sheets;
  }

  /**
   * Prepares sheets for batch storage and later token replacement.
   */
  function cleanupSheetsForBatch($sheets) {
    foreach ($sheets as $id => $sheet) {
      unset($sheet['cells']);
      unset($sheet['cellsInfo']);
      // Token get ID only works with objects.
      $sheets[$id] = (object)$sheet;
    }
    return $sheets;
  }

  /**
   * Sort out the given fixed cells.
   */
  private function getFixed($sheet) {
    // Store fixed cells in sheet
    $fixed = array();
    if ($this->config['fixed']) {
      $max = array(
        'rows' => $sheet['numRows'],
        'cols' => $sheet['numCols'],
      );
      $fixed_range = new ExcelRange($this->config['fixed'], $max);

      foreach ($sheet['cells'] as $row => $cols) {
        if ($fixed_range->isRowInAnyRange($row)) {
          foreach ($cols as $col => $val) {
            if ($fixed_range->isCellInAnyRange($row, $col)) {
              $cell = array(
                'value' => $val,
                'type' => $sheet['cellsInfo'][$row][$col]['type'],
                'raw' => (isset($sheet['cellsInfo'][$row][$col]['raw'])) ? $sheet['cellsInfo'][$row][$col]['raw'] : $val,
                'column' => $col,
                'row' => $row,
              );
              $fixed["$row-$col"] = $cell;
            }
          }
        }
      }
    }
    return $fixed;
  }

  /**
   * Retrieve Items from Spredsheet.
   */
  private function getItems($sheets) {
    $mode = $this->config['mapping_mode'];

    $items = array();

    // Run every sheet.
    foreach ($sheets as $sheet) {
      // Only run non-empty sheets
      if (!empty($sheet['cells'])) {
        $max = array(
          'rows' => $sheet['numRows'],
          'cols' => $sheet['numCols'],
        );
        $iterative_range = new ExcelRange($this->config['iterative'], $max);
        $sheet_id = $sheet['id'];

        // Retrieve all items out of defined iterative Range.
        while ($range = $iterative_range->getNextRange()) {
          $range_id = $iterative_range->getCurrentRangeID();
          $cells = $sheet['cells'];
          foreach ($cells as $row => $cols) {
            if ($iterative_range->isRowInCurrentRange($row)) {
              $row_offset = $iterative_range->getCurrentRangeRowOffset();
              $max_rows = $iterative_range->getCurrentRangeMaxRow();
              foreach($cols as $col => $value) {

                if ($iterative_range->isColInCurrentRange($col)) {
                  $col_offset = $iterative_range->getCurrentRangeColOffset();
                  $max_cols = $iterative_range->getCurrentRangeMaxRow();
                  // Encode value and raw to utf8 in any case
                  $value = utf8_encode($value);
                  if (!isset($sheet['cellsInfo'][$row][$col]['raw'])) {
                    $raw = $value;
                  }
                  else {
                    $raw = utf8_encode($sheet['cellsInfo'][$row][$col]['raw']);
                  }

                  // Build cell
                  $cell = array(
                    'value' => $value,
                    'type' => $sheet['cellsInfo'][$row][$col]['type'],
                    'raw' => $raw,
                    'column' => $col,
                    'row' => $row,
                    'x' => $col - $col_offset,
                    'y' => $row - $row_offset,
                  );

                  // Set items dependent on
                  switch ($mode) {
                    case 'rows':
                      $key = "$sheet_id:$range_id:$row";
                      $items[$key]['cells'][$col - $col_offset] = $cell;
                      $items[$key]['row'] = $row;
                      break;
                    case 'columns':
                      $key = "$sheet_id:$range_id:$col";
                      $items[$key]['cells'][$row - $row_offset] = $cell;
                      $items[$key]['column'] = $col;
                      break;
                  }
                  // Meta data for the given item
                  if ($key && !isset($items[$key]['meta'])) {
                    $items[$key]['meta'] = array(
                      'range_row_offset' => $row_offset,
                      'range_col_offset' => $col_offset,
                      'range_id' => $range_id,
                      'sheet_id' => $sheet_id,
                      'range_max_cols' => $max_cols,
                      'range_max_rows' => $max_rows,
                      'key' => $key,
                    );
                  }

                }
              }
            }
          }
        }
      }
    }
    return $items;
  }

  /**
   * Override parent::getMappingSources().
   */
  public function getMappingSources() {
    return FALSE;
  }

  /**
   * Return the token replaced value for the given element.
   */
  public function getSourceElement(FeedsImportBatch $batch, $element_key) {

    // excel file
    $types['excel_file'] = (object) array(
      'filepath' => $batch->getFilePath(),
    );
    // excel sheet
    $item = (object) $batch->currentItem();
    $types['excel_sheet'] = $batch->sheets[$item->meta['sheet_id']];
    // excel row or column
    switch ($this->config['mapping_mode']) {
      case 'rows':
        $types['excel_row'] = $item;
        break;
      case 'columns':
        $types['excel_column'] = $item;
        break;
    }
    // global
    $types['global'] = '';
    $value = token_replace_multiple($element_key, $types);

    // parent node
    if ($node = $batch->feedNode()) {
      $value = token_replace($value, 'node', $node, '[parent:', ']');
    }

    // Cleanup tokens of empty cells
    $patterns = array(
      '@\[sheet-cell-[0-9]+-[0-9]+(-raw)?\]@is',
      '@\[(column|row|x|y)-[0-9]+(-raw)?\]@is',
    );
    $value = preg_replace($patterns, '', $value);
    return $value;
  }

  /**
   * Define default configuration.
   */
  public function configDefaults() {
    return array(
      'mapping_mode' => 'rows',
      'sheets' => '',
      'header' => '',
      'fixed' => '',
      'iterative' => '1:10000',
    );
  }

  /**
   * Build configuration form.
   */
  public function configForm(&$form_state) {
    $form = array();
    $form['mapping_mode'] = array(
      '#type' => 'select',
      '#title' => t('Mapping mode'),
      '#description' => t('Whether to map rows or columns.'),
      '#options' => array(
        'rows' => t('Rows'),
        'columns' => t('Columns'),
      ),
      '#default_value' => $this->config['mapping_mode'],
    );

    $form['sheets'] = array(
      '#type' => 'textfield',
      '#title' => t('Sheets'),
      '#default_value' => $this->config['sheets'],
      '#description' => t('Enter the sheet names or IDs that shall be imported. Leaving empty means that all sheets are processed. Use <code>,</code> to separate different sheets. Use <code>:</code> to mark a range of IDs (e.g. <code>0:15</code>).'),
    );

    // Format string for range format.
    $format_single_1 = '<code>'. EXCELRANGE_ROW .'1'. EXCELRANGE_COL .'2</code>';
    $format_single_2 = '<code>B1</code>';
    $format_range_1 = '<code>'. EXCELRANGE_ROW .'1'. EXCELRANGE_COL .'2:'. EXCELRANGE_ROW .'5'. EXCELRANGE_COL .'4</code>';
    $format_range_2 = '<code>B1:D5</code>';
    $format_columns = '<code>B:D</code>';
    $format_rows = '<code>1:5</code>';
    $format = t('You can use different range formats: !formats <br/> Use !sep to separate multiple range entries.',
                array('!sep' => '<code>'. EXCELRANGE_SEP .'</code>', '!formats' => "$format_single_1, $format_single_2, $format_range_1, $format_range_2, $format_columns, $format_rows"));

    $form['fixed'] = array(
      '#type' => 'textfield',
      '#title' => t('Fixed Range'),
      '#description' => t('Range of the sheet, that can be referenced from any item.<br/>!format', array('!format' => $format)),
      '#default_value' => $this->config['fixed'],
    );
    $form['iterative'] = array(
      '#type' => 'textfield',
      '#title' => t('Iterative range'),
      '#description' => t('Enter a range that feeds should run through for iterative mapping to process items.<br/>!format', array('!format' => $format)),
      '#required' => TRUE,
      '#default_value' => $this->config['iterative'],
    );
    $form['header'] = array(
      '#type' => 'textfield',
      '#title' => t('Header range'),
      '#description' => t('Enter the range that can be used as row or column aliases for a given iterative range.<br/>!format', array('!format' => $format)),
      '#default_value' => $this->config['header'],
      '#disabled' => TRUE,
      '#prefix' => '<span class="error">Currently disabled option:</span>',
    );
    return $form;
  }

  /**
   * Validate rows and columns input in ConfigForm.
   */
  public function configFormValidate (&$values) {
    // Check valid range formats.
    $range_fields = array('iterative', 'fixed', 'header');
    foreach ($range_fields as $field) {
      if ($values[$field]) {
        $range = new ExcelRange($values[$field]);
        if (!$range->converted_all_ranges()) {
          form_set_error($field, t('The range expression could not be completely converted in a valid range format.'));
        }
      }
    }
  }
}