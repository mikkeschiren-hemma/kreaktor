<?php
// $Id: views-view-table.tpl.php,v 1.8 2009/01/28 00:43:43 merlinofchaos Exp $
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $class: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * @ingroup views_templates
 */
?>
<div class="kalendariepost">

<h1 class="kalendarietitel"><?php print t('Alla kalendariehändelser'); ?></h1>
<div class="allakalposter">
<?php

  $start = ($view->pager['current_page'] * $view->pager['items_per_page']) + 1;
  $finish = $start + count($view->result) - 1;
  $total = $view->total_rows;
  echo "Träffar $start &ndash; $finish av $total";
?>
</div>

<table class="<?php print $class; ?>">
  <?php if (!empty($title)) : ?>
    <caption><?php print $title; ?></caption>
  <?php endif; ?>
  <thead>
    <tr>
      <?php foreach ($header as $field => $label): ?>
        <th class="views-field views-field-<?php print $fields[$field]; ?>">
          <?php print $label; ?>
        </th>
      <?php endforeach; ?>
    </tr>
  </thead>
  <tbody>
    <?php foreach ($rows as $count => $row): ?>
      <tr class="<?php print implode(' ', $row_classes[$count]); ?>">
        <?php foreach ($row as $field => $content): ?>
          <td class="views-field views-field-<?php print $fields[$field]; ?>">
            <?php print $content; ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
</div>

<div class="kalendariumkol">
<fieldset id="ikalendariet">
<legend><?php print t('I kalendariet');?></legend>
<?php
print views_embed_view('kalposter_ref','panel_pane_1',$_GET['grundnod']);
?>
<p class="framtida">
<a href="<?php
print '/kalendariumetlistning/' . $_GET['grundnod'] . '?grundnod=' . $_GET['grundnod'] . '&amp;akt=' . $_GET['akt'];
?>
">Visa alla framtida kalendarieposter</a>
</p>
<p class="alla">
<a href="<?php
print '/kalendariumetlistningalla/' . $_GET['grundnod'] . '?grundnod=' . $_GET['grundnod'] . '&amp;akt=' . $_GET['akt'];
?>
">Visa alla kalendarieposter</a>
</p>
<p class="skapanykalendariepost">
<a href="
<?php
print '/node/add/kalendarie/' . $_GET['grundnod'] . '?destination=node/' . $_GET['grundnod'];
?>
"><?php print t('Skapa ny kalendariehändelse'); ?></a>

</p>

</fieldset>



</div>


