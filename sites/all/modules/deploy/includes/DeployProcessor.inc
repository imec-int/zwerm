<?php

/**
 * The interface for deployment processors.
 */
interface DeployProcessor {

  /**
   * Constructor for a deploy processor.
   *
   * @param DeployAggregator $aggregator
   *   The aggregator object that will be processed.
   *
   * @param array $config
   *   An associative array of configuration settings for the processor.
   */
  public function __construct(DeployAggregator $aggregator, Array $config = array());

  /**
   * Main process method that should hand over the plan to the endpoint.
   *
   * @param string $endpoint_name
   *   The name of the endpoint being deployed to.
   */
  public function process($endpoint_name);

  /**
   * Cleanup method where the processors can cleanup after itself.
   */
  public function cleanup();

  /**
   * Configuration form.
   *
   * @param array $form_state
   *   The complete form state.
   */
  public function configForm(&$form_state);

}
