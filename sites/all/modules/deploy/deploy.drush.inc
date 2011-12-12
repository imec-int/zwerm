<?php

/**
 * @file
 * Provides Drush integration for Deploy.
 */

/**
 * Implements hook_drush_command().
 */
function deploy_drush_command() {
  $commands = array();

  $commands['deploy-plan'] = array(
    'description' => 'Deploy all content from a plan to all its endpoints.',
    'drupal dependencies' => array('deploy'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    'arguments' => array(
      'plan' => 'The plan to deploy.'
    ),
    'examples' => array(
      'drush deploy my_plan' => 'Deploy all content from "my_plan" to all its endpoints.',
    ),
    'aliases' => array('deploy', 'dp'),
  );

  return $commands;
}

/**
 * Implements hook_drush_help().
 */
function deploy_drush_help($section) {
  switch ($section) {
    case 'drush:deploy-plan':
      return dt('Deploy all content from a plan to all its endpoints.');
  }
}

/**
 * Command callback.
 */
function drush_deploy_plan($name) {
  if ($plan = deploy_plan_load($name)) {
    $plan->deploy();
    return;
  }
  drush_set_error(dt('Cannot deploy non-existent plan @name'), array('@name' => $name));
}
