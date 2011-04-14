<?php
// $Id: views-view-fields.tpl.php,v 1.6 2008/09/24 22:48:21 merlinofchaos Exp $
/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->separator: an optional separator that may appear before a field.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>

<?php

/*

print $fields['title']->content;
print $fields['type']->content;
print $fields['field_fritext_value']->content;
*/
?>

<div class="kalendariepost">
<div class="datumforinlagg"> 

<?php
$datum = $fields['field_kaldatum_value']->content;;
$trimmatdatum = str_replace('kl</span>', '</span>', $datum);
?>

<?php print $trimmatdatum;?>
</div>
<?php


#node->field_ansokning[0]['value']
?>

<?php #print format_date($node->created,$type = 'small', $format='Y-m-d'); ?>

<h1 class="kalendarietitel"> <?php print $fields['title']->content; ?></h1>

<div class="brodtext">
<?php print $fields['body']->content; ?>


<div class="lankar">

<strong><?php print t('Länkar');?></strong>

 <?php print $fields['field_lank_url']->content; ?>


</div>



</div>

<div class="field field-type-gmaps-point field-field-geofield" style="overflow:hidden">
  <div class="field-items">
 <?php print $fields['field_geofield']->content; ?>


    <?php foreach ((array)$fields['geofield']->content as $item) { ?>
      <div class="field-item"><?php print $item['view'] ?></div>
    <?php } ?>
  </div>
</div>


<div class="bifogadefiler">
 <strong>Bifogade filer</strong><br />




<?php print $fields['upload_fid']->content; ?>




</div>


<?php print $fields['edit_node']->content; ?>
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
">Skapa ny kalendariepost</a>

</p>

</fieldset>



</div>
