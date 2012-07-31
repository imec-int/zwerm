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

    /**
     * called by cron job. Execution frequency is equal to or less than cron job frequency.
     * @param bool $force_execution
     */
    function scoga_cron_determine_current_campaign( $force_execution = FALSE ){
        watchdog( 'SCOGA', 'scoga_cron_determine_current_campaign', array(), WATCHDOG_INFO );

        $now = time();
        $next_time = scoga_get_determinecampaign_next_execution();

        //determine whether it's time to run, or if execution is forced

        if( $force_execution || $now >= $next_time ){

            //do the magic

            module_load_include( 'api.campaign.inc', 'scoga' );
            scoga_determine_current_campaign();

            //calculate and set the new execution time

            $interval = scoga_get_determinecampaign_cron_interval();
            //we want to do this _at_ the hour or minute or ...
            $next_time = scoga_add_seconds_till_next_unit( $now, $interval );
            scoga_set_determinecampaign_next_execution( $next_time );
        }
    }
