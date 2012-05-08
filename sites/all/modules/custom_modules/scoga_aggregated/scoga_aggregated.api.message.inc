<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 08/05/12
 * Time: 11:40
 * To change this template use File | Settings | File Templates.
 */

    function scoga_get_last_message_nid(){
        $entity_type = 'node';
        $query = new EntityFieldQuery();
        $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_MESSAGES_NODETYPE )
            ->propertyOrderBy( 'nid', 'DESC' )
            ->range( 0, 1 )
        ;
        $result = $query->execute();

        if( $result && array_key_exists( $entity_type, $result ) ){
            $temp = array_keys( $result[ $entity_type ] );
            return $temp[ 0 ];
        }

        return 0;
    }

    function scoga_get_message_vos_after_nid( $nid = NULL ){
        if( $nid == NULL ){
            $nid = 0;
        }
        $nids = scoga_get_message_nids_after_nid( $nid );

        dd( $nids, 'nids' );

        $output = array();
        if( $nids ){
            foreach( $nids as $message_nid ){
                $vo = scoga_get_message_vo_by_nid( $message_nid );
                $output[] = $vo;
            }
        }

        return $output;
    }

    function scoga_get_message_vo_by_nid( $nid ){
        $entity_type = 'node';
        $message_node = node_load( $nid );

        $points_values = field_get_items( $entity_type, $message_node, 'field_logmessages_points' );
        $description_values = field_get_items( $entity_type, $message_node, 'body' );
        $output = array();
        $output[ 'nid' ] = $message_node->nid;
        $output[ 'uid' ] = $message_node->uid;
        $output[ 'points' ] = $points_values[ 0 ][ 'value' ];
        $output[ 'timestamp' ] = $message_node->created;
        $output[ 'description'] = $description_values[ 0 ][ 'value' ];
        $output[ 'title' ] = $message_node->title;

        return $output;
    }

    /**
     * returns all message nids (higher than optional parameter <code>$nid</code>
     * @param int [$nid=0]
     * @return array|bool
     */
    function scoga_get_message_nids_after_nid( $nid ){

        $entity_type = 'node';
        $query = new EntityFieldQuery();
        $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_MESSAGES_NODETYPE )
            ->propertyCondition( 'nid', $nid, '>' )
            ->propertyOrderBy( 'nid' )
        ;
        $result = $query->execute();


        if( $result && array_key_exists( $entity_type, $result ) ){
            return array_keys( $result[ $entity_type ] );
        }

        return FALSE;

    }

    function scoga_create_message_entity( $message, $title, $uid, $points = 0 ){
        $lang = LANGUAGE_NONE;
        $node = new stdClass();
        $node->type = SCOGA_MESSAGES_NODETYPE;
        node_object_prepare( $node );
        $node->field_logmessages_points[ $lang ][ 0 ] = array(
            'value' => $points
        );
        $node->body[ $lang ][ 0 ] = array(
            'value' => $message
        );
        $node->title = $title;
        $node->uid = $uid;
        $node->status  = '1';
        $node->language = $lang;
        $node = node_submit( $node );
        node_save( $node );
        return $node;
    }