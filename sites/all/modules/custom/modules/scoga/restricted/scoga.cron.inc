<?php
/**
 * Invoked from cron jobs, i.e. cron handlers
 * cron job wiring happens in scoga.module#scoga_cron
 *
 * User: creynder
 * Date: 26/04/12
 * Time: 12:24
 *
 */
    function scoga_handle_cron(){
        scoga_cron_determine_current_campaign();
        scoga_cron_determine_campaignteam_creation();
    }


    /**
     * called by cron job. Execution frequency is equal to or less than cron job frequency.
     * @param bool $force_execution
     */
    function scoga_cron_determine_current_campaign( $force_execution = FALSE ){
        watchdog( 'SCOGA', 'scoga_cron_determine_current_campaign', array(), WATCHDOG_INFO );

        module_load_include( 'api.campaign.inc', 'scoga', 'api/scoga' );
        scoga_determine_current_campaign();

    }

    function scoga_cron_determine_campaignteam_creation(){
        watchdog( 'SCOGA', 'scoga_cron_determine_campaignteam_creation', array(), WATCHDOG_INFO );

        module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );
        scoga_determine_campaignteam_creation();
    }
