<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 06/12/12 - 17:19
 */

    function scoga_send_admin_mail( $message, $subject ){

        $to = 'camille.reynders@iminds.be';

        $success = mail( $to, $subject, $message );

        if( $success ){
            return 'mail sent';
        }

        return 'mail failed';
    }