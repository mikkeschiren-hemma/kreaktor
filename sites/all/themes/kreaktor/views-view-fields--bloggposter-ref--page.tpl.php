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
# dsm(array_keys($fields));
/*

print $fields['title']->content;
print $fields['type']->content;
print $fields['field_fritext_value']->content;
*/
?>

<div class="bloggpost">
<?php
if($_GET['bloggpost'])
{
print '<p>Visning av äldre bloggposter fungerar ej ännu</p>';
}
?>
<div class="datumforinlagg"> <?php print $fields['created']->content; ?> Av <?php print $fields['name']->content; ?></div>

<h1 class="bloggtitle"> <?php print $fields['title']->content; ?></h1>

<div class="brodtext">
 <?php print $fields['body']->content; ?>

<div class="laddahemfil">

<?php print $fields['upload_fid']->content; ?>

</div>




<?php print $fields['edit_node']->content; ?>
</div>


<div class="antalbloggkommentarer">
<?php print $fields['comment_count']->content; ?>
</div>

<div class="kommenterainlagget">


<?php print $fields['comments_link']->content; ?>

<?php print $fields['blogg']->content; ?>

</div>

</div>

<div class="bloggreferenser">
<fieldset id="bloggsenaste">
<legend><?php print t('Senaste inlägg')?></legend>
<?php
print views_embed_view('bloggposter_ref','panel_pane_1',$_GET['grundnod']);
?>

</fieldset>

<fieldset id="bloggarkiv">
<legend><?php print t('Arkiv');?></legend>
spalt....
</fieldset>

<div>
<?php
print '<p><a href="';
print '/node/add/blog/' . $_GET['grundnod'] . '?destination=' . 'node/' . $_GET['grundnod'];
print '">' . t('Skapa en bloggpost') . '</a></p>';
?>


</div>
</div>

