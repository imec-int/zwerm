<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 31/07/12
 * Time: 14:51
 * To change this template use File | Settings | File Templates.
 */


    function scoga_handle_permission(){
        return array(
            SCOGA_PERM_REST_EXECUTE_CREATE_CHECKIN  => array(
                'title'       => t( 'Create "Checkin" node' ),
                'description' => t( 'Create a node of content type "Checkin" through the REST service.<br/>' ),
            ),
            SCOGA_PERM_REST_EXECUTE_REGISTER_READER => array(
                'title'       => t( 'Register RFID reader' ),
                'description' => t( 'Register an RFID reader to be used with SCOGA' ),
            ),
            SCOGA_PERM_REST_EXECUTE_REGISTER_CARD   => array(
                'title'       => t( 'Register RFID card' ),
                'description' => t( 'Register an RFID card to be used with SCOGA' ),
            ),
        );
    }
