<?php
/**
 * @file
 * scoga_feature.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function scoga_feature_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'viewmode_revealing';
  $ds_view_mode->label = 'Revealing';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['viewmode_revealing'] = $ds_view_mode;

  return $export;
}
