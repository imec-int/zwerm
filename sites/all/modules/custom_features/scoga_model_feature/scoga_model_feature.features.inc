<?php
/**
 * @file
 * scoga_model_feature.features.inc
 */

/**
 * Implements hook_content_type_groups_features_default_settings().
 */
function scoga_model_feature_content_type_groups_features_default_settings() {
 $content_type_groups = array();

 $content_type_groups['player_action'] = array(
   'type' => 'player_action',
   'name' => 'Player action',
   'content_types' => array(
     'checkin' => array(
       'name' => 'Checkin',
       'weight' => '3',
     ),
   ),
 );

 return $content_type_groups;
}

/**
 * Implements hook_node_info().
 */
function scoga_model_feature_node_info() {
  $items = array(
    'checkin' => array(
      'name' => t('Checkin'),
      'base' => 'node_content',
      'description' => t('An unpublished checkin is not counted and was created by an unregistered user.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'kliek_team' => array(
      'name' => t('Kliek team'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'rfid_reader' => array(
      'name' => t('RFID reader'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
