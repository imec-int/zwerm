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

  // Exported menu link: main-menu:get_points
  $menu_links['main-menu:get_points'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'get_points',
    'router_path' => 'get_points',
    'link_title' => 'Speel',
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
    'weight' => '-49',
  );
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
  // Exported menu link: main-menu:messages
  $menu_links['main-menu:messages'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'messages',
    'router_path' => 'messages',
    'link_title' => 'Berichten',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-43',
  );
  // Exported menu link: main-menu:node/3
  $menu_links['main-menu:node/3'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/3',
    'router_path' => 'node/%',
    'link_title' => 'Info',
    'options' => array(
      'attributes' => array(
        'title' => 'General info on how to play the game',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: main-menu:team-overview
  $menu_links['main-menu:team-overview'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'team-overview',
    'router_path' => 'team-overview',
    'link_title' => 'Teams',
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
    'weight' => '-47',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Berichten');
  t('Info');
  t('Score');
  t('Speel');
  t('Teams');


  return $menu_links;
}
