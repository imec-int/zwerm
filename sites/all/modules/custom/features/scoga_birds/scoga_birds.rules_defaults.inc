<?php
/**
 * @file
 * scoga_birds.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function scoga_birds_default_rules_configuration() {
  $items = array();
  $items['rules_award_bird_points_on_whistle_event'] = entity_import('rules_config', '{ "rules_award_bird_points_on_whistle_event" : {
      "LABEL" : "Award bird points on whistle event",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "birds", "scoga" ],
      "REQUIRES" : [ "rules", "php" ],
      "ON" : [ "node_insert" ],
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "scoga_sensor_device_event" : "scoga_sensor_device_event" } }
          }
        },
        { "data_is" : { "data" : [ "node:field-sensor-type" ], "value" : "whistle" } }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "node:field-ref-sensor-device:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "sensor_device_node" : "sensor device node" } }
          }
        },
        { "php_eval" : { "code" : "module_load_include( \\u0027api.points.inc\\u0027, \\u0027scoga\\u0027, \\u0027api\\/scoga\\u0027 );\\r\\nwatchdog(\\u0027SCOGA Birds\\u0027,\\u0027Awarding points for :\\u0027.$sensor_device_node-\\u003Etitle.\\u0027, user :\\u0027.$sensor_device_node-\\u003Efield_ref_sensor_device_user[\\u0027und\\u0027][0][\\u0027target_id\\u0027]);\\r\\nscoga_award_points_to_user( $sensor_device_node-\\u003Efield_ref_sensor_device_user[\\u0027und\\u0027][0][\\u0027target_id\\u0027], 10, \\u0022Hoorde gefluit op straat!\\u0022);" } }
      ]
    }
  }');
  return $items;
}
