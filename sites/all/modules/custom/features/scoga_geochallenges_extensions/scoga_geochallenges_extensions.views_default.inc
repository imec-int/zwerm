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
  $handler->display->display_options['fields']['field_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_location']['settings'] = array(
    'data' => 'full',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['label'] = 'Geo Challenge';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['operator'] = 'field_ref_geo_challenge_target_id_op';
  $handler->display->display_options['filters']['field_ref_geo_challenge_target_id']['expose']['identifier'] = 'field_ref_geo_challenge_target_id';

  /* Display: OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'OpenLayers Data Overlay', 'openlayers_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'poi_overview_map';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'overview';
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
  $translatables['poi_overview'] = array(
    t('Master'),
    t('POI\'s'),
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
    t('Geo Challenge'),
    t('OpenLayers Data Overlay'),
    t('Page'),
    t('Block'),
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
