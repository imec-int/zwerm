<?php
/**
 * @file
 * scoga_feature.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function scoga_feature_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'event_formatter_map';
  $openlayers_maps->title = 'Event Formatter Map';
  $openlayers_maps->description = 'A Map Used for Geofield Output for the Event content type';
  $openlayers_maps->data = array(
    'width' => '300px',
    'height' => '400px',
    'image_path' => 'sites/all/modules/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '3.7127289120034, 51.052374937679',
        'zoom' => '14',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'event_map_overlay_openlayers_1' => 'event_map_overlay_openlayers_1',
      'geofield_formatter' => 'geofield_formatter',
    ),
    'layer_weight' => array(
      'event_map_overlay_openlayers_1' => '0',
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
    ),
    'layer_styles' => array(
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
      'event_map_overlay_openlayers_1' => 'default_marker_black',
    ),
    'layer_styles_select' => array(
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
      'event_map_overlay_openlayers_1' => 'default_marker_black',
    ),
    'layer_activated' => array(
      'geofield_formatter' => 'geofield_formatter',
      'event_map_overlay_openlayers_1' => 'event_map_overlay_openlayers_1',
      'openlayers_geojson_picture_this' => 0,
    ),
    'layer_switcher' => array(
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'event_map_overlay_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['event_formatter_map'] = $openlayers_maps;

  return $export;
}
