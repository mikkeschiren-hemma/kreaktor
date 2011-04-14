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
</div>
</div>


