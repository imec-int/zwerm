<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 20/04/12
     * Time: 14:24
     * To change this template use File | Settings | File Templates.
     */

    require_once 'includes/password.inc';

    function scoga_get_player_uids_by_team_nid( $team_nid, $negate = FALSE ){
        $query = new EntityFieldQuery();
        $entity_type = 'user';
        $operator = ( $negate ) ? '!=' : '=';
        $result = $query
            ->entityCondition( 'entity_type', $entity_type )
            ->fieldCondition( 'field_user_team', 'target_id', $team_nid, $operator )
            ->execute();

        $uids = array_keys( $result[ $entity_type ] );
        return $uids;
    }

    function scoga_get_player_vos_by_UUIDs( $player_UUIDs ){
        return scoga_get_output( $player_UUIDs, 'scoga_get_player_vo_by_UUID' );
    }

    /**
     * @param $player_UUID String UUID for the player entity
     *
     * @return array
     */
    function scoga_get_player_vo_by_UUID( $player_UUID ){
        $player_uid = scoga_get_eid_by_uuid( $player_UUID, 'user' );
        if( $player_uid ){
            return scoga_get_player_vo_by_uid( $player_uid );
        }

        return FALSE;
    }

    /**
     * retrieve a list of player VO's
     *
     * @param array $player_uids
     *
     * @return array|bool of player VO's
     */
    function scoga_get_player_vos_by_uids( $player_uids ){
        return scoga_get_output( $player_uids, 'scoga_get_player_vo_by_uid' );
    }

    /**
     * get player VO
     *
     * @param $player_uid
     *
     * @return array player VO
     */
    function scoga_get_player_vo_by_uid( $player_uid ){
        $player_profile = user_load( $player_uid );
        if( $player_profile ){
            $result = scoga_create_player_vo( $player_profile );
            return $result;
        }

        return FALSE;
    }

    /**
     * retrieve user id's by card ID
     *
     * @param $card_id String unique card ID, has nothing to do with Drupal ID's [!]
     *
     * @return array of uid's
     */
    function scoga_get_player_uids_by_card_id( $card_id ){
        $user_entity_type = 'user';
        $user_query = new EntityFieldQuery();

        //get user profile by card ID if possible
        $user_entities = $user_query
            ->entityCondition( 'entity_type', $user_entity_type )
            ->fieldCondition( 'field_card_id', 'value', $card_id, '=', 0 )
            ->execute();

        if( array_key_exists( $user_entity_type, $user_entities ) ){
            return array_keys( $user_entities[ $user_entity_type ] );
        }

        return array();
    }

    /**
     * @param $card_id String unique card ID, has nothing to do with Drupal ID's [!]
     *
     * @return bool|mixed
     */
    function scoga_get_player_entity_by_card_id( $card_id ){
        $user_uids = scoga_get_player_uids_by_card_id( $card_id );
        switch( count( $user_uids ) ){
            case 1 :
                //exactly one match, as it should
                return user_load( $user_uids[ 0 ] );
            case 0 :
                break;
            default :
                // multiple matches
                throw new Exception( 'card registered multiple times' );
        }

        return FALSE;
    }

    /**
     * create player VO
     *
     * @param $player_entity
     *
     * @return array
     */
    function scoga_create_player_vo( $player_entity ){
        $registered_values = field_get_items( 'user', $player_entity, 'field_user_registered' );
        $team_nid_values = field_get_items( 'user', $player_entity, 'field_user_team' );
        $firstname_values =field_get_items( 'user', $player_entity, 'field_user_firstname' );
        $surname_values = field_get_items( 'user', $player_entity, 'field_user_surname' );
        $image = ( $player_entity->picture ) ? $player_entity->picture->uri : '';
        $output = array(
            'uid'           => $player_entity->uid,
            'username'      => $player_entity->name,
            'uuid'          => $player_entity->uuid,
            'registered'    => $registered_values[ 0 ][ 'value' ],
            'team_nid'      => $team_nid_values[ 0 ][ 'target_id' ],
            'firstname'     => $firstname_values[ 0 ][ 'value' ],
            'surname'       => $surname_values[ 0 ][ 'value' ],
            'avatar_url'    => image_style_url( 'avatar_pinhead', $player_entity->picture->uri ),
            'points'        => userpoints_get_current_points( $player_entity->uid ),
        );
        return $output;
    }

    function scoga_get_next_player_id(){
        $next_id = variable_get( SCOGA_SETTING_NEXT_PLAYER_ID, 1 ) + 1;
        variable_set( SCOGA_SETTING_NEXT_PLAYER_ID, $next_id );
        return $next_id;
    }


    /**
     * create a player entity
     *
     * @param $card_id String unique card ID, has nothing to do with Drupal ID's [!]
     *
     * @return bool|stdClass
     */
    function scoga_create_player_entity( $card_id, $team_nid ){
        $lang = LANGUAGE_NONE;
        $player_id = scoga_get_next_player_id();
        $user_profile = new stdClass();
        $user_profile->name = scoga_get_default_username() . $player_id;
        $user_profile->status = 1; //0->blocked, 1->active
        $user_profile->mail = '';
        $user_profile->roles = array(
            2 => 'authenticated user',
            SCOGA_PLAYER_ROLE => 'player'
        );
        $user_profile->field_card_id[ $lang ][ 0 ] = array(
            'value' => $card_id
        );
        $user_profile->field_user_firstname[ $lang ][ 0 ] = array(
            'value' => scoga_get_default_username()
        );
        $user_profile->field_user_surname[ $lang ][ 0 ] = array(
            'value' => $player_id
        );
        $user_profile->field_user_registered[ $lang ][ 0 ] = array(
            'value' => 1
        );
        $user_profile->pass = user_hash_password( substr( $card_id, -4, 4 ) );
        $user_profile->is_new = TRUE;
        $user_profile->field_user_team[ LANGUAGE_NONE ][ 0 ] = array(
            'target_id' => $team_nid
        );
        $user_account = user_save( $user_profile );
        return $user_account;
    }

    /**
     * @param $uid
     */
    function scoga_award_default_credits_to_player( $uid ){
        /*
         *    if (int) assumed to be points for current user
         *    Accepts an array of keyed variables and parameters
         *    'points' => # of points (int) (required)
         *    'moderate' => TRUE/FALSE
         *    'uid' => $user->uid
         *    'time_stamp' => unix time of the points assignment date
         *    'operation' => 'published' 'moderated' etc.
         *    'tid' => 'category ID'
         *    'expirydate' => timestamp or 0, 0 = non-expiring; NULL = site default
         *    'description' => 'description'
         *    'reference' => reserved for module specific use
         *    'display' => whether or not to display "points awarded" message
         *    'txn_id' => Transaction ID of points, If present an UPDATE is performed
         *    'entity_id' => ID of an entity in the Database. ex. $node->id or $user->uid
         *    'entity_type' => string of the entity type. ex. 'node' or 'user' NOT 'node-content-custom'
         */
        $params = array(
            'uid'           => $uid,
            'points'        => scoga_get_default_credits(),
            'tid'           => scoga_get_credits_tid(),
            'operation'     => 'default credits',
            'description'   => 'default credits awarded',
            'moderate'      => FALSE,
            'display'       => TRUE,
        );
        $result = userpoints_userpointsapi($params);

    }

    function scoga_award_default_credits_to_all_players(){
        $uids = scoga_get_all_player_uids();
        foreach( $uids as $player_uid ){
            scoga_award_default_credits_to_player( $player_uid );
        }
    }

    function scoga_get_all_player_uids(){
        $uids = array();

        $query = 'SELECT DISTINCT(r.uid)
            FROM {users_roles} AS r
            WHERE r.rid IN (:rids)'
        ;
        $result = db_query( $query, array( ':rids' => array( SCOGA_PLAYER_ROLE ) ) );

        foreach( $result as $row ){
            $uids[ ] = $row->uid;
        }

        return $uids;
    }

    function scoga_get_all_player_accounts(){
        return user_load_multiple( scoga_get_all_player_uids() );
    }