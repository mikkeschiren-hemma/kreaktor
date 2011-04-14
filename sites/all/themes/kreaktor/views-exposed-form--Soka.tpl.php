<?php
// $Id: views-exposed-form.tpl.php,v 1.4.4.1 2009/11/18 20:37:58 merlinofchaos Exp $
/**
 * @file views-exposed-form.tpl.php
 *
 * This template handles the layout of the views exposed filter form.
 *
 * Variables available:
 * - $widgets: An array of exposed form widgets. Each widget contains:
 * - $widget->label: The visible label to print. May be optional.
 * - $widget->operator: The operator for the widget. May be optional.
 * - $widget->widget: The widget itself.
 * - $button: The submit button for the form.
 *
 * @ingroup views_templates
 */
?>

<?php if (!empty($q)): ?>
  <?php
    // This ensures that, if clean URLs are off, the 'q' is added first so that
    // it shows up first in the URL.
    print $q;
  ?>
<?php endif; ?>




<?php foreach($widgets as $id => $widget): ?>
<?php
if ($widget->id=='edit-fritext')
{
?>
<div class="sokrutan">
<span id="forstoringsglas"><img width="33" height="36" alt="" src="/sites/default/files/forstoring.png" /></span>
<div class="rutaochknapp">
<div class="form-item" id="edit-keywords-wrapper">



<span id="fraga"><img width="15" height="16" title="Skriv in ett eller flera s&ouml;kord om du vill s&ouml;ka p&aring; ord, om du vill s&ouml;ka i v&aring;ra olika databaser, klicka p&aring; Fler s&ouml;kalternativ" alt="Hj&auml;lp" src="/sites/default/files/fraga.png" /></span>
<?php
}
?>
   <?php endforeach; ?>
<?php
//hack till submitknapparna
$i = 1;
?>
<?php foreach($widgets as $id => $widget): ?>


<div class="views-exposed-form">
  <div class="views-exposed-widgets clear-block">
    
      <div class="views-exposed-widget">
        <?php if (!empty($widget->label)): ?>
          <label for="<?php print $widget->id; ?>">
            <?php print $widget->label; ?>
          </label>
        <?php endif; ?>
        <?php if (!empty($widget->operator)): ?>
          <div class="views-operator">
            <?php print $widget->operator; ?>
          </div>
        <?php endif; ?>
        <div class="views-widget">
          <?php print $widget->widget; ?>
        </div>
      </div>
 
    <div class="views-exposed-widget">


 <input type="submit" id="edit-submit-<?php print $id . $i; ?>" value="<?php print t('Search'); ?>"  class="form-submit" />
    </div>
  </div>


<?php
$i++;
?>
   <?php endforeach; ?>
<?php foreach($widgets as $id => $widget): ?>
<?php
if ($widget->id=='edit-fritext')
{
?>

<div id="textklicksok2"><fieldset class="collapsible collapsed" id="visaalla"><legend>Visa alla</legend>
<div class="grupp1">
<ul>
    <li><a href="/sok_medel">Resurser och medel</a></li>
    <li><a href="/sok_projekt">Projekt och utvecklingsarbeten</a></li>
    <li><a href="/sok_organisationer">Akt&ouml;rer och organisationer</a></li>
</ul>
</div>
<div class="grupp2">

<ul>
    <li><a href="/sok_projekt">Lista alla projekt&auml;gare</a></li>
    <li><a href="/sokpartner">Lista alla partners</a></li>
</ul>




<!--
<ul>
    <li><a href="/sokresultat?fritext=&tid[]=1&tid[]=12&typ[]=organisation">Lista alla kommunala finansi&auml;rer</a></li>
-->
<!--
    <li><a href="/test_sok2/results/lista/reg_finansiarer">Lista alla regionala/delregionala finansi&auml;rer</a></li>
</ul>
-->

</div>


</fieldset>
<div id="geografi">
<fieldset class="collapsible<?php if (!isset($_GET['field_kommun_delregion_value'])){?> collapsed<?php }?>" >
<legend><?php print t('Sök geografiskt');?></legend>
<div id="geoval">
<?php
$block = module_invoke('views', 'block' , 'view', '-exp-Soka-page_7'); 
print $block['content']; 
?>
</div>
</fieldset>
</div>
</div>
</div>
</div>
</div>
<?php
}
?>
   <?php endforeach; ?>
<div class="sorterafalt">
<?php $sel = $_REQUEST[ 'sort-order' ]; ?>

<form action="" method="get" id="sort-order">
<label>Sortera</label>
<select name="sort-order" onchange="this.form.submit()">
<option value="asc" <?php echo ( $sel == 'asc' ) ? 'selected' : '';?>>A-Ö</option>
<option value="desc" <?php echo ( $sel == 'desc' ) ? 'selected' : '';?>>Ö-A</option>
</select>
</form>
</div>

</div>

