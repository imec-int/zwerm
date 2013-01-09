<?php
/**
 * @file
 * scoga_geochallenges_extensions.openlayers_layers.inc
 */

/**
 * Implements hook_openlayers_layers().
 */
function scoga_geochallenges_extensions_openlayers_layers() {
  $export = array();

  $openlayers_layers = new stdClass();
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'google_hybrid_scoga';
  $openlayers_layers->title = 'Google Maps Hybrid for SCOGA';
  $openlayers_layers->description = 'Google Maps with roads and terrain with deeper zoom levels.';
  $openlayers_layers->data = array(
    'type' => 'hybrid',
    'layer_type' => 'openlayers_layer_type_google',
    'numZoomLevels' => '20',
  );
  $export['google_hybrid_scoga'] = $openlayers_layers;

  $openlayers_layers = new stdClass();
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'google_satellite_scoga';
  $openlayers_layers->title = 'Google Maps Satellite for SCOGA';
  $openlayers_layers->description = 'Google Maps Satellite Imagery with deeper zoom levels';
  $openlayers_layers->data = array(
    'type' => 'satellite',
    'layer_type' => 'openlayers_layer_type_google',
    'numZoomLevels' => '20',
  );
  $export['google_satellite_scoga'] = $openlayers_layers;

  return $export;
}
