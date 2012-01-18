<?php
/**
 * @file
 * scoga_kliek_team_feature.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function scoga_kliek_team_feature_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  array(
    \'vid\' => \'172\',
    \'uid\' => \'1\',
    \'title\' => \'Unassigned\',
    \'log\' => \'\',
    \'status\' => \'0\',
    \'comment\' => \'1\',
    \'promote\' => \'0\',
    \'sticky\' => \'0\',
    \'vuuid\' => \'\',
    \'nid\' => \'172\',
    \'type\' => \'kliek_team\',
    \'language\' => \'und\',
    \'created\' => \'1326813300\',
    \'changed\' => \'1326880895\',
    \'tnid\' => \'0\',
    \'translate\' => \'0\',
    \'uuid\' => \'8752a284-d3e7-cc24-1970-9c7264725541\',
    \'revision_timestamp\' => \'1326880895\',
    \'revision_uid\' => \'1\',
    \'body\' => array(
      \'und\' => array(
        \'0\' => array(
          \'value\' => \'<p>&nbsp;</p>
<div>
	<p>This is the default team a player belongs to. After registration ALL players should be part of a &quot;real&quot; team.</p>
</div>
<p>&nbsp;</p>
\',
          \'summary\' => \'\',
          \'format\' => \'filtered_html\',
          \'safe_value\' => \'<p> </p>
<p>	This is the default team a player belongs to. After registration ALL players should be part of a "real" team.</p>
<p> </p>
\',
          \'safe_summary\' => \'\',
        ),
      ),
    ),
    \'field_team_score\' => array(),
    \'field_team_score_multiplier\' => array(),
    \'rdf_mapping\' => array(
      \'rdftype\' => array(
        \'0\' => \'sioc:Item\',
        \'1\' => \'foaf:Document\',
      ),
      \'title\' => array(
        \'predicates\' => array(
          \'0\' => \'dc:title\',
        ),
      ),
      \'created\' => array(
        \'predicates\' => array(
          \'0\' => \'dc:date\',
          \'1\' => \'dc:created\',
        ),
        \'datatype\' => \'xsd:dateTime\',
        \'callback\' => \'date_iso8601\',
      ),
      \'changed\' => array(
        \'predicates\' => array(
          \'0\' => \'dc:modified\',
        ),
        \'datatype\' => \'xsd:dateTime\',
        \'callback\' => \'date_iso8601\',
      ),
      \'body\' => array(
        \'predicates\' => array(
          \'0\' => \'content:encoded\',
        ),
      ),
      \'uid\' => array(
        \'predicates\' => array(
          \'0\' => \'sioc:has_creator\',
        ),
        \'type\' => \'rel\',
      ),
      \'name\' => array(
        \'predicates\' => array(
          \'0\' => \'foaf:name\',
        ),
      ),
      \'comment_count\' => array(
        \'predicates\' => array(
          \'0\' => \'sioc:num_replies\',
        ),
        \'datatype\' => \'xsd:integer\',
      ),
      \'last_activity\' => array(
        \'predicates\' => array(
          \'0\' => \'sioc:last_activity_date\',
        ),
        \'datatype\' => \'xsd:dateTime\',
        \'callback\' => \'date_iso8601\',
      ),
    ),
    \'cid\' => \'0\',
    \'last_comment_timestamp\' => \'1326813300\',
    \'last_comment_name\' => NULL,
    \'last_comment_uid\' => \'1\',
    \'comment_count\' => \'0\',
    \'name\' => \'admin\',
    \'picture\' => \'0\',
    \'data\' => \'b:0;\',
    \'path\' => FALSE,
    \'menu\' => array(
      \'link_title\' => \'\',
      \'mlid\' => 0,
      \'plid\' => 0,
      \'menu_name\' => \'main-menu\',
      \'weight\' => 0,
      \'options\' => array(),
      \'module\' => \'menu\',
      \'expanded\' => 0,
      \'hidden\' => 0,
      \'has_children\' => 0,
      \'customized\' => 0,
      \'parent_depth_limit\' => 8,
      \'description\' => \'\',
      \'enabled\' => 1,
    ),
    \'node_export_drupal_version\' => \'7\',
    \'#_export_node_encode_object\' => \'1\',
  ),
)',
);
  return $node_export;
}
