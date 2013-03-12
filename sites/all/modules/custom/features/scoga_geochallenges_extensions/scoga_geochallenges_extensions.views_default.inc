<?php
/**
 * @file
 * scoga_geochallenges_extensions.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function scoga_geochallenges_extensions_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'poi_overview';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'POI_Overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'POI\'s';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filteren';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 1;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_location',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => 'field_comment',
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_geo_challenge_target_id']['id'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['relationships']['field_ref_geo_challenge_target_id']['table'] = 'field_data_field_ref_geo_challenge';
  $handler->display->display_options['relationships']['field_ref_geo_challenge_target_id']['field'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['relationships']['field_ref_geo_challenge_target_id']['label'] = 'Inhoud entity referenced from field_ref_geo_challenge';
  $handler->display->display_options['relationships']['field_ref_geo_challenge_target_id']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Commentaar */
  $handler->display->display_options['fields']['field_comment']['id'] = 'field_comment';
  $handler->display->display_options['fields']['field_comment']['table'] = 'field_data_field_comment';
  $handler->display->display_options['fields']['field_comment']['field'] = 'field_comment';
  $handler->display->display_options['fields']['field_comment']['label'] = '';
  $handler->display->display_options['fields']['field_comment']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_comment']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_comment']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_comment']['element_type'] = '0';
  $handler->display->display_options['fields']['field_comment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_comment']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_comment']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_comment']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_comment']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_comment']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_comment']['field_api_classes'] = 1;
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_foto']['id'] = 'field_foto';
  $handler->display->display_options['fields']['field_foto']['table'] = 'field_data_field_foto';
  $handler->display->display_options['fields']['field_foto']['field'] = 'field_foto';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Campaign (field_campaign) */
  $handler->display->display_options['arguments']['field_campaign_target_id']['id'] = 'field_campaign_target_id';
  $handler->display->display_options['arguments']['field_campaign_target_id']['table'] = 'field_data_field_campaign';
  $handler->display->display_options['arguments']['field_campaign_target_id']['field'] = 'field_campaign_target_id';
  $handler->display->display_options['arguments']['field_campaign_target_id']['relationship'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['arguments']['field_campaign_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_campaign_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_campaign_target_id']['default_argument_options']['code'] = 'return scoga_get_current_campaign_nid();';
  $handler->display->display_options['arguments']['field_campaign_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_campaign_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_campaign_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_campaign_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_campaign_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_campaign_target_id']['not'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poi' => 'poi',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Geo Challenge (field_ref_geo_challenge) */
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['id'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['table'] = 'field_data_field_ref_geo_challenge';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['field'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['operator_id'] = 'field_ref_geo_challenge_target_id_op';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['label'] = 'Filter op een geo-challenge';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['operator'] = 'field_ref_geo_challenge_target_id_op';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['identifier'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['reduce'] = 0;

  /* Display: OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'OpenLayers Data Overlay', 'openlayers_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_location',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => 'field_comment',
    'view_mode' => 'full',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
  );
  /* Field: Content: Foto */
  $handler->display->display_options['fields']['field_foto']['id'] = 'field_foto';
  $handler->display->display_options['fields']['field_foto']['table'] = 'field_data_field_foto';
  $handler->display->display_options['fields']['field_foto']['field'] = 'field_foto';
  $handler->display->display_options['fields']['field_foto']['label'] = '';
  $handler->display->display_options['fields']['field_foto']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_foto']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_foto']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_foto']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_foto']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_foto']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_foto']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_foto']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_foto']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_foto']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_foto']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_foto']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_foto']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_foto']['element_type'] = '0';
  $handler->display->display_options['fields']['field_foto']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_foto']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_foto']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_foto']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_foto']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_foto']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_foto']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_foto']['settings'] = array(
    'image_style' => 'avatar_pinhead',
    'image_link' => 'file',
  );
  $handler->display->display_options['fields']['field_foto']['field_api_classes'] = 1;
  /* Field: Content: Commentaar */
  $handler->display->display_options['fields']['field_comment']['id'] = 'field_comment';
  $handler->display->display_options['fields']['field_comment']['table'] = 'field_data_field_comment';
  $handler->display->display_options['fields']['field_comment']['field'] = 'field_comment';
  $handler->display->display_options['fields']['field_comment']['label'] = '';
  $handler->display->display_options['fields']['field_comment']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_comment']['alter']['text'] = '[field_comment]
[field_foto]
';
  $handler->display->display_options['fields']['field_comment']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_comment']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_comment']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_comment']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_comment']['element_type'] = '0';
  $handler->display->display_options['fields']['field_comment']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_comment']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_comment']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_comment']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_comment']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_comment']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_comment']['field_api_classes'] = 1;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poi' => 'poi',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['relationship'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  /* Filter criterion: Content: Geo Challenge (field_ref_geo_challenge) */
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['id'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['table'] = 'field_data_field_ref_geo_challenge';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['field'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['operator_id'] = 'field_ref_geo_challenge_target_id_op';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['label'] = 'Filter op een geo challenge';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['operator'] = 'field_ref_geo_challenge_target_id_op';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['identifier'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Zwerm Kaart';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'poi_overview_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poi' => 'poi',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Geo Challenge (field_ref_geo_challenge) */
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['id'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['table'] = 'field_data_field_ref_geo_challenge';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['field'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['operator_id'] = 'field_ref_geo_challenge_target_id_op';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['label'] = 'Filter op een geochallenge';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['operator'] = 'field_ref_geo_challenge_target_id_op';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['identifier'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'kaart';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Kaart';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'poi_overview_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poi' => 'poi',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Geo Challenge (field_ref_geo_challenge) */
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['id'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['table'] = 'field_data_field_ref_geo_challenge';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['field'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['operator_id'] = 'field_ref_geo_challenge_target_id_op';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['label'] = 'Geo Challenge';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['operator'] = 'field_ref_geo_challenge_target_id_op';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['identifier'] = 'field_ref_geo_challenge_target_id';

  /* Display: Birds Data Overlay */
  $handler = $view->new_display('openlayers', 'Birds Data Overlay', 'openlayers_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Birds';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filteren';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = 0;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = 1;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'name',
    'other_lon' => 'name',
    'wkt' => 'field_sensor_device_location',
    'other_top' => 'name',
    'other_right' => 'name',
    'other_bottom' => 'name',
    'other_left' => 'name',
    'name_field' => 'name',
    'description_field' => '#row',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_ref_sensor_device_user_target_id']['id'] = 'field_ref_sensor_device_user_target_id';
  $handler->display->display_options['relationships']['field_ref_sensor_device_user_target_id']['table'] = 'field_data_field_ref_sensor_device_user';
  $handler->display->display_options['relationships']['field_ref_sensor_device_user_target_id']['field'] = 'field_ref_sensor_device_user_target_id';
  $handler->display->display_options['relationships']['field_ref_sensor_device_user_target_id']['required'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_ref_sensor_device_user_target_id';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 0;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_sensor_device_location']['id'] = 'field_sensor_device_location';
  $handler->display->display_options['fields']['field_sensor_device_location']['table'] = 'field_data_field_sensor_device_location';
  $handler->display->display_options['fields']['field_sensor_device_location']['field'] = 'field_sensor_device_location';
  $handler->display->display_options['fields']['field_sensor_device_location']['label'] = '';
  $handler->display->display_options['fields']['field_sensor_device_location']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_sensor_device_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_sensor_device_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_sensor_device_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_sensor_device_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_sensor_device_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_sensor_device_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_sensor_device_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_sensor_device_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_sensor_device_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_sensor_device_location']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_sensor_device_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_sensor_device_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_sensor_device_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_sensor_device_location']['element_type'] = '0';
  $handler->display->display_options['fields']['field_sensor_device_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sensor_device_location']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_sensor_device_location']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_sensor_device_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_sensor_device_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_sensor_device_location']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_sensor_device_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_sensor_device_location']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_sensor_device_location']['field_api_classes'] = 1;
  /* Field: Gebruiker: Team */
  $handler->display->display_options['fields']['field_user_team']['id'] = 'field_user_team';
  $handler->display->display_options['fields']['field_user_team']['table'] = 'field_data_field_user_team';
  $handler->display->display_options['fields']['field_user_team']['field'] = 'field_user_team';
  $handler->display->display_options['fields']['field_user_team']['relationship'] = 'field_ref_sensor_device_user_target_id';
  $handler->display->display_options['fields']['field_user_team']['label'] = '';
  $handler->display->display_options['fields']['field_user_team']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_team']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_team']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_team']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_team']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_team']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_team']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_team']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_team']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_team']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_team']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_team']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_team']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_team']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_team']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_team']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_team']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_team']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_team']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_team']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_user_team']['field_api_classes'] = 1;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = '$query = new EntityFieldQuery;
$result = $query
  ->entityCondition(\'entity_type\', \'node\')
  ->entityCondition(\'bundle\', \'scoga_sensor_device_event\')
  ->fieldCondition(\'field_ref_sensor_device\', \'target_id\', $row->nid , \'=\')
  ->fieldCondition(\'field_sensor_type\', \'value\', \'whistle\' , \'=\')
  ->propertyOrderBy(\'nid\', \'DESC\')
  ->range(0, 1)
  ->execute();
if (key($result) == \'node\') {
return(key($result[\'node\']));
} else {
return null;
}';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
//sadly we load the event node (views messes up here)
if ($value):
  $event=node_load($value);
  $timestamp = $event->field_sensor_val_timestamp[\'und\'][0][\'value\'];
  $today = date(\'j\');
  $timestamp_day = date(\'j\',$timestamp);
  if ($today == $timestamp_day) {
    $timestamp_text = "om ".date(\'G:i\',$timestamp);
  } else {
    $timestamp_text = "op ".date(\'j/n\',$timestamp)." om ".date(\'G:i\',$timestamp);
  }
?>
Hoorde laatst iemand fluiten <?php print $timestamp_text; ?>
<?php else: ?>
Hoorde nog niemand fluiten tijdens deze campagne!
<?php endif; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = '$query = new EntityFieldQuery;
$result = $query
  ->entityCondition(\'entity_type\', \'node\')
  ->entityCondition(\'bundle\', \'scoga_sensor_device_event\')
  ->fieldCondition(\'field_ref_sensor_device\', \'target_id\', $row->nid , \'=\')
  ->fieldCondition(\'field_sensor_type\', \'value\', \'co2\' , \'=\')
  //->propertyOrderBy(\'nid\', \'DESC\')
  ->range(0, 1)
  ->execute();
if (key($result) == \'node\') {
return(key($result[\'node\']));
} else {
return null;
}';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php 
//sadly we load the event node (views messes up here)
if ($value):
  $event=node_load($value);
  $co2_value = $event->field_sensor_val[\'und\'][0][\'value\'];
?>
en detecteerde een CO2 waarde van <?php print $co2_value; ?> deeltjes per miljoen.
<?php endif; ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'scoga_sensor_device' => 'scoga_sensor_device',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $translatables['poi_overview'] = array(
    t('Master'),
    t('POI\'s'),
    t('more'),
    t('Filteren'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Inhoud entity referenced from field_ref_geo_challenge'),
    t('Location'),
    t('Foto'),
    t('All'),
    t('Filter op een geo-challenge'),
    t('OpenLayers Data Overlay'),
    t('[field_comment]
[field_foto]
'),
    t('Filter op een geo challenge'),
    t('Page'),
    t('Zwerm Kaart'),
    t('Filter op een geochallenge'),
    t('Block'),
    t('Geo Challenge'),
    t('Birds Data Overlay'),
    t('Gebruiker entity referenced from field_ref_sensor_device_user'),
  );
  $export['poi_overview'] = $view;

  $view = new view;
  $view->name = 'poi_per_challenge';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'POI per Challenge';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'POI per Geochallenge export';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'geofield_map_map';
  $handler->display->display_options['style_options']['data_source'] = 'field_location';
  $handler->display->display_options['style_options']['popup_source'] = 'title';
  $handler->display->display_options['style_options']['geofield_map_height'] = '400px';
  $handler->display->display_options['style_options']['geofield_map_streetview_show'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_location']['type'] = 'geofield_latlon';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
    'labels' => 1,
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Geo Challenge (field_ref_geo_challenge) */
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['id'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['table'] = 'field_data_field_ref_geo_challenge';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['field'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poi' => 'poi',
  );

  /* Display: Openlayers overview map */
  $handler = $view->new_display('block', 'Openlayers overview map', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'poi_per_challenge_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: POI per Geochallenge Export */
  $handler = $view->new_display('views_data_export', 'POI per Geochallenge Export', 'views_data_export_1');
  $translatables['poi_per_challenge'] = array(
    t('Master'),
    t('POI per Geochallenge export'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Location'),
    t('All'),
    t('Openlayers overview map'),
    t('POI per Geochallenge Export'),
  );
  $export['poi_per_challenge'] = $view;

  $view = new view;
  $view->name = 'poi_per_challenge_data';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'POI per Challenge Data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Challenge Specific POI\'s';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_location',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => '',
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location']['id'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['table'] = 'field_data_field_location';
  $handler->display->display_options['fields']['field_location']['field'] = 'field_location';
  $handler->display->display_options['fields']['field_location']['label'] = '';
  $handler->display->display_options['fields']['field_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
  );
  /* Contextual filter: Content: Geo Challenge (field_ref_geo_challenge) */
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['id'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['table'] = 'field_data_field_ref_geo_challenge';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['field'] = 'field_ref_geo_challenge_target_id';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_ref_geo_challenge_target_id']['not'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'poi' => 'poi',
  );

  /* Display: OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'OpenLayers Data Overlay', 'openlayers_1');
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $translatables['poi_per_challenge_data'] = array(
    t('Master'),
    t('Challenge Specific POI\'s'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('All'),
    t('OpenLayers Data Overlay'),
  );
  $export['poi_per_challenge_data'] = $view;

  return $export;
}
