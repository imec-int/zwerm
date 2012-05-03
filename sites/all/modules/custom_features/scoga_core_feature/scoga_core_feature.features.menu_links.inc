<?php
/**
 * @file
 * scoga_core_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function scoga_core_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:messages
  $menu_links['main-menu:messages'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'messages',
    'router_path' => 'messages',
    'link_title' => 'My messages',
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
    'weight' => '-46',
  );
  // Exported menu link: main-menu:myuserpoints
  $menu_links['main-menu:myuserpoints'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'myuserpoints',
    'router_path' => 'myuserpoints',
    'link_title' => 'My !points',
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
    'weight' => '-47',
  );
  // Exported menu link: main-menu:user
  $menu_links['main-menu:user'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: main-menu:user/teammembers
  $menu_links['main-menu:user/teammembers'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user/teammembers',
    'router_path' => 'user/teammembers',
    'link_title' => 'My team',
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
    'weight' => '-45',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('My !points');
  t('My messages');
  t('My team');
  t('User account');


  return $menu_links;
}
