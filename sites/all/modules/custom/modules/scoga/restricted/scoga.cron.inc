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
        watchdog( 'SCOGA', 'scoga_cron_determine_current_campaign', array(), WATCHDOG_INFO );

        module_load_include( 'api.campaign.inc', 'scoga', 'api/scoga' );
        scoga_determine_current_campaign();
    }