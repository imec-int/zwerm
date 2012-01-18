<?php
/**
 * @file
 * scoga_kliek_user_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function scoga_kliek_user_feature_default_rules_configuration() {
  $items = array();
  $items['rules_assign_kliek_role'] = entity_import('rules_config', '{ "rules_assign_kliek_role" : {
      "LABEL" : "Assign KLIEK role",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_update" ],
      "IF" : [
        { "entity_has_field" : { "entity" : [ "account" ], "field" : "field_card_id" } },
        { "NOT data_is_empty" : { "data" : [ "account:field-card-id" ] } }
      ],
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
      ]
    }
  }');
  return $items;
}
