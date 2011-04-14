<?php
// $Id: views-view-unformatted.tpl.php,v 1.6 2008/10/01 20:52:11 merlinofchaos Exp $
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>


<!--
resultat i array

<?php


$vyer = views_get_current_view_result();

for($intI = 0; $intI < count($vyer); $intI++){ 
   $nummer[] = $vyer[$intI]->nid; 
} 

$nummer_plus = implode("+", $nummer);
print $nummer_plus;
?>
-->
<!--
<div id="exportlankar">
<p><a href="/sokresultat_karta/<?php print $nummer_plus;?>">Visa träfflista på karta</a> &bull; <a href="/sok/excel/<?php print $nummer_plus;?>/excel.xls">Exportera träfflistan som Excelark</a>  &bull; <a href="/sokresultat/xml/<?php print $nummer_plus;?>/XML.xml">Exportera träfflistan som XML-fil</a></p>
</div>
-->


<h2 class="sokresrubrik"><?php print t('Sökresultat');?></h2>
<div class="soktraffar">
<?php




  $start = ($view->pager['current_page'] * $view->pager['items_per_page']) + 1;
  $finish = $start + count($view->result) - 1;
  $total = $view->total_rows;
  echo "Träffar $start &ndash; $finish av $total";
?>
</div>
<div class="listasoktraffar">
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="<?php print $classes[$id]; ?>">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
</div>
