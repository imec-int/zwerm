<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 20/04/12
     * Time: 14:24
     * To change this template use File | Settings | File Templates.
     */


    function scoga_get_transaction_vos_by_period( $begin_time = NULL, $end_time = NULL ){

        if( $begin_time == NULL ){
            $begin_time = 0;
        }
        if( $end_time == NULL ){
            $end_time = time() + 1;
        }

        //dd( $begin_time, 'begin time');
        //dd( $end_time, 'end time' );

        //TODO: check if this can be rewritten to use the user_points methods
        $query =
            " SELECT txn_id, time_stamp "
                . "FROM {userpoints_txn} "
                . "WHERE tid = :tid "
                . "AND time_stamp >= :begin_time "
                . "AND time_stamp < :end_time";
        $rows = db_query( $query, array(
            ':tid'          => userpoints_get_default_tid(),
            ':begin_time'   => $begin_time,
            ':end_time'     => $end_time,
        ) );

        $options = array(
            'link'             => FALSE,
            'truncate'         => FALSE,
            'skip_description' => FALSE,
        );

        $result = array();
        foreach( $rows as $row ){
            $transaction = userpoints_transaction_load( $row->txn_id );
            $description = userpoints_create_description( $transaction, $options );
            $result[ ] = scoga_create_transaction_vo( $transaction, $description );
        }

        return $result;
    }

    function scoga_create_transaction_vo( $transaction, $description ){
        $output = array(
            'txn_id'        => $transaction->txn_id,
            'uid'           => $transaction->uid,
            'points'        => $transaction->points,
            'time_stamp'    => $transaction->time_stamp,
            'description'   => $description,
        );
        return $output;
    }

    function scoga_transfer_transaction_points_to_team( $transaction ){
        if( $transaction->tid === userpoints_get_default_tid() ){
            module_load_include( 'api.campaign.inc', 'scoga_core' );
            $user_account = user_load( $transaction->uid );
            $team_nid = $user_account->field_user_team[ LANGUAGE_NONE ][ 0 ][ 'target_id' ];
            $campaignteam_node = scoga_get_campaignteam_entity_by_team_nid( $team_nid );
            if( $campaignteam_node ){
                $campaignteam_node->field_campaignteam_totalpoints[ LANGUAGE_NONE ][ 0 ][ 'value' ] += $transaction->points;
                node_save( $campaignteam_node );
            }
        }
    }