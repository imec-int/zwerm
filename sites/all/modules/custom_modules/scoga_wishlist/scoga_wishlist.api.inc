<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 27/04/12
 * Time: 14:54
 * To change this template use File | Settings | File Templates.
 */
    define( 'SCOGA_WISHEDITEM_NODETYPE', 'nodetype_wished_item' );
    define( 'SCOGA_WISHFULFILLED_NODETYPE', 'nodetype_wish_fulfilled' );
    define( 'SCOGA_SETTING_MAX_WISHITEM_CREDIT', 'scoga_setting_max_wishitem_credit' );

    function scoga_get_max_wishitem_credits(){
        return intval( variable_get( SCOGA_SETTING_MAX_WISHITEM_CREDIT, 10 ) );
    }

