<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 20/04/12
     * Time: 15:04
     * To change this template use File | Settings | File Templates.
     */


    function scoga_core_settings_form( $form, &$form_state ){

        //cool down
        $form_elem_name = SCOGA_SETTING_CHECKIN_COOLDOWN;
        $form[ $form_elem_name ] = array(
            '#type'          => 'textfield',
            '#title'         => t( 'Cooldown for "checkin"' ),
            '#description'   => t( 'Define cooldown period for "checkins",in seconds, 0 for unlimited.' ),
            '#default_value' => variable_get( $form_elem_name, 0 ),
            '#size'          => 10,
            '#required'      => TRUE
        );

        //combo time frame
        $form_elem_name = SCOGA_SETTING_COMBOCHECKIN_TIMEFRAME;
        $form[ $form_elem_name ] = array(
            '#type'          => 'textfield',
            '#title'         => t( 'Timeframe for combo checkins' ),
            '#description'   => t( 'Define timeframe for combo checkins,in seconds, 0 for unlimited.' ),
            '#default_value' => variable_get( $form_elem_name, 0 ),
            '#size'          => 10,
            '#required'      => TRUE
        );

        //default player name
        $form_elem_name = SCOGA_SETTING_DEFAULT_USERNAME;
        $form[ $form_elem_name ] = array(
            '#type'          => 'textfield',
            '#title'         => t( 'Default username base' ),
            '#description'   => t( 'When creating new users through the services this value will be used in combination with a unique identifier to create the username' ),
            '#default_value' => variable_get( $form_elem_name, 'player' ),
            '#size'          => 20,
            '#required'      => TRUE
        );

        //default credits
        $form_elem_name = SCOGA_SETTING_DEFAULT_CREDITS;
        $form[ $form_elem_name ] = array(
            '#type'          => 'textfield',
            '#title'         => t( 'Default amount of credits awarded' ),
            '#description'   => t( 'Default amount of credits awarded' ),
            '#default_value' => variable_get( $form_elem_name, 10 ),
            '#size'          => 4,
            '#required'      => TRUE
        );

        //determinecampaign cron interval
        $form_elem_name = SCOGA_SETTING_DETERMINECAMPAIGN_CRON_INTERVAL;
        $form[ $form_elem_name ] = array(
            '#type'          => 'textfield',
            '#title'         => t( 'Determine campaign cron interval' ),
            '#description'   => t( 'In seconds' ),
            '#default_value' => variable_get( $form_elem_name, 60*60 ),
            '#size'          => 10,
            '#required'      => TRUE
        );


        $form[ 'submit' ] = array(
            '#type'  => 'submit',
            '#value' => t( 'Save settings' ),
        );

        return $form;
    }

    function scoga_core_settings_form_submit( $form, &$form_state ){

        $settings = array(
            SCOGA_SETTING_CHECKIN_COOLDOWN,
            SCOGA_SETTING_COMBOCHECKIN_TIMEFRAME,
            SCOGA_SETTING_DEFAULT_USERNAME,
            SCOGA_SETTING_DETERMINECAMPAIGN_CRON_INTERVAL,
            SCOGA_SETTING_DEFAULT_CREDITS,
        );

        foreach( $settings as $form_elem_name ){
            variable_set( $form_elem_name, $form_state[ 'values' ][ $form_elem_name ] );
        }

        drupal_set_message( t( 'The SCOGA settings have been saved.' ) );
    }
