<?php
/**
 * @file
 * scoga_wishlist_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function scoga_wishlist_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:user/wishlist
  $menu_links['main-menu:user/wishlist'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'user/wishlist',
    'router_path' => 'user/wishlist',
    'link_title' => 'My Wishlist',
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
    'weight' => '-48',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('My Wishlist');


  return $menu_links;
}
