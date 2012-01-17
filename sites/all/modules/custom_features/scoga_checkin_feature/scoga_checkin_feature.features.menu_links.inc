<?php
/**
 * @file
 * scoga_checkin_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function scoga_checkin_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:checkins
  $menu_links['main-menu:checkins'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'checkins',
    'router_path' => 'checkins',
    'link_title' => 'Checkins',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Checkins');


  return $menu_links;
}
