<?php
/**
 * @file
 * scoga_kliek_team_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function scoga_kliek_team_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: view field_score
  $permissions['view field_score'] = array(
    'name' => 'view field_score',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_score
  $permissions['view own field_score'] = array(
    'name' => 'view own field_score',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
