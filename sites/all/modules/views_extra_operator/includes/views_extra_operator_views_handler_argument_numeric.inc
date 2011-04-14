<?php
// $Id$

/**
 * @file
 * This is the handler for field type integer.
 */

class views_extra_operator_views_handler_argument_numeric extends views_handler_argument_numeric {

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['operator'] = array(
      '#type' => 'select',
      '#title' => t('Numeric operator'),
      '#description' => t('Choose how to handle the numeric argument'),
      '#options' => array(
        'op_equal' => t('Is equal to'),
        'op_nequal' => t('Is not equal to'),
        'op_contains' => t('Contains'),
        'op_contains_any_word' => t('Contains any words'),
        'op_contains_all_words' => t('Contains all words'),
        'op_ncontains' => t('Does not contain'),
        'op_start_with' => t('Start with'),
        'op_nstart_with' => t('Does not start with'),
        'op_ends_with' => t('Ends with'),
        'op_nends_with' => t('Does not end with'),
        'op_lesser' => t('Is lesser'),
        'op_greater' => t('Is greater'),
        'op_lesser_equal' => t('Is lesser or equal'),
        'op_greater_equal' => t('Is greater or equal'),
        'op_different' => t('Is different'),
        'op_length_greater' => t('String length greater'),
        'op_length_greater_equal' => t('String length greater or equal'),
        'op_length_lesser' => t('String length lesser'),
        'op_length_lesser_equal' => t('String length lesser or equal'),
        'op_length_different' => t('String length different'),
        'op_between' => t('Is between'),
        'op_nbetween' => t('Is not between'),
        'op_length_between' => t('String length is between'),
        'op_length_nbetween' => t('String length is not between'),
      ),
      '#default_value' => $this->options['operator']
    );
  }

  function query() {

    $argument = $this->argument;

    if (!empty($this->options['transform_dash'])) {
      $argument = strtr($argument, '-', ' ');
    }

    $this->ensure_my_table();
    if (empty($this->options['glossary'])) {
      $field = "$this->table_alias.$this->real_field";
    }
    else {
      $field = $this->get_formula();
    }

    switch ($this->options['operator']) {
        case 'op_equal':
            $this->query->add_where(0, "$field = '%s'", $argument);
        break;
        case 'op_nequal':
            $this->query->add_where(0, "$field != '%s'", $argument);
        break;
        case 'op_contains':
            $this->query->add_where(0, "$field LIKE '%%%s%%'", $argument);
        break;
        case 'op_contains_any_word':
            $where = array();
            preg_match_all('/ (-?)("[^"]+"|[^" ]+)/i', ' ' . $argument, $matches, PREG_SET_ORDER);
            foreach ($matches as $match) {
              $phrase = FALSE;
              // Strip off phrase quotes
              if ($match[2]{0} == '"') {
                $match[2] = substr($match[2], 1, -1);
                $phrase = TRUE;
              }
              $words = trim($match[2], ',?!();:-');
              $words = $phrase ? array($words) : preg_split('/ /', $words, -1, PREG_SPLIT_NO_EMPTY);
              foreach ($words as $word) {
                $where[] = "$upper($field) LIKE $upper('%%%s%%')";
                $values[] = trim($word, " ,!?");
              }
            }

            $where = '(' . implode(' OR ', $where) . ')';
            $this->query->add_where(0, $where, $values);
        break;
        case 'op_contains_all_words':
            $where = array();
            preg_match_all('/ (-?)("[^"]+"|[^" ]+)/i', ' ' . $argument, $matches, PREG_SET_ORDER);
            foreach ($matches as $match) {
              $phrase = FALSE;
              // Strip off phrase quotes
              if ($match[2]{0} == '"') {
                $match[2] = substr($match[2], 1, -1);
                $phrase = TRUE;
              }
              $words = trim($match[2], ',?!();:-');
              $words = $phrase ? array($words) : preg_split('/ /', $words, -1, PREG_SPLIT_NO_EMPTY);
              foreach ($words as $word) {
                $where[] = "$upper($field) LIKE $upper('%%%s%%')";
                $values[] = trim($word, " ,!?");
              }
            }

            $where = implode(' AND ', $where);
            $this->query->add_where(0, $where, $values);
        break;
        case 'op_start_with':
            $this->query->add_where(0, "$field LIKE '%s%%'", $argument);
        break;
        case 'op_nstart_with':
            $this->query->add_where(0, "$field NOT LIKE '%s%%'", $argument);
        break;
        case 'op_ends_with':
            $this->query->add_where(0, "$field LIKE '%%%s'", $argument);
        break;
        case 'op_nends_with':
            $this->query->add_where(0, "$field NOT LIKE '%%%s'", $argument);
        break;
        case 'op_ncontains':
            $this->query->add_where(0, "$field NOT LIKE '%%%s%%'", $argument);
        break;
        case 'op_greater':
            $this->query->add_where(0, "$field > %d", $argument);
        break;
        case 'op_lesser':
            $this->query->add_where(0, "$field < %d", $argument);
        break;
        case 'op_greater_equal':
            $this->query->add_where(0, "$field >= %d", $argument);
        break;
        case 'op_lesser_equal':
            $this->query->add_where(0, "$field <= %d", $argument);
        break;
        case 'op_different':
            $this->query->add_where(0, "$field <> %d", $argument);
        break;
        case 'op_length_greater':
            $argument = (is_numeric($argument)) ? $argument : strlen($argument); 
            $this->query->add_where(0, "LENGTH($field) > %d", $argument);
        break;
        case 'op_length_greater_equal':
            $argument = (is_numeric($argument)) ? $argument : strlen($argument); 
            $this->query->add_where(0, "LENGTH($field) >= %d", $argument);
        break;
        case 'op_length_lesser':
            $argument = (is_numeric($argument)) ? $argument : strlen($argument); 
            $this->query->add_where(0, "LENGTH($field) < %d", $argument);
        break;
        case 'op_length_lesser_equal':
            $argument = (is_numeric($argument)) ? $argument : strlen($argument); 
            $this->query->add_where(0, "LENGTH($field) <= %d", $argument);
        break;
        case 'op_length_different':
            $argument = (is_numeric($argument)) ? $argument : strlen($argument); 
            $this->query->add_where(0, "LENGTH($field) <> %d", $argument);
        break;
        case 'op_between':
            list($min, $max) = explode(",", $argument);
            $min = (is_numeric($min)) ? $min : strlen($min);
            $max = (is_numeric($max)) ? $max : strlen($max);
            $this->query->add_where(0, "$field BETWEEN %d AND %d", $min, $max);
        break;
        case 'op_nbetween':
            list($min, $max) = explode(",", $argument);
            $min = (is_numeric($min)) ? $min : strlen($min);
            $max = (is_numeric($max)) ? $max : strlen($max);
            $this->query->add_where(0, "$field NOT BETWEEN %d AND %d", $min, $max);
        break;
        case 'op_length_between':
            list($min, $max) = explode(",", $argument);
            $min = (is_numeric($min)) ? $min : strlen($min);
            $max = (is_numeric($max)) ? $max : strlen($max);
            $this->query->add_where(0, "LENGTH($field) BETWEEN %d AND %d", $min, $max);
        break;
        case 'op_length_nbetween':
            list($min, $max) = explode(",", $argument);
            $min = (is_numeric($min)) ? $min : strlen($min);
            $max = (is_numeric($max)) ? $max : strlen($max);
            $this->query->add_where(0, "LENGTH($field) NOT BETWEEN %d AND %d", $min, $max);
        break;
       }
    }




}