<?php
/**
 * @file
 * scoga_core_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scoga_core_feature_ctools_plugin_api() {
  return array("version" => "3");
}

/**
 * Implements hook_views_api().
 */
function scoga_core_feature_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function scoga_core_feature_node_info() {
  $items = array(
    'nodetype_campaign' => array(
      'name' => t('Campaign'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nodetype_campaign_team' => array(
      'name' => t('Campaign Team'),
      'base' => 'node_content',
      'description' => t('Assigns a specific team to a specific campaign, this is a separate node type, to allow for specific settings per team per campaign, like the points modifier and the total points'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nodetype_team' => array(
      'name' => t('Team'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
