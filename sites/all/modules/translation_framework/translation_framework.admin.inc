<?php
// $Id

/**
 * @file
 * Admin page callback file for the translation_framework module.
 */

//////////////////////////////////////////////////////////////////////////////
// Translation Framework Admin Settings

/**
 * Settings form display.
 */
function translation_framework_admin_settings() {
  $info = translation_framework_apis();
  $options = array();
  foreach (array_keys($info) as $key) {
    $options[$key] = $info[$key]['name'];
  }

  $form['translation_framework'] = array('#type' => 'fieldset', '#title' => t('Translation Framework Settings'), '#collapsible' => TRUE, '#collapsed' => FALSE);
  $form['translation_framework']['translation_framework_api'] = array(
    '#type' => 'select',
    '#title' => t('Translation API'),
    '#default_value' => TRANSLATION_FRAMEWORK_API,
    '#options' => $options,
    '#description' => t('API that we shall utilize to translate the data'),
  );
  return system_settings_form($form);
}
