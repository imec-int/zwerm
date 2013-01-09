<?php
/**
 * @file
 * scoga_feature.views_default.inc
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
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['hide_empty'] = 1;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relatie: Handler defect of ontbreekt */
  $handler->display->display_options['relationships']['field_assignment_participants_target_id']['id'] = 'field_assignment_participants_target_id';
  $handler->display->display_options['relationships']['field_assignment_participants_target_id']['table'] = 'field_data_field_assignment_participants';
  $handler->display->display_options['relationships']['field_assignment_participants_target_id']['field'] = 'field_assignment_participants_target_id';
  $handler->display->display_options['relationships']['field_assignment_participants_target_id']['label'] = 'User entity referenced from field_assignment_participants';
  $handler->display->display_options['relationships']['field_assignment_participants_target_id']['required'] = 0;
  /* Veld: Inhoud: Titel */
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
  /* Veld: Handler defect of ontbreekt */
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
  /* Veld: Handler defect of ontbreekt */
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
  /* Sorteercriterium: Handler defect of ontbreekt */
  $handler->display->display_options['sorts']['field_assignment_period_value2']['id'] = 'field_assignment_period_value2';
  $handler->display->display_options['sorts']['field_assignment_period_value2']['table'] = 'field_data_field_assignment_period';
  $handler->display->display_options['sorts']['field_assignment_period_value2']['field'] = 'field_assignment_period_value2';
  $handler->display->display_options['sorts']['field_assignment_period_value2']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_assignment_period_value2']['expose']['label'] = 'End time';
  /* Sorteercriterium: Handler defect of ontbreekt */
  $handler->display->display_options['sorts']['field_assignment_awardpoints_value']['id'] = 'field_assignment_awardpoints_value';
  $handler->display->display_options['sorts']['field_assignment_awardpoints_value']['table'] = 'field_data_field_assignment_awardpoints';
  $handler->display->display_options['sorts']['field_assignment_awardpoints_value']['field'] = 'field_assignment_awardpoints_value';
  $handler->display->display_options['sorts']['field_assignment_awardpoints_value']['order'] = 'DESC';
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodetype_assignment' => 'nodetype_assignment',
  );
  /* Filtercriterium: Gebruiker: Huidige */
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
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Offset'),
    t('User entity referenced from field_assignment_participants'),
    t('Kapotte handler field_data_field_assignment_participants.field_assignment_participants'),
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
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
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
  /* Relatie: Inhoud: Auteur */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Veld: Inhoud: Titel */
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
  /* Veld: Inhoud: Datum van inzending */
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
  /* Veld: Inhoud: Type */
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
  /* Veld: Inhoud: Heeft nieuwe inhoud */
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
  /* Veld: Inhoud: Nieuwe reacties */
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
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Gebruiker: Huidige */
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
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Offset'),
    t('auteur'),
    t('Titel'),
    t('Datum van inzending'),
    t('Type'),
    t('.'),
    t(','),
    t('Page'),
  );
  $export['content_of_current_user'] = $view;

  $view = new view;
  $view->name = 'event_content_type_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Event content type map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'event_formatter_map';
  /* Veld: Inhoud: Titel */
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
  /* Sorteercriterium: Inhoud: Datum van inzending */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'event-content-type-map';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['event_content_type_map'] = array(
    t('Master'),
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Page'),
    t('Block'),
  );
  $export['event_content_type_map'] = $view;

  $view = new view;
  $view->name = 'event_map_overlay';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'event map overlay';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'field_event_location',
    'wkt' => 'field_event_location',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => '',
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Veld: Inhoud: Titel */
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
  /* Veld: Inhoud: Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_event_location']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_event_location']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_event_location']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_event_location']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_event_location']['element_type'] = '0';
  $handler->display->display_options['fields']['field_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_location']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_event_location']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_event_location']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_event_location']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_event_location']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_event_location']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_event_location']['settings'] = array(
    'data' => 'full',
  );
  $handler->display->display_options['fields']['field_event_location']['field_api_classes'] = 1;
  /* Sorteercriterium: Inhoud: Datum van inzending */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextuele filter: Inhoud: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = '$node = menu_get_object(\'node\');
if(isset($node))
  return $node->nid;
else return 0;';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodetype_event' => 'nodetype_event',
  );

  /* Display: OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'OpenLayers Data Overlay', 'openlayers_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $translatables['event_map_overlay'] = array(
    t('Master'),
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Offset'),
    t('Alle'),
    t('OpenLayers Data Overlay'),
  );
  $export['event_map_overlay'] = $view;

  $view = new view;
  $view->name = 'leader';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Leaderboard';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['hide_attachment_summary'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relatie: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_team_target_id']['id'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['table'] = 'field_data_field_user_team';
  $handler->display->display_options['relationships']['field_user_team_target_id']['field'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['required'] = 0;
  /* Relatie: User relationships: RTID */
  $handler->display->display_options['relationships']['rtid']['id'] = 'rtid';
  $handler->display->display_options['relationships']['rtid']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['rtid']['field'] = 'rtid';
  $handler->display->display_options['relationships']['rtid']['required'] = 0;
  /* Veld: Gebruiker: Afbeelding */
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
  /* Veld: Gebruiker: Naam */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Gebruikersnaam';
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
  /* Veld: Gebruiker: First name */
  $handler->display->display_options['fields']['field_user_firstname']['id'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['table'] = 'field_data_field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['field'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['label'] = 'Naam';
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
  /* Veld: Gebruiker: Surname */
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
  /* Veld: Userpoints: Current points in category */
  $handler->display->display_options['fields']['points']['id'] = 'points';
  $handler->display->display_options['fields']['points']['table'] = 'userpoints';
  $handler->display->display_options['fields']['points']['field'] = 'points';
  $handler->display->display_options['fields']['points']['label'] = 'Punten';
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
  /* Sorteercriterium: Gebruiker: Naam */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Contextuele filter: Inhoud: Titel */
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
  /* Filtercriterium: Gebruiker: Actief */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Userpoints: Points category */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'userpoints';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    4 => '4',
  );

  /* Display: Leaderboard */
  $handler = $view->new_display('page', 'Leaderboard', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'color.[field_team_colour]';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_team_colour' => 'field_team_colour',
    'php' => 'php',
    'field_user_firstname' => 'field_user_firstname',
    'field_user_surname' => 'field_user_firstname',
    'field_user_team' => 'field_user_team',
    'points_1' => 'points_1',
    'name' => 'name',
    'is_oneway' => 'is_oneway',
    'uid' => 'uid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_team_colour' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_firstname' => array(
      'sortable' => 0,
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
    'field_user_team' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'points_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
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
    'is_oneway' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 0;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Veld: Inhoud: Team colour */
  $handler->display->display_options['fields']['field_team_colour']['id'] = 'field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['table'] = 'field_data_field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['field'] = 'field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['relationship'] = 'field_user_team_target_id';
  $handler->display->display_options['fields']['field_team_colour']['label'] = '';
  $handler->display->display_options['fields']['field_team_colour']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_colour']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['element_type'] = '0';
  $handler->display->display_options['fields']['field_team_colour']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_colour']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_team_colour']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['field_api_classes'] = 1;
  /* Veld: Global: PHP */
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
  $handler->display->display_options['fields']['php']['use_php_setup'] = 1;
  $handler->display->display_options['fields']['php']['php_setup'] = '$static->fieldCounter = 0;';
  $handler->display->display_options['fields']['php']['php_value'] = '$static->fieldCounter = $static->fieldCounter+1;
//rewrite nr format : 1 becomes 001
$reformattedNr = $static->fieldCounter;
$reformattedNr = $reformattedNr +1000;
$reformattedNr = substr($reformattedNr,1,strlen($reformattedNr));
return $reformattedNr;
';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Veld: Gebruiker: First name */
  $handler->display->display_options['fields']['field_user_firstname']['id'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['table'] = 'field_data_field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['field'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['label'] = '';
  $handler->display->display_options['fields']['field_user_firstname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['path'] = '$user->uid';
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
  $handler->display->display_options['fields']['field_user_firstname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_firstname']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['field_api_classes'] = 1;
  /* Veld: Gebruiker: Surname */
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
  $handler->display->display_options['fields']['field_user_surname']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_surname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_surname']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_surname']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['field_api_classes'] = 1;
  /* Veld: Gebruiker: Team */
  $handler->display->display_options['fields']['field_user_team']['id'] = 'field_user_team';
  $handler->display->display_options['fields']['field_user_team']['table'] = 'field_data_field_user_team';
  $handler->display->display_options['fields']['field_user_team']['field'] = 'field_user_team';
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
  $handler->display->display_options['fields']['field_user_team']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_team']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_user_team']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_team']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_team']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_team']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_user_team']['field_api_classes'] = 0;
  /* Veld: Userpoints: Current points in category */
  $handler->display->display_options['fields']['points_1']['id'] = 'points_1';
  $handler->display->display_options['fields']['points_1']['table'] = 'userpoints';
  $handler->display->display_options['fields']['points_1']['field'] = 'points';
  $handler->display->display_options['fields']['points_1']['label'] = '';
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
  $handler->display->display_options['fields']['points_1']['element_type'] = 'div';
  $handler->display->display_options['fields']['points_1']['element_class'] = 'points';
  $handler->display->display_options['fields']['points_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['points_1']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['points_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['points_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['points_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['points_1']['format_plural'] = 0;
  $handler->display->display_options['fields']['points_1']['suffix'] = ' punten';
  /* Veld: Gebruiker: Naam */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
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
  $handler->display->display_options['fields']['name']['element_type'] = '0';
  $handler->display->display_options['fields']['name']['element_class'] = 'name';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 0;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Veld: Gebruiker: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uid']['element_type'] = '0';
  $handler->display->display_options['fields']['uid']['element_class'] = 'uid';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['uid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uid']['link_to_user'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sorteercriterium: Userpoints: Current points in category */
  $handler->display->display_options['sorts']['points']['id'] = 'points';
  $handler->display->display_options['sorts']['points']['table'] = 'userpoints';
  $handler->display->display_options['sorts']['points']['field'] = 'points';
  $handler->display->display_options['sorts']['points']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtercriterium: Gebruiker: Actief */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Userpoints: Points category */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'userpoints';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    4 => '4',
  );
  /* Filtercriterium: Global: PHP */
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
          //set a variable for later use in the theme
          variable_set(\'userLeaderboardPosition\',$i);
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
  $translatables['leader'] = array(
    t('Master'),
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Offset'),
    t('Inhoud entity referenced from field_user_team'),
    t('rtid'),
    t('Gebruikersnaam'),
    t('Naam'),
    t('Punten'),
    t('.'),
    t(','),
    t('Alle'),
    t('Leaderboard'),
    t('$user->uid'),
    t(' punten'),
  );
  $export['leader'] = $view;

  $view = new view;
  $view->name = 'players_by_team';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Players by team';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Actieve leden';
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relatie: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_team_target_id']['id'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['table'] = 'field_data_field_user_team';
  $handler->display->display_options['relationships']['field_user_team_target_id']['field'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['label'] = 'Content entity referenced from field_user_team';
  $handler->display->display_options['relationships']['field_user_team_target_id']['required'] = 0;
  /* Veld: Gebruiker: Naam */
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
  /* Veld: Gebruiker: Team */
  $handler->display->display_options['fields']['field_user_team']['id'] = 'field_user_team';
  $handler->display->display_options['fields']['field_user_team']['table'] = 'field_data_field_user_team';
  $handler->display->display_options['fields']['field_user_team']['field'] = 'field_user_team';
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
  /* Sorteercriterium: Gebruiker: Aanmaakdatum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextuele filter: Inhoud: Titel */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['relationship'] = 'field_user_team_target_id';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['glossary'] = 0;
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  $handler->display->display_options['arguments']['title']['transform_dash'] = 0;
  $handler->display->display_options['arguments']['title']['break_phrase'] = 0;
  /* Filtercriterium: Gebruiker: Actief */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'players-by-team';
  $translatables['players_by_team'] = array(
    t('Master'),
    t('Actieve leden'),
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Offset'),
    t('Content entity referenced from field_user_team'),
    t('Alle'),
    t('Page'),
  );
  $export['players_by_team'] = $view;

  $view = new view;
  $view->name = 'players_no_checkin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Players no checkin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Players you haven\'t checked in with before';
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '5';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Veld: Gebruiker: Naam */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
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
  /* Sorteercriterium: Gebruiker: Naam */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Contextuele filter: User relationships: Requester user */
  $handler->display->display_options['arguments']['requester_id']['id'] = 'requester_id';
  $handler->display->display_options['arguments']['requester_id']['table'] = 'user_relationships';
  $handler->display->display_options['arguments']['requester_id']['field'] = 'requester_id';
  $handler->display->display_options['arguments']['requester_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['requester_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['requester_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['requester_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['requester_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['requester_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['requester_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['requester_id']['not'] = 1;
  /* Contextuele filter: User relationships: Requestee user */
  $handler->display->display_options['arguments']['requestee_id']['id'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['table'] = 'user_relationships';
  $handler->display->display_options['arguments']['requestee_id']['field'] = 'requestee_id';
  $handler->display->display_options['arguments']['requestee_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['requestee_id']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['requestee_id']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['requestee_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['requestee_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['requestee_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['requestee_id']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['requestee_id']['not'] = 1;
  /* Filtercriterium: Gebruiker: Actief */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'players-no-checkin';

  /* Display: Spike */
  $handler = $view->new_display('page', 'Spike', 'page_1');
  $handler->display->display_options['path'] = 'players_no_checkin_spike';
  $translatables['players_no_checkin'] = array(
    t('Master'),
    t('Players you haven\'t checked in with before'),
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Offset'),
    t('Alle'),
    t('Page'),
    t('Spike'),
  );
  $export['players_no_checkin'] = $view;

  $view = new view;
  $view->name = 'team_overview';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Team_overview';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Relatie: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_campaignteam_team_target_id']['id'] = 'field_campaignteam_team_target_id';
  $handler->display->display_options['relationships']['field_campaignteam_team_target_id']['table'] = 'field_data_field_campaignteam_team';
  $handler->display->display_options['relationships']['field_campaignteam_team_target_id']['field'] = 'field_campaignteam_team_target_id';
  $handler->display->display_options['relationships']['field_campaignteam_team_target_id']['label'] = 'Inhoud entity referenced from field_campaignteam_team';
  $handler->display->display_options['relationships']['field_campaignteam_team_target_id']['required'] = 0;
  /* Relatie: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_campaignteam_campaign_target_id']['id'] = 'field_campaignteam_campaign_target_id';
  $handler->display->display_options['relationships']['field_campaignteam_campaign_target_id']['table'] = 'field_data_field_campaignteam_campaign';
  $handler->display->display_options['relationships']['field_campaignteam_campaign_target_id']['field'] = 'field_campaignteam_campaign_target_id';
  $handler->display->display_options['relationships']['field_campaignteam_campaign_target_id']['label'] = 'Inhoud entity referenced from field_campaignteam_campaign';
  $handler->display->display_options['relationships']['field_campaignteam_campaign_target_id']['required'] = 0;
  /* Veld: Inhoud: Image */
  $handler->display->display_options['fields']['field_team_image']['id'] = 'field_team_image';
  $handler->display->display_options['fields']['field_team_image']['table'] = 'field_data_field_team_image';
  $handler->display->display_options['fields']['field_team_image']['field'] = 'field_team_image';
  $handler->display->display_options['fields']['field_team_image']['label'] = '';
  $handler->display->display_options['fields']['field_team_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_team_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_team_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_team_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_team_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_team_image']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_team_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_team_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_team_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_team_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_team_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_team_image']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_team_image']['field_api_classes'] = 1;
  /* Veld: Inhoud: Titel */
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
  /* Veld: Inhoud: Team colour */
  $handler->display->display_options['fields']['field_team_colour']['id'] = 'field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['table'] = 'field_data_field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['field'] = 'field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['label'] = '';
  $handler->display->display_options['fields']['field_team_colour']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_colour']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_colour']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['field_api_classes'] = 0;
  /* Veld: Global: Aangepaste tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href=\'team/players/[title] \'>Bekijk actieve leden</a>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'color-[field_team_colour] ';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Veld: Inhoud: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['field_api_classes'] = 1;
  /* Veld: Inhoud: Total points */
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['id'] = 'field_campaignteam_totalpoints';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['table'] = 'field_data_field_campaignteam_totalpoints';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['field'] = 'field_campaignteam_totalpoints';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['label'] = '';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['element_type'] = '0';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['field_api_classes'] = 1;
  /* Veld: Content revision: Titel */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_campaignteam_campaign_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Titel';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 0;
  $handler->display->display_options['fields']['title_1']['link_to_node_revision'] = 0;
  /* Sorteercriterium: Inhoud: Datum van inzending */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodetype_campaign_team' => 'nodetype_campaign_team',
    'nodetype_team' => 'nodetype_team',
  );

  /* Display: Extended team view */
  $handler = $view->new_display('page', 'Extended team view', 'page');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodetype_team' => 'nodetype_team',
  );
  $handler->display->display_options['path'] = 'team';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'team-overview';

  /* Display: Extended team view with score */
  $handler = $view->new_display('page', 'Extended team view with score', 'page_3');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Veld: Inhoud: Image */
  $handler->display->display_options['fields']['field_team_image']['id'] = 'field_team_image';
  $handler->display->display_options['fields']['field_team_image']['table'] = 'field_data_field_team_image';
  $handler->display->display_options['fields']['field_team_image']['field'] = 'field_team_image';
  $handler->display->display_options['fields']['field_team_image']['relationship'] = 'field_campaignteam_team_target_id';
  $handler->display->display_options['fields']['field_team_image']['label'] = '';
  $handler->display->display_options['fields']['field_team_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_team_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_team_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_team_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_team_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_team_image']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_team_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_team_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_team_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_team_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_team_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_team_image']['field_api_classes'] = 1;
  /* Veld: Inhoud: Titel */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_campaignteam_team_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 0;
  /* Veld: Inhoud: Total points */
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['id'] = 'field_campaignteam_totalpoints';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['table'] = 'field_data_field_campaignteam_totalpoints';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['field'] = 'field_campaignteam_totalpoints';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['label'] = '';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['text'] = '[field_campaignteam_totalpoints] punten';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['element_class'] = 'points';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['field_api_classes'] = 0;
  /* Veld: Global: Aangepaste tekst */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href=\'team/players/[title_1] \'>Bekijk actieve leden</a>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'color-[field_team_colour] ';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  /* Veld: Inhoud: Campaign */
  $handler->display->display_options['fields']['field_campaignteam_campaign']['id'] = 'field_campaignteam_campaign';
  $handler->display->display_options['fields']['field_campaignteam_campaign']['table'] = 'field_data_field_campaignteam_campaign';
  $handler->display->display_options['fields']['field_campaignteam_campaign']['field'] = 'field_campaignteam_campaign';
  $handler->display->display_options['fields']['field_campaignteam_campaign']['label'] = '';
  $handler->display->display_options['fields']['field_campaignteam_campaign']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['element_type'] = '0';
  $handler->display->display_options['fields']['field_campaignteam_campaign']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_campaignteam_campaign']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_campaignteam_campaign']['field_api_classes'] = 1;
  /* Veld: Inhoud: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_campaignteam_campaign_target_id';
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
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Veld: Inhoud: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_campaignteam_team_target_id';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 1;
  /* Veld: Inhoud: Team colour */
  $handler->display->display_options['fields']['field_team_colour']['id'] = 'field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['table'] = 'field_data_field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['field'] = 'field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['relationship'] = 'field_campaignteam_team_target_id';
  $handler->display->display_options['fields']['field_team_colour']['label'] = '';
  $handler->display->display_options['fields']['field_team_colour']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_colour']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['element_type'] = '0';
  $handler->display->display_options['fields']['field_team_colour']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_colour']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_team_colour']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['field_api_classes'] = 1;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodetype_campaign_team' => 'nodetype_campaign_team',
  );
  /* Filtercriterium: Campaign is current campaign */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['ui_name'] = 'Campaign is current campaign';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = '//Filters the Campaign team nodes that correspond to the current campaign
module_load_include( \'api.campaign.inc\', \'scoga\', \'api/scoga\' );
if ($row->nid == scoga_get_campaign_nid_for_time())
return false;
else 
return true;';
  $handler->display->display_options['path'] = 'team3';

  /* Display: Team view with only score */
  $handler = $view->new_display('page', 'Team view with only score', 'page_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Veld: Inhoud: Image */
  $handler->display->display_options['fields']['field_team_image']['id'] = 'field_team_image';
  $handler->display->display_options['fields']['field_team_image']['table'] = 'field_data_field_team_image';
  $handler->display->display_options['fields']['field_team_image']['field'] = 'field_team_image';
  $handler->display->display_options['fields']['field_team_image']['relationship'] = 'field_campaignteam_team_target_id';
  $handler->display->display_options['fields']['field_team_image']['label'] = '';
  $handler->display->display_options['fields']['field_team_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_team_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_team_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_team_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_team_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_team_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_team_image']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_team_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_team_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_team_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_team_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_team_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_team_image']['field_api_classes'] = 1;
  /* Veld: Inhoud: Titel */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_campaignteam_team_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = 0;
  /* Veld: Inhoud: Total points */
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['id'] = 'field_campaignteam_totalpoints';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['table'] = 'field_data_field_campaignteam_totalpoints';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['field'] = 'field_campaignteam_totalpoints';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['label'] = '';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['text'] = '[field_campaignteam_totalpoints] punten';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['element_class'] = 'points';
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_campaignteam_totalpoints']['field_api_classes'] = 0;
  /* Veld: Inhoud: Campaign */
  $handler->display->display_options['fields']['field_campaignteam_campaign']['id'] = 'field_campaignteam_campaign';
  $handler->display->display_options['fields']['field_campaignteam_campaign']['table'] = 'field_data_field_campaignteam_campaign';
  $handler->display->display_options['fields']['field_campaignteam_campaign']['field'] = 'field_campaignteam_campaign';
  $handler->display->display_options['fields']['field_campaignteam_campaign']['label'] = '';
  $handler->display->display_options['fields']['field_campaignteam_campaign']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['element_type'] = '0';
  $handler->display->display_options['fields']['field_campaignteam_campaign']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_campaignteam_campaign']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_campaignteam_campaign']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_campaignteam_campaign']['field_api_classes'] = 1;
  /* Veld: Inhoud: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_campaignteam_campaign_target_id';
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
  $handler->display->display_options['fields']['nid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Veld: Inhoud: Team colour */
  $handler->display->display_options['fields']['field_team_colour']['id'] = 'field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['table'] = 'field_data_field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['field'] = 'field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['relationship'] = 'field_campaignteam_team_target_id';
  $handler->display->display_options['fields']['field_team_colour']['label'] = '';
  $handler->display->display_options['fields']['field_team_colour']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_colour']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['element_type'] = '0';
  $handler->display->display_options['fields']['field_team_colour']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_colour']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_team_colour']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['field_api_classes'] = 1;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodetype_campaign_team' => 'nodetype_campaign_team',
  );
  /* Filtercriterium: Campaign is current campaign */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['ui_name'] = 'Campaign is current campaign';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 0;
  $handler->display->display_options['filters']['php']['php_filter'] = '//Filters the Campaign team nodes that correspond to the current campaign
module_load_include( \'api.campaign.inc\', \'scoga\', \'api/scoga\' );
if ($row->nid == scoga_get_campaign_nid_for_time())
return false;
else 
return true;';
  $handler->display->display_options['path'] = 'team_score';
  $translatables['team_overview'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Inhoud entity referenced from field_campaignteam_team'),
    t('Inhoud entity referenced from field_campaignteam_campaign'),
    t('<a href=\'team/players/[title] \'>Bekijk actieve leden</a>'),
    t('Titel'),
    t('Extended team view'),
    t('Page'),
    t('Extended team view with score'),
    t('[field_campaignteam_totalpoints] punten'),
    t('<a href=\'team/players/[title_1] \'>Bekijk actieve leden</a>'),
    t('Nid'),
    t('Team view with only score'),
  );
  $export['team_overview'] = $view;

  $view = new view;
  $view->name = 'view_front_page';
  $view->description = 'Emulates the default Drupal front page; you may set the default home page path to this view to make it your front page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Front page';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Veld: Inhoud: Titel */
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
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
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
  /* Veld: Inhoud: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['body']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 1;
  /* Sorteercriterium: Inhoud: Vastgeplakt (sticky) */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sorteercriterium: Inhoud: Datum van inzending */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtercriterium: Inhoud: Aangeraden op de voorpagina */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 0;
  $handler->display->display_options['filters']['promote']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'page' => 'page',
    'poll' => 'poll',
  );
  /* Filtercriterium: Inhoud: Body (body) */
  $handler->display->display_options['filters']['body_value']['id'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['table'] = 'field_data_body';
  $handler->display->display_options['filters']['body_value']['field'] = 'body_value';
  /* Filtercriterium: Inhoud: Titel */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'page' => 'page',
  );
  /* Filtercriterium: Inhoud: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['value']['value'] = '3';
  $handler->display->display_options['path'] = 'frontpage';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Voorpagina-feed';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'rss.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $handler->display->display_options['sitename_title'] = '1';
  $translatables['view_front_page'] = array(
    t('Master'),
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Offset'),
    t('Page'),
    t('Feed'),
    t('Voorpagina-feed'),
  );
  $export['view_front_page'] = $view;

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
  $handler->display->display_options['title'] = '%1';
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relatie: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_team_target_id']['id'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['table'] = 'field_data_field_user_team';
  $handler->display->display_options['relationships']['field_user_team_target_id']['field'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['required'] = 0;
  /* Relatie: User relationships: RTID */
  $handler->display->display_options['relationships']['rtid']['id'] = 'rtid';
  $handler->display->display_options['relationships']['rtid']['table'] = 'user_relationships';
  $handler->display->display_options['relationships']['rtid']['field'] = 'rtid';
  $handler->display->display_options['relationships']['rtid']['required'] = 0;
  /* Veld: Gebruiker: Afbeelding */
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
  /* Veld: Gebruiker: Naam */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Gebruikersnaam';
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
  /* Veld: Gebruiker: First name */
  $handler->display->display_options['fields']['field_user_firstname']['id'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['table'] = 'field_data_field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['field'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['label'] = 'Naam';
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
  /* Veld: Gebruiker: Surname */
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
  /* Veld: Userpoints: Current points in category */
  $handler->display->display_options['fields']['points']['id'] = 'points';
  $handler->display->display_options['fields']['points']['table'] = 'userpoints';
  $handler->display->display_options['fields']['points']['field'] = 'points';
  $handler->display->display_options['fields']['points']['label'] = 'Punten';
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
  /* Sorteercriterium: Gebruiker: Naam */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Contextuele filter: Inhoud: Titel */
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
  /* Filtercriterium: Gebruiker: Actief */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Userpoints: Points category */
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
  /* Veld: Gebruiker: Afbeelding */
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
  /* Veld: Gebruiker: Naam */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Gebruikersnaam';
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
  /* Veld: Gebruiker: First name */
  $handler->display->display_options['fields']['field_user_firstname']['id'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['table'] = 'field_data_field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['field'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['label'] = 'Naam';
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
  /* Veld: Gebruiker: Surname */
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
  /* Contextuele filter: Gebruiker: Team (field_user_team) */
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
  /* Filtercriterium: Gebruiker: Actief */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Gebruiker: Huidige */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '0';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filtercriterium: Gebruiker: Laatste login */
  $handler->display->display_options['filters']['login']['id'] = 'login';
  $handler->display->display_options['filters']['login']['table'] = 'users';
  $handler->display->display_options['filters']['login']['field'] = 'login';
  $handler->display->display_options['filters']['login']['operator'] = '>=';
  $handler->display->display_options['filters']['login']['value']['value'] = '2012-05-01';
  $handler->display->display_options['path'] = 'user/teammembers';

  /* Display: Players by team */
  $handler = $view->new_display('page', 'Players by team', 'page_1');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'color.[field_team_colour]';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_team_colour' => 'field_team_colour',
    'picture' => 'picture',
    'name' => 'name',
    'field_user_firstname' => 'field_user_firstname',
    'field_user_surname' => 'field_user_surname',
    'points' => 'points',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_team_colour' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'picture' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_firstname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
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
      'sortable' => 0,
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
  /* Veld: Inhoud: Team colour */
  $handler->display->display_options['fields']['field_team_colour']['id'] = 'field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['table'] = 'field_data_field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['field'] = 'field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['relationship'] = 'field_user_team_target_id';
  $handler->display->display_options['fields']['field_team_colour']['label'] = '';
  $handler->display->display_options['fields']['field_team_colour']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_colour']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['element_type'] = '0';
  $handler->display->display_options['fields']['field_team_colour']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_colour']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_team_colour']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['field_api_classes'] = 1;
  /* Veld: Gebruiker: Afbeelding */
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
  /* Veld: Gebruiker: Naam */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
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
  /* Veld: Gebruiker: First name */
  $handler->display->display_options['fields']['field_user_firstname']['id'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['table'] = 'field_data_field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['field'] = 'field_user_firstname';
  $handler->display->display_options['fields']['field_user_firstname']['label'] = '';
  $handler->display->display_options['fields']['field_user_firstname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['alter']['path'] = 'users/[name]';
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
  $handler->display->display_options['fields']['field_user_firstname']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_firstname']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_firstname']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_firstname']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_user_firstname']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_user_firstname']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['field_user_firstname']['field_api_classes'] = 1;
  /* Field: Gebruiker: Surname */
  $handler->display->display_options['fields']['field_user_surname']['id'] = 'field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['table'] = 'field_data_field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['field'] = 'field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['label'] = '';
  $handler->display->display_options['fields']['field_user_surname']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_user_surname']['alter']['make_link'] = 1;
  $handler->display->display_options['fields']['field_user_surname']['alter']['path'] = '/users/[name]';
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
  /* Veld: Userpoints: Current points in category */
  $handler->display->display_options['fields']['points']['id'] = 'points';
  $handler->display->display_options['fields']['points']['table'] = 'userpoints';
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
  $handler->display->display_options['fields']['points']['separator'] = '.';
  $handler->display->display_options['fields']['points']['format_plural'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtercriterium: Gebruiker: Actief */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Userpoints: Points category */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'userpoints';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['path'] = 'team/players/%';

  /* Display: Entity Reference View Widget */
  $handler = $view->new_display('entityreference_view_widget', 'Entity Reference View Widget', 'entityreference_view_widget_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'entityreference_view_widget';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextuele filter: Inhoud: Nid */
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
    t('%1'),
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Offset'),
    t('Inhoud entity referenced from field_user_team'),
    t('rtid'),
    t('Gebruikersnaam'),
    t('Naam'),
    t('Punten'),
    t('.'),
    t(','),
    t('Alle'),
    t('Team members of current user'),
    t('Players by team'),
    t('users/[name]'),
    t('/users/[name]'),
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
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
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
  /* Relatie: Userpoints Transactions: Gebruiker */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'userpoints_txn';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Relatie: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_team_target_id']['id'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['table'] = 'field_data_field_user_team';
  $handler->display->display_options['relationships']['field_user_team_target_id']['field'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['field_user_team_target_id']['required'] = 0;
  /* Veld: Userpoints Transactions: Punten */
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
  /* Veld: Gebruiker: Naam */
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
  /* Veld: Userpoints Transactions: Tijdstip */
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
  /* Sorteercriterium: Userpoints Transactions: Tijdstip */
  $handler->display->display_options['sorts']['time_stamp']['id'] = 'time_stamp';
  $handler->display->display_options['sorts']['time_stamp']['table'] = 'userpoints_txn';
  $handler->display->display_options['sorts']['time_stamp']['field'] = 'time_stamp';
  $handler->display->display_options['sorts']['time_stamp']['order'] = 'DESC';
  /* Filtercriterium: Global: PHP */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 1;
  $handler->display->display_options['filters']['php']['php_setup'] = 'module_load_include( \'api.inc\', \'scoga\', \'api/scoga\' );
$static->current_userpoints_category_tid = scoga_get_current_userpoints_category_tid();
//dsm($static->current_userpoints_category_tid);';
  $handler->display->display_options['filters']['php']['php_filter'] = '//Filters the Campaign team nodes that correspond to the current campaign
dsm($static);
dsm($row->tid);
/*if ($row->nid == scoga_get_campaign_nid_for_time())
return false;
else 
return true;*/';

  /* Display: Recent points block */
  $handler = $view->new_display('block', 'Recent points block', 'block');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Points page */
  $handler = $view->new_display('page_with_page_title', 'Points page', 'page_with_page_title_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Punten';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
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
  /* Veld: Userpoints Transactions: Punten */
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
  /* Veld: Gebruiker: Naam */
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
  /* Veld: Userpoints Transactions: Tijdstip */
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
  /* Veld: Userpoints Transactions: Beschrijving */
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
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'points';

  /* Display: Points in current campaign page */
  $handler = $view->new_display('page_with_page_title', 'Points in current campaign page', 'page_with_page_title_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['row_class'] = 'color[field_team_colour] ';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_team_colour' => 'field_team_colour',
    'points' => 'points',
    'name' => 'name',
    'time_stamp' => 'time_stamp',
    'description' => 'description',
    'tid_1' => 'tid_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_team_colour' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
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
    'tid_1' => array(
      'sortable' => 0,
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
  /* Veld: Inhoud: Team colour */
  $handler->display->display_options['fields']['field_team_colour']['id'] = 'field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['table'] = 'field_data_field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['field'] = 'field_team_colour';
  $handler->display->display_options['fields']['field_team_colour']['relationship'] = 'field_user_team_target_id';
  $handler->display->display_options['fields']['field_team_colour']['label'] = '';
  $handler->display->display_options['fields']['field_team_colour']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_team_colour']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['element_type'] = '0';
  $handler->display->display_options['fields']['field_team_colour']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_team_colour']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_team_colour']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_team_colour']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_team_colour']['field_api_classes'] = 1;
  /* Veld: Userpoints Transactions: Punten */
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
  /* Veld: Gebruiker: Naam */
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
  /* Veld: Userpoints Transactions: Beschrijving */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'userpoints_txn';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
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
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['description']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['description']['hide_empty'] = 0;
  $handler->display->display_options['fields']['description']['empty_zero'] = 0;
  $handler->display->display_options['fields']['description']['hide_alter_empty'] = 1;
  /* Veld: Taxonomie term: Term-ID */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['label'] = '';
  $handler->display->display_options['fields']['tid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['tid_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['tid_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['tid_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['tid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['tid_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['tid_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['tid_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['tid_1']['format_plural'] = 0;
  /* Veld: Userpoints Transactions: Tijdstip */
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
  $handler->display->display_options['fields']['time_stamp']['date_format'] = 'short';
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtercriterium: transaction belongs to current userpoints category */
  $handler->display->display_options['filters']['php']['id'] = 'php';
  $handler->display->display_options['filters']['php']['table'] = 'views';
  $handler->display->display_options['filters']['php']['field'] = 'php';
  $handler->display->display_options['filters']['php']['ui_name'] = 'transaction belongs to current userpoints category';
  $handler->display->display_options['filters']['php']['use_php_setup'] = 1;
  $handler->display->display_options['filters']['php']['php_setup'] = 'module_load_include( \'api.inc\', \'scoga\', \'api/scoga\' );
$static->current_userpoints_category_tid = scoga_get_current_userpoints_category_tid();';
  $handler->display->display_options['filters']['php']['php_filter'] = '//Filters the Campaign team nodes that correspond to the current campaign
//dsm($static->current_userpoints_category_tid);
var_dump($row);
if ($static->current_userpoints_category_tid == $row->tid_1)
return false;
else
return true;

';
  $handler->display->display_options['path'] = 'points_in_campaign';
  $translatables['view_transactions'] = array(
    t('Master'),
    t('Recent points'),
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Gebruikers'),
    t('Inhoud entity referenced from field_user_team'),
    t('.'),
    t(','),
    t('Recent points block'),
    t('Points page'),
    t('Punten'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Offset'),
    t('Beschrijving'),
    t('Points in current campaign page'),
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
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relatie: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_team_target_id']['id'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['table'] = 'field_data_field_user_team';
  $handler->display->display_options['relationships']['field_user_team_target_id']['field'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['required'] = 0;
  /* Veld: Gebruiker: Naam */
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
  /* Veld: Gebruiker: First name */
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
  /* Veld: Gebruiker: Afbeelding */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  /* Veld: Gebruiker: Surname */
  $handler->display->display_options['fields']['field_user_surname']['id'] = 'field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['table'] = 'field_data_field_user_surname';
  $handler->display->display_options['fields']['field_user_surname']['field'] = 'field_user_surname';
  /* Sorteercriterium: Gebruiker: Aanmaakdatum */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextuele filter: Gebruiker: Uid */
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
  /* Filtercriterium: Gebruiker: Actief */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Titel */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_user_team_target_id';
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Titel';
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
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'entityreference_view_widget';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtercriterium: Gebruiker: Actief */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Titel */
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
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Offset'),
    t('Inhoud entity referenced from field_user_team'),
    t('First name'),
    t('Afbeelding'),
    t('Surname'),
    t('Alle'),
    t('Titel'),
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
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'viewmode_revealing';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Relatie: Inhoud: Auteur */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
  /* Relatie: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_user_team_target_id']['id'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['table'] = 'field_data_field_user_team';
  $handler->display->display_options['relationships']['field_user_team_target_id']['field'] = 'field_user_team_target_id';
  $handler->display->display_options['relationships']['field_user_team_target_id']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['field_user_team_target_id']['required'] = 0;
  /* Veld: Inhoud: Titel */
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
  /* Veld: Gebruiker: Naam */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Gebruikersnaam';
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
  /* Veld: Gebruiker: Afbeelding */
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
  /* Sorteercriterium: Inhoud: Datum van inzending */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Datum van inzending';
  $handler->display->display_options['sorts']['created']['granularity'] = 'minute';
  /* Sorteercriterium: Inhoud: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Titel';
  /* Sorteercriterium: Gebruiker: Naam */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'uid';
  $handler->display->display_options['sorts']['name']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['name']['expose']['label'] = 'Wisher';
  /* Contextuele filter: Inhoud: Titel */
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
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodetype_wished_item' => 'nodetype_wished_item',
  );
  /* Filtercriterium: Inhoud: State (field_wisheditem_state) */
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
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodetype_wished_item' => 'nodetype_wished_item',
  );
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filtercriterium: Inhoud: State (field_wisheditem_state) */
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
  /* Relatie: Inhoud: Auteur */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Veld: Inhoud: Titel */
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
  /* Veld: Inhoud: Datum van inzending */
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
  /* Veld: Inhoud: Reward */
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
  /* Contextuele filter: Inhoud: Author uid */
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
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodetype_wished_item' => 'nodetype_wished_item',
  );
  /* Filtercriterium: Inhoud: State (field_wisheditem_state) */
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
  /* Veld: Inhoud: Reward */
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
  /* Veld: Inhoud: Titel */
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
  /* Veld: Gebruiker: Naam */
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
  /* Veld: Inhoud: Datum van inzending */
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
  /* Sorteercriterium: Inhoud: Datum van inzending */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Datum van inzending';
  $handler->display->display_options['sorts']['created']['granularity'] = 'minute';
  /* Sorteercriterium: Inhoud: Titel */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Titel';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filtercriterium: Inhoud: Gepubliceerd */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filtercriterium: Inhoud: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'nodetype_wished_item' => 'nodetype_wished_item',
  );
  /* Filtercriterium: Inhoud: State (field_wisheditem_state) */
  $handler->display->display_options['filters']['field_wisheditem_state_value']['id'] = 'field_wisheditem_state_value';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['table'] = 'field_data_field_wisheditem_state';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['field'] = 'field_wisheditem_state_value';
  $handler->display->display_options['filters']['field_wisheditem_state_value']['value'] = array(
    'open' => 'open',
  );
  /* Filtercriterium: Inhoud: Titel */
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
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'entityreference_view_widget';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relatie: Inhoud: Auteur */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextuele filter: Inhoud: Author uid */
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
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Offset'),
    t('auteur'),
    t('Inhoud entity referenced from field_user_team'),
    t('Wished item'),
    t('Gebruikersnaam'),
    t('Datum van inzending'),
    t('Titel'),
    t('Wisher'),
    t('Alle'),
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
  $handler->display->display_options['use_more_text'] = 'meer';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Opnieuw instellen';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorteer op';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Oplopend';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Aflopend';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Items per pagina';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
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
  /* Veld: Inhoud: Titel */
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
  /* Veld: Inhoud: Gepubliceerd */
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
  /* Veld: Inhoud: Nieuwe reacties */
  $handler->display->display_options['fields']['new_comments']['id'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['table'] = 'node';
  $handler->display->display_options['fields']['new_comments']['field'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['label'] = 'Reacties';
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
  /* Sorteercriterium: Inhoud: Datum van inzending */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextuele filter: Inhoud: Author uid */
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
  /* Filtercriterium: Inhoud: Type */
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
    t('meer'),
    t('Toepassen'),
    t('Opnieuw instellen'),
    t('Sorteer op'),
    t('Oplopend'),
    t('Aflopend'),
    t('Items per pagina'),
    t('- Alle -'),
    t('Offset'),
    t('Titel'),
    t('Gepubliceerd'),
    t('Reacties'),
    t('.'),
    t(','),
    t('Alle'),
    t('Wishlist for current user'),
  );
  $export['view_wishlist_for_user'] = $view;

  return $export;
}
