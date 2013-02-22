<?php
/**
 * @file
 * scoga_birds.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scoga_birds_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_styles") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function scoga_birds_node_info() {
  $items = array(
    'scoga_sensor_device' => array(
      'name' => t('SCOGA sensor device'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Device name'),
      'help' => '',
    ),
    'scoga_sensor_device_event' => array(
      'name' => t('SCOGA sensor device event'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Event name'),
      'help' => '',
    ),
  );
  return $items;
}
