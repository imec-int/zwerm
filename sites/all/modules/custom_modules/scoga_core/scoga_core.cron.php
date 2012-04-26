<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 26/04/12
 * Time: 12:24
 *
 */

    function scoga_cron_determine_current_campaign(){
        module_load_include( 'api.campaign.inc', 'scoga_core' );
        scoga_determine_current_campaign();
    }
