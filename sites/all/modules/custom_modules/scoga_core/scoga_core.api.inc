<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 12/04/12
     * Time: 10:20
     * To change this template use File | Settings | File Templates.
     */

    function scoga_get_eid_by_uuid( $uuid, $entity_type = 'node' ){
        $query = new EntityFieldQuery();
        $result = $query
            ->entityCondition( 'entity_type', $entity_type )
            ->propertyCondition( 'uuid', $uuid )
            ->range( 0, 1 )
            ->execute();

        $eids = array_keys( $result[ $entity_type ] );
        if( $eids ){
            return $eids[ 0 ];
        }

        return FALSE;
    }


    function scoga_get_output( $param, $callback ){
        if( is_array( $param ) ){
            $output = array();
            foreach( $param as $payload ){
                $output[ ] = $callback( $payload );
            }
            return $output;
        }
        return $callback( $param );
    }


    function scoga_retrieve_terms_by_machinename( $machine_name ){
        $vocab = taxonomy_vocabulary_machine_name_load( $machine_name );
        $terms = taxonomy_get_tree( $vocab->vid, 0, NULL, TRUE );
        return $terms;
    }


    function scoga_throw_fatal_error( $message ){
        watchdog( 'SCOGA', $message, NULL, WATCHDOG_ERROR );
        throw new Exception( $message );
    }

    function scoga_get_default_username(){
        return variable_get( SCOGA_SETTING_DEFAULT_USERNAME );
    }

    function scoga_get_checkin_cooldown(){
        return intval( variable_get( SCOGA_SETTING_CHECKIN_COOLDOWN ) );
    }

    function scoga_get_combocheckin_timeframe(){
        return intval( variable_get( SCOGA_SETTING_COMBOCHECKIN_TIMEFRAME ) );
    }

    function scoga_get_current_campaign_nid(){
        return intval( variable_get( SCOGA_SETTING_CURRENT_CAMPAIGN_NID ) );
    }

    function scoga_get_determinecampaign_cron_interval(){
        return intval( variable_get( SCOGA_SETTING_DETERMINECAMPAIGN_CRON_INTERVAL ) );
    }

    function scoga_get_determinecampaign_next_execution(){
        return intval( variable_get( SCOGA_SETTING_DETERMINECAMPAIGN_NEXT_EXECUTION ) );
    }

    function scoga_set_determinecampaign_next_execution( $value ){
        variable_set( SCOGA_SETTING_DETERMINECAMPAIGN_NEXT_EXECUTION, $value );
    }

    function scoga_set_current_campaign_nid( $campaign_nid ){
        watchdog( 'SCOGA', 'set current campaign nid to @nid', array(
           '@nid' => $campaign_nid
        ));
        variable_set( SCOGA_SETTING_CURRENT_CAMPAIGN_NID, $campaign_nid );
    }
    /**
     * @param $timeMS
     *
     * @return int|string
     */
    function scoga_time_MS_to_SEC( $timeMS = NULL ){
        if( $timeMS ){
            return number_format( $timeMS / 1000, 0, '.', '' );
        }

        return time();
    }


    /**
     * returns the time at the next unit
     *
     * example 1:
     * $time = 1335443816; //Thu, 26 Apr 2012 12:36:56 GMT
     * //we want to know the next hour at the hour
     * $new_time = scoga_add_seconds_till_next_unit( $time, 60 * 60 );
     * //$new_time is 1335448800 (Thu, 26 Apr 2012 14:00:00 GMT)
     *
     * example 2:
     * $time = 1335443816; //Thu, 26 Apr 2012 12:36:56 GMT
     * //we want to know the next minute at the minute
     * $new_time = scoga_add_seconds_till_next_unit( $time, 60 );
     * //$new_time is 1335443820 (Thu, 26 Apr 2012 12:37:00 GMT)
     *
     * @param $time int Unix time stamp
     * @param $seconds int seconds
     * @return int Unix timestamp
     */
    function scoga_add_seconds_till_next_unit( $time, $seconds ){
        $a = ( $time + $seconds ) / $seconds;
        return intval( $a ) * $seconds;
    }