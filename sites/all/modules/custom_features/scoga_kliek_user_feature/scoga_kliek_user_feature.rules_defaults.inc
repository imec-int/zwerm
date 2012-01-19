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
  $items['rules_set_user_as_registered'] = entity_import('rules_config', '{ "rules_set_user_as_registered" : {
      "LABEL" : "Set user as registered",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "user_update" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "4" : "4" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "account:field-user-registered" ], "value" : 1 } }
      ]
    }
  }');
  return $items;
}
