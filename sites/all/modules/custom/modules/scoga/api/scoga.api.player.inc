<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 20/04/12
     * Time: 14:24
     * To change this template use File | Settings | File Templates.
     */

    require_once 'includes/password.inc';

    /**
     *
     */
    class Player {
        public $uid = '-1';
        public $username = '';
        public $registered;
        public $team_nid;
        public $firstname;
        public $surname;
        public $avatar_url;
        public $points;
        public $card_id;
    }

    /**
     * returns all ACTIVE players that belong to the team with nid <code>team_nid</code>
     * unless if <code>exclude</code> is TRUE, then it returns all players that do NOT belong to that team
     * @param      $team_nid
     * @param bool $exclude
     *
     * @return array
     */
    function scoga_get_player_uids_by_team_nid( $team_nid, $exclude = FALSE ){
        $query = new EntityFieldQuery();
        $entity_type = 'user';
        $operator = ( $exclude ) ? '!=' : '=';
        $result = $query
            ->entityCondition( 'entity_type', $entity_type )
            ->fieldCondition( 'field_user_team', 'target_id', $team_nid, $operator )
            ->fieldCondition( 'field_user_active', 'value', 1, '=' )
            ->execute();


        if( $uids = array_keys( $result[ $entity_type ] ) ){
            return $uids;
        }

        return array();
    }

    function scoga_get_player_vos_by_team_nid( $team_nid, $exclude = FALSE ){
        $uids = scoga_get_player_uids_by_team_nid( $team_nid, $exclude );
        $vos = scoga_get_player_vos_by_uids( $uids );
        return $vos;
    }

//    function scoga_get_player_vos_by_UUIDs( $player_UUIDs ){
//        return scoga_get_output( $player_UUIDs, 'scoga_get_player_vo_by_UUID' );
//    }
//
//    /**
//     * @param $player_UUID String UUID for the player entity
//     *
//     * @return array
//     */
//    function scoga_get_player_vo_by_UUID( $player_UUID ){
//        $player_uid = scoga_get_eid_by_uuid( $player_UUID, 'user' );
//        if( $player_uid ){
//            return scoga_get_player_vo_by_uid( $player_uid );
//        }
//
//        return FALSE;
//    }

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
     * @return bool|array player VO
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
     * @param $card_id
     *
     * @return bool|mixed
     * @throws Exception
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
        $options = array(
            'entity_type' => 'user',
        );
        $is_registered = scoga_get_field_value( $player_entity, 'field_user_registered', $options );
        $team_nid = scoga_get_eid_from_field( $player_entity, 'field_user_team', $options );
        $firstname = scoga_get_field_value( $player_entity, 'field_user_firstname', $options );
        $surname = scoga_get_field_value( $player_entity, 'field_user_surname', $options );
        $cardID = scoga_get_field_value( $player_entity, 'field_card_id', $options );
        $image = ( $player_entity->picture )
            ? $player_entity->picture->uri
            : '';

        $output = new Player();
        $output->avatar_url = image_style_url( 'avatar_pinhead', $image );
        $output->firstname = $firstname;
        $output->points = userpoints_get_current_points( $player_entity->uid );
        $output->registered = $is_registered;
        $output->surname = $surname;
        $output->team_nid = $team_nid;
        $output->username = $player_entity->name;
        $output->uid = $player_entity->uid;
        $output->card_id = isset( $cardID ) ? $cardID : '';

        return $output;
    }

    /**
     * @return null
     */
    function scoga_get_next_player_id(){
        $next_id = variable_get( SCOGA_SETTING_NEXT_PLAYER_ID, 1 ) + 1;
        variable_set( SCOGA_SETTING_NEXT_PLAYER_ID, $next_id );
        return $next_id;
    }


    /**
     * create a player entity
     *
     * @param $card_id String unique card ID, has nothing to do with Drupal ID's [!]
     * @param $team_nid
     *
     * @return bool|stdClass
     */
    function scoga_create_player_entity( $card_id, $team_nid = NULL ){
        $lang = LANGUAGE_NONE;
        $player_id = scoga_get_next_player_id();
        $user_profile = new stdClass();
        $user_profile->name = scoga_get_default_username() . $player_id;
        $user_profile->status = 1; //0->blocked, 1->active
        $user_profile->mail = '';
        $user_profile->roles = array(
            2                 => 'authenticated user',
            SCOGA_PLAYER_ROLE => 'player'
        );
        $user_profile->pass = user_hash_password( substr( $card_id, -4, 4 ) );
        $user_profile->is_new = TRUE;

        scoga_set_field_value( $user_profile, 'field_card_id', $card_id );
        scoga_set_field_value( $user_profile, 'field_user_firstname', scoga_get_default_username() );
        scoga_set_field_value( $user_profile, 'field_user_surname', $player_id );
        scoga_set_field_value( $user_profile, 'field_user_registered', 1 );

        scoga_set_eid_in_field( $user_profile, 'field_user_team', $team_nid, array( 'entity_type' => 'user' ) );

        $user_account = user_save( $user_profile );
        return $user_account;
    }

    /**
     * @return array
     */
    function scoga_get_all_player_uids(){
        $uids = array();

        $query = 'SELECT DISTINCT(r.uid)
            FROM {users_roles} AS r
            WHERE r.rid IN (:rids)';
        $result = db_query( $query, array( ':rids' => array( SCOGA_PLAYER_ROLE ) ) );

        foreach( $result as $row ){
            $uids[ ] = $row->uid;
        }

        return $uids;
    }

    /**
     * @return mixed
     */
    function scoga_get_all_player_accounts(){
        return user_load_multiple( scoga_get_all_player_uids() );
    }

//    function scoga_assign_random_teams_to_players(){
//        module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );
//        $team_nids = scoga_get_team_nids();
//        $team_count = count( $team_nids );
//        $player_uids = scoga_get_all_player_uids();
//
//        //[!] not a typical for-loop, but a counter is needed
//        for( $i=0; count( $player_uids ) > 0; $i++ ){
//            $player_index = rand( 0, count( $player_uids ) - 1 );
//            $values = array_splice( $player_uids, $player_index, 1 );
//            $uid = $values[ 0 ];
//            $team_index = $i % $team_count;
//            $team_nid = $team_nids[ $team_index ];
//            $account = user_load( $uid );
//            $account->field_user_team[ LANGUAGE_NONE ][ 0 ] = array(
//                'target_id' => $team_nid
//            );
//            user_save( $account );
//        }
//    }


    /**
     *
     */
//    function scoga_reset_user_relationships(){
//        db_query( 'TRUNCATE {user_relationships}' );
//    }
