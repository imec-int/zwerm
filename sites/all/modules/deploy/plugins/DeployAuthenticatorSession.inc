<?php

/**
 * Authentication class that uses session authentication.
 */
class DeployAuthenticatorSession implements DeployAuthenticator {

  /**
   * Configuration options.
   *
   * @var array
   */
  public $config = array();

  public function __construct(DeployService $service, Array $config = array()) {
    $this->service = $service;
    $this->config += array(
      'debug' => FALSE,
      'username' => '',
      'password' => '',
    );
    $this->config = array_merge($this->config, $config);
  }

  public function deploy(Traversable $iterator) {
    // Only authenticate if we've got a username and password. This allows for
    // deployment as an anonymous user. There are usecases for that.
    if (!empty($this->config['username']) && !empty($this->config['password'])) {
      // TODO: Consider making the resource/action path configurable. For now,
      // the default Services path is OK, since it covers 99% of the use cases.
      $login_url = $this->service->config['url'] . '/user/login';
      $logout_url = $this->service->config['url'] . '/user/logout';

      $options = array(
        'method' => 'POST',
        'headers' => array('Content-Type' => 'application/json'),
        'data' => drupal_json_encode(array(
          'username' => $this->config['username'],
          'password' => $this->config['password'],
        )),
      );

      if ($this->config['debug']) {
        watchdog('deploy', 'Login request URL: %url', array('%url' => $login_url), WATCHDOG_DEBUG);
        watchdog('deploy', 'Login request options: <pre>@options</pre>', array('@options' => print_r($options, TRUE)), WATCHDOG_DEBUG);
      }

      // Login on the endpoint.
      $response = drupal_http_request($login_url, $options);

      if ($this->config['debug']) {
        watchdog('deploy', 'Login response: <pre>@response</pre>', array('@response' => print_r($response, TRUE)), WATCHDOG_DEBUG);
      }
      if (isset($response->error)) {
        // TODO: Throw exception.
        watchdog('deploy', 'Login error: %code %error', array('%code' => $response->code, '%error' => $response->error), WATCHDOG_ERROR);
      }

      if ($response->code == 200 && !empty($response->headers['set-cookie'])) {
        // Set the session cookie, retrieved from the login request on the
        // endpoint, for all calls made by the service.
        $this->service->config['headers']['Cookie'] = $response->headers['set-cookie'];
      }
      else {
        // TODO: Throw exception because of failed authnetication.
      }
    }
    else {
      watchdog('deploy', 'Deployment authentication is done anonymously, without user credentials.', array(), WATCHDOG_NOTICE);
    }

    // Deploy the plan.
    $this->service->deploy($iterator);

    // We only need to log out if we logged in and got a session cookie.
    if (!empty($this->service->config['headers']['Cookie'])) {
      // Log out, since we are done now.
      $options = array(
        'method' => 'POST',
        'headers' => array('Cookie' => $response->headers['set-cookie']),
      );
      $response = drupal_http_request($logout_url, $options);

      if ($this->config['debug']) {
        watchdog('deploy', 'Logout response: <pre>@response</pre>', array('@response' => print_r($response, TRUE)), WATCHDOG_DEBUG);
      }
    }
  }

  public function configForm(&$form_state) {
    return array(
      'username' => array(
        '#type' => 'textfield',
        '#title' => t('Username'),
        '#description' => t('Enter the username that you want to authenticate with on this endpoint.'),
        '#default_value' => $this->config['username'],
      ),
      'password' => array(
        '#type' => 'password',
        '#title' => t('Password'),
        '#description' => t('Enter the password that you want to authenticate with on this endpoint.'),
        '#default_value' => $this->config['password'],
      ),
    );
  }

}
