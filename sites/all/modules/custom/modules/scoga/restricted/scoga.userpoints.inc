<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 23/11/12 - 11:15
 */

    /**
     * @param array $params the original $params array as sent to userpoints_userpointsapi
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
    function scoga_handle_userpoints_after( $params = array()){

        if( $params[ 'tid' ] == scoga_get_current_userpoints_category_tid() ){
            module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
            scoga_set_player_active( $params['uid'] );
            module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
            scoga_transfer_transaction_points_to_team( $params );
        }
    }