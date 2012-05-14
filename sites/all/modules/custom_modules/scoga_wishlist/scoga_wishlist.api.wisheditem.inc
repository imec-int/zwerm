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
            ->execute()
        ;

        return array_keys( $result[ $entity_type ] );

    }

    function scoga_sync_credits_for_wisheditem( $node, $old_award_value = 0 ){
        //[!] negative value
        $award_field = field_get_items( 'node', $node, 'field_wisheditem_award' );
        $award = $old_award_value - intval( $award_field[ 0 ][ 'value' ] );
        $params = array(
            'uid'           => $node->uid,
            'points'        => $award,
            'tid'           => scoga_get_credits_tid(),
            'operation'     => 'sync',
            'description'   => 'sync credits for wished item',
            'moderate'      => FALSE,
            'display'       => TRUE,
        );
        $result = userpoints_userpointsapi($params);

        $award = - $award;
        $params = array(
            'uid'           => $node->uid,
            'points'        => $award,
            'operation'     => 'sync',
            'description'   => 'sync score for wished item',
            'moderate'      => FALSE,
            'display'       => TRUE,
        );
        $result = userpoints_userpointsapi($params);
    }

    function scoga_set_wisheditem_state( $wisheditem_node, $state ){
        $wisheditem_node->field_wisheditem_state[ LANGUAGE_NONE ][ 0 ][ 'value' ] = $state;
        node_save( $wisheditem_node );
    }

    function scoga_set_campaign_of_wisheditem( $wisheditem_node, $campaign_nid = NULL ){
        if( $campaign_nid == NULL ){
            $campaign_nid = scoga_get_current_campaign_nid();
        }
        //field_attach_insert( 'node', $wisheditem_node );
        $wisheditem_node->field_wisheditem_campaign[ LANGUAGE_NONE ][ 0 ][ 'target_id' ] = $campaign_nid;
    }

    function scoga_close_all_open_wisheditems(){
        //TEMPORARY FIX
        //TODO: should filter wished items for current campaign
        $entity_type = 'node';
        $query = new EntityFieldQuery();
        $result = $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_WISHEDITEM_NODETYPE )
            ->fieldCondition( 'field_wisheditem_state', 'value', 'open', '=')
            ->execute()
        ;

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