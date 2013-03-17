<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 31/07/12
 * Time: 15:26
 * To change this template use File | Settings | File Templates.
 */

    function scoga_handle_form_nodetype_wished_item_node_form_alter( &$form, $form_state, $form_id ){
        $uid = $form[ 'uid' ][ '#value' ];

        $field_name = 'field_wisheditem_award';
        $award_element = $form[ $field_name ];
        $lang = $award_element[ '#language' ];
        $assigned_credits_values = $award_element[ $lang ][ '#default_value' ];
        $assigned_credits = ( count( $assigned_credits_values ) > 0 )
            ? $assigned_credits_values[ 0 ]
            : 0;

        $current_points = userpoints_get_current_points( $uid, scoga_get_credits_tid() );
        $max_wishitem_credits = scoga_get_max_wishitem_credits();
        $user_remaining_credits = min( $current_points + $assigned_credits, $max_wishitem_credits );

        if( $user_remaining_credits > 0 ){
            $credits_select_data = array(
                '_none' => t('- Select a value -')
            );
            for( $i = 0; $i < $user_remaining_credits; $i++ ){
                $value = $i + 1;
                $credits_select_data[ $value ] = $value;
            }
        } else{
            $credits_select_data = array(
                '_none' => t('- NOT ENOUGH CREDITS -')
            );
        }

        $award_element[ $lang ][ '#options' ] = $credits_select_data;
        $form[ $field_name ] = $award_element;
    }

    function scoga_handle_form_nodetype_wish_fulfilled_node_form_alter( &$form, $form_state, $form_id ){
        global $user;

        $user_profile = user_load( $user->uid );
        module_load_include( 'api.wishlist.inc', 'scoga', 'api/scoga' );
        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );

        /*
         * wished item
         *
         */
        $wisheditem_nids = scoga_get_wisheditem_nids_for_uid( $user_profile->uid );

        $wishlist_select_data = array(
            '_none' => t('- Select a value -')
        );
        foreach( $wisheditem_nids as $nid ){
            $wisheditem_node = node_load( $nid );
            $wishlist_select_data[ $nid ] = $wisheditem_node->title;
        }

        //TODO: OPTIMIZE THIS, it simply overwrites a list of ALL wished items
        $wisheditem_element = $form[ 'field_wishfulfilled_wisheditem' ];
        $lang = $wisheditem_element[ '#language' ];
        $wisheditem_element[ $lang ][ '#options' ] = $wishlist_select_data;
        $form[ 'field_wishfulfilled_wisheditem' ] = $wisheditem_element;


        /*
         * fulfiller
         */

        $team_nid = scoga_get_eid_from_field( $user_profile, 'field_user_team', array( 'entity_type' => 'user' ) );
        if( ! $team_nid ){
            $team_nid = -1;
        }

        $player_uids = scoga_get_player_uids_by_team_nid( $team_nid, TRUE ); //TRUE->excludes
        $player_select_data = array(
            '_none' => t('- Select a value -')
        );
        foreach( $player_uids as $uid ){
            $player_profile = user_load( $uid );
            $player_select_data[ $uid ] = $player_profile->name;
        }

        //TODO: OPTIMIZE THIS, it simply overwrites a list of ALL users

        $fulfiller_element = $form[ 'field_wishfulfilled_fulfiller' ];
        $lang = $fulfiller_element[ '#language' ];
        $fulfiller_element[ $lang ][ '#options' ] = $player_select_data;
        $form[ 'field_wishfulfilled_fulfiller' ] = $fulfiller_element;

        /*
         * title
         */
        $form[ 'title' ][ '#required' ] = FALSE;
        //hide the title field
        $form[ 'title' ][ '#access' ] = FALSE;

        //dsm( $form[ 'title' ] );
        $form[ 'title' ][ '#value' ] = 'wish fullfilled ' . $user->uid . ' ' . time();
    }

