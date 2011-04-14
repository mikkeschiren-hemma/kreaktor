<?php
// $Id: key_combo.inc,v 1.1.2.2 2009/04/06 02:46:17 deciphered Exp $

/**
 * @file
 * Defines the Key Combo dropdown behavior
 */

function admin_menu_dropdown_key_combo_js_vars($js) {
  if (variable_get('admin_menu_dropdown_mode', 'key_combo') == 'key_combo') {
    $js['visibilityCombo'] = variable_get('admin_menu_dropdown_visibility_modifier', 'ctrl + alt') .
      (variable_get('admin_menu_dropdown_visibility_key', '') ? " + ". variable_get('admin_menu_dropdown_visibility_key', '') : '');

    $js['positionCombo'] = variable_get('admin_menu_dropdown_disable_modifier', 'ctrl + alt + shift') .
      (variable_get('admin_menu_dropdown_disable_key', '') ? " + ". variable_get('admin_menu_dropdown_disable_key', '') : '');
  }

  return $js;
}

function admin_menu_dropdown_key_combo_settings() {
  $form['#element_validate'] = array('admin_menu_dropdown_key_combo_settings_validate');
  $form['admin_menu_dropdown_visibility_modifier'] = array(
    '#type' => 'select',
    '#title' => t('Visibilty toggle modifier + key'),
    '#options' => admin_menu_dropdown_key_combo_settings_combos('modifier'),
    '#default_value' => variable_get('admin_menu_dropdown_visibility_modifier', ''),
    '#prefix' => '<div class="inline-element">',
    '#suffix' => '</div>',
  );
  $form['admin_menu_dropdown_visibility_key'] = array(
    '#type' => 'select',
    '#options' => admin_menu_dropdown_key_combo_settings_combos('key'),
    '#default_value' => variable_get('admin_menu_dropdown_visibility_key', ''),
    '#description' => t('Key combination to show/hide Administration Menu.'),
    '#prefix' => '<div class="inline-element"> + ',
    '#suffix' => '</div>',
  );

  $form['admin_menu_dropdown_disable_modifier'] = array(
    '#type' => 'select',
    '#title' => t('Position toggle modifier + key'),
    '#options' => admin_menu_dropdown_key_combo_settings_combos('modifier'),
    '#default_value' => variable_get('admin_menu_dropdown_disable_modifier', 'ctrl + alt + shift'),
    '#prefix' => '<div class="inline-element">',
    '#suffix' => '</div>',
  );
  $form['admin_menu_dropdown_disable_key'] = array(
    '#type' => 'select',
    '#options' => admin_menu_dropdown_key_combo_settings_combos('key'),
    '#default_value' => variable_get('admin_menu_dropdown_disable_key', ''),
    '#description' => t('Key combination to enable/disable fixed positioning of Administration Menu.'),
    '#prefix' => '<div class="inline-element"> + ',
    '#suffix' => '</div>',
  );

  return $form;
}

function admin_menu_dropdown_key_combo_settings_validate($form, &$form_state) {
  if ($form_state['values']['admin_menu_dropdown_visibility_modifier'] == $form_state['values']['admin_menu_dropdown_disable_modifier']
      && $form_state['values']['admin_menu_dropdown_visibility_key'] == $form_state['values']['admin_menu_dropdown_disable_key']) {
    form_set_error('', t('Each key combination must be unique.'));
  }
}

function admin_menu_dropdown_key_combo_settings_combos($type) {
  switch ($type) {
    case 'key':
      $options = array(
        '' => 'None',
        '65' => 'A',
        '66' => 'B',
        '67' => 'C',
        '68' => 'D',
        '69' => 'E',
        '70' => 'F',
        '71' => 'G',
        '72' => 'H',
        '73' => 'I',
        '74' => 'J',
        '75' => 'K',
        '76' => 'L',
        '77' => 'M',
        '78' => 'N',
        '79' => 'O',
        '80' => 'P',
        '81' => 'Q',
        '82' => 'R',
        '83' => 'S',
        '84' => 'T',
        '85' => 'U',
        '86' => 'V',
        '87' => 'W',
        '88' => 'X',
        '89' => 'Y',
        '90' => 'Z',
      );
      break;

    case 'modifier':
      $options = array(
        'ctrl + alt' => 'ctrl + alt',
        'ctrl + shift' => 'ctrl + shift',
        'ctrl + alt + shift' => 'ctrl + alt + shift',
      );
      break;
  }

  return $options;
}