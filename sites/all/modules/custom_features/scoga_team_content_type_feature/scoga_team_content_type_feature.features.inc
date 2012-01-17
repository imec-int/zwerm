<?php
/**
 * @file
 * scoga_team_content_type_feature.features.inc
 */

/**
 * Implements hook_node_info().
 */
function scoga_team_content_type_feature_node_info() {
  $items = array(
    'kliek_team' => array(
      'name' => t('Kliek team'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
