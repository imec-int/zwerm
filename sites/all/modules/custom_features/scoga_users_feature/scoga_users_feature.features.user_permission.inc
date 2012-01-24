<?php
/**
 * @file
 * scoga_users_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function scoga_users_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: create checkin content
  $permissions['create checkin content'] = array(
    'name' => 'create checkin content',
    'roles' => array(),
  );

  // Exported permission: create field_card_id
  $permissions['create field_card_id'] = array(
    'name' => 'create field_card_id',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_checkin_score
  $permissions['create field_checkin_score'] = array(
    'name' => 'create field_checkin_score',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_team_reference
  $permissions['create field_team_reference'] = array(
    'name' => 'create field_team_reference',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_team_score
  $permissions['create field_team_score'] = array(
    'name' => 'create field_team_score',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_team_score_multiplier
  $permissions['create field_team_score_multiplier'] = array(
    'name' => 'create field_team_score_multiplier',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_user_registered
  $permissions['create field_user_registered'] = array(
    'name' => 'create field_user_registered',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_user_score
  $permissions['create field_user_score'] = array(
    'name' => 'create field_user_score',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create kliek_team content
  $permissions['create kliek_team content'] = array(
    'name' => 'create kliek_team content',
    'roles' => array(),
  );

  // Exported permission: create rfid_reader content
  $permissions['create rfid_reader content'] = array(
    'name' => 'create rfid_reader content',
    'roles' => array(),
  );

  // Exported permission: delete any checkin content
  $permissions['delete any checkin content'] = array(
    'name' => 'delete any checkin content',
    'roles' => array(),
  );

  // Exported permission: delete any kliek_team content
  $permissions['delete any kliek_team content'] = array(
    'name' => 'delete any kliek_team content',
    'roles' => array(),
  );

  // Exported permission: delete any rfid_reader content
  $permissions['delete any rfid_reader content'] = array(
    'name' => 'delete any rfid_reader content',
    'roles' => array(),
  );

  // Exported permission: delete own checkin content
  $permissions['delete own checkin content'] = array(
    'name' => 'delete own checkin content',
    'roles' => array(),
  );

  // Exported permission: delete own kliek_team content
  $permissions['delete own kliek_team content'] = array(
    'name' => 'delete own kliek_team content',
    'roles' => array(),
  );

  // Exported permission: delete own rfid_reader content
  $permissions['delete own rfid_reader content'] = array(
    'name' => 'delete own rfid_reader content',
    'roles' => array(),
  );

  // Exported permission: edit any checkin content
  $permissions['edit any checkin content'] = array(
    'name' => 'edit any checkin content',
    'roles' => array(),
  );

  // Exported permission: edit any kliek_team content
  $permissions['edit any kliek_team content'] = array(
    'name' => 'edit any kliek_team content',
    'roles' => array(),
  );

  // Exported permission: edit any rfid_reader content
  $permissions['edit any rfid_reader content'] = array(
    'name' => 'edit any rfid_reader content',
    'roles' => array(),
  );

  // Exported permission: edit field_card_id
  $permissions['edit field_card_id'] = array(
    'name' => 'edit field_card_id',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_checkin_score
  $permissions['edit field_checkin_score'] = array(
    'name' => 'edit field_checkin_score',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_team_reference
  $permissions['edit field_team_reference'] = array(
    'name' => 'edit field_team_reference',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_team_score
  $permissions['edit field_team_score'] = array(
    'name' => 'edit field_team_score',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_team_score_multiplier
  $permissions['edit field_team_score_multiplier'] = array(
    'name' => 'edit field_team_score_multiplier',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_user_registered
  $permissions['edit field_user_registered'] = array(
    'name' => 'edit field_user_registered',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_user_score
  $permissions['edit field_user_score'] = array(
    'name' => 'edit field_user_score',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own checkin content
  $permissions['edit own checkin content'] = array(
    'name' => 'edit own checkin content',
    'roles' => array(),
  );

  // Exported permission: edit own field_card_id
  $permissions['edit own field_card_id'] = array(
    'name' => 'edit own field_card_id',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_checkin_score
  $permissions['edit own field_checkin_score'] = array(
    'name' => 'edit own field_checkin_score',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_team_reference
  $permissions['edit own field_team_reference'] = array(
    'name' => 'edit own field_team_reference',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_team_score
  $permissions['edit own field_team_score'] = array(
    'name' => 'edit own field_team_score',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_team_score_multiplier
  $permissions['edit own field_team_score_multiplier'] = array(
    'name' => 'edit own field_team_score_multiplier',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_user_registered
  $permissions['edit own field_user_registered'] = array(
    'name' => 'edit own field_user_registered',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_user_score
  $permissions['edit own field_user_score'] = array(
    'name' => 'edit own field_user_score',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own kliek_team content
  $permissions['edit own kliek_team content'] = array(
    'name' => 'edit own kliek_team content',
    'roles' => array(),
  );

  // Exported permission: edit own rfid_reader content
  $permissions['edit own rfid_reader content'] = array(
    'name' => 'edit own rfid_reader content',
    'roles' => array(),
  );

  // Exported permission: view field_card_id
  $permissions['view field_card_id'] = array(
    'name' => 'view field_card_id',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_checkin_score
  $permissions['view field_checkin_score'] = array(
    'name' => 'view field_checkin_score',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_team_reference
  $permissions['view field_team_reference'] = array(
    'name' => 'view field_team_reference',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_team_score
  $permissions['view field_team_score'] = array(
    'name' => 'view field_team_score',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_team_score_multiplier
  $permissions['view field_team_score_multiplier'] = array(
    'name' => 'view field_team_score_multiplier',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_user_registered
  $permissions['view field_user_registered'] = array(
    'name' => 'view field_user_registered',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_user_score
  $permissions['view field_user_score'] = array(
    'name' => 'view field_user_score',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_card_id
  $permissions['view own field_card_id'] = array(
    'name' => 'view own field_card_id',
    'roles' => array(
      0 => 'administrator',
      1 => 'kliek user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_checkin_score
  $permissions['view own field_checkin_score'] = array(
    'name' => 'view own field_checkin_score',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_team_reference
  $permissions['view own field_team_reference'] = array(
    'name' => 'view own field_team_reference',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_team_score
  $permissions['view own field_team_score'] = array(
    'name' => 'view own field_team_score',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_team_score_multiplier
  $permissions['view own field_team_score_multiplier'] = array(
    'name' => 'view own field_team_score_multiplier',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_user_registered
  $permissions['view own field_user_registered'] = array(
    'name' => 'view own field_user_registered',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_user_score
  $permissions['view own field_user_score'] = array(
    'name' => 'view own field_user_score',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
