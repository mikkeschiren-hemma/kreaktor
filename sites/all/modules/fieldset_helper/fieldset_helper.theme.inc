<?php
// $Id: fieldset_helper.theme.inc,v 1.1 2009/04/02 17:20:43 jrockowitz Exp $

/**
 * @file
 * Using an include file insures that if a phptemplate_fieldset() function
 * already exists the below function won't throw a
 * 'Fatal error: Cannot redeclare _phptemplate_fieldset()'
 */

/**
 * Overide theme_fieldset using phptemplate.
 */
function phptemplate_fieldset($element) {
  $element = fieldset_helper_alter_theme_fieldset($element);
  return theme_fieldset($element);
}

/**
 * Overide CCK's theme_fieldgroup_fieldset using phptemplate.
 */
function phptemplate_fieldgroup_fieldset($element) {
  $element = fieldset_helper_alter_theme_fieldset($element);
  return theme_fieldgroup_fieldset($element);
}

/**
 * Overide theme_system_modules using phptemplate.
 */
function phptemplate_system_modules($form) {
  $output = theme_system_modules($form);
  return fieldset_helper_alter_theme_system_modules($output);
}
