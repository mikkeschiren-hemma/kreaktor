<?php
// $Id: theme.inc,v 1.1 2010/12/16 23:06:30 swentel Exp $

/**
 * @file
 * Theming functions for Object cache views support.
 */

/**
 * Template helper for theme_views_view_object_cache_node().
 */
function template_preprocess_object_cache_node(&$vars) {
  $options = $vars['options'];

  // Make sure the variables are defined.
  $vars['node'] = '';
  $vars['comments'] = '';

  $nid = $vars['row']->{$vars['field_alias']};
  if (!is_numeric($nid)) {
    return;
  }

  $node = object_cache_get('node', $nid);

  if (empty($node)) {
    return;
  }

  $node->view = $vars['view'];
  $node->build_mode = ($options['build_mode'] == 'teaser' || $options['build_mode'] == 'full') ? NODE_BUILD_NORMAL : $options['build_mode'];
  $vars['node'] = node_view($node, $options['build_mode'] == 'teaser', FALSE, $options['links']);

  if (!empty($options['comments']) && function_exists('comment_render')) {
    $vars['comments'] = comment_render($node);
  }
}

/**
 * Template helper for theme_views_view_object_cache_comment().
 */
function template_preprocess_object_cache_comment(&$vars) {
  $options = $vars['options'];
  $view = &$vars['view'];
  $plugin = &$view->style_plugin->row_plugin;
  $comment = $plugin->comments[$vars['row']->cid];
  $node = object_cache_get('node', $comment->nid);
  // Put the view on the node so we can retrieve it in the preprocess.
  $node->view = &$view;

  $links = array();
  if (!empty($options['links'])) {
    $links = module_invoke_all('link', 'comment', $comment, 0);
    drupal_alter('link', $links, $node);
  }

  $vars['comment'] = theme('comment_view', $comment, $node, $links);
}
