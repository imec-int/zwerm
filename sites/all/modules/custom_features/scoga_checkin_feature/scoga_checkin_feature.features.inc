<?php
/**
 * @file
 * scoga_checkin_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function scoga_checkin_feature_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_node_info().
 */
function scoga_checkin_feature_node_info() {
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
