<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 02/05/12
 * Time: 15:19
 * To change this template use File | Settings | File Templates.
 */
    /**
     * @param $wishfulfilled_node stdClass node of nodetype_wished_item
     */
    function scoga_award_wishfulfilled_to_player( $wishfulfilled_node ){
        $wisheditem_value = field_get_items( 'node', $wishfulfilled_node, 'field_wishfulfilled_wisheditem' );
        $wisheditem_nid = $wisheditem_value[ 0 ][ 'target_id' ];
        $wisheditem_node = node_load( $wisheditem_nid );
        $receiver_value = field_get_items( 'node', $wishfulfilled_node, 'field_wishfulfilled_fulfiller' );
        $receiver_uid = $receiver_value[ 0 ][ 'target_id' ];

        $award_field = field_get_items( 'node', $wisheditem_node, 'field_wisheditem_award' );
        $award = intval( $award_field[ 0 ][ 'value' ] );
        $params = array(
            'uid'           => $receiver_uid,
            'points'        => $award,
            'operation'     => 'insert',
            'description'   => 'add credits for fulfilling wished item',
            'moderate'      => FALSE,
            'display'       => TRUE,
        );
        $result = userpoints_userpointsapi($params);
        return $wisheditem_node;
    }