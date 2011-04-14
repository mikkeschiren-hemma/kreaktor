<?php
// $Id: object_cache.views.inc,v 1.1 2010/12/16 23:06:30 swentel Exp $

/**
 * @file
 * Views file for Object cache.
 */

/**
 * Implementation of hook_views_plugins().
 */
function object_cache_views_plugins() {
  $path = drupal_get_path('module', 'object_cache');
  return array(
    'module' => 'object_cache',
    'row' => array(
      'object_cache_node' => array(
        'title' => t('Object cache node'),
        'help' => t('Caches the node into the object cache for fast retrieval.'),
        'handler' => 'views_plugin_object_cache_node_view',
        'theme' => 'object_cache_node',
        'path' => $path .'/views',
        'base' => array('node'),
        'theme path' => $path .'/views',
        'theme file' => 'theme.inc',
        'uses options' => TRUE,
        'type' => 'normal',
        'help topic' => 'style-node',
      ),
      'object_cache_comment' => array(
        'title' => t('Object cache comment'),
        'help' => t('Caches the comment into the object cache for fast retrieval.'),
        'handler' => 'views_plugin_object_cache_comment_view',
        'theme' => 'object_cache_comment',
        'path' => $path .'/views',
        'base' => array('comments'),
        'theme path' => $path .'/views',
        'theme file' => 'theme.inc',
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}
