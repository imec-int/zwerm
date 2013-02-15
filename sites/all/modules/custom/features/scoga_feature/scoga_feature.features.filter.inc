<?php
/**
 * @file
 * scoga_feature.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function scoga_feature_filter_default_formats() {
  $formats = array();

  // Exported format: Flash HTML.
  $formats['flash_html'] = array(
    'format' => 'flash_html',
    'name' => 'Flash HTML',
    'cache' => '1',
    'status' => '1',
    'weight' => '0',
    'filters' => array(
      'filter_autop' => array(
        'weight' => '-48',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_html' => array(
        'weight' => '-47',
        'status' => '1',
        'settings' => array(
          'allowed_html' => '<a> <b> <br> <font> <img> <i> <li> <p> <span> <textformat> <u> ',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
    ),
  );

  return $formats;
}
