<?php
/**
 * @file
 * scoga_pages_feature.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function scoga_pages_feature_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  array(
    \'vid\' => \'250\',
    \'uid\' => \'1\',
    \'title\' => \'About SCOGA\',
    \'log\' => \'\',
    \'status\' => \'1\',
    \'comment\' => \'1\',
    \'promote\' => \'0\',
    \'sticky\' => \'0\',
    \'vuuid\' => \'862f89a8-9d2b-0914-4985-8c69ea045046\',
    \'ds_switch\' => \'\',
    \'nid\' => \'250\',
    \'type\' => \'page\',
    \'language\' => \'und\',
    \'created\' => \'1335352903\',
    \'changed\' => \'1335352949\',
    \'tnid\' => \'0\',
    \'translate\' => \'0\',
    \'uuid\' => \'ff7eea9a-cac3-9f74-79a2-952260c92b9d\',
    \'revision_timestamp\' => \'1335352949\',
    \'revision_uid\' => \'1\',
    \'body\' => array(
      \'und\' => array(
        \'0\' => array(
          \'value\' => \'<p>Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.</p>\',
          \'summary\' => \'\',
          \'format\' => \'filtered_html\',
          \'safe_value\' => \'<p>Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.</p>
\',
          \'safe_summary\' => \'\',
        ),
      ),
    ),
    \'rdf_mapping\' => array(
      \'rdftype\' => array(
        \'0\' => \'foaf:Document\',
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
    \'last_comment_timestamp\' => \'1335352903\',
    \'last_comment_name\' => NULL,
    \'last_comment_uid\' => \'1\',
    \'comment_count\' => \'0\',
    \'name\' => \'admin\',
    \'picture\' => \'0\',
    \'data\' => \'b:0;\',
    \'path\' => array(
      \'pid\' => \'606\',
      \'source\' => \'node/250\',
      \'alias\' => \'content/about\',
      \'language\' => \'und\',
    ),
    \'menu\' => array(
      \'link_title\' => \'About\',
      \'mlid\' => 0,
      \'plid\' => \'0\',
      \'menu_name\' => \'main-menu\',
      \'weight\' => \'-44\',
      \'options\' => array(),
      \'module\' => \'menu\',
      \'expanded\' => \'0\',
      \'hidden\' => \'1\',
      \'has_children\' => \'0\',
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
