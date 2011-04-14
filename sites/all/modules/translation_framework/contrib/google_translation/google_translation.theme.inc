<?php
// $id

/**
 * Theme the translation language mappings form
 */
function theme_google_translation_language_mappings_form($form) {
  if (isset($form['mappings'])) {
    $output = drupal_render($form['mappings']);
  }
  $rows = array();
  $rows[] = array(
    'language' => drupal_render($form['language']),
    'google' => drupal_render($form['google']),
    'link' => drupal_render($form['submit']),
  );
  $output .= theme('table', NULL, $rows);
  $output .= drupal_render($form);
  return $output;
}
