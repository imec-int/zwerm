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
        return variable_get( SCOGA_SETTINGS_DEFAULT_USERNAME );
    }

    function scoga_get_checkin_cooldown(){
        return intval( variable_get( SCOGA_SETTINGS_CHECKIN_COOLDOWN ) );
    }

    function scoga_get_combocheckin_timeframe(){
        return intval( variable_get( SCOGA_SETTINGS_COMBOCHECKIN_TIMEFRAME ) );
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

