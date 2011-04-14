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
<div class="sokrutan">
<span id="forstoringsglas"><img width="33" height="36" alt="" src="/sites/default/files/forstoring.png" /></span>
<div class="rutaochknapp">
<div class="form-item" id="edit-keywords-wrapper">

<span id="fraga"><img width="15" height="16" title="Skriv in ett eller flera s&ouml;kord om du vill s&ouml;ka p&aring; ord, om du vill s&ouml;ka i v&aring;ra olika databaser, klicka p&aring; Fler s&ouml;kalternativ" alt="Hj&auml;lp" src="/sites/default/files/fraga.png" /></span>
<?php if (!empty($q)): ?>
  <?php
    // This ensures that, if clean URLs are off, the 'q' is added first so that
    // it shows up first in the URL.
    print $q;
  ?>
<?php endif; ?>
<?php foreach($widgets as $id => $widget): ?>
<div class="views-exposed-form" id="<?php print $widget->id; ?>_id">
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
 

  </div>

</div> 
<?php endforeach; ?>

    <div class="views-exposed-widget">
      <?php print $button ?>
    </div>





<div id="textklicksok"><fieldset class="collapsible collapsed" id="visaalla"><legend>Visa alla</legend>
<div class="grupp1">
<ul>
    <li><a href="/sokresultat?typ[]=medel">Resurser och medel</a></li>
    <li><a href="/sokresultat?typ[]=verksamhet">Projekt och utvecklingsarbeten</a></li>
    <li><a href="/sokresultat?typ[]=organisation">Akt&ouml;rer och organisationer</a></li>

<?php
$con = mysql_connect("localhost","kreaktor_base","Aepaw5oo");
mysql_select_db("kreaktor_", $con);

$sql = 'SELECT node.nid AS nid, node_node_data_field_partners.nid AS node_node_data_field_partners_nid, node_node_data_field_partners.language AS node_node_data_field_partners_language FROM node node  LEFT JOIN content_field_partners node_data_field_partners ON node.vid = node_data_field_partners.vid LEFT JOIN node node_node_data_field_partners ON node_data_field_partners.field_partners_nid = node_node_data_field_partners.nid WHERE node_data_field_partners.field_partners_nid IS NOT NULL';
$result = mysql_query($sql) or die("Failed Query of " . $sql);  //do the query
while($row = mysql_fetch_array($result))
  {
  echo $row['nid'] . '+';
  } 


?>
</ul>
</div>
<div class="grupp2">
<!--
<h4>Projekt&auml;gare och partners</h4>
<ul>
    <li><a href="/test_sok2/results/lista/projekt_agare">Lista alla projekt&auml;gare</a></li>
    <li><a href="/test_sok2/results/lista/partner">Lista alla partners</a></li>
</ul>

-->
<!--

<ul>
    <li><a href="/sokresultat?fritext=&tid[]=1&tid[]=12&typ[]=organisation">Lista alla kommunala finansi&auml;rer</a></li>

-->
<!--
    <li><a href="/test_sok2/results/lista/reg_finansiarer">Lista alla regionala/delregionala finansi&auml;rer</a></li></ul>
-->

</div>
</fieldset>



</div>
</div>
<fieldset  class="collapsible collapsed" id="sokgeografiskt">
<legend>Sök geografiskt</legend>

<?php
$block2 = module_invoke('views', 'block' , 'view', '-exp-Sokfunktion-panel_pane_1'); 
print $block2['content']; 
?>
</div></div>
</fieldset>
</div>




</div>




<div id="exportlankar">
<p><a href="sokresultat_karta/<?php echo htmlentities($_SERVER["QUERY_STRING"]);?>">Visa träfflista på karta</a> &bull; <a href="sokresultat/excel/<?php echo htmlentities($_SERVER["QUERY_STRING"]);?>&amp;attach=page_1">Exportera träfflistan som Excelark</a>  &bull; <a href="sokresultat/xml/<?php echo htmlentities($_SERVER["QUERY_STRING"]);?>&amp;attach=page_1">Exportera träfflistan som XML-fil</a></p>
</div>

<h2 class="sokresrubrik">Sökresultat</h2>



