<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 27/04/12
     * Time: 14:46
     * To change this template use File | Settings | File Templates.
     */

    function scoga_get_wisheditem_nids_for_uid( $uid ){
        $entity_type = 'node';
        $query = new EntityFieldQuery();

        $result = $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_WISHEDITEM_NODETYPE )
            ->propertyCondition( 'uid', $uid )
            ->propertyCondition( 'status', '1' )
            ->propertyOrderBy( 'title', 'ASC' )
            ->fieldCondition( 'field_wisheditem_state', 'value', 'open', '=' )
            ->execute();

        if( array_key_exists( $entity_type, $result ) ){
            return array_keys( $result[ $entity_type ] );
        }

        return array();

    }

    /**
     * @param     $node
     * @param int $old_award_value
     */
    function scoga_sync_credits_for_wisheditem( $node, $old_award_value = 0 ){
        //[!] negative value
        $award = $old_award_value - intval( scoga_get_field_value( $node, 'field_wisheditem_award' ) );
        $params = array(
            'uid'           => $node->uid,
            'points'        => $award,
            'tid'           => scoga_get_credits_tid(),
            'operation'     => 'sync',
            'description'   => 'sync credits for wished item',
            'moderate'      => FALSE,
            'display'       => TRUE,
        );
        $result = userpoints_userpointsapi( $params );

        $award = -$award;
        $params = array(
            'uid'           => $node->uid,
            'points'        => $award,
            'operation'     => 'sync',
            'description'   => t('sync score for wished item'),
            'moderate'      => FALSE,
            'display'       => TRUE,
        );
        $result = userpoints_userpointsapi( $params );
    }

    /**
     * @param $wisheditem_node
     * @param $state
     */
    function scoga_set_wisheditem_state( $wisheditem_node, $state ){
        $wisheditem_node->field_wisheditem_state[ LANGUAGE_NONE ][ 0 ][ 'value' ] = $state;
        node_save( $wisheditem_node );
    }

    /**
     * @param      $wisheditem_node
     * @param null $campaign_nid
     */
    function scoga_set_campaign_of_wisheditem( $wisheditem_node, $campaign_nid = NULL ){
        if( $campaign_nid == NULL ){
            $campaign_nid = scoga_get_current_campaign_nid();
        }
        //field_attach_insert( 'node', $wisheditem_node );
        scoga_set_eid_in_field( $wisheditem_node, 'field_wisheditem_campaign', $campaign_nid );
    }

    /**
     *
     */
    function scoga_close_all_open_wisheditems_of_campaign( $campaign_nid ){
        $entity_type = 'node';
        $query = new EntityFieldQuery();
        $result = $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_WISHEDITEM_NODETYPE )
            ->fieldCondition( 'field_wisheditem_state', 'value', 'open', '=' )
            ->fieldCondition( 'field_wisheditem_campaign', 'target_id', $campaign_nid, '=' )
            ->execute();

        if( $result && array_key_exists( $entity_type, $result ) ){
            $nids = array_keys( $result[ $entity_type ] );
            foreach( $nids as $nid ){
                $node = node_load( $nid );
                scoga_set_wisheditem_state( $node, 'failed' );
                $node->status = '0';
                node_save( $node );
            }
        }
    }

    /**
     * @param $wishfulfilled_node
     *
     * @return bool|mixed
     */
    function scoga_award_wishfulfilled_to_player( $wishfulfilled_node ){
        $wisheditem_nid = scoga_get_eid_from_field( $wishfulfilled_node, 'field_wishfulfilled_wisheditem' );
        $receiver_uid = scoga_get_eid_from_field( $wishfulfilled_node, 'field_wishfulfilled_fulfiller' );

        $wisheditem_node = node_load( $wisheditem_nid );
        $award = intval( scoga_get_field_value( $wisheditem_node, 'field_wisheditem_award' ) );
        $params = array(
            'uid'           => $receiver_uid,
            'points'        => $award,
            'operation'     => 'insert',
            'description'   => 'add credits for fulfilling wished item',
            'moderate'      => FALSE,
            'display'       => TRUE,
        );
        $result = userpoints_userpointsapi( $params );
        return $wisheditem_node;
    }