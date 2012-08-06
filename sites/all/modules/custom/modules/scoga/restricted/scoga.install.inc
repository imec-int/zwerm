<?php
/**
 *
 * User: creynder
 * Date: 31/07/12
 * Time: 14:47
 * To change this template use File | Settings | File Templates.
 */


    //N.B. all default settings are handled through the variable module, see scoga.variable.inc

    function scoga_handle_install(){
        $vid = scoga_get_userpoints_vid();

        //create credits term
        $credits_term = scoga_create_term( $vid, t( 'Credits' ) );
        scoga_set_credits_tid( $credits_term->tid );

        //create score term

        //TODO: create score term
        $score_term = scoga_create_term( $vid, t( 'Score' ) );

    }

    function scoga_handle_uninstall(){

    }