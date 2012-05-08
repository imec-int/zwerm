<?php
/**
 * @file
 * scoga_aggregates_feature.features.inc
 */

/**
 * Implements hook_node_info().
 */
function scoga_aggregates_feature_node_info() {
  $items = array(
    'nodetype_logmessages' => array(
      'name' => t('Logmessages'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
