<?php
/**
 * @file
 * deploy_example.deploy_endpoints.inc
 */

/**
 * Implements hook_deploy_endpoints_default().
 */
function deploy_example_deploy_endpoints_default() {
  $export = array();

  $endpoint = new DeployEndpoint;
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 1;
  $endpoint->name = 'deploy_example_endpoint';
  $endpoint->title = 'Simple example endpoint';
  $endpoint->description = 'Example remote endpoint not using any authentication.';
  $endpoint->debug = 1;
  $endpoint->authenticator_plugin = 'DeployAuthenticatorSession';
  $endpoint->authenticator_config = array(
    'username' => '',
    'password' => '',
  );
  $endpoint->service_plugin = 'DeployServiceRestJSON';
  $endpoint->service_config = array(
    'url' => 'http://example.com/api',
  );
  $export['deploy_example_endpoint'] = $endpoint;

  return $export;
}
