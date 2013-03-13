<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 08/05/12
     * Time: 11:40
     * To change this template use File | Settings | File Templates.
     */

    class Message {
        static public $types = array(
            SCOGA_MESSAGES_NODETYPE,
            SCOGA_ARTICLE_NODETYPE,
            SCOGA_POLL_NODETYPE,
            SCOGA_EVENT_NODETYPE,
            SCOGA_GEOCHALLENGE_NODETYPE,
            SCOGA_GENERIC_ASSIGNMENT,
            SCOGA_QUESTION_NODETYPE,
        );

        public $nid;
        public $uid;
        public $timestamp;
        public $description;
        public $title;
        public $type;

    }

    /**
     * @param int $nid
     *
     * @return array
     */
    function scoga_get_message_vos_after_nid( $nid = 0 ){
        $nids = scoga_get_message_nids_after_nid( $nid );
        $vos = scoga_get_message_vos_by_nids( $nids );
        return $vos;
    }

    function scoga_get_message_vos_by_nids( $nids ){
        return scoga_get_output( $nids, 'scoga_get_message_vo_by_nid' );
    }
    /**
     * @param $nid
     *
     * @return Message
     */
    function scoga_get_message_vo_by_nid( $nid ){
        $entity_type = 'node';
        $message_node = node_load( $nid );
        return scoga_create_message_vo( $message_node );
    }

    /**
     * returns all message nids (higher than optional parameter <code>$nid</code>
     *
     * @param int [$nid=0]
     *
     * @return array
     */
    function scoga_get_message_nids_after_nid( $nid = 0 ){
        $campaign_nid = scoga_get_current_campaign_nid();
        $entity_type = 'node';
        $query =  db_select( 'node', 'node_table' );
        $query->leftJoin( 'field_data_field_campaign', 'campaign_field_table', 'node_table.nid=campaign_field_table.entity_id');
        $query
            ->fields( 'node_table', array( 'nid' ) )
            ->condition( 'node_table.type', Message::$types, 'IN' )
            ->condition( 'node_table.nid', $nid, '>' )
            ->condition( 'node_table.status', 1 )
            ->where( '( campaign_field_table.field_campaign_target_id=' . $campaign_nid . ') OR ( campaign_field_table.field_campaign_target_id IS NULL )')
            ->orderBy( 'node_table.nid', 'DESC' )
        ;
        if(  $nid <= 0 ){
            $query->range( 0, 5 );
        }
        $result = $query->execute();
        $nids = array();
        foreach( $result as $record ) {
            //dsm($record);
            $nids[] = $record->nid;
        }

        return $nids;
    }

    function scoga_create_message_vo( $message_node ){
        $output = new Message();
        $output->nid = $message_node->nid;
        $output->uid = $message_node->uid;
        $output->description = check_markup( scoga_get_field_value( $message_node, 'body' ), FLASH_HTML_FORMAT, '', TRUE );
        $output->timestamp = $message_node->created;
        $output->title = $message_node->title;
        $output->type = $message_node->type;
        return $output;
    }

//    function scoga_get_message_nids(){
//        $entity_type = 'node';
//        $query = new EntityFieldQuery();
//        $query
//            ->entityCondition( 'entity_type', $entity_type )
//            ->entityCondition( 'bundle', SCOGA_MESSAGES_NODETYPE )
//            ->propertyCondition( 'status', '1', '=' )
//            ->propertyOrderBy( 'nid' );
//        $result = $query->execute();
//
//
//        if( $result && array_key_exists( $entity_type, $result ) ){
//            return array_keys( $result[ $entity_type ] );
//        }
//
//        return array();
//    }

    /**
     * @param     $message
     * @param     $title
     * @param     $uid
     *
     * @return stdClass
     */
    function scoga_create_message_entity( $message, $title, $uid, $campaign_nid ){
        $lang = LANGUAGE_NONE;
        $node = new stdClass();
        $node->type = SCOGA_MESSAGES_NODETYPE;
        node_object_prepare( $node );
        $node->body[ $lang ][ 0 ] = array(
            'value' => $message
        );
        $node->title = $title;
        $node->uid = $uid;
        $node->status = '1';
        $node->language = $lang;
        scoga_set_eid_in_field( $node, 'field_campaign', $campaign_nid );
        $node = node_submit( $node );
        node_save( $node );
        return $node;
    }

