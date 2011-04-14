<?php
// $Id: template.php,v 1.1.2.3 2009/11/05 03:32:15 sociotech Exp $

/**
 * Changed breadcrumb separator
 */
function acquia_prosper_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    return '<div class="breadcrumb">'. implode(' &rarr; ', $breadcrumb) .'</div>';
  }
}

/*


function phptemplate_views_view_list($view, $nodes) {
  $thismap = gmap_parse_macro('[gmap|id=viewmap|center=37,-100|zoom=3|width=100%|height=400px]');
  foreach ($nodes as $node) {
    $node_data = node_load(array("nid"=>$node->nid));
    $location = $node_data->location;
    $newmarker['label'] = '';
    foreach ($view->field as $field) {
      $newmarker['label'] .= "<p>" . _views_handle_field($fields, $field, $node) . "</p>";
    }
    $newmarker['point']= $location['lat'] . ',' . $location['lon'];
    $newmarker['markername']='drupal_view';
    $thismap['markers'][]= $newmarker;
  }
  $output .= gmap_draw_map($thismap);
  return $output;
}
function kreaktor_views_view_list($view, $nodes) {
  $thismap = gmap_parse_macro('[gmap|id=viewmap|center=37,-100|zoom=3|width=100%|height=400px]');
  foreach ($nodes as $node) {
    $node_data = node_load(array("nid"=>$node->nid));
    $location = $node_data->location;
    $newmarker['label'] = '';
    foreach ($view->field as $field) {
      $newmarker['label'] .= "<p>" . _views_handle_field($fields, $field, $node) . "</p>";
    }
    $newmarker['point']= $location['lat'] . ',' . $location['lon'];
    $newmarker['markername']='drupal_view';
    $thismap['markers'][]= $newmarker;
  }
  $output .= gmap_draw_map($thismap);
  return $output;
}

*/

function kreaktor_preprocess_views_exposed_form(&$vars, $hook) {

// Specify the Form ID
if ($vars['form']['#id'] == 'views-exposed-form-Sokfunktion-page-1') {

$vars['form']['submit']['#value'] = t('Search');

$vars['form']['typ']['#value'] = t('');



// Rebuild the rendered version (submit button, rest remains unchanged)
unset($vars['form']['submit']['#printed']);
unset($vars['form']['typ[]']['#printed']);
unset($vars['form']['edit-typ-medel']['#printed']);
$vars['button'] = drupal_render($vars['form']['submit']);



}
if ($vars['form']['#id'] == 'views-exposed-form-Sokfunktion-default') {

$vars['form']['submit']['#value'] = t('Search');
$vars['form']['submit']['#class'] = 'form-submit-form2';




// Rebuild the rendered version (submit button, rest remains unchanged)
unset($vars['form']['submit']['#printed']);
$vars['button'] = drupal_render($vars['form']['submit']);



}

if ($vars['form']['#id'] == 'views-exposed-form-Sokfunktion-panel-pane-1') {

$vars['form']['submit']['#value'] = t('Search');
$vars['form']['submit']['#id'] = 'form-submit-form3';

// Rebuild the rendered version (submit button, rest remains unchanged)
unset($vars['form']['submit']['#printed']);
$vars['button'] = drupal_render($vars['form']['submit']);
}

if ($vars['form']['#id'] == 'views-exposed-form-Soka-page-1') {

$vars['form']['#action'] == '/sok';

$vars['form']['submit']['#value'] = t('Search');
//$vars['form']['submit']['#id'] = 'form-submit-form';

// Rebuild the rendered version (submit button, rest remains unchanged)
unset($vars['form']['submit']['#printed']);
unset($vars['form']['#printed']);
$vars['button'] = drupal_render($vars['form']['submit']);
$vars['form'] = drupal_render($form);
}

if ($vars['form']['#id'] == 'views-exposed-form-Soka-page-2') {
$vars['form']['#action'] == '/sok';
$vars['form']['submit']['#value'] = t('Search');
$vars['form']['edit-fritext']['#size'] = 40;

//$vars['form']['submit']['#id'] = 'form-submit-form';

// Rebuild the rendered version (submit button, rest remains unchanged)
unset($vars['form']['submit']['#printed']);
unset($vars['form']['#printed']);
$vars['button'] = drupal_render($vars['sform']['submit']);
$vars['form'] = drupal_render($form);

}

if ($vars['form']['#id'] == 'views-exposed-form-Soka-page-3') {
$vars['form']['#action'] == '/sok';
$vars['form']['submit']['#value'] = t('Search');
$vars['form']['submit']['#id'] = 'form-submit-form';

// Rebuild the rendered version (submit button, rest remains unchanged)
unset($vars['form']['submit']['#printed']);
unset($vars['form']['#printed']);
$vars['button'] = drupal_render($vars['form']['submit']);
$vars['form'] = drupal_render($form);
}

if ($vars['form']['#id'] == 'views-exposed-form-Soka-page-4') {
//$vars['form']['#action'] = "/search";
//$vars['form']['views-exposed-form-Soka-page-4']['#action'] == '/sok';
$vars['form']['submit']['#value'] = t('Search');
$vars['form']['submit']['#onclick'] = 'changeAction(this.value)';

$vars['form']['submit']['#id'] = 'form-submit-form';
//$form['#action'] = url('/sok');
$vars['form']['#action'] = '/sok';
$form['#action'] = '/sok';
//$form['name']['#id'] = 'edit-username'; 
//$vars['form']['#title'] = "test";
//dsm($vars);

// Rebuild the rendered version (submit button, rest remains unchanged)
unset($vars['form']['submit']['#printed']);
//unset($vars['form']['#action']);
$vars['button'] = drupal_render($vars['form']['submit']);
$vars['form'] = drupal_render($vars['form']);


//unset($vars['form']['#printed']);

//dsm($vars);

//$vars['form_markup'] = drupal_render($vars['form']);
//$vars['form'] = drupal_render($vars['form']);
//return drupal_render($vars['form']);



}

if ($vars['form']['#id'] == 'views-exposed-form-Soka-page-5') {
$vars['form']['#action'] == '/sok';
$vars['form']['submit']['#value'] = t('Search');
$vars['form']['submit']['#id'] = 'form-submit-form';

// Rebuild the rendered version (submit button, rest remains unchanged)
unset($vars['form']['submit']['#printed']);
$vars['button'] = drupal_render($vars['form']['submit']);
}
if ($vars['form']['#id'] == 'views-exposed-form-Soka-page-6') {
$vars['form']['#action'] == '/sok';
$vars['form']['submit']['#value'] = t('Search');
$vars['form']['submit']['#id'] = 'form-submit-form';

// Rebuild the rendered version (submit button, rest remains unchanged)
unset($vars['form']['submit']['#printed']);
$vars['button'] = drupal_render($vars['form']['submit']);
}
if ($vars['form']['#id'] == 'views-exposed-form-Soka-page-7') {
$vars['form']['#action'] == '/sok';
$vars['form']['submit']['#value'] = t('Search');
$vars['form']['submit']['#id'] = 'form-submit-form';

// Rebuild the rendered version (submit button, rest remains unchanged)
unset($vars['form']['submit']['#printed']);
$vars['button'] = drupal_render($vars['form']['submit']);
}

if ($vars['form']['#id'] == 'views-exposed-form-Soka-page-8') {

$vars['form']['submit']['#value'] = t('Search');
$vars['form']['submit']['#id'] = 'form-submit-form';

// Rebuild the rendered version (submit button, rest remains unchanged)
unset($vars['form']['submit']['#printed']);
$vars['button'] = drupal_render($vars['form']['submit']);
}






}
function phptemplate_date_all_day_label() {
/** This overrides a theme found in the date module so that "All Day" will not display on the calendar.
To return to normal function replace the line with return t('(All day)'); or any other text that you would rather display
for an all day event. Might be better to override the whole them function rather than the label but this is an easy fix **/
return t('');
}

function skrivutfakta ($indata) {
if (strlen($indata)>=1)
{
print $indata;
}
else
{
print '&mdash;';
}
}



function phptemplate_fieldset_helper_toggle_all($selector = NULL, $id = NULL) {
  if (!user_access('save fieldset state')) {
    return '';
  }

  // Wrap selector string in single quotes
  if ($selector != NULL) {
    $selector = "'". $selector ."'";
  }

  $output = '';
  $output .= '<div class="fieldset-helper-toggle-all"'. (($id != NULL)?' id="'. $id .'"':'') .'>';
  $output .= '<a href="javascript:Drupal.FieldsetHelper.expandFieldsets('. $selector .');">'. t('Expand all') .'</a>';
#  $output .= ' | ';
#  $output .= '<a href="javascript:Drupal.FieldsetHelper.collapseFieldsets('. $selector .');">'. t('Collapse all') .'</a>';
  $output .= '</div>';
  return $output;
}


function lasbartid($tiden)
{
if (strlen($tiden)<=0)
{
return '';
}
$tid =  (strtotime("$tiden"));
$tidformat = date('Y-m-d', $tid);
return $tidformat;
}

function kaltid($tiden)
{
if (strlen($tiden)<=0)
{
return '';
}
$tid =  (strtotime("$tiden"));
$tidformat = date('j M Y \k\l\. H:i', $tid);
return $tidformat;
}




# styla fillistningen
# idé från http://teddy.fr/blog/improving-file-attachments-form-drupal

function phptemplate_upload_attachments($files) {
  $items = array();
  foreach ($files as $file) {
    $file = (object)$file;
    if ($file->list && empty($file->remove)) {
      $extension = strtolower(substr(strrchr($file->filename, '.'), 1));
      $href = file_create_url($file->filepath);
      $text = $file->description ? $file->description : $file->filename;
      $items[] = array(
       'data' => l($text, $href) .'<span class="filstorlek"> ('. format_size($file->filesize) . ')</span>',
//'data' => l($text, $href),
        'class' => 'mime-'. $extension,
      );
    }
  }
  if (count($items)) {
    return theme('item_list', $items, $title = NULL, $type = 'ul', array('class' => 'attachment-list', 'id' => 'attachments'));
  }
}


function phptemplate_status_messages($display = NULL) {
  $output = '';
  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= "<div class=\"messages $type\">\n";
    $output .= " <ul>\n";
    foreach ($messages as $message) {
      $output .= '  <li>'. $message ."</li>\n";
    }
    $output .= " </ul>\n";
    $output .= "</div>\n";
  }
  return $output;
}



function phptemplate_item_list($items = array(), $title = NULL, $type = 'ul', $attributes = NULL) {
  $output = '<div class="item-list">';
  if (isset($title)) {
    $output .= '<h3>'. $title .'</h3>';
  }

  if (!empty($items)) {
    $output .= "<div". drupal_attributes($attributes) .'>';
    $num_items = count($items);
    foreach ($items as $i => $item) {
      $attributes = array();
      $children = array();
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        $data .= theme_item_list($children, NULL, $type, $attributes); // Render nested list
      }
      if ($i == 0) {
        $attributes['class'] = empty($attributes['class']) ? 'first' : ($attributes['class'] .' first');
      }
      if ($i == $num_items - 1) {
        $attributes['class'] = empty($attributes['class']) ? 'last' : ($attributes['class'] .' last');
      }
      $output .= '<span'. drupal_attributes($attributes) .'>'. $data ."</span>\n";
    }
    $output .= "</div>";
  }
  $output .= '</div>';
  return $output;
}

/*

function views_get_current_view_result() {
  $view = views_get_current_view();

  return $view->result;

}
*/

function views_get_current_view_result() {

$view = views_get_current_view();
$view->pager['items_per_page'] = 0;
$view->set_items_per_page(0);

//$view = views_get_view('Soka');
//$view->set_display('page_1');
//  $view->set_items_per_page(5);
//  $view->pre_execute();

//$view->render();  
//$view->preview('default');
//$view->init_display();
//$view = views_get_view('Soka');
//$view->set_display('page_19');
//$view->set_items_per_page(5);
//$view->set_items_per_page(0);
//$view->preview();
//$view->pre_execute();
//$view->execute();




return $view->result;
}

function kreaktor_preprocess_page(&$variables) {  
if ($variables['node']->type != "") {   
$variables['template_files'][] = "page-nodetype-" . $variables['node']->type;
}
}


