<?php
/**
 * @file
 * scoga_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function scoga_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:leaderboard
  $menu_links['main-menu:leaderboard'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'leaderboard',
    'router_path' => 'leaderboard',
    'link_title' => 'Score',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Score');


  return $menu_links;
}
