<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 27/04/12
 * Time: 18:48
 * To change this template use File | Settings | File Templates.
 */


    function scoga_wishlist_settings_form( $form, &$form_state ){
        //cool down
        $form_elem_name = SCOGA_SETTING_MAX_WISHITEM_CREDIT;
        $form[ $form_elem_name ] = array(
            '#type'          => 'textfield',
            '#title'         => t( 'Max credit value for wished items' ),
            '#description'   => t( 'Maximum credit value for wished items' ),
            '#default_value' => variable_get( $form_elem_name, 10 ),
            '#size'          => 4,
            '#required'      => TRUE
        );

        $form[ 'submit' ] = array(
            '#type'  => 'submit',
            '#value' => t( 'Save settings' ),
        );

        return $form;
    }

    function scoga_wishlist_settings_form_submit( $form, &$form_state ){

        $settings = array(
            SCOGA_SETTING_MAX_WISHITEM_CREDIT,
        );

        foreach( $settings as $form_elem_name ){
            variable_set( $form_elem_name, $form_state[ 'values' ][ $form_elem_name ] );
        }

        drupal_set_message( t( 'The SCOGA wishlist settings have been saved.' ) );
    }

