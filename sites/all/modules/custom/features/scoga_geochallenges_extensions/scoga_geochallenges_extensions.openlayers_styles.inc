<?php
/**
 * @file
 * scoga_geochallenges_extensions.openlayers_styles.inc
 */

/**
 * Implements hook_openlayers_styles().
 */
function scoga_geochallenges_extensions_openlayers_styles() {
  $export = array();

  $openlayers_styles = new stdClass();
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'scoga_marker_green_1';
  $openlayers_styles->title = 'SCOGA Green Marker 1';
  $openlayers_styles->description = 'SCOGA Green Marker 1';
  $openlayers_styles->data = array(
    'externalGraphic' => 'http://localhost/smartip/sites/all/themes/zwerm/images/scoga_marker_green_1.png',
    'pointRadius' => 16,
    'fillColor' => '#EE9900',
    'strokeColor' => '#EE9900',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 32,
    'graphicHeight' => 37,
    'graphicOpacity' => 1,
    'graphicYOffset' => -37,
    'graphicName' => 'scogamarker',
    'labelAlign' => 'cm',
  );
  $export['scoga_marker_green_1'] = $openlayers_styles;

  $openlayers_styles = new stdClass();
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'scoga_marker_green_1_invert';
  $openlayers_styles->title = 'SCOGA Green Marker 1 Inverted';
  $openlayers_styles->description = 'SCOGA Green Marker 1 Inverted';
  $openlayers_styles->data = array(
    'externalGraphic' => 'http://localhost/smartip/sites/all/themes/zwerm/images/scoga_marker_green_1_invert.png',
    'pointRadius' => 16,
    'fillColor' => '#EE9900',
    'strokeColor' => '#EE9900',
    'strokeWidth' => 1,
    'fillOpacity' => 1,
    'strokeOpacity' => 1,
    'strokeLinecap' => 'round',
    'strokeDashstyle' => 'solid',
    'graphicWidth' => 32,
    'graphicHeight' => 37,
    'graphicOpacity' => 1,
    'graphicYOffset' => -37,
    'graphicName' => 'scogamarker',
    'labelAlign' => 'cm',
  );
  $export['scoga_marker_green_1_invert'] = $openlayers_styles;

  return $export;
}
