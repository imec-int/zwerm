<?php
/**
 * @file
 * scoga_rfid_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function scoga_rfid_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: REST create checkin
  $permissions['REST create checkin'] = array(
    'name' => 'REST create checkin',
    'roles' => array(
      0 => 'administrator',
      1 => 'player',
    ),
    'module' => 'scoga_rfid',
  );

  // Exported permission: REST register rfid card
  $permissions['REST register rfid card'] = array(
    'name' => 'REST register rfid card',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'scoga_rfid',
  );

  // Exported permission: REST register rfid reader
  $permissions['REST register rfid reader'] = array(
    'name' => 'REST register rfid reader',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'scoga_rfid',
  );

  return $permissions;
}
