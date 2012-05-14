<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 26/04/12
 * Time: 12:24
 *
 */

    function scoga_cron_determine_current_campaign(){
        $now = time();
        $next_time = scoga_get_determinecampaign_next_execution();
        if( $now >= $next_time ){
            module_load_include( 'api.campaign.inc', 'scoga_core' );
            scoga_determine_current_campaign();
            $interval = scoga_get_determinecampaign_cron_interval();
            //we want to do this _at_ the hour or minute or ...
            $next_time = scoga_add_seconds_till_next_unit( $now, $interval );
            scoga_set_determinecampaign_next_execution( $next_time );
        }
    }
