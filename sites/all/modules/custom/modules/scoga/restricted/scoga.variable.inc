<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 01/08/12
 * Time: 11:42
 * To change this template use File | Settings | File Templates.
 */

    function scoga_handle_variable_group_info(){
        $groups = array();
        $groups[ SCOGA_VARIABLE_GROUP_NAME ] = array(
            'title'         => t( 'SCOGA settings' ),
            'description'   => t( 'Settings for SCOGA' ),
            'access'        => SCOGA_PERM_ADMINISTER_SETTINGS,
            'path'          => array( SCOGA_ADMIN_PAGE ),
        );
        return $groups;
    }

    function scoga_handle_variable_type_info(){
        $types = array();
        $types[ 'uint' ] = array(
          'title' => t('Unsigned integer'),
          'element' => array('#type' => 'textfield', '#size' => 15, '#maxlength' => 10),
          'token' => TRUE,
          'validate callback' => 'scoga_validate_uint',
        );

        return $types;
    }

    function scoga_handle_variable_info( $options ){

        $variables = array();

        //checkin cooldown
        $variables[ SCOGA_SETTING_CHECKIN_COOLDOWN ] = array(
            'group'         => SCOGA_VARIABLE_GROUP_NAME,
            'type'          => 'uint',
            'title'         => t( 'Cooldown for "checkin"' ),
            'description'   => t( 'Define cooldown period for "checkins",in seconds, 0 for disabled.' ),
            'default'       => 60,
            'required'      => TRUE,
        );

        //cmobocheckin timeframe
        $variables[ SCOGA_SETTING_COMBOCHECKIN_TIMEFRAME ] = array(
            'group'         => SCOGA_VARIABLE_GROUP_NAME,
            'type'          => 'uint',
            'title'         => t( 'Timeframe for combo checkins' ),
            'description'   => t( 'Define timeframe for combo checkins,in seconds, 0 for unlimited.' ),
            'default'       => 60,
            'required'      => TRUE,
        );

        //default username
        $variables[ SCOGA_SETTING_DEFAULT_USERNAME ] = array(
            'group'             => SCOGA_VARIABLE_GROUP_NAME,
            'type'              => 'string',
            'title'             => t( 'Default username base' ),
            'description'       => t( 'When creating new users through the services this value will be used in combination with a unique identifier to create the username' ),
            'default'           => t( 'player' ),
            'required'          => TRUE,
            'localize'          => TRUE,
        );

        $variables[ SCOGA_SETTING_DEFAULT_CREDITS ] = array(
            'group'             => SCOGA_VARIABLE_GROUP_NAME,
            'type'              => 'number',
            'title'             => t( 'Default amount of credits awarded/subtracted' ),
            'description'       => t( 'Default amount of credits awarded/subtracted' ),
            'default'           => 10,
            'required'          => TRUE
        );

        //determinecampaign cron interval
        $variables[ SCOGA_SETTING_DETERMINECAMPAIGN_CRON_INTERVAL ] = array(
            'group'             => SCOGA_VARIABLE_GROUP_NAME,
            'type'              => 'uint',
            'title'             => t( 'Determine campaign cron interval' ),
            'description'       => t( 'Cron interval for determining current campaign, in seconds' ),
            'default'           => 60 * 60,
            'required'          => TRUE
        );

        $variables[ SCOGA_SETTING_MAX_WISHITEM_CREDIT ] = array(
            'group'             => SCOGA_VARIABLE_GROUP_NAME,
            'type'              => 'number',
            'title'             => t( 'Max credit value for wished items' ),
            'description'       => t( 'Maximum credit value for wished items' ),
            'default'           => 10,
            'required'          => TRUE
        );

        $variables[ SCOGA_SETTING_REWARD_ANSWER_POLL ] = array(
            'group'             => SCOGA_VARIABLE_GROUP_NAME,
            'type'              => 'number',
            'title'             => t( 'Reward points amount for answering a poll' ),
            'description'       => t( 'Reward points amount for answering a poll' ),
            'default'           => 5,
            'required'          => TRUE
        );

        $variables[ SCOGA_SETTING_CURRENT_COMBOCHECKIN_RTID ] = array(
            'group'             => SCOGA_VARIABLE_GROUP_NAME,
            'type'              => 'number',
            'title'             => t( 'The current user relationship type ID' ),
            'description'       => t( 'FOR DEBUGGING AND DEVELOPMENT PURPOSES ONLY, DO NOT MODIFY ON LIVE SITE' ),
            'default'           => 0,
            'required'          => TRUE
        );

        $variables[ SCOGA_SETTING_CURRENT_CAMPAIGN_NID ] = array(
            'group'             => SCOGA_VARIABLE_GROUP_NAME,
            'type'              => 'number',
            'title'             => t( 'The current campaign' ),
            'description'       => t( 'FOR DEBUGGING AND DEVELOPMENT PURPOSES ONLY, DO NOT MODIFY ON LIVE SITE' ),
            'default'           => 0,
            'required'          => TRUE
        );

        $variables[ SCOGA_SETTING_CREDITS_TID ] = array(
            'group'             => SCOGA_VARIABLE_GROUP_NAME,
            'type'              => 'number',
            'title'             => t( 'Credits TID' ),
            'description'       => t( 'FOR DEBUGGING AND DEVELOPMENT PURPOSES ONLY, DO NOT MODIFY ON LIVE SITE' ),
            'default'           => 0,
            'required'          => TRUE
        );

        $variables[ SCOGA_SETTING_SCORE_TID ] = array(
            'group'             => SCOGA_VARIABLE_GROUP_NAME,
            'type'              => 'number',
            'title'             => t( 'Score TID' ),
            'description'       => t( 'FOR DEBUGGING AND DEVELOPMENT PURPOSES ONLY, DO NOT MODIFY ON LIVE SITE' ),
            'default'           => 0,
            'required'          => TRUE
        );
        return $variables;

    }

