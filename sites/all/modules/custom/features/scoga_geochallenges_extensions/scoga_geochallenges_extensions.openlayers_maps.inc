<?php
/**
 * @file
 * scoga_geochallenges_extensions.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function scoga_geochallenges_extensions_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'poi_overview_map';
  $openlayers_maps->title = 'SCOGA POI Overview Map';
  $openlayers_maps->description = 'A map for a large overview with multiple SCOGA POI layers';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '350px',
    'image_path' => 'sites/all/modules/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '3.7199356355641, 51.055020528332',
        'zoom' => '15',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_fullscreen' => array(
        'activated' => 0,
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_attribution' => array(
        'seperator' => '',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 1,
        'zoomBoxEnabled' => 0,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'poi_overview_openlayers_1' => 'poi_overview_openlayers_1',
        ),
      ),
    ),
    'default_layer' => 'google_hybrid_scoga',
    'layers' => array(
      'google_hybrid_scoga' => 'google_hybrid_scoga',
      'poi_overview_openlayers_1' => 'poi_overview_openlayers_1',
    ),
    'layer_weight' => array(
      'poi_overview_openlayers_1' => '0',
      'poi_per_challenge_data_openlayers_1' => '0',
      'event_map_overlay_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'event_map_overlay_openlayers_1' => '0',
      'poi_per_challenge_data_openlayers_1' => '0',
      'poi_overview_openlayers_1' => 'scoga_marker_green_1_invert',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'event_map_overlay_openlayers_1' => '0',
      'poi_per_challenge_data_openlayers_1' => '0',
      'poi_overview_openlayers_1' => 'scoga_marker_green_1',
    ),
    'layer_activated' => array(
      'poi_overview_openlayers_1' => 'poi_overview_openlayers_1',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'event_map_overlay_openlayers_1' => 0,
      'poi_per_challenge_data_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'poi_overview_openlayers_1' => 'poi_overview_openlayers_1',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'event_map_overlay_openlayers_1' => 0,
      'poi_per_challenge_data_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'scoga_marker_green_1',
      'select' => 'scoga_marker_green_1',
      'temporary' => 'scoga_marker_green_1',
    ),
  );
  $export['poi_overview_map'] = $openlayers_maps;

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'poi_per_challenge_map';
  $openlayers_maps->title = 'SCOGA POI Per Challenge Map';
  $openlayers_maps->description = 'All POI\'s for a given SCOGA Geo-challenge';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'sites/all/modules/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '3.7227344512978, 51.055296041635',
        'zoom' => '15',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'poi_per_challenge_data_openlayers_1' => 'poi_per_challenge_data_openlayers_1',
        ),
      ),
      'openlayers_behavior_zoompanel' => array(),
    ),
    'default_layer' => 'google_hybrid_scoga',
    'layers' => array(
      'google_hybrid_scoga' => 'google_hybrid_scoga',
      'poi_per_challenge_data_openlayers_1' => 'poi_per_challenge_data_openlayers_1',
    ),
    'layer_weight' => array(
      'poi_per_challenge_data_openlayers_1' => '0',
      'poi_overview_openlayers_1' => '0',
      'event_map_overlay_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'event_map_overlay_openlayers_1' => '0',
      'poi_overview_openlayers_1' => '0',
      'poi_per_challenge_data_openlayers_1' => 'default_marker_gold',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'event_map_overlay_openlayers_1' => '0',
      'poi_overview_openlayers_1' => '0',
      'poi_per_challenge_data_openlayers_1' => 'default_marker_gold',
    ),
    'layer_activated' => array(
      'poi_per_challenge_data_openlayers_1' => 'poi_per_challenge_data_openlayers_1',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'event_map_overlay_openlayers_1' => 0,
      'poi_overview_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'event_map_overlay_openlayers_1' => 0,
      'poi_overview_openlayers_1' => 0,
      'poi_per_challenge_data_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $export['poi_per_challenge_map'] = $openlayers_maps;

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'scoga_poi_input';
  $openlayers_maps->title = 'SCOGA POI Input';
  $openlayers_maps->description = 'A Map for adding POI to SCOGA Geo Challenges';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '350px',
    'image_path' => 'sites/all/modules/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '3.7187462230119, 51.056095694645',
        'zoom' => '17',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_geofield' => array(
        'feature_types' => array(
          'point' => 'point',
          'path' => 0,
          'polygon' => 0,
        ),
        'allow_edit' => 0,
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'zoomBoxEnabled' => 0,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
      'openlayers_behavior_tooltip' => array(
        'layers' => array(
          'poi_per_challenge_data_openlayers_1' => 'poi_per_challenge_data_openlayers_1',
        ),
      ),
    ),
    'default_layer' => 'google_hybrid_scoga',
    'layers' => array(
      'google_hybrid_scoga' => 'google_hybrid_scoga',
      'poi_per_challenge_data_openlayers_1' => 'poi_per_challenge_data_openlayers_1',
    ),
    'layer_weight' => array(
      'poi_per_challenge_data_openlayers_1' => '0',
      'poi_overview_openlayers_1' => '0',
      'event_map_overlay_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'event_map_overlay_openlayers_1' => '0',
      'poi_overview_openlayers_1' => '0',
      'poi_per_challenge_data_openlayers_1' => 'default_marker_blue',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'event_map_overlay_openlayers_1' => '0',
      'poi_overview_openlayers_1' => '0',
      'poi_per_challenge_data_openlayers_1' => 'default_marker_blue',
    ),
    'layer_activated' => array(
      'poi_per_challenge_data_openlayers_1' => 'poi_per_challenge_data_openlayers_1',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'event_map_overlay_openlayers_1' => 0,
      'poi_overview_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'poi_per_challenge_data_openlayers_1' => 'poi_per_challenge_data_openlayers_1',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'event_map_overlay_openlayers_1' => 0,
      'poi_overview_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default_select',
      'temporary' => 'default',
    ),
  );
  $export['scoga_poi_input'] = $openlayers_maps;

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'scoga_test_1';
  $openlayers_maps->title = 'SCOGA Test Map 1';
  $openlayers_maps->description = 'Map for entering Geofield data';
  $openlayers_maps->data = array(
    'width' => 'auto',
    'height' => '400px',
    'image_path' => 'sites/all/modules/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '3.7187462230119, 51.056095694645',
        'zoom' => '17',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_geofield' => array(
        'feature_types' => array(
          'point' => 'point',
          'path' => 0,
          'polygon' => 0,
        ),
        'allow_edit' => 0,
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'zoomBoxEnabled' => 0,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
    ),
    'default_layer' => 'google_hybrid_scoga',
    'layers' => array(
      'google_hybrid_scoga' => 'google_hybrid_scoga',
      'poi_per_challenge_data_openlayers_1' => 'poi_per_challenge_data_openlayers_1',
    ),
    'layer_weight' => array(
      'poi_per_challenge_data_openlayers_1' => '0',
      'poi_overview_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'poi_overview_openlayers_1' => '0',
      'poi_per_challenge_data_openlayers_1' => 'default_marker_blue',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'poi_overview_openlayers_1' => '0',
      'poi_per_challenge_data_openlayers_1' => 'default_marker_blue',
    ),
    'layer_activated' => array(
      'poi_per_challenge_data_openlayers_1' => 0,
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'poi_overview_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'poi_per_challenge_data_openlayers_1' => 'poi_per_challenge_data_openlayers_1',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'poi_overview_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['scoga_test_1'] = $openlayers_maps;

  return $export;
}
