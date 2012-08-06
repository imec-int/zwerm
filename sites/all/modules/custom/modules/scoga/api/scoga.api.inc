<?php
    /**
     * "global" SCOGA functions
     *
     * User: creynder
     * Date: 12/04/12
     * Time: 10:20
     * To change this template use File | Settings | File Templates.
     */

    /**
     * @param $vid
     * @param $term_name
     *
     * @return stdClass
     */
    function scoga_create_term( $vid, $term_name ){
        $term = new stdClass();
        $term->vid = $vid;
        $term->name = $term_name;

        taxonomy_term_save( $term );
        return $term;
    }

    /**
     * @param $variable
     *
     * @return array|null|string
     */
    function scoga_validate_uint( $variable ){
        $value = $variable[ 'value' ];
        if( ! is_numeric( $value ) || $value < 0 ){
            return t( 'The value is not an unsigned integer' );
        }
    }

    /**
     * @param        $uuid
     * @param string $entity_type
     *
     * @return bool
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


    /**
     * @param $param
     * @param $callback
     *
     * @return array
     */
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

    /**
     * @param $machine_name
     *
     * @return array
     */
    function scoga_retrieve_terms_by_machinename( $machine_name ){
        $vocab = taxonomy_vocabulary_machine_name_load( $machine_name );
        $terms = taxonomy_get_tree( $vocab->vid, 0, NULL, TRUE );
        return $terms;
    }

    /**
     * @param     $message
     * @param int $severity
     *
     * @throws Exception
     */
    function scoga_throw_exception( $message, $severity = WATCHDOG_NOTICE ){
        watchdog( 'SCOGA', $message, NULL, $severity );
        throw new Exception( $message );
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

    //--( ACCESSORS )--//

    /**
     * @return string
     */
    function scoga_get_default_username(){
        return variable_get( SCOGA_SETTING_DEFAULT_USERNAME );
    }

    /**
     * @return int
     */
    function scoga_get_checkin_cooldown(){
        return variable_get( SCOGA_SETTING_CHECKIN_COOLDOWN );
    }

    /**
     * @return int
     */
    function scoga_get_combocheckin_timeframe(){
        return variable_get( SCOGA_SETTING_COMBOCHECKIN_TIMEFRAME );
    }

    /**
     * @return int
     */
    function scoga_get_determinecampaign_cron_interval(){
        return variable_get( SCOGA_SETTING_DETERMINECAMPAIGN_CRON_INTERVAL );
    }

    /**
     * @return int
     */
    function scoga_get_determinecampaign_next_execution(){
        return variable_get( SCOGA_SETTING_DETERMINECAMPAIGN_NEXT_EXECUTION );
    }
    function scoga_set_determinecampaign_next_execution( $value ){
        variable_set( SCOGA_SETTING_DETERMINECAMPAIGN_NEXT_EXECUTION, $value );
    }

    /**
     * @return int
     */
    function scoga_get_current_campaign_nid(){
        return variable_get( SCOGA_SETTING_CURRENT_CAMPAIGN_NID );
    }
    function scoga_set_current_campaign_nid( $campaign_nid ){
        watchdog( 'SCOGA', 'set current campaign nid to @nid', array(
           '@nid' => $campaign_nid
        ));
        variable_set( SCOGA_SETTING_CURRENT_CAMPAIGN_NID, $campaign_nid );
    }

    /**
     * @return int
     */
    function scoga_get_current_combocheckin_rtid(){
        return variable_get( SCOGA_SETTING_CURRENT_COMBOCHECKIN_RTID );
    }
    function scoga_set_current_combocheckin_rtid( $value ){
        variable_set( SCOGA_SETTING_CURRENT_COMBOCHECKIN_RTID, $value );
    }

    /**
     * @param $value
     */
    function scoga_set_current_userpoints_category_tid( $value ){
        //from userpoints module
        variable_set( USERPOINTS_CATEGORY_DEFAULT_TID, $value );
    }
    function scoga_get_current_userpoints_category_tid(){
        return userpoints_get_default_tid();
    }

    /**
     * @return int
     */
    function scoga_get_default_credits(){
        return variable_get( SCOGA_SETTING_DEFAULT_CREDITS );
    }

    /**
     * @return bool|null
     */
    function scoga_get_userpoints_vid(){
        return userpoints_get_vid();
    }


//    function scoga_get_current_team_nid(){
//        return variable_get( SCOGA_SETTING_CURRENT_TEAM );
//    }
//
//    function scoga_set_current_team_nid( $value ){
//        variable_set( SCOGA_SETTING_CURRENT_TEAM, $value );
//    }


    /**
     * @return int
     */
    function scoga_get_credits_tid(){
        return SCOGA_SETTING_CREDITS_TID;
    }
    function scoga_set_credits_tid( $value ) {
        variable_set( SCOGA_SETTING_CREDITS_TID, $value );
    }

    /**
     * @return int
     */
    function scoga_get_score_tid(){
        return SCOGA_SETTING_SCORE_TID;
    }
    function scoga_set_score_tid( $value ){
        variable_set( SCOGA_SETTING_SCORE_TID, $value );
    }

    /**
     * @return int
     */
    function scoga_get_max_wishitem_credits(){
        return intval( variable_get( SCOGA_SETTING_MAX_WISHITEM_CREDIT, 10 ) );
    }

