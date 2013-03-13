<?php
// $Id$

/**
 * @file
 * Field utility functions for the 'Answers' module
 * 
 * @author Chip Cleary
 * 
 */

function answers_field_get_value($node, $field) {
  $items = field_get_items('node', $node, $field);
  return $items[0]['value'];
}


function answers_field_get_node_reference($source_node, $field) {
  $items = field_get_items('node', $source_node, $field);
  $target_nid = $items[0]['nid'];
  return node_load($target_nid);
}

