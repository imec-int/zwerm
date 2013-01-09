<?php
/**
 * @file
 * scoga_geochallenges.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scoga_geochallenges_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function scoga_geochallenges_node_info() {
  $items = array(
    'geo_challenge' => array(
      'name' => t('Geo challenge'),
      'base' => 'node_content',
      'description' => t('A geo challenge is initiated by players or game masters and asks players to add as well as confirm points of interest on a map around a given subject.'),
      'has_title' => '1',
      'title_label' => t('Challenge'),
      'help' => '',
    ),
    'poi' => array(
      'name' => t('POI'),
      'base' => 'node_content',
      'description' => t('A Point of Interest added to a Geochallenge'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'poi_confirmation' => array(
      'name' => t('POI Confirmation'),
      'base' => 'node_content',
      'description' => t('A confirmation of a POI entered by a player for a Geochallenge'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
