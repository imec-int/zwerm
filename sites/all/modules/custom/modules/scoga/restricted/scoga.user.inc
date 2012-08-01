<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 31/07/12
 * Time: 15:33
 * To change this template use File | Settings | File Templates.
 */

    function scoga_handle_user_insert( $account ){
        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        scoga_award_default_credits_to_player( $account->uid );
    }
