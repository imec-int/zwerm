<?php

/**
 * Class for basic memory-based processing
 */
class DeployProcessorMemory implements DeployProcessor {

  /**
   * The aggregator containing the items to be processed.
   *
   * @var DeployAggregator
   */
  public $aggregator = NULL;

  /**
   * Configuration options.
   *
   * @var array
   */
  public $config = array();

  public function __construct(DeployAggregator $aggregator, Array $config = array()) {
    $this->aggregator = $aggregator;
    $this->config += array(
      'debug' => FALSE,
    );
    $this->config = array_merge($this->config, $config);
  }

  public function process($endpoint_name) {
    if ($endpoint = deploy_endpoint_load($endpoint_name)) {
      $endpoint->deploy($this->aggregator->plan, $this->aggregator);
      drupal_set_message(t('Plan %plan has been deployed to %endpoint.', array('%plan' => $this->aggregator->plan->title, '%endpoint' => $endpoint->title)));
    }
  }

  public function cleanup() {}

  public function configForm(&$form_state) {
    // We have no settings for this processor.
    return array();
  }
}
