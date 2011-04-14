<?php
// $id:

/**
 * Function used to display the admin screen for the module
 */
function google_translation_admin_settings() {
  $form['settings'] = array('#type' => 'fieldset', '#title' => t('GOOGLE Translation Settings'), '#collapsible' => TRUE, '#collapsed' => FALSE);
  $form['settings']['google_translation_url'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Google Translation Url'),
    '#default_value' => GOOGLE_TRANSLATION_URL,
    '#size'          => 50,
    '#maxlength'     => 255,
    '#description'   => t('Url where GOOGLE Requests will be sent too'),
  );
  $form['settings']['google_translation_http_method'] = array(
    '#type'          => 'select',
    '#title'         => t('GOOGLE Translation HTTP Request Method'),
    '#default_value' => GOOGLE_TRANSLATION_HTTP_METHOD,
    '#options'       => array('GET' => 'GET', 'POST' => 'POST'),
    '#description'   => t('Port where all XMLRPC requests will be sent too'),
  );
  $form['settings']['google_translation_http_retry'] = array(
    '#type'          => 'textfield',
    '#title'         => t('HTTP Retry Number'),
    '#default_value' => GOOGLE_TRANSLATION_HTTP_RETRY,
    '#size'          => 50,
    '#maxlength'     => 255,
    '#description'   => t('Number of HTTP redirects that should be followed by the request'),
  );
  $form['settings']['google_translation_max_string_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum String Size'),
    '#default_value' => variable_get('google_translation_max_string_size', 500),
    '#size' => 10,
    '#maxlength' => 10,
    '#description' => t('Google Translation API has a maximum limit of around 500 to 700 in the url string, so this allows you to limit the string chunks being sent too the google translation api'),
  );
  return system_settings_form($form);
}

/**
 * Form handler for google translation language mapping form
 */
function google_translation_language_mappings_form(&$form_state) {
  $form = array();
  $mappings = variable_get('google_translation_language_mappings', array());
  $locales = locale_language_list('name');
  $google_locales = google_translation_languages();
  if (is_array($mappings) && !empty($mappings)) {
    $rows = array();
    $header = array('language' => t('Drupal Language'), 'google' => t('Google Language'), 'link' => t('Operation'));
    foreach ($mappings as $k => $v) {
      $rows[] = array('language' => $locales[$k], 'google' => $google_locales[$v], 'link' => l(t('Delete'), 'admin/translation_framework/google_translation/mappings/delete/'. $k));
      unset($locales[$k]);
    }
    // Only display this section if the mappings are not empty
    if (!empty($rows)) {
      $form['mappings'] = array('#value' => theme('table', $header, $rows));
    }
  }
  $form['google'] = array(
    '#type' => 'select',
    '#title' => t('Google Languages'),
    '#options' => $google_locales,
    '#description' => t('Languages that are currently supported by the Google translation engine'),
  );
  $form['language'] = array(
    '#type' => 'select',
    '#title' => t('Drupal Language'),
    '#options' => $locales,
    '#description' => t('Language in Drupal that you wish to map to a Google language'),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add'),
  );
  $form['#theme'] = 'google_translation_language_mappings_form';
  return $form;
}

/**
 * Language Mapping Form Submit Handler
 */
function google_translation_language_mappings_form_submit(&$form, &$form_state) {
  $mappings = variable_get('google_translation_language_mappings', array());
  $google = $form_state['values']['google'];
  $language = $form_state['values']['language'];
  if (isset($mappings[$language])) {
    drupal_set_message(t('Value is already mapped in the system, you must remove the existing mapping before you can re-map the value'), 'error');
  }
  else {
    $mappings[$language] = $google;
    variable_set('google_translation_language_mappings', $mappings);
    drupal_set_message(t('Google langauge mapping has successfully been created'));
  }
  $form_state['redirect'] = 'admin/translation_framework/google_translation/mappings';
}

/**
 * Remove a language mapping from the system
 */
function google_translation_language_mappings_delete($language = NULL) {
  if (is_null($language) || drupal_strlen($language) == 0) {
    watchdog('google_translation', t('Invalid language %language was received by the module'), array('%language' => $language), WATCHDOG_ERROR);
    drupal_set_message(t('Invalid language %language was received by the module', array('%language' => $language), 'error'));
  }
  else {
    $mappings = variable_get('google_translation_language_mappings', array());
    if (isset($mappings[$language])) {
      unset($mappings[$language]);
    }
    variable_set('google_translation_language_mappings', $mappings);
  }
  drupal_goto('admin/translation_framework/google_translation/mappings');
}
