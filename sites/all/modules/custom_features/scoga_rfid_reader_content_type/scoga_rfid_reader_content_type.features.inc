<?php
/**
 * @file
 * scoga_rfid_reader_content_type.features.inc
 */

/**
 * Implements hook_node_info().
 */
function scoga_rfid_reader_content_type_node_info() {
  $items = array(
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