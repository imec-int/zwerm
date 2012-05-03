<?php
/**
 * @file
 * scoga_wishlist_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function scoga_wishlist_feature_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function scoga_wishlist_feature_node_info() {
  $items = array(
    'nodetype_wish_fulfilled' => array(
      'name' => t('Wish fulfilled'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nodetype_wished_item' => array(
      'name' => t('Wished Item'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
