<?php
/**
 * @file
 * scoga_feature.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function scoga_feature_default_rules_configuration() {
  $items = array();
  $items['rules_award_default_credits'] = entity_import('rules_config', '{ "rules_award_default_credits" : {
      "LABEL" : "Award default credits",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "REQUIRES" : [ "rules", "userpoints_rules" ],
      "ON" : [ "user_insert" ],
      "IF" : [
        { "user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "4" : "4" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "account" ],
            "points" : "10",
            "tid" : "3",
            "entity" : [ "account" ],
            "description" : "Default credits",
            "operation" : "Add",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_award_points_for_combo_checkin'] = entity_import('rules_config', '{ "rules_award_points_for_combo_checkin" : {
      "LABEL" : "Award points for combo checkin",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "user_relationships_rules", "userpoints_rules" ],
      "ON" : [ "user_relationships_request" ],
      "IF" : [
        { "user_relationships_rules_condition_relationship_has_type" : {
            "relationship" : [ "relationship" ],
            "relationship_type" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "requester" ],
            "points" : "5",
            "tid" : "4",
            "entity" : [ "requester" ],
            "description" : "Awarded for combo checkin",
            "operation" : "Add",
            "display" : 1,
            "moderate" : "approved"
          }
        },
        { "userpoints_action_grant_points" : {
            "user" : [ "requestee" ],
            "points" : "5",
            "tid" : "4",
            "entity" : [ "requestee" ],
            "description" : "Awarded for combo checkin",
            "operation" : "Add",
            "display" : 1,
            "moderate" : "approved"
          }
        }
      ]
    }
  }');
  $items['rules_create_campaignteam_nodes_for_campaign'] = entity_import('rules_config', '{ "rules_create_campaignteam_nodes_for_campaign" : {
      "LABEL" : "Create campaignteam nodes for campaign",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "php" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "nodetype_campaign" : "nodetype_campaign" } }
          }
        }
      ],
      "DO" : [
        { "php_eval" : { "code" : "module_load_include( \\u0027rules.php\\u0027, \\u0027scoga\\u0027 );\\r\\nscoga_rule_create_campaignteam_nodes_for_campaign( $node );" } }
      ]
    }
  }');
  $items['rules_delete_campaignteam_nodes_for_campaign'] = entity_import('rules_config', '{ "rules_delete_campaignteam_nodes_for_campaign" : {
      "LABEL" : "Delete campaignteam nodes for campaign",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "php" ],
      "ON" : [ "node_delete" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "nodetype_campaign" : "nodetype_campaign" } }
          }
        }
      ],
      "DO" : [
        { "php_eval" : { "code" : "module_load_include( \\u0027rules.php\\u0027, \\u0027scoga\\u0027 );\\r\\nscoga_rule_delete_campaignteam_nodes_for_campaign( $node );" } }
      ]
    }
  }');
  $items['rules_fail_all_open_wished_items'] = entity_import('rules_config', '{ "rules_fail_all_open_wished_items" : {
      "LABEL" : "Fail all open wished items",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "php", "rules" ],
      "DO" : [
        { "php_eval" : { "code" : "        module_load_include( \\u0027rules.php\\u0027, \\u0027scoga\\u0027 );\\r\\n        scoga_rule_close_wisheditems();" } }
      ]
    }
  }');
  $items['rules_log_user_points'] = entity_import('rules_config', '{ "rules_log_user_points" : {
      "LABEL" : "Log user points",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "php", "userpoints_rules" ],
      "ON" : [ "userpoints_event_points_awarded_after" ],
      "IF" : [
        { "data_is" : { "data" : [ "userpoints-transaction:tid" ], "value" : "4" } }
      ],
      "DO" : [
        { "php_eval" : { "code" : "module_load_include( \\u0027rules.php\\u0027, \\u0027scoga\\u0027 );\\r\\nscoga_rule_log_user_points( $userpoints_transaction );\\r\\n" } }
      ]
    }
  }');
  $items['rules_reserve_credits_after_wishitem_creation'] = entity_import('rules_config', '{ "rules_reserve_credits_after_wishitem_creation" : {
      "LABEL" : "Reserve credits after wishitem creation",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "REQUIRES" : [ "rules", "php", "userpoints_rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "nodetype_wished_item" : "nodetype_wished_item" } }
          }
        }
      ],
      "DO" : [
        { "userpoints_action_grant_points" : {
            "user" : [ "node:author" ],
            "points" : {
              "select" : "node:field-wisheditem-award",
              "php" : { "code" : "return - $value;" }
            },
            "tid" : "3",
            "entity" : [ "node" ],
            "description" : "Deducted for creating wished item",
            "operation" : "Remove",
            "display" : 1,
            "moderate" : "moderated"
          }
        }
      ]
    }
  }');
  $items['rules_rule_determine_current_campaign'] = entity_import('rules_config', '{ "rules_rule_determine_current_campaign" : {
      "LABEL" : "Determine current campaign",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "php", "rules" ],
      "DO" : [
        { "php_eval" : { "code" : " module_load_include( \\u0027rules.php\\u0027, \\u0027scoga\\u0027 );\\r\\nscoga_rule_determine_current_campaign( TRUE );\\r\\n" } }
      ]
    }
  }');
  $items['rules_rule_send_message_after_comment'] = entity_import('rules_config', '{ "rules_rule_send_message_after_comment" : {
      "LABEL" : "Send message to author after commenting",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "privatemsg_rules", "comment" ],
      "ON" : [ "comment_insert" ],
      "IF" : [
        { "NOT data_is" : { "data" : [ "comment:node:author" ], "value" : [ "comment:author" ] } }
      ],
      "DO" : [
        { "privatemsg_rules_new" : {
            "recipient" : [ "comment:node:author" ],
            "author" : [ "comment:author" ],
            "subject" : "User [comment:name] commented on your item \\u0022[comment:node:title]\\u0022",
            "body" : "User [comment:name] commented on your item \\u0022[comment:node:title]\\u0022,\\r\\ngoto [comment:node]\\r\\n"
          }
        }
      ]
    }
  }');
  $items['rules_rule_transfer_points_to_team'] = entity_import('rules_config', '{ "rules_rule_transfer_points_to_team" : {
      "LABEL" : "Transfer points to team",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "php", "rules", "userpoints_rules" ],
      "ON" : [ "userpoints_event_points_awarded_after" ],
      "DO" : [
        { "php_eval" : { "code" : "module_load_include( \\u0027rules.php\\u0027, \\u0027scoga\\u0027 );\\r\\nscoga_rule_transfer_transaction_points_to_team( $userpoints_transaction );" } }
      ]
    }
  }');
  return $items;
}
