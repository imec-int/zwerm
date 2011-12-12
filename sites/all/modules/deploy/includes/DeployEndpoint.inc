<?php

/**
 * Class representing a deployment endpoint.
 */
class DeployEndpoint {

  /**
   * Whether debug mode is enabled for this endpoint.
   *
   * @var boolean
   */
  public $debug = FALSE;

  /**
   * The name of the service plugin to be used to deploy to this endpoint.
   *
   * @var string
   */
  public $service_plugin = NULL;

  /**
   * An associative array of configuration settings to pass to the service
   * object's constructor. Allowable keys will depend on the plugin being used.
   *
   * @var array
   */
  public $service_config = array();

  /**
   * The service object that will be used to push to this endpoint.
   *
   * @var DeployService
   */
  public $service = NULL;

  /**
   * The name of the authenticator plugin to be used for this endpoint.
   *
   * @var string
   */
  public $authenticator_plugin = NULL;

  /**
   * An associative array of configuration settings to pass to the authenticator
   * object's constructor. Allowable keys will depend on the plugin being used.
   *
   * @var array
   */
  public $authenticator_config = array();

  /**
   * The authenticator object that will be used to push to this endpoint.
   *
   * @var DeployAuthenticator
   */
  public $authenticator = NULL;

  /**
   * Performs a deployment to the endpoint.
   *
   * @param DeployPlan $plan
   *   The plan being deployed.
   *
   * @param Traversable $iterator
   *   Usually this will be an object from a subclass of DeployAggregatorBase.
   */
  public function deploy(DeployPlan $plan, Traversable $iterator) {
    // Since the CTools Export API is declarative by nature, we can't realy on
    // contructor injection and deploy_endpoint_create() as the only factory.
    if (!empty($this->service_plugin)) {
      $service_config = $this->service_config + array('debug' => $this->debug);
      $this->service = new $this->service_plugin($plan, $service_config);
    }
    if (!empty($this->authenticator_plugin)) {
      $authenticator_config = $this->authenticator_config + array('debug' => $this->debug);
      $this->authenticator = new $this->authenticator_plugin($this->service, $authenticator_config);
    }

    $this->authenticator->deploy($iterator);
  }
}
