<?php
// $Id: fieldset_helper.admin.inc,v 1.1.2.1 2009/04/23 20:43:32 jrockowitz Exp $

/**
 * @file
 * Administration page for the 'Fieldset helper' module.
 */

/**
 * Administration page for the 'Fieldset helper' module.
 */
function fieldset_helper_admin_settings() {

  if ( !FORM_HELPER_FIELDSET_PHPTEMPLATE_LOADED ) {
    drupal_set_message(
        t("This module attempted to override the 'phptemplate_fieldset' and 'theme_system_modules' the functions but they already been defined.") .
        t('Please review the <a href="@read_me">README.txt</a> for more information on how to resolve this issue.', array('@readme' => drupal_get_path('module', 'fieldset_helper') .'/README.txt')),
        'error'
    );
  }

  // Auto excluded
  $form['auto_exclude'] = array(
    '#type' => 'fieldset',
    '#title' => t('Automatically excluded forms'),
    '#description' => t("The 'Fieldset helper' module automatically collects a list of any form, by id, that does not have any collapsible fieldsets.") .' '.
        t("These forms are then ignored by this module's hook_form_alter() code, which insures that this module's code is only executed on forms with collapsible fieldsets.") .' '.
        t("If a currently excluded form now has a collapsible fieldset you should clear the excluded forms list below."),
  );

  $form['auto_exclude']['clear_auto_exclude'] = array(
    '#type' => 'submit',
    '#value' => t('Clear automatically excluded forms'),
    '#submit' => array('fieldset_helper_clear_auto_excluded_submit'),
  );

  $auto_exclude = variable_get('fieldset_helper_auto_exclude', array());
  if ($auto_exclude) {
    $value = '<div><ul><li>'. implode('</li><li>', array_keys($auto_exclude)) .'</li></ul></div>';
  }
  else {
    $value = '<div>'. t('There are no excluded forms.') .'</div>';
  }

  $form['auto_exclude']['forms'] = array(
    '#type' => 'fieldset',
    '#title' => t('Automatically excluded forms by id'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#value' => $value,
  );

  // Clear fieldset id lookup
  $form['fieldset_id_lookup_ids'] = array(
    '#type' => 'fieldset',
    '#title' => t('Clear fieldset lookup ids'),
    '#description' => t("The 'Fieldset helper' module creates a lookup table for all the collapsible fieldset ids discovered on your website.") .' '.
        t("Clearing this list will affect the saved collapsible fieldset states for any user who is currently logged in.") .' '.
        t("This list should only need to be cleared if a larger number of forms and/or fieldsets on your website have been modified."),
  );

  $form['fieldset_id_lookup_ids']['clear_fieldset_id_lookup'] = array(
    '#type' => 'submit',
    '#value' => t('Clear fieldset lookup ids'),
    '#submit' => array('fieldset_helper_clear_fieldset_id_lookup_submit'),
  );

  return system_settings_form($form);
}

/**
 * Clear the list of form id excluded by the fieldset_helper_form_alter() function.
 */
function fieldset_helper_clear_auto_excluded_submit() {
  variable_set('fieldset_helper_auto_exclude', array());

  // Set message
  drupal_set_message(t('Excluded forms cleared.'));
}

/**
 * Clear the fieldset helper state manager table
 */
function fieldset_helper_clear_fieldset_id_lookup_submit() {
  fieldset_helper_state_manager_clear_lookup_ids();

  // Set message
  drupal_set_message(t('Fieldset lookup ids  cleared.'));
}


/**
 * Test page for the 'Fieldset helper' module.
 */
function fieldset_helper_test() {
  $output = '';

  // Test FAPI fieldsets
  $output .= '<h3>'. t('Test collapsible fieldsets associated with a FAPI form') .'</h3>';
  $output .= drupal_get_form('fieldset_helper_test_form');

  // Test unassociated fieldsets
  $output .= '<h3>'. t('Test a collapsible fieldset that is not associated with a form or node') .'</h3>';
  $element = array(
    '#type' => 'fieldset',
    '#title' => t('The un-associated fieldset'),
    '#value' => '<div>'. t('Testing the un-associated fieldset') .'</div>',
    '#collapsible' => TRUE,
  );
  $output .= theme('fieldset', $element);

  // Test unassociated fieldsets
  $output .= '<h3>'. t('Test a collapsible fieldset that is just plain html') .'</h3>';
  $output .= '<fieldset class="collapsible"><legend>The plain html fieldset</legend><div>';
  $output .= t('Testing a fieldset that is plain html');

  $output .= '<fieldset class="collapsible"><legend>A nested plain html fieldset</legend><div>'. t('Testing a nested fieldset that is plain html') .'</div></fieldset>';

  $output .= '</div></fieldset>';


  return $output;
}

/**
 * Test form for the 'Fieldset helper' module.
 */
function fieldset_helper_test_form() {
  // Fieldset
  $form['toggle'] = array(
    '#type' => 'markup',
    '#value' => theme('fieldset_helper_toggle_all') .' ['. t("Collapse's only the below forms fieldsets and not the un-associated fieldset.") .']',
  );

  $form['default_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default fieldset'),
  );

  $form['default_fieldset']['textfield'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
  );

  // Collapsible
  $form['collapsible'] = array(
    '#type' => 'fieldset',
    '#title' => t('Collapsible fieldset'),
    '#collapsible' => TRUE,
  );

  $form['collapsible']['textfield'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
  );

  // Collapsed
  $form['collapsed'] = array(
    '#type' => 'fieldset',
    '#title' => t('Collapsed fieldset'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['collapsed']['textfield'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
  );

  // Nested collapsible
  $form['nested'] = array(
    '#type' => 'fieldset',
    '#title' => t('Nested fieldsets'),
    '#collapsible' => TRUE,
  );

  $form['nested']['textfield'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
  );

  // Nested collapsed
  $form['nested']['collapsed'] = array(
    '#type' => 'fieldset',
    '#title' => t('Nested collapsed fieldset'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['nested']['collapsed'] ['textfield'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
  );

  return $form;
}