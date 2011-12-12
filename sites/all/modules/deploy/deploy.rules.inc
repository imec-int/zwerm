<?php

/**
 * @file
 * Rules implementations.
 */

/**
 * Implements hook_rules_data_info().
 */
function deploy_rules_data_info() {
  return array(
    'deploy_plan' => array(
      'label' => t('deploy plan'),
      'group' => t('Deploy'),
      'ui class' => 'RulesDataUIText',
    ),
  );
}

/**
 * Implements hook_rules_action_info().
 */
function deploy_rules_action_info() {
  $entity_types = entity_get_info();
  $entity_type_options = array_keys($entity_types);

  return array(
    'deploy_rules_action_deploy_plan' => array(
      'label' => t('Deploy a plan'),
      'group' => t('Deploy'),
      'parameter' => array(
        'plan' => array(
          'type' => 'deploy_plan',
          'label' => t('Plan'),
          'options list' => 'deploy_rules_plan_get_options'
        ),
      ),
    ),
    'deploy_rules_action_add_to_managed_plan' => array(
      'label' => t('Add an entity to a managed deployment plan'),
      'group' => t('Deploy'),
      'parameter' => array(
        'plan' => array(
          'type' => 'deploy_plan',
          'label' => t('Plan'),
          'options list' => 'deploy_rules_manager_plan_get_options'
        ),
        'entity' => array(
          'type' => $entity_type_options,
          'label' => t('Entity'),
          'wrapped' => TRUE,
        ),
      ),
    ),
  );
}

/**
 * Option callback.
 */
function deploy_rules_plan_get_options() {
  return deploy_plan_get_options(array('fetch_only' => FALSE));
}

/**
 * Option callback.
 */
function deploy_rules_manager_plan_get_options() {
  return deploy_manager_plan_get_options(array('fetch_only' => FALSE));
}

/**
 * Action callback for the "Deploy a plan" action.
 */
function deploy_rules_action_deploy_plan($name) {
  if ($plan = deploy_manager_plan_load($name)) {
    $plan->deploy();
    return;
  }
  watchdog('deploy', 'Cannot deploy non-existent plan @name', array('@name' => $name), WATCHDOG_ERROR);
}

/**
 * Action callback for the "Add to deploy plan" action.
 */
function deploy_rules_action_add_to_managed_plan($plan_name, $entity_wrapper) {
  if (!deploy_manager_plan_load($plan_name)) {
    watchdog('deploy manager', 'Attempted to add to a non-existent deploy plan or one that cannot be arbitrarily added to: @plan', array('@plan' => $plan_name));
    return;
  }
  $entity_type = $entity_wrapper->type();
  $entity = $entity_wrapper->value();
  deploy_manager_add_to_plan($plan_name, $entity_type, $entity);
}
