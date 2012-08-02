<?php
/**
 * @file
 * scoga_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function scoga_feature_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function scoga_feature_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Article'),
      'base' => 'node_content',
      'description' => t('Use <em>articles</em> for time-sensitive content like news, press releases or blog posts.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nodetype_campaign' => array(
      'name' => t('Campaign'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nodetype_campaign_team' => array(
      'name' => t('Campaign Team'),
      'base' => 'node_content',
      'description' => t('Assigns a specific team to a specific campaign, this is a separate node type, to allow for specific settings per team per campaign, like the points modifier and the total points'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nodetype_checkin' => array(
      'name' => t('Checkin'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nodetype_logmessages' => array(
      'name' => t('Logmessages'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nodetype_rfid_reader' => array(
      'name' => t('RFID reader'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nodetype_team' => array(
      'name' => t('Team'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nodetype_wish_fulfilled' => array(
      'name' => t('Wish fulfilled'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nodetype_wished_item' => array(
      'name' => t('Wished Item'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
