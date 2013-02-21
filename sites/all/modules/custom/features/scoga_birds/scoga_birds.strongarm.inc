<?php
/**
 * @file
 * scoga_birds.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function scoga_birds_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_scoga_sensor_device';
  $strongarm->value = 0;
  $export['comment_anonymous_scoga_sensor_device'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_scoga_sensor_device_event';
  $strongarm->value = 0;
  $export['comment_anonymous_scoga_sensor_device_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_scoga_sensor_device';
  $strongarm->value = 1;
  $export['comment_default_mode_scoga_sensor_device'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_scoga_sensor_device_event';
  $strongarm->value = 1;
  $export['comment_default_mode_scoga_sensor_device_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_scoga_sensor_device';
  $strongarm->value = '50';
  $export['comment_default_per_page_scoga_sensor_device'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_scoga_sensor_device_event';
  $strongarm->value = '50';
  $export['comment_default_per_page_scoga_sensor_device_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_scoga_sensor_device';
  $strongarm->value = 1;
  $export['comment_form_location_scoga_sensor_device'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_scoga_sensor_device_event';
  $strongarm->value = 1;
  $export['comment_form_location_scoga_sensor_device_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_scoga_sensor_device';
  $strongarm->value = '1';
  $export['comment_preview_scoga_sensor_device'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_scoga_sensor_device_event';
  $strongarm->value = '1';
  $export['comment_preview_scoga_sensor_device_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_scoga_sensor_device';
  $strongarm->value = '1';
  $export['comment_scoga_sensor_device'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_scoga_sensor_device_event';
  $strongarm->value = '1';
  $export['comment_scoga_sensor_device_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_scoga_sensor_device';
  $strongarm->value = 1;
  $export['comment_subject_field_scoga_sensor_device'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_scoga_sensor_device_event';
  $strongarm->value = 1;
  $export['comment_subject_field_scoga_sensor_device_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_scoga_sensor_device';
  $strongarm->value = '0';
  $export['language_content_type_scoga_sensor_device'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_scoga_sensor_device_event';
  $strongarm->value = '0';
  $export['language_content_type_scoga_sensor_device_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_scoga_sensor_device';
  $strongarm->value = array();
  $export['menu_options_scoga_sensor_device'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_scoga_sensor_device_event';
  $strongarm->value = array();
  $export['menu_options_scoga_sensor_device_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_scoga_sensor_device';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_scoga_sensor_device'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_scoga_sensor_device_event';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_scoga_sensor_device_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_scoga_sensor_device';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_scoga_sensor_device'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_scoga_sensor_device_event';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_scoga_sensor_device_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_scoga_sensor_device';
  $strongarm->value = '0';
  $export['node_preview_scoga_sensor_device'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_scoga_sensor_device_event';
  $strongarm->value = '0';
  $export['node_preview_scoga_sensor_device_event'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_scoga_sensor_device';
  $strongarm->value = 0;
  $export['node_submitted_scoga_sensor_device'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_scoga_sensor_device_event';
  $strongarm->value = 0;
  $export['node_submitted_scoga_sensor_device_event'] = $strongarm;

  return $export;
}
