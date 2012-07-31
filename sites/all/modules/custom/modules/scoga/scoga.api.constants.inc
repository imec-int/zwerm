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

    //--( SETTINGS )--//

    define( 'SCOGA_SETTING_CHECKIN_COOLDOWN',                   'scoga_settings_checkin_cooldown' );
    define( 'SCOGA_SETTING_COMBOCHECKIN_TIMEFRAME',             'scoga_settings_combocheckin_timeframe' );
    define( 'SCOGA_SETTING_DEFAULT_USERNAME',                   'scoga_settings_default_username' );
    define( 'SCOGA_SETTING_CURRENT_CAMPAIGN_NID',               'scoga_settings_current_campaign_nid' );
    define( 'SCOGA_SETTING_DETERMINECAMPAIGN_CRON_INTERVAL',    'scoga_settings_determine_campaign_cron_interval' );
    define( 'SCOGA_SETTING_DETERMINECAMPAIGN_NEXT_EXECUTION',   'scoga_settings_determine_campaign_next_execution' );
    define( 'SCOGA_SETTING_DEFAULT_CREDITS',                    'scoga_settings_default_credits' );
    define( 'SCOGA_SETTING_CURRENT_TEAM',                       'scoga_settings_current_team' );
    define( 'SCOGA_SETTING_NEXT_PLAYER_ID',                     'scoga_settings_next_player_id');
    define( 'SCOGA_SETTING_MAX_WISHITEM_CREDIT',                'scoga_setting_max_wishitem_credit' );

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
    define( 'SCOGA_PERM_REST_ACCESS_REGISTER_READER',   'access content' );
    define( 'SCOGA_PERM_REST_EXECUTE_REGISTER_READER',  'REST register rfid reader' );
    define( 'SCOGA_PERM_REST_ACCESS_REGISTER_CARD',     'access content' );
    define( 'SCOGA_PERM_REST_EXECUTE_REGISTER_CARD',    'REST register rfid card' );

    //--( VALUES )--//

    define( 'SCOGA_ADMIN_PAGE',             'admin/config/scoga' );
    define( 'SCOGA_CREDITS_UUID',           'f3538084-2198-5064-cd37-8b0b39ba32b4' );
    define( 'SCOGA_PLAYER_ROLE',            4 );
    define( 'SCOGA_CHECKINPARTNER_RTID',    1 );
    define( 'SCOGA_TIME_FORMAT',            'H:i:s d/m/Y' );


