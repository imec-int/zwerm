<?php
/**
 * @file
 * scoga_kliek_user_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function scoga_kliek_user_feature_user_default_roles() {
  $roles = array();

  // Exported role: kliek user
  $roles['kliek user'] = array(
    'name' => 'kliek user',
    'weight' => '3',
  );

  return $roles;
}
