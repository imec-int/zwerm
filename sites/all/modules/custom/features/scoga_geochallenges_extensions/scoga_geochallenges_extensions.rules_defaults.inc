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
  $items['rules_preprocess_new_poi_for_geochallenge'] = entity_import('rules_config', '{ "rules_preprocess_new_poi_for_geochallenge" : {
      "LABEL" : "Preprocess new POI for Geochallenge",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "geochallenges", "scoga" ],
      "REQUIRES" : [ "rules", "php" ],
      "ON" : [ "node_presave" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "poi" : "poi" } } } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : {
              "type" : "integer",
              "value" : {
                "select" : "site:current-user:uid",
                "php" : { "code" : "$value = 271;\\r\\nreturn $value;" }
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
      "LABEL" : "Process new POI for Geochallenge",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "geochallenges", "scoga" ],
      "REQUIRES" : [ "rules" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "poi" : "poi" } } } }
      ],
      "DO" : [
        { "redirect" : { "url" : [ "node:field-ref-geo-challenge:url" ] } },
        { "drupal_message" : { "message" : "Bedankt om dit punt toe te voegen! Het zal nu worden gecontroleerd door een van je medespelers. Van zodra dat gebeurd is, worden je punten toegekend! " } }
      ]
    }
  }');
  return $items;
}
