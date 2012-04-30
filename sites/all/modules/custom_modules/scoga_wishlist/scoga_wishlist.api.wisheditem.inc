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
