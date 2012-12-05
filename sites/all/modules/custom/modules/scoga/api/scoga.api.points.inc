<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 20/04/12
     * Time: 14:24
     * To change this template use File | Settings | File Templates.
     */

    class PointsTransaction {
        public $txn_id;
        public $uid;
        public $points;
        public $time_stamp;
        public $description;
    }

    /**
     * @param $last_txnid
     *
     * @return array
     */
    function scoga_get_transaction_vos_after_txnid( $last_txnid = 0 ){
        if( $last_txnid > 0 ){
            $query =
                " SELECT txn_id, time_stamp "
                    . "FROM {userpoints_txn} "
                    . "WHERE tid = :tid "
                    . "AND txn_id > :txnid ";

            $rows = db_query( $query, array(
                ':tid'          => scoga_get_current_userpoints_category_tid(),
                ':txnid'        => $last_txnid,
            ) );

//            $options = array(
//                'link'             => FALSE,
//                'truncate'         => FALSE,
//                'skip_description' => FALSE,
//            );

            $result = array();
            foreach( $rows as $row ){
                $transaction = userpoints_transaction_load( $row->txn_id );
                $result[ ] = scoga_create_transaction_vo_from_std_class( $transaction );
            }

            return $result;
        }

        return array();
    }

//    /**
//     * @param null $begin_time
//     * @param null $end_time
//     *
//     * @return array
//     */
//    function scoga_get_transaction_vos_by_period( $begin_time = NULL, $end_time = NULL ){
//
//        if( $begin_time == NULL ){
//            $begin_time = 0;
//        }
//        if( $end_time == NULL ){
//            $end_time = time() + 1;
//        }
//
//        //dd( $begin_time, 'begin time');
//        //dd( $end_time, 'end time' );
//
//        //TODO: check if this can be rewritten to use the user_points methods
//        $query =
//            " SELECT txn_id, time_stamp "
//                . "FROM {userpoints_txn} "
//                . "WHERE tid = :tid "
//                . "AND time_stamp >= :begin_time "
//                . "AND time_stamp < :end_time";
//        $rows = db_query( $query, array(
//            ':tid'          => scoga_get_current_userpoints_category_tid(),
//            ':begin_time'   => $begin_time,
//            ':end_time'     => $end_time,
//        ) );
//
//        $options = array(
//            'link'             => FALSE,
//            'truncate'         => FALSE,
//            'skip_description' => FALSE,
//        );
//
//        $result = array();
//        foreach( $rows as $row ){
//            $transaction = userpoints_transaction_load( $row->txn_id );
//            $result[ ] = scoga_create_transaction_vo_from_std_class( $transaction );
//        }
//
//        return $result;
//    }

    /**
     * @param $transaction array
     *
     * @return PointsTransaction
     */
    function scoga_create_transaction_vo_from_assoc_arr( $transaction ){
        $output = new PointsTransaction();
        $output->txn_id = $transaction['txn_id'];
        $output->uid = $transaction['uid'];
        $output->points = $transaction['points'];
        $output->description = $transaction['description'];
        $output->time_stamp = $transaction['time_stamp'];

        return $output;
    }

    /**
     * @param $transaction array
     *
     * @return PointsTransaction
     */
    function scoga_create_transaction_vo_from_std_class( $transaction ){
        $output = new PointsTransaction();
        $output->txn_id = $transaction->txn_id;
        $output->uid = $transaction->uid;
        $output->points = $transaction->points;
        $output->description = $transaction->description;
        $output->time_stamp = $transaction->time_stamp;

        return $output;
    }

    /**
     * @param array $transaction
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
    function scoga_transfer_transaction_points_to_team( $transaction ){

        if( intval( $transaction[ 'tid' ] ) === scoga_get_current_userpoints_category_tid() ){
            module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );
            $user_account = user_load( $transaction[ 'uid' ] );
            $team_nid = scoga_get_eid_from_field( $user_account, 'field_user_team', array( 'entity_type' => 'user' ) );
            $campaignteam_node = scoga_get_latest_campaignteam_entity( scoga_get_current_campaign_nid(), $team_nid );
            if( $campaignteam_node ){
                $field_name = 'field_campaignteam_totalpoints';
                $total_points = scoga_get_field_value( $campaignteam_node, $field_name );
                scoga_set_field_value( $campaignteam_node, $field_name, $total_points + $transaction[ 'points' ] );
                node_save( $campaignteam_node );
            }
        }
    }

    /**
     * @param $iteration
     */
    function scoga_create_userpoints_category( $iteration ){
        $name = $iteration . ' score';
        $userpoints_vid = scoga_get_userpoints_vid();
        $score_tid = scoga_get_score_tid();
        $score_children = taxonomy_get_children( $score_tid );
        foreach( $score_children as $score_child_term ){
            if( $score_child_term->name == $name ){
                return $score_child_term;
            }
        }
        $term = new stdClass();
        $term->vid = $userpoints_vid;
        $term->name = $iteration;
        $term->parent = $score_tid;
        taxonomy_term_save( $term );
        return $term;
    }

    /**
     * @param $uid
     * @param $points
     * @param $reason
     *
     * @return array
     */

    function scoga_award_points_to_user( $uid, $points, $reason ){
        $params = array(
            'uid'           => $uid,
            'points'        => $points,
            'tid'           => scoga_get_current_userpoints_category_tid(),
            'operation'     => $reason,
            'description'   => $reason,
            'moderate'      => FALSE,
            'display'       => TRUE,
        );
        $temp = userpoints_userpointsapi( $params );
        if( $temp[ 'status' ] ){
            return $temp[ 'transaction' ];
        }
        return array();
    }

