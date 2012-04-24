<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 20/04/12
 * Time: 15:04
 * To change this template use File | Settings | File Templates.
 */



function scoga_core_settings_form( $form, &$form_state ){

    //cool down
    $form_elem_name = SCOGA_SETTINGS_CHECKIN_COOLDOWN;
    $form[ $form_elem_name ] = array(
        '#type' => 'textfield',
        '#title' => t('Cooldown for "checkin"' ),
        '#description' => t('Define cooldown period for "checkins",in seconds, 0 for unlimited.' ),
        '#default_value' => variable_get( $form_elem_name, 0 ),
        '#size' => 10,
        '#required' => TRUE
    );

    //combo time frame
    $form_elem_name = SCOGA_SETTINGS_COMBOCHECKIN_TIMEFRAME;
    $form[ $form_elem_name ] = array(
        '#type' => 'textfield',
        '#title' => t('Timeframe for combo checkins' ),
        '#description' => t('Define timeframe for combo checkins,in seconds, 0 for unlimited.' ),
        '#default_value' => variable_get( $form_elem_name, 0 ),
        '#size' => 10,
        '#required' => TRUE
    );

    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save settings'),
    );

    return $form;
}

function scoga_core_settings_form_submit( $form, &$form_state ){
    //cooldown
    $form_elem_name = SCOGA_SETTINGS_CHECKIN_COOLDOWN;
    variable_set( $form_elem_name, $form_state['values'][$form_elem_name] );

    $form_elem_name = SCOGA_SETTINGS_COMBOCHECKIN_TIMEFRAME;
    variable_set( $form_elem_name, $form_state['values'][$form_elem_name] );

    drupal_set_message( t('The SCOGA settings have been saved.') );
}
