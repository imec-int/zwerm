<?php

    //--( MACHINE NAMES )--//

    define( 'SCOGA_CAMPAIGN_NODETYPE',          'nodetype_campaign' );
    define( 'SCOGA_CAMPAIGNTEAM_NODETYPE',      'nodetype_campaign_team' );
    define( 'SCOGA_TEAM_NODETYPE',              'nodetype_team' );
    define( 'SCOGA_CHECKIN_NODETYPE',           'nodetype_checkin' );
    define( 'SCOGA_READER_NODETYPE',            'nodetype_rfid_reader' );
    define( 'SCOGA_POINTS_VOCAB',               'userpoints' );
    define( 'SCOGA_MESSAGES_NODETYPE',          'nodetype_logmessages' );
    define( 'SCOGA_WISHEDITEM_NODETYPE',        'nodetype_wished_item' );
    define( 'SCOGA_WISHFULFILLED_NODETYPE',     'nodetype_wish_fulfilled' );
    define( 'SCOGA_PAGE_NODETYPE',              'nodetype_service_page');
    define( 'SCOGA_ARTICLE_NODETYPE',           'article' );
    define( 'SCOGA_POLL_NODETYPE',              'poll' );
    define( 'SCOGA_EVENT_NODETYPE',             'nodetype_event' );

    //--( SETTINGS )--//

    define( 'SCOGA_SETTING_CHECKIN_COOLDOWN',                   'scoga_settings_checkin_cooldown' );
    define( 'SCOGA_SETTING_COMBOCHECKIN_TIMEFRAME',             'scoga_settings_combocheckin_timeframe' );
    define( 'SCOGA_SETTING_DEFAULT_USERNAME',                   'scoga_settings_default_username' );
    define( 'SCOGA_SETTING_DEFAULT_CREDITS',                    'scoga_settings_default_credits' );
    define( 'SCOGA_SETTING_DETERMINECAMPAIGN_CRON_INTERVAL',    'scoga_settings_determine_campaign_cron_interval' );
    define( 'SCOGA_SETTING_MAX_WISHITEM_CREDIT',                'scoga_setting_max_wishitem_credit' );
    define( 'SCOGA_SETTING_REWARD_ANSWER_POLL',                 'scoga_setting_reward_answer_poll' );
    define( 'SCOGA_SETTING_REWARD_RFID_CHECKIN',                 'scoga_setting_reward_rfid_checkin' );
    define( 'SCOGA_SETTING_REWARD_COMBO_CHECKIN',                 'scoga_setting_reward_combo_checkin' );
    define( 'SCOGA_SETTING_REWARD_COMPLETE_PROFILE',            'scoga_setting_reward_complete_profile' );

    define( 'SCOGA_SETTING_CURRENT_COMBOCHECKIN_RTID',          'scoga_setting_current_combocheckin_rtid' );
    define( 'SCOGA_SETTING_CHECKIN_EXPLANATION_NID',            'scoga_setting_checkin_explanation_nid' );
    define( 'SCOGA_SETTING_CREDITS_TID',                        'scoga_setting_credits_tid' );
    define( 'SCOGA_SETTING_SCORE_TID',                          'scoga_setting_score_tid' );
    define( 'SCOGA_SETTING_CURRENT_TEAM',                       'scoga_settings_current_team' );
    define( 'SCOGA_SETTING_NEXT_PLAYER_ID',                     'scoga_settings_next_player_id');
    define( 'SCOGA_SETTING_DETERMINECAMPAIGN_NEXT_EXECUTION',   'scoga_settings_determine_campaign_next_execution' );
    define( 'SCOGA_SETTING_CURRENT_CAMPAIGN_NID',               'scoga_settings_current_campaign_nid' );

    //--( PERMISSIONS )--//

    define( 'SCOGA_PERM_ADMINISTER_SETTINGS',           'scoga administer settings' );
    define( 'SCOGA_PERM_REST_ACCESS_CAMPAIGN_DATA',     'access content' );
    define( 'SCOGA_PERM_REST_ACCESS_TEAM_DATA',         'access content' );
    define( 'SCOGA_PERM_REST_ACCESS_PLAYER_DATA',       'access content' );
    define( 'SCOGA_PERM_REST_ACCESS_TRANSACTION_DATA',  'access content' );
    define( 'SCOGA_PERM_REST_ACCESS_OVERVIEW_DATA',     'access content' );
    define( 'SCOGA_PERM_REST_ACCESS_MESSAGES_DATA',     'access content' );
    define( 'SCOGA_PERM_REST_ACCESS_CREATE_CHECKIN',    'access content' );
    define( 'SCOGA_PERM_REST_EXECUTE_CREATE_CHECKIN',   'REST create checkin' );
    define( 'SCOGA_PERM_REST_ACCESS_READER_DATA',       'access content' );
    define( 'SCOGA_PERM_REST_ACCESS_REGISTER_READER',   'access content' );
    define( 'SCOGA_PERM_REST_EXECUTE_REGISTER_READER',  'REST register rfid reader' );
    define( 'SCOGA_PERM_REST_ACCESS_REGISTER_CARD',     'access content' );
    define( 'SCOGA_PERM_REST_EXECUTE_REGISTER_CARD',    'REST register rfid card' );
    define( 'SCOGA_PERM_REST_ACCESS_SYNC',              'access content' );
    define( 'SCOGA_PERM_REST_ACCESS_RELATIONSHIPS',     'access content' );
    define( 'SCOGA_PAGE_ACCESS_NOT_CHECKIN_PARTNER',    'access content' );
    define( 'SCOGA_PERM_PAGE_ACCESS_GET_POINTS',        'play game' );
    define( 'SCOGA_PERM_PAGE_ACCESS_NOT_CHECKIN_PARTNER', 'access content');
    define( 'SCOGA_PERM_REST_ACCESS_PAGES_DATA',        'access content' );
    define( 'SCOGA_PERM_REST_ACCESS_MAIL',              'access content' );
    define( 'SCOGA_PERM_REST_ACCESS_CONFIG',              'access content' );


//--( VALUES )--//

    define( 'SCOGA_ADMIN_PAGE',             'admin/config/scoga' );
    define( 'SCOGA_NOT_PARTNER_PAGE',             'not_partner' );
    define( 'SCOGA_GET_POINTS_PAGE', 'get_points');
    define( 'SCOGA_CREDITS_UUID',           'f3538084-2198-5064-cd37-8b0b39ba32b4' );
    define( 'SCOGA_PLAYER_ROLE',            4 );
    define( 'SCOGA_TIME_FORMAT',            'H:i:s d/m/Y' );
    define( 'SCOGA_VARIABLE_GROUP_NAME',    'scoga' );
    define( 'SCOGA_SALT',                   '97zw3rM&:*');
    define( 'FLASH_HTML_FORMAT',            'flash_html');
    define( 'SCOGA_NULL_CAMPAIGN_NID',      0 );

    //--( RESPONSE CODES )--//
    define( 'CODE_NO_CAMPAIGN',             1010 );
    define( 'CODE_CARD_NOT_REGISTERED',     1020 );
    define( 'CODE_NOT_ALLOWED',             1030 );
    define( 'CODE_INVALID_READER',          1040 );
    define( 'CODE_PLAYER_NEEDS_COOLDOWN',   1050 );
    define( 'CODE_CHECKIN_SUCCESS',         1060 );
    define( 'CODE_COMBO_SUCCESS',           1070 );
    define( 'CODE_READER_UNREGISTERED',     2010 );
    define( 'CODE_CARD_MULTIPLE',         2020 );
    define( 'CODE_CARD_REGISTRATION_SUCCESS', 2030 );






