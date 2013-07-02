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
  );

  return $actions;
}

/**
 * The action function for 'rules_example_action_hello_world'.
 */
function rules_example_action_hello_world() {
  drupal_set_message(t('Hello, World!'));
}