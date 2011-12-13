<?php
/**
 * @file
 * scoga_checkin_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function scoga_checkin_content_type_node_info() {
  $items = array(
    'checkin' => array(
      'name' => t('Checkin'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
