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
//            'scoga_card'        => scoga_outline_services_card(),
        return array(
            'scoga_teams'        => scoga_outline_services_teams(),
            'scoga_campaigns'    => scoga_outline_services_campaigns(),
            'scoga_sync'        => scoga_outline_services_sync(),
            'scoga_network'     => scoga_outline_services_network(),
            'scoga_checkin'     => scoga_outline_services_checkin(),
            'scoga_reader'      => scoga_outline_services_reader(),
            'scoga_pages'       =>  scoga_outline_services_pages(),
            'scoga_config'      => scoga_outline_services_config(),
            'scoga_players'     => scoga_outline_services_players(),
        );
    }

    function scoga_outline_services_network(){
        return array(
            'index' => array(
                'help'             => 'Retrieve network',
                'file'             => array(
                    'file'   => 'services.inc',
                    'module' => 'scoga',
                ),
                'callback'         => 'scoga_service_network_index',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_RELATIONSHIPS ),
            )
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
                        'description' => 'The ID of the message lastly retrieved',
                        'source'      => 'param',
                        'optional'    => TRUE,
                    ),
                    array(
                        'name'        => 'transactionID',
                        'type'        => 'string',
                        'description' => 'The ID of the points transaction lastly retrieved',
                        'source'      => 'param',
                        'optional'    => TRUE,
                    ),
                    array(
                        'name'        => 'relationshipID',
                        'type'        => 'string',
                        'description' => 'The ID of the relationship lastly retrieved',
                        'source'      => 'param',
                        'optional'    => TRUE,
                    ),
                    array(
                        'name'        => 'readerID',
                        'type'        => 'string',
                        'description' => 'The ID of the reader, NOT USED except for logging purposes',
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
            'index' => array(
                'help'             => 'Retrieve reader info',
                'file'             => array(
                    'file'   => 'services.inc',
                    'module' => 'scoga',
                ),
                'callback'         => 'scoga_service_reader_index',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_READER_DATA ),
                'args'             => array(
                    array(
                        'name'        => 'readerID',
                        'type'        => 'string',
                        'description' => 'The ID of the reader',
                        'source'      => 'param',
                        'optional'    => false,
                    ),
                )
            ),
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
                        'name'          => 'time',
                        'type'          => 'int',
                        'description'   => 'The unix epoch timestamp of checkin',
                        'source'        => 'data',
                        'optional'      => TRUE,
                        'default value' => -1
                    ),
                    array(
                        'name'          => 's',
                        'type'          => 'string',
                        'source'        => 'data',
                        'optional'      => TRUE,
                        'default value' => -1
                    ),
                    array(
                        'name'          => 'type',
                        'type'          => 'string',
                        'source'        => 'data',
                        'optional'      => TRUE,
                        'default value' => 'single'
                    ),

                )
            )
        );
    }

    function scoga_outline_services_messages(){
        return array(
            'index' => array(
                'help'             => 'Retrieves all messages',
                'file'             => array(
                    'type'   => 'services.inc',
                    'module' => 'scoga'
                ),
                'callback'         => 'scoga_service_messages_index',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_MESSAGES_DATA ),
                'args'             => array(
                    array(
                        'name'        => 'messageID',
                        'type'        => 'string',
                        'description' => 'Messages with a nid higher than last_nid will be retrieved',
                        'source'      => 'param',
                        'optional'    => TRUE
                    ),
                )
            ),
        );
    }

    function scoga_outline_services_config(){
        return array(
            'index' => array(
                'help'             => 'Retrieves all remote config data',
                'file'             => array(
                    'type'   => 'services.inc',
                    'module' => 'scoga'
                ),
                'callback'         => 'scoga_service_config_index',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_MESSAGES_DATA ),
            ),
        );
    }

//    function scoga_outline_services_overview(){
//        return array(
//            'index' => array(
//                'help'             => 'Retrieves a snapshot of the SCOGA state',
//                'file'             => array(
//                    'type'   => 'services.inc',
//                    'module' => 'scoga'
//                ),
//                'callback'         => 'scoga_service_overview_index',
//                'access arguments' => array( SCOGA_PERM_REST_ACCESS_OVERVIEW_DATA ),
//            ),
//        );
//    }

//    function scoga_outline_services_transaction(){
//        return array(
//            'index' => array(
//                'help'             => 'Retrieves all transactions',
//                'file'             => array(
//                    'file'   => 'services.inc',
//                    'module' => 'scoga'
//                ),
//                'callback'         => 'scoga_service_transaction_index',
//                'access arguments' => array( SCOGA_PERM_REST_ACCESS_TRANSACTION_DATA ),
//                'args'             => array(
//                    array(
//                        'name'        => 'campaign_uuid',
//                        'type'        => 'string',
//                        'description' => 'The UUID of the campaign node',
//                        'source'      => 'param',
//                        'optional'    => TRUE
//                    ),
//                    array(
//                        'name'        => 'last_txnid',
//                        'description' => 'Transaction ID',
//                        'source'      => 'param',
//                        'optional'    => TRUE
//                    ),
//                )
//            ),
//        );
//    }

    function scoga_outline_services_players(){
        return array(
            'index' => array(
                'help'             => 'Retrieves all data of player(s)',
                'file'             => array(
                    'file'   => 'services.inc',
                    'module' => 'scoga'
                ),
                'callback'         => 'scoga_service_players_index',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_PLAYER_DATA ),
                'args'             => array(
                    array(
                        'name'        => 'uids',
                        'description' => 'The uids of the players',
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

    function scoga_outline_services_pages() {
        return array(
            'index' => array(
                'help'             => 'Retrieves all pages or a specific one',
                'file'             => array(
                    'type'   => 'services.inc',
                    'module' => 'scoga'
                ),
                'callback'         => 'scoga_service_pages_index',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_PAGES_DATA ),
                'args'             => array(
                    array(
                        'name'        => 'machine_name',
                        'description' => 'The machine name of the page node',
                        'source'      => 'param',
                        'optional'    => TRUE
                    ),
                )
            ),
        );
    }

    function scoga_outline_services_mail(){
        return array(
            'create' =>array(
                'help'             => 'Send mail to admin',
                'file'             => array(
                    'type'   => 'services.inc',
                    'module' => 'scoga'
                ),
                'callback'         => 'scoga_service_mail_create',
                'access arguments' => array( SCOGA_PERM_REST_ACCESS_MAIL ),
                'args'             => array(
                    array(
                        'name'        => 'message',
                        'description' => 'Message to send',
                        'source'      => 'data',
                        'optional'    => TRUE,
                    ),
                    array(
                        'name'          => 'time',
                        'source'        => 'data',
                        'optional'    => TRUE,
                    ),
                    array(
                        'name'          => 's',
                        'source'        => 'data',
                        'optional'    => TRUE,
                    ),
                    array(
                        'name'        => 'subject',
                        'type'        => 'string',
                        'source'      => 'data',
                        'optional'    => TRUE,
                    ),
                )
            )
        );
    }

    function scoga_service_network_index( $params = array() ){
        watchdog( 'SCOGA', 'scoga_service_network_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
        module_load_include( 'api.network.inc', 'scoga', 'api/scoga' );
        return scoga_get_current_relationships();
    }

    /**
     * @param array $params
     *
     * @return SyncData
     */
    function scoga_service_sync_index( $params = array() ){
        watchdog( 'SCOGA', 'scoga_service_sync_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
        module_load_include( 'api.sync.inc', 'scoga', 'api/scoga' );
        if( $params ){
            $messageID = array_key_exists( 'messageID', $params ) ? $params[ 'messageID' ] : 0;
            $transactionID = array_key_exists( 'transactionID', $params ) ? $params[ 'transactionID' ] : 0;
            $relationshipID = array_key_exists( 'relationshipID', $params ) ? $params[ 'relationshipID' ] : 0;
            return scoga_get_sync_vo( $messageID, $transactionID, $relationshipID );
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

        return scoga_get_team_vos_by_campaign_nid( scoga_get_current_campaign_nid() );
    }

    function scoga_service_players_index( $params ){
        watchdog( 'SCOGA', 'scoga_service_players_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        if( array_key_exists( 'uids', $params ) ){
            return scoga_get_player_vos_by_uids( $params[ 'uids' ] );
        }

        return scoga_get_active_player_vos();
    }

    function scoga_service_transaction_index( $params ){
        watchdog( 'SCOGA', 'scoga_service_transaction_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
        module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
        $last_txnid = ( array_key_exists( 'last_txnid', $params ) ) ? $params[ 'last_txnid' ] : '0';
        return scoga_get_transaction_vos_after_txnid( $last_txnid );
    }

//    function scoga_service_overview_index(){
//        watchdog( 'SCOGA', 'scoga_service_overview_index', NULL, WATCHDOG_INFO );
//    	module_load_include( 'api.message.inc', 'scoga', 'api/scoga' );
//        $output = array();
//        $output[ 'campaign' ] = scoga_service_campaign_index();
//        $output[ 'last_message_nid' ] = scoga_get_last_message_nid();
//        return $output;
//    }
//
    function scoga_service_messages_index( $params ){
        watchdog( 'SCOGA', 'scoga_services_message_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
    	module_load_include( 'api.message.inc', 'scoga', 'api/scoga' );
        $last_nid = ( array_key_exists( 'messageID', $params ) )
            ? $params[ 'messageID' ]
            : NULL
        ;
        return scoga_get_message_vos_after_nid( $last_nid );
    }


    function scoga_service_checkin_create( $params ){
        watchdog( 'SCOGA', 'scoga_service_checkin_create: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_INFO );
        module_load_include( 'api.checkin.inc', 'scoga', 'api/scoga' );
        module_load_include( 'api.reader.inc', 'scoga', 'api/scoga' );

        /*
        * catch parameters
        */
        $card_id = $params[ 'cardID' ];
        $reader_id = $params[ 'readerID' ];
        $remote_signature = $params[ 's' ];
        $timestamp = $params[ 'time' ];
        $type = $params[ 'type' ];
        try{
            $unenc_signature = $timestamp . $reader_id . SCOGA_SALT. $card_id;
            if( hash( 'sha256', $unenc_signature ) != $remote_signature ){
                throw new ErrorException( 'incorrect signature' );
            }

            $reader_node = scoga_get_reader_entity_by_reader_id( $reader_id );
            $current_campaign_nid = scoga_get_current_campaign_nid();

            if( $type == SCOGA_CHECKIN_TYPE_COMBO ){
                $result = scoga_register_combo_checkin( $card_id, $reader_node, $timestamp, $current_campaign_nid );
            }else{
                $result = scoga_register_single_checkin( $card_id, $reader_node, $timestamp, $current_campaign_nid );
            }
        }catch ( Exception $e ){
            $message = $e->getMessage();
            watchdog( 'SCOGA', $message );
            $result = $message;
        }
        return $result;
    }

    function scoga_service_reader_index( $params ){
        watchdog( 'SCOGA', 'scoga_service_reader_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_NOTICE );
        module_load_include( 'api.reader.inc', 'scoga', 'api/scoga' );
        /*
        * catch parameters
        */
        $reader_id = $params[ 'readerID' ];

        return scoga_get_reader_vo_by_reader_id( $reader_id );
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


    function scoga_service_pages_index( $params ){
        watchdog( 'SCOGA', 'scoga_service_pages_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_NOTICE );
        module_load_include( 'api.page.inc', 'scoga', 'api/scoga' );
        /*
        * catch parameters
        */

        if( $params ){
            if( array_key_exists( 'machine_name', $params ) ){
                return scoga_get_page_vo_by_machine_name( $params[ 'machine_name' ] );
            }
        }
        return scoga_get_page_vos();
    }

    function scoga_service_mail_create( $params ){
        watchdog( 'SCOGA', 'scoga_service_mail_create: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_NOTICE );
        module_load_include( 'api.mail.inc', 'scoga', 'api/scoga' );
        $subject = $params[ 'subject' ];
        $remote_signature = $params[ 's' ];
        $timestamp = $params[ 'time' ];
        $message = $params[ 'message' ];
        try{
            $unenc_signature = $timestamp . SCOGA_SALT. $subject;
            $enc_signature = hash( 'sha256', $unenc_signature );
//            watchdog( 'SCOGA', $enc_signature, array(), WATCHDOG_DEBUG );
            if( $enc_signature != $remote_signature ){
                throw new ErrorException( 'incorrect signature' );
            }
            $result = scoga_send_admin_mail( $message, $subject );
        }catch ( Exception $e ){
            $message = $e->getMessage();
            watchdog( 'SCOGA', $message, array(), WATCHDOG_ERROR );
            $result = $message;
        }

        return $result;
    }

    function scoga_service_config_index(){
        watchdog( 'SCOGA', 'scoga_service_config_index', array(  ), WATCHDOG_NOTICE );

        module_load_include( 'api.config.inc', 'scoga', 'api/scoga' );
        return scoga_get_config_vo();
    }