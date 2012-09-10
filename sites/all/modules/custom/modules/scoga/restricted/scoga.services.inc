<?php
    /**
     * Invoked from services, i.e. service handlers
     * Service handler wiring happens in scoga.module#scoga_services_resources
     *
     * User: creynder
     * Date: 20/04/12
     * Time: 14:41
     *
     */

    function scoga_handle_services_resources(){
//            'scoga_player'      => scoga_outline_services_player(),
//            'scoga_transaction' => scoga_outline_services_transaction(),
//            'scoga_overview'    => scoga_outline_services_overview(),
//            'scoga_message'     => scoga_outline_services_message(),
//            'scoga_checkin'     => scoga_outline_services_checkin(),
//            'scoga_reader'      => scoga_outline_services_reader(),
//            'scoga_card'        => scoga_outline_services_card(),
        return array(
            'scoga_teams'        => scoga_outline_services_teams(),
            'scoga_campaigns'    => scoga_outline_services_campaigns(),
            'scoga_sync'        => scoga_outline_services_sync(),
        );
    }

    function scoga_outline_services_sync(){
        return array(
            'index' => array(
                'help'             => 'Retrieve syncing info',
                'file'             => array(
                    'file'   => 'services.inc',
                    'module' => 'scoga',
                ),
                'callback'         => 'scoga_service_sync_index',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_SYNC ),
                'args'             => array(
                    array(
                        'name'        => 'messageID',
                        'type'        => 'string',
                        'description' => 'The ID of the message previously retrieved',
                        'source'      => 'param',
                        'optional'    => TRUE,
                    ),
                )
            )
        );
    }

    function scoga_outline_services_card(){
        return array(
            'create' => array(
                'help'             => 'Register an RFID card to be used with SCOGA',
                'file'             => array(
                    'file'   => 'services.inc',
                    'module' => 'scoga',
                ),
                'callback'         => 'scoga_service_card_create',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_REGISTER_CARD ),
                'args'             => array(
                    array(
                        'name'        => 'cardID',
                        'type'        => 'string',
                        'description' => 'The unique ID of the card',
                        'source'      => 'data',
                        'optional'    => FALSE,
                    ),
                    array(
                        'name'        => 'readerID',
                        'type'        => 'string',
                        'description' => 'The unique ID of the RFID reader',
                        'source'      => 'data',
                        'optional'    => FALSE,
                    ),
                )
            )
        );
    }

    function scoga_outline_services_reader(){
        return array(
            'create' => array(
                'help'             => 'Register an RFID reader to be used with SCOGA',
                'file'             => array(
                    'file'   => 'services.inc',
                    'module' => 'scoga',
                ),
                'callback'         => 'scoga_service_reader_create',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_REGISTER_READER ),
                'args'             => array(
                    array(
                        'name'        => 'cardID',
                        'type'        => 'string',
                        'description' => 'The unique ID of the card',
                        'source'      => 'data',
                        'optional'    => FALSE,
                    ),
                    array(
                        'name'        => 'readerID',
                        'type'        => 'string',
                        'description' => 'The unique ID of the RFID reader',
                        'source'      => 'data',
                        'optional'    => FALSE,
                    ),
                    array(
                        'name'          => 'timestamp',
                        'type'          => 'int',
                        'description'   => 'The unix epoch timestamp of checkin',
                        'source'        => 'data',
                        'optional'      => TRUE,
                        'default value' => -1
                    ),
                )
            )
        );
    }

    function scoga_outline_services_checkin(){
        return array(
            'create' => array(
                'help'             => 'Creates a node of content type "Checkin"',
                'file'             => array(
                    'file'   => 'services.inc',
                    'module' => 'scoga',
                ),
                'callback'         => 'scoga_service_checkin_create',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_CREATE_CHECKIN ),
                'args'             => array(
                    array(
                        'name'        => 'cardID',
                        'type'        => 'string',
                        'description' => 'The unique ID of the card',
                        'source'      => 'data',
                        'optional'    => FALSE,
                    ),
                    array(
                        'name'        => 'readerID',
                        'type'        => 'string',
                        'description' => 'The unique ID of the RFID reader',
                        'source'      => 'data',
                        'optional'    => FALSE,
                    ),
                    array(
                        'name'          => 'timestamp',
                        'type'          => 'int',
                        'description'   => 'The unix epoch timestamp of checkin',
                        'source'        => 'data',
                        'optional'      => TRUE,
                        'default value' => -1
                    ),
                )
            )
        );
    }

    function scoga_outline_services_message(){
        return array(
            'index' => array(
                'help'             => 'Retrieves all messages',
                'file'             => array(
                    'type'   => 'services.inc',
                    'module' => 'scoga'
                ),
                'callback'         => 'scoga_service_message_index',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_MESSAGES_DATA ),
                'args'             => array(
                    array(
                        'name'        => 'last_nid',
                        'type'        => 'string',
                        'description' => 'Messages with a nid higher than last_nid will be retrieved',
                        'source'      => 'param',
                        'optional'    => TRUE
                    ),
                )
            ),
        );
    }

    function scoga_outline_services_overview(){
        return array(
            'index' => array(
                'help'             => 'Retrieves a snapshot of the SCOGA state',
                'file'             => array(
                    'type'   => 'services.inc',
                    'module' => 'scoga'
                ),
                'callback'         => 'scoga_service_overview_index',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_OVERVIEW_DATA ),
            ),
        );
    }

    function scoga_outline_services_transaction(){
        return array(
            'index' => array(
                'help'             => 'Retrieves all transactions between two timestamps',
                'file'             => array(
                    'file'   => 'services.inc',
                    'module' => 'scoga'
                ),
                'callback'         => 'scoga_service_transaction_index',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_TRANSACTION_DATA ),
                'args'             => array(
                    array(
                        'name'        => 'campaign_uuid',
                        'type'        => 'string',
                        'description' => 'The UUID of the campaign node',
                        'source'      => 'param',
                        'optional'    => TRUE
                    ),
                    array(
                        'name'        => 'last_txnid',
                        'description' => 'Transaction ID',
                        'source'      => 'param',
                        'optional'    => TRUE
                    ),
                )
            ),
        );
    }

    function scoga_outline_services_player(){
        return array(
            'index' => array(
                'help'             => 'Retrieves all data of a player',
                'file'             => array(
                    'file'   => 'services.inc',
                    'module' => 'scoga'
                ),
                'callback'         => 'scoga_service_player_index',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_PLAYER_DATA ),
                'args'             => array(
                    array(
                        'name'        => 'uuid',
                        'description' => 'The UUID of the player',
                        'source'      => 'param',
                        'optional'    => TRUE
                    ),
                    array(
                        'name'        => 'uid',
                        'description' => 'The uid of the team node',
                        'source'      => 'param',
                        'optional'    => TRUE
                    ),
                )
            ),
        );
    }

    function scoga_outline_services_teams(){
        return array(
            'index' => array(
                'help'             => 'Retrieves all data of a team',
                'file'             => array(
                    'file'   => 'services.inc',
                    'module' => 'scoga'
                ),
                'callback'         => 'scoga_service_teams_index',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_TEAM_DATA ),
                'args'             => array(
                    array(
                        'name'        => 'nid',
                        'description' => 'The nid of the team node',
                        'source'      => 'param',
                        'optional'    => TRUE
                    ),
                )
            ),
        );
    }

    function scoga_outline_services_campaigns(){
        return array(
            'index' => array(
                'help'             => 'Retrieves all campaigns or a specific one',
                'file'             => array(
                    'type'   => 'services.inc',
                    'module' => 'scoga'
                ),
                'callback'         => 'scoga_service_campaigns_index',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_CAMPAIGN_DATA ),
                'args'             => array(
                    array(
                        'name'        => 'nid',
                        'description' => 'The nid of the campaign node',
                        'source'      => 'param',
                        'optional'    => TRUE
                    ),
                )
            ),
        );
    }

    /**
     * @param array $params
     *
     * @return SyncData
     */
    function scoga_service_sync_index( $params = array() ){
        watchdog( 'SCOGA', 'scoga_service_sync_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
        module_load_include( 'api.sync.inc', 'scoga', 'api/scoga' );
        if( $params && array_key_exists( 'messageID', $params ) ){
            return scoga_get_sync_vo( $params[ 'messageID' ] );
        }
        return scoga_get_sync_vo();
    }

    function scoga_service_campaigns_index( $params = array() ){
        watchdog( 'SCOGA', 'scoga_service_campaigns_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
        module_load_include( 'api.campaign.inc', 'scoga', 'api/scoga' );
        if( $params ){
            if( array_key_exists( 'nid', $params ) ){
                return scoga_get_campaign_vo_by_nid( $params[ 'nid' ] );
            }
        }
        return scoga_get_campaign_vos();
    }

    function scoga_service_teams_index( $params ){
        watchdog( 'SCOGA', 'scoga_service_team_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
        module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );
        if( array_key_exists( 'nid', $params ) ){
            return scoga_get_team_vos_by_nids( $params[ 'nid' ] );
        }

        return scoga_get_team_vos();
    }

    function scoga_service_player_index( $params ){
        watchdog( 'SCOGA', 'scoga_service_player_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
//        if( array_key_exists( 'uuid', $params ) ){
//            return scoga_get_player_vos_by_UUIDs( $params[ 'uuid' ] );
//        }

        if( array_key_exists( 'uid', $params ) ){
            return scoga_get_player_vos_by_uids( $params[ 'uid' ] );
        }

        return FALSE;
    }

    function scoga_service_transaction_index( $params ){
        watchdog( 'SCOGA', 'scoga_service_transaction_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
        module_load_include( 'api.transaction.inc', 'scoga', 'api/scoga' );
        $last_txnid = ( array_key_exists( 'last_txnid', $params ) ) ? $params[ 'last_txnid' ] : '0';
        return scoga_get_transaction_vos_by_txnid( $last_txnid );
    }

    function scoga_service_overview_index(){
        watchdog( 'SCOGA', 'scoga_service_overview_index', NULL, WATCHDOG_INFO );
    	module_load_include( 'api.message.inc', 'scoga', 'api/scoga' );
        $output = array();
        $output[ 'campaign' ] = scoga_service_campaign_index();
        $output[ 'last_message_nid' ] = scoga_get_last_message_nid();
        return $output;
    }

    function scoga_service_message_index( $params ){
        watchdog( 'SCOGA', 'scoga_service_message_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
    	module_load_include( 'api.message.inc', 'scoga', 'api/scoga' );
        $last_nid = ( array_key_exists( 'last_nid', $params ) )
            ? $params[ 'last_nid' ]
            : NULL
        ;
        return scoga_get_message_vos_after_nid( $last_nid );
    }


    function scoga_service_checkin_create( $params ){
        watchdog( 'SCOGA', 'scoga_service_checkin_create: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_INFO );
        module_load_include( 'api.checkin.inc', 'scoga', 'api/scoga' );

        /*
        * catch parameters
        */
        $card_id = $params[ 'cardID' ];
        $reader_id = $params[ 'readerID' ];
        try{
            $result = scoga_register_checkin( $card_id, $reader_id );
        }catch ( Exception $e ){
            $message = $e->getMessage();
            watchdog( 'SCOGA', $message );
            $result = $message;
        }
        return $result;
    }

    function scoga_service_reader_create( $params ){
        watchdog( 'SCOGA', 'scoga_service_reader_create: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_NOTICE );
        module_load_include( 'api.reader.inc', 'scoga', 'api/scoga' );
        /*
        * catch parameters
        */
        $card_id = $params[ 'cardID' ];
        $reader_id = $params[ 'readerID' ];
        //$checkin_timeMS = $params[ 'timestamp' ];

        try{
            $result = scoga_register_reader( $card_id, $reader_id );
        }catch ( Exception $e ){
            $message = $e->getMessage();
            watchdog( 'SCOGA', $message );
            $result = $message;
        }

        return $result;
    }

    function scoga_service_card_create( $params ){
        watchdog( 'SCOGA', 'scoga_service_card_create: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_NOTICE );
        module_load_include( 'api.card.inc', 'scoga', 'api/scoga' );
        /*
        * catch parameters
        */
        $card_id = $params[ 'cardID' ];
        $reader_id = $params[ 'readerID' ];

        try{
            $result = scoga_register_card( $card_id, $reader_id );
        }catch ( Exception $e ){
            $message = $e->getMessage();
            watchdog( 'SCOGA', $message );
            $result = $message;
        }

        return $result;
    }

