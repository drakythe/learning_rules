<?php

/**
 * Example Rules code: actions, conditions, and events.
 */

/**
 * Implements hook_rules_action_info().
 *
 * Declares any meta-data about actions for Rules.
 */
function rules_example_rules_action_info() {
  $actions = array(
    'rules_example_action_hello_world' => array(
      'label' => t('Print Hello World! on the page'),
      'group' => t('Rules examples'),
    ),

    'rules_example_action_hello_user' => array(
      'label' => t('Say hello to a select user'),
      'group' => t('Rules examples'),
      'parameter' => array(
        'account' => array(
          'type' => 'user',
          'label' => t('User to say hello to'),
          'save' => TRUE,
        ),
      ),
    ),
  );

  if(module_exists('views')) {
    $actions['rules_example_action_get_view_results'] = array(
      'label' => t('Get the number of results in a view'),
    ),
  }

  return $actions;
}

/**
 * The action function for 'rules_example_action_hello_world'.
 */
function rules_example_action_hello_world() {
  drupal_set_message(t('Hello, World!'));
}

/**
 * The action function for the 'rules_example_action_hello_user'
 *
 * @param $account
 * User object sent into this action, selected in the Rules configuration interface.
 */
function rules_example_action_hello_user($account) {
  drupal_set_message(t('Hello, @username!',
    array('@username' => $account->name)));
}