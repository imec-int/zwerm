<?php
/**
 * @file
 * scoga_views_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function scoga_feature_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'assignments_for_current_user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Assignments for current user';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My assignments';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_assignment_participants_target_id']['id'] = 'field_assignment_participants_target_id';
  $handler->display->display_options['relationships']['field_assignment_participants_target_id']['table'] = 'field_data_field_assignment_participants';
  $handler->display->display_options['relationships']['field_assignment_participants_target_id']['field'] = 'field_assignment_participants_target_id';
  $handler->display->display_options['relationships']['field_assignment_participants_target_id']['label'] = 'User entity referenced from field_assignment_participants';
  $handler->display->display_options['relationships']['field_assignment_participants_target_id']['required'] = 0;
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
  /* Field: Content: Participants */
  $handler->display->display_options['fields']['field_assignment_participants']['id'] = 'field_assignment_participants';
  $handler->display->display_options['fields']['field_assignment_participants']['table'] = 'field_data_field_assignment_participants';
  $handler->display->display_options['fields']['field_assignment_participants']['field'] = 'field_assignment_participants';
  $handler->display->display_options['fields']['field_assignment_participants']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_assignment_participants']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_assignment_participants']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_assignment_participants']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_assignment_participants']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_assignment_participants']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_assignment_participants']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_assignment_participants']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_assignment_participants']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_assignment_participants']['field_api_classes'] = 0;
  /* Field: Content: Time Period */
  $handler->display->display_options['fields']['field_assignment_period']['id'] = 'field_assignment_period';
  $handler->display->display_options['fields']['field_assignment_period']['table'] = 'field_data_field_assignment_period';
  $handler->display->display_options['fields']['field_assignment_period']['field'] = 'field_assignment_period';
  $handler->display->display_options['fields']['field_assignment_period']['label'] = 'End time';
  $handler->display->display_options['fields']['field_assignment_period']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_assignment_period']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_assignment_period']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_assignment_period']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_assignment_period']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_assignment_period']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_assignment_period']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_assignment_period']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_assignment_period']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_assignment_period']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_assignment_period']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_assignment_period']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_assignment_period']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_assignment_period']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_assignment_period']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_assignment_period']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_assignment_period']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_assignment_period']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_assignment_period']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  $handler->display->display_options['fields']['field_assignment_period']['field_api_classes'] = 0;
  /* Sort criterion: Content: Time Period - end date (field_assignment_period:value2) */
  $handler->display->display_options['sorts']['field_assignment_period_value2']['id'] = 'field_assignment_period_value2';
  $handler->display->display_options['sorts']['field_assignment_period_value2']['table'] = 'field_data_field_assignment_period';
  $handler->display->display_options['sorts']['field_assignment_period_value2']['field'] = 'field_assignment_period_value2';
  $handler->display->display_options['sorts']['field_assignment_period_value2']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_assignment_period_value2']['expose']['label'] = 'End time';
  /* Sort criterion: Content: Points award (field_assignment_awardpoints) */
  $handler->display->display_options['sorts']['field_assignment_awardpoints_value']['id'] = 'field_assignment_awardpoints_value';
  $handler->display->display_options['sorts']['field_assignment_awardpoints_value']['table'] = 'field_data_field_assignment_awardpoints';
  $handler->display->display_options['sorts']['field_assignment_awardpoints_value']['field'] = 'field_assignment_awardpoints_value';
  $handler->display->display_options['sorts']['field_assignment_awardpoints_value']['order'] = 'DESC';
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
    'nodetype_assignment' => 'nodetype_assignment',
  );
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'field_assignment_participants_target_id';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/assignments';
  $handler->display->display_options['menu']['title'] = 'My assignments';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['assignments_for_current_user'] = array(
    t('Master'),
    t('My assignments'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('User entity referenced from field_assignment_participants'),
    t('Participants'),
    t('End time'),
    t('Page'),
  );
  $export['assignments_for_current_user'] = $view;

  $view = new view;
  $view->name = 'content_of_current_user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Content of current user';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My content';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'created' => 'created',
    'type' => 'type',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['type']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['type']['link_to_node'] = 0;
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['timestamp']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['timestamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['timestamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['timestamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['timestamp']['link_to_node'] = 0;
  $handler->display->display_options['fields']['timestamp']['comments'] = 0;
  /* Field: Content: New comments */
  $handler->display->display_options['fields']['new_comments']['id'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['table'] = 'node';
  $handler->display->display_options['fields']['new_comments']['field'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['label'] = '';
  $handler->display->display_options['fields']['new_comments']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['external'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['new_comments']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['new_comments']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['html'] = 0;
  $handler->display->display_options['fields']['new_comments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['new_comments']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['new_comments']['hide_empty'] = 0;
  $handler->display->display_options['fields']['new_comments']['empty_zero'] = 0;
  $handler->display->display_options['fields']['new_comments']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['new_comments']['format_plural'] = 0;
  $handler->display->display_options['fields']['new_comments']['link_to_comment'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/content';
  $translatables['content_of_current_user'] = array(
    t('Master'),
    t('My content'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('author'),
    t('Title'),
    t('Post date'),
    t('Type'),
    t('.'),
    t(','),
    t('Page'),
  );
  $export['content_of_current_user'] = $view;

  $view = new view;
  $view->name = 'view_team_members_of_current_user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Players';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'picture' => 'picture',
    'name' => 'name',
    'field_user_firstname' => 'field_user_firstname',
    'field_user_surname' => 'field_user_firstname',
    'points' => 'points',
  );
  $handler->display->display_options['style_options']['default'] = 'name';
  $handler->display->display_options['style_options']['info'] = array(
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_firstname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_user_surname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'points' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_team_target_id']['id'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['table'] = 'field_data_field_user_team';
  $handler->display->display_options['relationships']['field_user_team_target_id']['field'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['required'] = 0;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 1;
  $handler->display->display_options['fields']['picture']['image_style'] = 'thumbnail';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
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
  $handler->display->display_options['fields']['name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_user_firstname']['id'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['table'] = 'field_data_field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['field'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['label'] = 'Name';
  $handler->display->display_options['fields']['field_user_firstname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['field_api_classes'] = 0;
  /* Field: User: Surname */
  $handler->display->display_options['fields']['field_user_surname']['id'] = 'field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['table'] = 'field_data_field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['field'] = 'field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['label'] = '';
  $handler->display->display_options['fields']['field_user_surname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_surname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['field_api_classes'] = 0;
  /* Field: Userpoints: Current points in category */
  $handler->display->display_options['fields']['points']['id'] = 'points';
  $handler->display->display_options['fields']['points']['table'] = 'userpoints';
  $handler->display->display_options['fields']['points']['field'] = 'points';
  $handler->display->display_options['fields']['points']['label'] = 'Points';
  $handler->display->display_options['fields']['points']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['points']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['points']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['points']['alter']['external'] = 0;
  $handler->display->display_options['fields']['points']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['points']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['points']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['points']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['points']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['points']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['points']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['points']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['points']['alter']['html'] = 0;
  $handler->display->display_options['fields']['points']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['points']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['points']['hide_empty'] = 0;
  $handler->display->display_options['fields']['points']['empty_zero'] = 0;
  $handler->display->display_options['fields']['points']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['points']['format_plural'] = 0;
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['relationship'] = 'field_user_team_target_id';
  $handler->display->display_options['arguments']['title']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = 0;
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  $handler->display->display_options['arguments']['title']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['title']['break_phrase'] = 0;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Userpoints: Points category */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'userpoints';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    4 => '4',
  );

  /* Display: Team members of current user */
  $handler = $view->new_display('page', 'Team members of current user', 'page');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 1;
  $handler->display->display_options['fields']['picture']['image_style'] = 'thumbnail';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
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
  $handler->display->display_options['fields']['name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_user_firstname']['id'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['table'] = 'field_data_field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['field'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['label'] = 'Name';
  $handler->display->display_options['fields']['field_user_firstname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['field_api_classes'] = 0;
  /* Field: User: Surname */
  $handler->display->display_options['fields']['field_user_surname']['id'] = 'field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['table'] = 'field_data_field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['field'] = 'field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['label'] = '';
  $handler->display->display_options['fields']['field_user_surname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_surname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Team (field_user_team) */
  $handler->display->display_options['arguments']['field_user_team_target_id']['id'] = 'field_user_team_target_id';
  $handler->display->display_options['arguments']['field_user_team_target_id']['table'] = 'field_data_field_user_team';
  $handler->display->display_options['arguments']['field_user_team_target_id']['field'] = 'field_user_team_target_id';
  $handler->display->display_options['arguments']['field_user_team_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_user_team_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_user_team_target_id']['default_argument_options']['code'] = 'global $user;
$user_profile = user_load( $user->uid);
return $user_profile->field_user_team[ LANGUAGE_NONE ][ 0 ][ \'target_id\' ];';
  $handler->display->display_options['arguments']['field_user_team_target_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_user_team_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_team_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_team_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_user_team_target_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_user_team_target_id']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '0';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: User: Last login */
  $handler->display->display_options['filters']['login']['id'] = 'login';
  $handler->display->display_options['filters']['login']['table'] = 'users';
  $handler->display->display_options['filters']['login']['field'] = 'login';
  $handler->display->display_options['filters']['login']['operator'] = '>=';
  $handler->display->display_options['filters']['login']['value']['value'] = '2012-05-01';
  $handler->display->display_options['path'] = 'user/teammembers';

  /* Display: Players by team */
  $handler = $view->new_display('page', 'Players by team', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 1;
  $handler->display->display_options['fields']['picture']['image_style'] = 'thumbnail';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
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
  $handler->display->display_options['fields']['name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_user_firstname']['id'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['table'] = 'field_data_field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['field'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['label'] = 'Name';
  $handler->display->display_options['fields']['field_user_firstname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['field_api_classes'] = 0;
  /* Field: User: Surname */
  $handler->display->display_options['fields']['field_user_surname']['id'] = 'field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['table'] = 'field_data_field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['field'] = 'field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['label'] = '';
  $handler->display->display_options['fields']['field_user_surname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_surname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Last login */
  $handler->display->display_options['filters']['login']['id'] = 'login';
  $handler->display->display_options['filters']['login']['table'] = 'users';
  $handler->display->display_options['filters']['login']['field'] = 'login';
  $handler->display->display_options['filters']['login']['operator'] = '>';
  $handler->display->display_options['filters']['login']['value']['value'] = '2012-05-01';
  $handler->display->display_options['path'] = 'team/%/players';

  /* Display: Leaderboard */
  $handler = $view->new_display('page', 'Leaderboard', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Leaderboard';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'picture' => 'picture',
    'name' => 'name',
    'field_user_firstname' => 'field_user_firstname',
    'field_user_surname' => 'field_user_firstname',
    'points' => 'points',
    'field_user_team' => 'field_user_team',
  );
  $handler->display->display_options['style_options']['default'] = 'points';
  $handler->display->display_options['style_options']['info'] = array(
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_firstname' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'field_user_surname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'points' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_team' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Rank';
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
  $handler->display->display_options['fields']['php']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 1;
  $handler->display->display_options['fields']['php']['php_setup'] = '$static->fieldCounter = 0;';
  $handler->display->display_options['fields']['php']['php_value'] = '$static->fieldCounter = $static->fieldCounter+1;
return $static->fieldCounter;';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 1;
  $handler->display->display_options['fields']['picture']['image_style'] = 'avatar_pinhead';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
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
  $handler->display->display_options['fields']['name']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_user_firstname']['id'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['table'] = 'field_data_field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['field'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['label'] = 'Name';
  $handler->display->display_options['fields']['field_user_firstname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['field_api_classes'] = 0;
  /* Field: User: Surname */
  $handler->display->display_options['fields']['field_user_surname']['id'] = 'field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['table'] = 'field_data_field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['field'] = 'field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['label'] = '';
  $handler->display->display_options['fields']['field_user_surname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_surname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['field_api_classes'] = 0;
  /* Field: User: Team */
  $handler->display->display_options['fields']['field_user_team']['id'] = 'field_user_team';
  $handler->display->display_options['fields']['field_user_team']['table'] = 'field_data_field_user_team';
  $handler->display->display_options['fields']['field_user_team']['field'] = 'field_user_team';
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
  $handler->display->display_options['fields']['field_user_team']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_user_team']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_team']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_team']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_team']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_team']['settings'] = array(
    'link' => 1,
  );
  $handler->display->display_options['fields']['field_user_team']['field_api_classes'] = 0;
  /* Field: Userpoints: Current points in category */
  $handler->display->display_options['fields']['points_1']['id'] = 'points_1';
  $handler->display->display_options['fields']['points_1']['table'] = 'userpoints';
  $handler->display->display_options['fields']['points_1']['field'] = 'points';
  $handler->display->display_options['fields']['points_1']['label'] = 'Points';
  $handler->display->display_options['fields']['points_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['points_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['points_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['points_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['points_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['points_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['points_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['points_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['points_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['points_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['points_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['points_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['points_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['points_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['points_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['points_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['points_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['points_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['points_1']['format_plural'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Userpoints: Current points in category */
  $handler->display->display_options['sorts']['points']['id'] = 'points';
  $handler->display->display_options['sorts']['points']['table'] = 'userpoints';
  $handler->display->display_options['sorts']['points']['field'] = 'points';
  $handler->display->display_options['sorts']['points']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Userpoints: Points category */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'userpoints';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    4 => '4',
  );
  /* Filter criterion: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 1;
  $handler->display->display_options['filters']['php']['php_setup'] = '$static->userPosition = 0;
$static->counter = 0;';
  $handler->display->display_options['filters']['php']['php_filter'] = '//this filter depends on the view_php module
//$static->counter set to 0 in filter setup code
//$static->userPosition set to 0 in filter setup code
//find the position of the logged in user on the leaderboard
//store the position in the $static variable for reference in later calls


if ($static->userPosition == 0)
{
   global $user;
   $results = $view->result;
   for ($i = 0; $i <= count($results); $i++)
   {
      $result = $results[$i];
      $user_name = $result->users_name;
      if ($user_name==$user->name)
      {
          $static->userPosition = $i;
          break;
      }
   }
   //increment, to reflect real user rank, not zero-based array positions
   $static->userPosition = $static->userPosition+1;
}
else
{
	$static->counter = $static->counter+1;
	$numberOnLeaderboard =$static->counter;
	$loggedInUserPosition = $static->userPosition;

	//if $static->userPosition ==1 , this means that user was not in $view result and has no points
	//in that case, only show top 10 results
	if ($static->userPosition == 1)
	{
		if ($numberOnLeaderboard>9)
		{
			return true;
		}
	}
	else
	{
		//print top 3 players
		//don\'t print the users between top 3 and 3 positions above $static->userPosition
		//don\'t print the users starting from 3 positions under $static->userPosition
		if ((2<$numberOnLeaderboard && $numberOnLeaderboard<$loggedInUserPosition-4) ||
			($numberOnLeaderboard>$loggedInUserPosition+2))
		{
			return true;
		}

		else
		{
			$row->counter = $numberOnLeaderboard ;
			return false;
		}
	}
}
';
  $handler->display->display_options['path'] = 'leaderboard';

  /* Display: Entity Reference View Widget */
  $handler = $view->new_display('entityreference_view_widget', 'Entity Reference View Widget', 'entityreference_view_widget_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'entityreference_view_widget';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_user_team_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'global $user;
$user_profile = user_load( $user->uid);
return $user_profile->field_user_team[ LANGUAGE_NONE ][ 0 ][ \'target_id\' ];';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 1;
  $translatables['view_team_members_of_current_user'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Content entity referenced from field_user_team'),
    t('Username'),
    t('Name'),
    t('Points'),
    t('.'),
    t(','),
    t('All'),
    t('Team members of current user'),
    t('Players by team'),
    t('Leaderboard'),
    t('Team'),
    t('Entity Reference View Widget'),
  );
  $export['view_team_members_of_current_user'] = $view;

  $view = new view;
  $view->name = 'view_transactions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'userpoints_txn';
  $view->human_name = 'Transactions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent points';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'points' => 'points',
    'name' => 'name',
  );
  $handler->display->display_options['row_options']['separator'] = '-';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relationship: Userpoints Transactions: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'userpoints_txn';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Field: Userpoints Transactions: Points */
  $handler->display->display_options['fields']['points']['id'] = 'points';
  $handler->display->display_options['fields']['points']['table'] = 'userpoints_txn';
  $handler->display->display_options['fields']['points']['field'] = 'points';
  $handler->display->display_options['fields']['points']['label'] = '';
  $handler->display->display_options['fields']['points']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['points']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['points']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['points']['alter']['external'] = 0;
  $handler->display->display_options['fields']['points']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['points']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['points']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['points']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['points']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['points']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['points']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['points']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['points']['alter']['html'] = 0;
  $handler->display->display_options['fields']['points']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['points']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['points']['hide_empty'] = 0;
  $handler->display->display_options['fields']['points']['empty_zero'] = 0;
  $handler->display->display_options['fields']['points']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['points']['format_plural'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
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
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Userpoints Transactions: Timestamp */
  $handler->display->display_options['fields']['time_stamp']['id'] = 'time_stamp';
  $handler->display->display_options['fields']['time_stamp']['table'] = 'userpoints_txn';
  $handler->display->display_options['fields']['time_stamp']['field'] = 'time_stamp';
  $handler->display->display_options['fields']['time_stamp']['label'] = '';
  $handler->display->display_options['fields']['time_stamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['time_stamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['time_stamp']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['time_stamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['time_stamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['time_stamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['time_stamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['time_stamp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['time_stamp']['date_format'] = 'time ago';
  /* Sort criterion: Userpoints Transactions: Timestamp */
  $handler->display->display_options['sorts']['time_stamp']['id'] = 'time_stamp';
  $handler->display->display_options['sorts']['time_stamp']['table'] = 'userpoints_txn';
  $handler->display->display_options['sorts']['time_stamp']['field'] = 'time_stamp';
  $handler->display->display_options['sorts']['time_stamp']['order'] = 'DESC';
  /* Filter criterion: Userpoints Transactions: Category */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'userpoints_txn';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    4 => '4',
  );

  /* Display: Recent points block */
  $handler = $view->new_display('block', 'Recent points block', 'block');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );

  /* Display: Points page */
  $handler = $view->new_display('page_with_page_title', 'Points page', 'page_with_page_title_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Points';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'points' => 'points',
    'name' => 'name',
    'time_stamp' => 'time_stamp',
    'description' => 'description',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'points' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'time_stamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'description' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Userpoints Transactions: Points */
  $handler->display->display_options['fields']['points']['id'] = 'points';
  $handler->display->display_options['fields']['points']['table'] = 'userpoints_txn';
  $handler->display->display_options['fields']['points']['field'] = 'points';
  $handler->display->display_options['fields']['points']['label'] = '';
  $handler->display->display_options['fields']['points']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['points']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['points']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['points']['alter']['external'] = 0;
  $handler->display->display_options['fields']['points']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['points']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['points']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['points']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['points']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['points']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['points']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['points']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['points']['alter']['html'] = 0;
  $handler->display->display_options['fields']['points']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['points']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['points']['hide_empty'] = 0;
  $handler->display->display_options['fields']['points']['empty_zero'] = 0;
  $handler->display->display_options['fields']['points']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['points']['format_plural'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
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
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Userpoints Transactions: Timestamp */
  $handler->display->display_options['fields']['time_stamp']['id'] = 'time_stamp';
  $handler->display->display_options['fields']['time_stamp']['table'] = 'userpoints_txn';
  $handler->display->display_options['fields']['time_stamp']['field'] = 'time_stamp';
  $handler->display->display_options['fields']['time_stamp']['label'] = '';
  $handler->display->display_options['fields']['time_stamp']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['external'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['time_stamp']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['time_stamp']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['time_stamp']['alter']['html'] = 0;
  $handler->display->display_options['fields']['time_stamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['time_stamp']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['time_stamp']['hide_empty'] = 0;
  $handler->display->display_options['fields']['time_stamp']['empty_zero'] = 0;
  $handler->display->display_options['fields']['time_stamp']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['time_stamp']['date_format'] = 'time ago';
  /* Field: Userpoints Transactions: Description */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'userpoints_txn';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['description']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['description']['alter']['external'] = 0;
  $handler->display->display_options['fields']['description']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['description']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['description']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['description']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['description']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['description']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['description']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['description']['alter']['html'] = 0;
  $handler->display->display_options['fields']['description']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 1;
  $handler->display->display_options['path'] = 'points';
  $translatables['view_transactions'] = array(
    t('Master'),
    t('Recent points'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Users'),
    t('.'),
    t(','),
    t('Recent points block'),
    t('Points page'),
    t('Points'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Description'),
  );
  $export['view_transactions'] = $view;

  $view = new view;
  $view->name = 'view_users_by_team';
  $view->description = '';
  $view->tag = 'entity reference view widget';
  $view->base_table = 'users';
  $view->human_name = 'Players by team (ERVW)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_team_target_id']['id'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['table'] = 'field_data_field_user_team';
  $handler->display->display_options['relationships']['field_user_team_target_id']['field'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['required'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Gebruiker: First name */
  $handler->display->display_options['fields']['field_user_firstname']['id'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['table'] = 'field_data_field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['field'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['field_api_classes'] = 0;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  /* Field: Gebruiker: Surname */
  $handler->display->display_options['fields']['field_user_surname']['id'] = 'field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['table'] = 'field_data_field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['field'] = 'field_user_surname';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 1;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_user_team_target_id';
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = FALSE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember'] = FALSE;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;

  /* Display: Entity Reference View Widget */
  $handler = $view->new_display('entityreference_view_widget', 'Entity Reference View Widget', 'entityreference_view_widget_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'entityreference_view_widget';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'entityreference_view_widget';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_user_team_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Team';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'team';
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  $translatables['view_users_by_team'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Content entity referenced from field_user_team'),
    t('First name'),
    t('Picture'),
    t('Surname'),
    t('All'),
    t('Title'),
    t('Entity Reference View Widget'),
    t('Team'),
  );
  $export['view_users_by_team'] = $view;

  $view = new view;
  $view->name = 'view_wishlist_by_team';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Wishlist';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest wishes';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'viewmode_revealing';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_team_target_id']['id'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['table'] = 'field_data_field_user_team';
  $handler->display->display_options['relationships']['field_user_team_target_id']['field'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['field_user_team_target_id']['required'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Wished item';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
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
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['external'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['picture']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['picture']['alter']['html'] = 0;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['picture']['hide_empty'] = 0;
  $handler->display->display_options['fields']['picture']['empty_zero'] = 0;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = 1;
  $handler->display->display_options['fields']['picture']['image_style'] = 'avatar_pinhead';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  $handler->display->display_options['sorts']['created']['granularity'] = 'minute';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'uid';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Wisher';
  /* Contextual filter: Content: Title */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['relationship'] = 'field_user_team_target_id';
  $handler->display->display_options['arguments']['title']['title_enable'] = 1;
  $handler->display->display_options['arguments']['title']['title'] = 'Wishlist for team %1';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = 0;
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  $handler->display->display_options['arguments']['title']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['title']['break_phrase'] = 0;
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
    'nodetype_wished_item' => 'nodetype_wished_item',
  );
  /* Filter criterion: Content: State (field_wisheditem_state) */
  $handler->display->display_options['filters']['field_wisheditem_state_value']['id'] = 'field_wisheditem_state_value';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['table'] = 'field_data_field_wisheditem_state';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['field'] = 'field_wisheditem_state_value';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['value'] = array(
    'open' => 'open',
  );

  /* Display: Wishlist by team */
  $handler = $view->new_display('page', 'Wishlist by team', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Wishlist by team';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodetype_wished_item' => 'nodetype_wished_item',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: State (field_wisheditem_state) */
  $handler->display->display_options['filters']['field_wisheditem_state_value']['id'] = 'field_wisheditem_state_value';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['table'] = 'field_data_field_wisheditem_state';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['field'] = 'field_wisheditem_state_value';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['value'] = array(
    'open' => 'open',
  );
  $handler->display->display_options['path'] = 'team/%/wishlist';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Wishlist';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 1;

  /* Display: Wishlist of current user */
  $handler = $view->new_display('page', 'Wishlist of current user', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My wishlist';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'created' => 'created',
    'field_wisheditem_state' => 'field_wisheditem_state',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_wisheditem_state' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Reward */
  $handler->display->display_options['fields']['field_wisheditem_award']['id'] = 'field_wisheditem_award';
  $handler->display->display_options['fields']['field_wisheditem_award']['table'] = 'field_data_field_wisheditem_award';
  $handler->display->display_options['fields']['field_wisheditem_award']['field'] = 'field_wisheditem_award';
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_wisheditem_award']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_wisheditem_award']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodetype_wished_item' => 'nodetype_wished_item',
  );
  /* Filter criterion: Content: State (field_wisheditem_state) */
  $handler->display->display_options['filters']['field_wisheditem_state_value']['id'] = 'field_wisheditem_state_value';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['table'] = 'field_data_field_wisheditem_state';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['field'] = 'field_wisheditem_state_value';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['value'] = array(
    'open' => 'open',
  );
  $handler->display->display_options['path'] = 'user/wishlist';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Wishlist';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 1;

  /* Display: Wishlist block */
  $handler = $view->new_display('block', 'Wishlist block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Recent wishes';
  $handler->display->display_options['display_description'] = 'Displays latest wished items';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_wisheditem_award' => 'field_wisheditem_award',
    'title' => 'title',
    'name' => 'name',
  );
  $handler->display->display_options['row_options']['separator'] = '-';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Reward */
  $handler->display->display_options['fields']['field_wisheditem_award']['id'] = 'field_wisheditem_award';
  $handler->display->display_options['fields']['field_wisheditem_award']['table'] = 'field_data_field_wisheditem_award';
  $handler->display->display_options['fields']['field_wisheditem_award']['field'] = 'field_wisheditem_award';
  $handler->display->display_options['fields']['field_wisheditem_award']['label'] = '';
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_wisheditem_award']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_wisheditem_award']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_wisheditem_award']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_wisheditem_award']['field_api_classes'] = 0;
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
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
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
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'time ago';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  $handler->display->display_options['sorts']['created']['granularity'] = 'minute';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
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
    'nodetype_wished_item' => 'nodetype_wished_item',
  );
  /* Filter criterion: Content: State (field_wisheditem_state) */
  $handler->display->display_options['filters']['field_wisheditem_state_value']['id'] = 'field_wisheditem_state_value';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['table'] = 'field_data_field_wisheditem_state';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['field'] = 'field_wisheditem_state_value';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['value'] = array(
    'open' => 'open',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_user_team_target_id';
  $handler->display->display_options['filters']['title']['operator'] = '!=';
  $handler->display->display_options['filters']['title']['value'] = 'Unassigned';
  $handler->display->display_options['block_description'] = 'Wishlist';

  /* Display: Wishlist of current user (ERVW) */
  $handler = $view->new_display('entityreference_view_widget', 'Wishlist of current user (ERVW)', 'entityreference_view_widget_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'entityreference_view_widget';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'entityreference_view_widget';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  $translatables['view_wishlist_by_team'] = array(
    t('Master'),
    t('Latest wishes'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('author'),
    t('Content entity referenced from field_user_team'),
    t('Wished item'),
    t('Username'),
    t('Post date'),
    t('Title'),
    t('Wisher'),
    t('All'),
    t('Wishlist for team %1'),
    t('Wishlist by team'),
    t('Wishlist of current user'),
    t('My wishlist'),
    t('Reward'),
    t('Wishlist block'),
    t('Recent wishes'),
    t('Displays latest wished items'),
    t('Wishlist'),
    t('Wishlist of current user (ERVW)'),
  );
  $export['view_wishlist_by_team'] = $view;

  $view = new view;
  $view->name = 'view_wishlist_for_user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Wishlist for user';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My wishlist';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['status']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['status']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['status']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['status']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: New comments */
  $handler->display->display_options['fields']['new_comments']['id'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['table'] = 'node';
  $handler->display->display_options['fields']['new_comments']['field'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['label'] = 'Comments';
  $handler->display->display_options['fields']['new_comments']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['external'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['new_comments']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['new_comments']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['new_comments']['alter']['html'] = 0;
  $handler->display->display_options['fields']['new_comments']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['new_comments']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['new_comments']['hide_empty'] = 0;
  $handler->display->display_options['fields']['new_comments']['empty_zero'] = 0;
  $handler->display->display_options['fields']['new_comments']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['new_comments']['format_plural'] = 0;
  $handler->display->display_options['fields']['new_comments']['link_to_comment'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['default_argument_skip_url'] = 1;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['uid']['not'] = 0;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodetype_wished_item' => 'nodetype_wished_item',
  );

  /* Display: Wishlist for current user */
  $handler = $view->new_display('page', 'Wishlist for current user', 'page');
  $handler->display->display_options['path'] = 'user/wishlistTEMP';
  $translatables['view_wishlist_for_user'] = array(
    t('Master'),
    t('My wishlist'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Title'),
    t('Published'),
    t('Comments'),
    t('.'),
    t(','),
    t('All'),
    t('Wishlist for current user'),
  );
  $export['view_wishlist_for_user'] = $view;

  return $export;
}
