<?php
/**
 * @file
 * scoga_checkins_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function scoga_checkins_view_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'checkins';
  $view->description = 'List of all the checkins';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Checkins';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Checkins';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Reader (field_reader_reference) */
  $handler->display->display_options['relationships']['field_reader_reference_nid']['id'] = 'field_reader_reference_nid';
  $handler->display->display_options['relationships']['field_reader_reference_nid']['table'] = 'field_data_field_reader_reference';
  $handler->display->display_options['relationships']['field_reader_reference_nid']['field'] = 'field_reader_reference_nid';
  $handler->display->display_options['relationships']['field_reader_reference_nid']['required'] = 1;
  $handler->display->display_options['relationships']['field_reader_reference_nid']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_reader_reference_nid';
  $handler->display->display_options['fields']['title_1']['label'] = 'Reader';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 1;
  /* Field: Content: User */
  $handler->display->display_options['fields']['field_user_reference']['id'] = 'field_user_reference';
  $handler->display->display_options['fields']['field_user_reference']['table'] = 'field_data_field_user_reference';
  $handler->display->display_options['fields']['field_user_reference']['field'] = 'field_user_reference';
  /* Field: Content: Checkin time (MS) */
  $handler->display->display_options['fields']['field_checkin_time']['id'] = 'field_checkin_time';
  $handler->display->display_options['fields']['field_checkin_time']['table'] = 'field_data_field_checkin_time';
  $handler->display->display_options['fields']['field_checkin_time']['field'] = 'field_checkin_time';
  $handler->display->display_options['fields']['field_checkin_time']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_checkin_time']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_checkin_time']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_checkin_time']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_checkin_time']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_checkin_time']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_checkin_time']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_checkin_time']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_checkin_time']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_checkin_time']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_checkin_time']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_checkin_time']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_checkin_time']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_checkin_time']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_checkin_time']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_checkin_time']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_checkin_time']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_checkin_time']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'checkin' => 'checkin',
  );
  /* Filter criterion: Content: Reader (field_reader_reference) */
  $handler->display->display_options['filters']['field_reader_reference_nid']['id'] = 'field_reader_reference_nid';
  $handler->display->display_options['filters']['field_reader_reference_nid']['table'] = 'field_data_field_reader_reference';
  $handler->display->display_options['filters']['field_reader_reference_nid']['field'] = 'field_reader_reference_nid';
  $handler->display->display_options['filters']['field_reader_reference_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_reader_reference_nid']['expose']['operator_id'] = 'field_reader_reference_nid_op';
  $handler->display->display_options['filters']['field_reader_reference_nid']['expose']['label'] = 'Reader';
  $handler->display->display_options['filters']['field_reader_reference_nid']['expose']['operator'] = 'field_reader_reference_nid_op';
  $handler->display->display_options['filters']['field_reader_reference_nid']['expose']['identifier'] = 'field_reader_reference_nid';
  $handler->display->display_options['filters']['field_reader_reference_nid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_reader_reference_nid']['expose']['reduce'] = 0;
  /* Filter criterion: Content: User (field_user_reference) */
  $handler->display->display_options['filters']['field_user_reference_uid']['id'] = 'field_user_reference_uid';
  $handler->display->display_options['filters']['field_user_reference_uid']['table'] = 'field_data_field_user_reference';
  $handler->display->display_options['filters']['field_user_reference_uid']['field'] = 'field_user_reference_uid';
  $handler->display->display_options['filters']['field_user_reference_uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_reference_uid']['expose']['operator_id'] = 'field_user_reference_uid_op';
  $handler->display->display_options['filters']['field_user_reference_uid']['expose']['label'] = 'User';
  $handler->display->display_options['filters']['field_user_reference_uid']['expose']['operator'] = 'field_user_reference_uid_op';
  $handler->display->display_options['filters']['field_user_reference_uid']['expose']['identifier'] = 'field_user_reference_uid';
  $handler->display->display_options['filters']['field_user_reference_uid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_user_reference_uid']['expose']['reduce'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'checkins';
  $export['checkins'] = $view;

  return $export;
}
