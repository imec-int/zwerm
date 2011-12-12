<?php

/**
 * Interface for all deploy service plugins.
 */
interface DeployService {

  /**
   * Constructor for a deploy service.
   *
   * @param DeployPlan $plan
   *   The plan being deployed.
   *
   * @param array $config
   *   An associative array containing the settings for the service plugin.
   */
  public function __construct(DeployPlan $plan, Array $config = array());

  /**
   * Deploy a plan.
   *
   * @param Traverable $iterator
   *   This will usually be an object of a subclass of DeployAggregatorBase
   */
  public function deploy(Traversable $iterator);

  /**
   * Configuration form.
   *
   * @param array $form_state
   *   The complete form state.
   */
  public function configForm(&$form_state);

}
