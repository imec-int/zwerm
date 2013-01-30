<?php
/**
 * @file
 * scoga_geochallenges_extensions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scoga_geochallenges_extensions_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_layers") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function scoga_geochallenges_extensions_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_rules_link().
 */
function scoga_geochallenges_extensions_default_rules_link() {
  $items = array();
  $items['poi_confirm_accept'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Goedkeuren",
      "link_type" : "javascript",
      "bundles" : { "poi_confirmation" : "poi_confirmation" },
      "entity_link" : 1,
      "confirm_question" : "Punt goedkeuren ?",
      "confirm_description" : "Ben je zeker dat je dit punt wil goedkeuren ?"
    },
    "name" : "poi_confirm_accept",
    "label" : "POI Confirm Accept",
    "path" : "geochallenges\\/poi_confirm_accept",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['poi_confirm_reject'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "Afkeuren",
      "link_type" : "javascript",
      "bundles" : { "poi_confirmation" : "poi_confirmation" },
      "entity_link" : 1,
      "confirm_question" : "Punt goedkeuren ?",
      "confirm_description" : "Ben je zeker dat je dit punt wil goedkeuren ?"
    },
    "name" : "poi_confirm_reject",
    "label" : "POI Confirm Reject",
    "path" : "geochallenges\\/poi_confirm_reject",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  return $items;
}
