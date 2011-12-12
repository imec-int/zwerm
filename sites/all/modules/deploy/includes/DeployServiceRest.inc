<?php

/**
 * Base class for REST-based service plugins.
 * 
 * This is not a full plugin, but an abstract class that plugins can extend.
 */
class DeployServiceRest implements DeployService {

  /**
   * Configuration options.
   *
   * @var array
   */
  public $config = array();

  /**
   * An associative array of http headers for the REST request.
   *
   * @var array
   */
  public $headers = array();

  /**
   * The deployment plan being deployed.
   *
   * @var DeployPlan
   */
  protected $plan;

  /**
   * Constructor for a service plugin.
   *
   * @param DeployPlan $plan
   *   The deployment plan being deployed.
   *
   * @param array $config
   *   An associative array of configuration settings for the service plugin.
   */
  public function __construct(DeployPlan $plan, Array $config = array()) {
    $this->config += array(
      'debug' => FALSE,
      'url' => '',
      'headers' => array(),
    );
    $this->config = array_merge($this->config, $config);
    $this->plan = $plan;
  }

  /**
   * Deploy a plan using this service.
   *
   * @param Traversable $iterator
   *   This will usually be an object of a subclass of DeployAggregatorBase.
   */
  public function deploy(Traversable $iterator) {}

  /**
   * Makes a http PUT request to deploy an item.
   *
   * @param string $uuid
   *   The uuid of the entity being deployed.
   *
   * @param string @data
   *   A string of data, which will be the payload of the request.
   *
   * @param string $format
   *   The format of the data, e.g. 'json' or 'xml'.
   */
  public function httpPut($uuid, $data, $format) {
     // TODO: Consider making the resource path configurable. For now, the
     // default UUID Services path is OK, since it covers 99% of the use cases.
    $url = $this->config['url'] . '/uuid_entity/' . $uuid . '.' . $format;

    $options = array(
      'method' => 'PUT',
      'headers' => $this->config['headers'],
      'data' => $data
    );

    if ($this->config['debug']) {
      watchdog('deploy', 'Request URL: %url', array('%url' => $url), WATCHDOG_DEBUG);
      watchdog('deploy', 'Request options: <pre>@options</pre>', array('@options' => print_r($options, TRUE)), WATCHDOG_DEBUG);
    }

    $response = drupal_http_request($url, $options);

    if ($this->config['debug']) {
      watchdog('deploy', 'Request response: <pre>@response</pre>', array('@response' => print_r($response, TRUE)), WATCHDOG_DEBUG);
    }
    if (isset($response->error)) {
      // TODO: Throw exception.
      watchdog('deploy', 'Request response error: %code %error', array('%code' => $response->code, '%error' => $response->error), WATCHDOG_ERROR);
    }
    return $response;
  }

  /**
   * Configuration form.
   *
   * @param array $form_state
   *   The complete form state.
   */
  public function configForm(&$form_state) {
    return array(
      'url' => array(
        '#type' => 'textfield',
        '#title' => t('Endpoint URL'),
        '#description' => t('Enter endpoint URL. Example: %url', array('%url' => 'http://example.com/api')),
        '#default_value' => $this->config['url'],
      ),
    );
  }

}
