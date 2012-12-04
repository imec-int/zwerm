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
        );

        public $nid;
        public $uid;
        public $timestamp;
        public $description;
        public $title;

    }

    function scoga_get_messages_vos(){
        $nids = scoga_get_message_nids();
        $vos = scoga_get_messages_vos_by_nids( $nids );
        return $vos;
    }

    /**
     * @return int
     */
    function scoga_get_last_message_nid(){
        $entity_type = 'node';
        $query = new EntityFieldQuery();
        $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', Message::$types, 'IN' )
            ->propertyOrderBy( 'nid', 'DESC' )
            ->range( 0, 1 );
        $result = $query->execute();

        if( $result && array_key_exists( $entity_type, $result ) ){
            $temp = array_keys( $result[ $entity_type ] );
            return $temp[ 0 ];
        }

        return 0;
    }

    /**
     * @param null $nid
     *
     * @return array
     */
    function scoga_get_message_vos_after_nid( $nid = NULL ){
        if( $nid == NULL ){
            $nid = 0;
        }
        $nids = scoga_get_message_nids_after_nid( $nid );

        $output = array();
        if( $nids ){
            foreach( $nids as $message_nid ){
                $vo = scoga_get_message_vo_by_nid( $message_nid );
                $output[ ] = $vo;
            }
        }

        return $output;
    }

    /**
     * @param $nid
     *
     * @return Message
     */
    function scoga_get_message_vo_by_nid( $nid ){
        $entity_type = 'node';
        $message_node = node_load( $nid );

        $output = new Message();
        $output->nid = $message_node->nid;
        $output->uid = $message_node->uid;
        $output->description = check_markup( scoga_get_field_value( $message_node, 'body' ), FLASH_HTML_FORMAT, '', TRUE );
        $output->timestamp = $message_node->created;
        $output->title = $message_node->title;

        return $output;
    }

    /**
     * returns all message nids (higher than optional parameter <code>$nid</code>
     *
     * @param int [$nid=0]
     *
     * @return array|bool
     */
    function scoga_get_message_nids_after_nid( $nid ){

        $entity_type = 'node';
        $query = new EntityFieldQuery();
        $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_MESSAGES_NODETYPE )
            ->propertyCondition( 'status', '1', '=' )
            ->propertyCondition( 'nid', $nid, '>' )
            ->propertyOrderBy( 'nid' );
        $result = $query->execute();


        if( $result && array_key_exists( $entity_type, $result ) ){
            return array_keys( $result[ $entity_type ] );
        }

        return FALSE;

    }

    function scoga_get_message_nids(){
        $entity_type = 'node';
        $query = new EntityFieldQuery();
        $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_MESSAGES_NODETYPE )
            ->propertyCondition( 'status', '1', '=' )
            ->propertyOrderBy( 'nid' );
        $result = $query->execute();


        if( $result && array_key_exists( $entity_type, $result ) ){
            return array_keys( $result[ $entity_type ] );
        }

        return array();
    }

    /**
     * @param     $message
     * @param     $title
     * @param     $uid
     *
     * @return stdClass
     */
    function scoga_create_message_entity( $message, $title, $uid ){
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
        $node = node_submit( $node );
        node_save( $node );
        return $node;
    }

    function scoga_get_messages_vos_by_nids( $nids ){
        return scoga_get_output( $nids, 'scoga_get_message_vo_by_nid' );
    }