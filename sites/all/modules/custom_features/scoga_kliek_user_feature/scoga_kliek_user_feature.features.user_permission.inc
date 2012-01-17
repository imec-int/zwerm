<?php
/**
 * @file
 * scoga_kliek_user_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function scoga_kliek_user_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: view field_team_reference
  $permissions['view field_team_reference'] = array(
    'name' => 'view field_team_reference',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_team_reference
  $permissions['view own field_team_reference'] = array(
    'name' => 'view own field_team_reference',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
