<?php
/**
 * @file
 * scoga_geochallenges_extensions.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function scoga_geochallenges_extensions_default_rules_configuration() {
  $items = array();
  $items['rules_link_condition_poi_confirm_accept'] = entity_import('rules_config', '{ "rules_link_condition_poi_confirm_accept" : {
      "LABEL" : "Rules link: POI Confirm Accept condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "poi_confirmation" : "poi_confirmation" } }
          }
        },
        { "data_is" : { "data" : [ "node:field-status" ], "value" : "0" } }
      ]
    }
  }');
  $items['rules_link_condition_poi_confirm_reject'] = entity_import('rules_config', '{ "rules_link_condition_poi_confirm_reject" : {
      "LABEL" : "Rules link: POI Confirm Reject condition",
      "PLUGIN" : "and",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "poi_confirmation" : "poi_confirmation" } }
          }
        }
      ]
    }
  }');
  $items['rules_link_set_poi_confirm_accept'] = entity_import('rules_config', '{ "rules_link_set_poi_confirm_accept" : {
      "LABEL" : "Rules link: POI Confirm Accept rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules", "php" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "entity_fetched" : { "geochallenge_node" : "Geochallenge Node" } },
            "IF" : [
              { "node_is_of_type" : {
                  "node" : [ "node" ],
                  "type" : { "value" : { "poi_confirmation" : "poi_confirmation" } }
                }
              }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-status" ], "value" : "1" } },
              { "entity_fetch" : {
                  "USING" : { "type" : "node", "id" : [ "node:field-ref-geochallenge:nid" ] },
                  "PROVIDE" : { "entity_fetched" : { "geochallenge_node" : "Geochallenge Node" } }
                }
              },
              { "php_eval" : { "code" : "module_load_include( \\u0027api.points.inc\\u0027, \\u0027scoga\\u0027, \\u0027api\\/scoga\\u0027 );\\r\\n$geochallenge_node = node_load($geochallenge_node-\\u003Enid);\\r\\n\\r\\n\\/\\/Award points to POI Spotter\\r\\n\\/\\/watchdog(\\u0027SCOGA\\u0027,\\u0027reward of \\u0027.$geochallenge_node-\\u003Efield_geochallenge_reward_spot[\\u0027und\\u0027][0][\\u0027value\\u0027].\\u0027 for \\u0027.$node-\\u003Euid.\\u0027 in \\u0027.$geochallenge_node-\\u003Elanguage);\\r\\nscoga_award_points_to_user( $node-\\u003Euid, $geochallenge_node-\\u003Efield_geochallenge_reward_spot[\\u0027und\\u0027][0][\\u0027value\\u0027], \\u0022Geochallenge punt goedgekeurd!\\u0022 );\\r\\n\\r\\n\\/\\/Award points to POI Checker\\r\\n\\/\\/watchdog(\\u0027SCOGA\\u0027,\\u0027reward of \\u0027.$geochallenge_node-\\u003Efield_geochallenge_reward_check[\\u0027und\\u0027][0][\\u0027value\\u0027].\\u0027 for \\u0027.$node-\\u003Efield_poi_confirm_ref_user[\\u0027und\\u0027][0][\\u0027target_id\\u0027]);\\r\\nscoga_award_points_to_user( $node-\\u003Efield_poi_confirm_ref_user[\\u0027und\\u0027][0][\\u0027target_id\\u0027], $geochallenge_node-\\u003Efield_geochallenge_reward_check[\\u0027und\\u0027][0][\\u0027value\\u0027], \\u0022Geochallenge punt gecontroleerd\\u0022 );" } }
            ],
            "LABEL" : "Confirm a POI Confirmation"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_poi_confirm_reject'] = entity_import('rules_config', '{ "rules_link_set_poi_confirm_reject" : {
      "LABEL" : "Rules link: POI Confirm Reject rules set",
      "PLUGIN" : "rule set",
      "REQUIRES" : [ "rules", "php" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "entity_fetched" : { "geochallenge_node" : "Geochallenge Node" } },
            "IF" : [
              { "node_is_of_type" : {
                  "node" : [ "node" ],
                  "type" : { "value" : { "poi_confirmation" : "poi_confirmation" } }
                }
              }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-status" ], "value" : "2" } },
              { "entity_fetch" : {
                  "USING" : { "type" : "node", "id" : [ "node:field-ref-geochallenge:nid" ] },
                  "PROVIDE" : { "entity_fetched" : { "geochallenge_node" : "Geochallenge Node" } }
                }
              },
              { "php_eval" : { "code" : "module_load_include( \\u0027api.points.inc\\u0027, \\u0027scoga\\u0027, \\u0027api\\/scoga\\u0027 );\\r\\n$geochallenge_node = node_load($geochallenge_node-\\u003Enid);\\r\\n\\r\\n\\/\\/Award points to POI Checker\\r\\nwatchdog(\\u0027SCOGA\\u0027,\\u0027reward of \\u0027.$geochallenge_node-\\u003Efield_geochallenge_reward_check[\\u0027und\\u0027][0][\\u0027value\\u0027].\\u0027 for \\u0027.$node-\\u003Efield_poi_confirm_ref_user[\\u0027und\\u0027][0][\\u0027target_id\\u0027]);\\r\\nscoga_award_points_to_user( $node-\\u003Efield_poi_confirm_ref_user[\\u0027und\\u0027][0][\\u0027target_id\\u0027], $geochallenge_node-\\u003Efield_geochallenge_reward_check[\\u0027und\\u0027][0][\\u0027value\\u0027], \\u0022Geochallenge punt gecontroleerd\\u0022 );" } }
            ],
            "LABEL" : "POI Confirm Reject"
          }
        }
      ]
    }
  }');
  $items['rules_preprocess_new_poi_for_geochallenge'] = entity_import('rules_config', '{ "rules_preprocess_new_poi_for_geochallenge" : {
      "LABEL" : "Preprocess new POI for Geochallenge",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "geochallenges", "scoga" ],
      "REQUIRES" : [ "rules", "php" ],
      "ON" : [ "node_presave" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "poi" : "poi" } } } },
        { "entity_is_new" : { "entity" : [ "node" ] } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : {
              "type" : "integer",
              "value" : {
                "select" : "site:current-user:uid",
                "php" : { "code" : "$geochallenge_nid = arg(1);\\r\\nreturn $geochallenge_nid;" }
              }
            },
            "PROVIDE" : { "variable_added" : { "ref_geochallenge_nid" : "NID of Geochallenge" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "ref-geochallenge-nid" ] },
            "PROVIDE" : { "entity_fetched" : { "ref_geochallenge_node" : "Fetched Geochallenge" } }
          }
        },
        { "data_set" : {
            "data" : [ "node:field-ref-geo-challenge" ],
            "value" : [ "ref-geochallenge-node" ]
          }
        },
        { "data_set" : {
            "data" : [ "node:title" ],
            "value" : "[ref-geochallenge-node:field-poi-unit-name] door [site:current-user]"
          }
        }
      ]
    }
  }');
  $items['rules_process_new_poi_for_geochallenge'] = entity_import('rules_config', '{ "rules_process_new_poi_for_geochallenge" : {
      "LABEL" : "POI for Geochallenge with confirmation processing",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "geochallenges", "scoga" ],
      "REQUIRES" : [ "rules", "php" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "poi" : "poi" } } } },
        { "php_eval" : { "code" : "$poi_node = node_load($node-\\u003Enid);\\r\\n$geochallenge_node = node_load($poi_node-\\u003Efield_ref_geo_challenge[\\u0027und\\u0027][0][\\u0027target_id\\u0027]);\\r\\nif ($geochallenge_node-\\u003Efield_options[\\u0027und\\u0027][1][\\u0027value\\u0027] == \\u0027poi_confirm\\u0027) {\\r\\n  return true;\\r\\n} else {\\r\\n  return false;\\r\\n}" } }
      ],
      "DO" : [
        { "redirect" : { "url" : [ "node:field-ref-geo-challenge:url" ] } },
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "poi_confirmation",
              "param_title" : "[node:title]",
              "param_author" : [ "node:author" ]
            },
            "PROVIDE" : { "entity_created" : { "poi_confirmation_created_1" : "POI Confirmation #1" } }
          }
        },
        { "variable_add" : {
            "USING" : {
              "type" : "integer",
              "value" : {
                "select" : "node:author:uid",
                "php" : { "code" : "module_load_include( \\u0027api.player.inc\\u0027, \\u0027scoga\\u0027, \\u0027api\\/scoga\\u0027 );\\r\\n$player = user_load($value);\\r\\n$player_team = $player-\\u003Efield_user_team[\\u0027und\\u0027][0][\\u0027target_id\\u0027];\\r\\n$team = scoga_get_player_uids_by_team_nid($player_team);\\r\\n\\/\\/remove node author from team\\r\\n$player_key_in_array = array_search($value,$team);\\r\\nunset($team[$player_key_in_array]);\\r\\n\\r\\n$checker_1 = array_rand($team);\\r\\n$checker_1 = $team[$checker_1];\\r\\nreturn $checker_1;" }
              }
            },
            "PROVIDE" : { "variable_added" : { "poi_checker_1_uid" : "poi_checker_1_uid" } }
          }
        },
        { "variable_add" : {
            "USING" : {
              "type" : "integer",
              "value" : {
                "select" : "node:field-ref-geo-challenge:nid",
                "php" : { "code" : "$geochallenge = node_load($value);\\r\\n$campaign_nid = $geochallenge-\\u003Efield_campaign[\\u0027und\\u0027][0][\\u0027target_id\\u0027];\\r\\nreturn $campaign_nid;" }
              }
            },
            "PROVIDE" : { "variable_added" : { "geochallenge_campaign_nid" : "Geochallenge Campain NID" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "user", "id" : [ "poi-checker-1-uid" ] },
            "PROVIDE" : { "entity_fetched" : { "poi_checker_1_user" : "poi_checker_1_user" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "geochallenge-campaign-nid" ] },
            "PROVIDE" : { "entity_fetched" : { "geochallenge_campaign_node" : "Geochallenge Campaign Node" } }
          }
        },
        { "data_set" : {
            "data" : [ "poi-confirmation-created-1:field-ref-poi" ],
            "value" : [ "node" ]
          }
        },
        { "data_set" : {
            "data" : [ "poi-confirmation-created-1:field-ref-geochallenge" ],
            "value" : [ "node:field-ref-geo-challenge" ]
          }
        },
        { "data_set" : {
            "data" : [ "poi-confirmation-created-1:field-poi-confirm-ref-user" ],
            "value" : [ "poi-checker-1-user" ]
          }
        },
        { "data_set" : {
            "data" : [ "poi-confirmation-created-1:field-location" ],
            "value" : [ "node:field-location" ]
          }
        },
        { "data_set" : {
            "data" : [ "poi-confirmation-created-1:field-geochallenge-ref-campaign" ],
            "value" : [ "geochallenge-campaign-node" ]
          }
        },
        { "drupal_message" : { "message" : "Bedankt om dit punt toe te voegen! Het zal nu worden gecontroleerd door een van je medespelers. Van zodra dat gebeurd is, worden je punten toegekend! " } }
      ]
    }
  }');
  return $items;
}
