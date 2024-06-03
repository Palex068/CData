#include <check.h>

#include "tetris.h"

START_TEST(suite_fsm_test1) {
  action result = NULL;
  fsm_state state = none;
  for (UserAction_t i = None; i < Action; i++) {
    result = fsm(state, i);
    ck_assert(result == NULL);
  }
}
END_TEST

START_TEST(suite_fsm_test2) {
  action result = NULL;
  fsm_state state = start;
  for (UserAction_t i = None; i < Action; i++) {
    result = fsm(state, i);
    if (i == 1)
      ck_assert(result == start_fn);
    else if (i == 3)
      ck_assert(result == terminate_fn);
    else
      ck_assert(result == NULL);
  }
}
END_TEST

START_TEST(suite_fsm_test3) {
  action result = NULL;
  fsm_state state = pause;
  for (UserAction_t i = None; i < Action; i++) {
    result = fsm(state, i);
    if (i == 2)
      ck_assert(result == pause_fn);
    else if (i == 3)
      ck_assert(result == terminate_fn);
    else
      ck_assert(result == NULL);
  }
}
END_TEST

START_TEST(suite_fsm_test4) {
  action result = NULL;
  fsm_state state = spawn;
  for (UserAction_t i = None; i < Action; i++) {
    result = fsm(state, i);
    if (i == 3)
      ck_assert(result == terminate_fn);
    else
      ck_assert(result == NULL);
  }
}
END_TEST

START_TEST(suite_fsm_test5) {
  action result = NULL;
  fsm_state state = moving;
  result = fsm(state, 0);
  ck_assert(result == NULL);
  result = fsm(state, 1);
  ck_assert(result == NULL);
  result = fsm(state, 2);
  ck_assert(result == pause_fn);
  result = fsm(state, 3);
  ck_assert(result == terminate_fn);
  result = fsm(state, 4);
  ck_assert(result == left_fn);
  result = fsm(state, 5);
  ck_assert(result == right_fn);
  result = fsm(state, 6);
  ck_assert(result == up_fn);
  result = fsm(state, 7);
  ck_assert(result == down_fn);
  result = fsm(state, 8);
  ck_assert(result == action_fn);
}
END_TEST

START_TEST(suite_fsm_test6) {
  action result = NULL;
  fsm_state state = shift;
  for (UserAction_t i = None; i < Action; i++) {
    result = fsm(state, i);
    ck_assert(result == NULL);
  }
}
END_TEST

START_TEST(suite_fsm_test7) {
  action result = NULL;
  fsm_state state = connect;
  for (UserAction_t i = None; i < Action; i++) {
    result = fsm(state, i);
    ck_assert(result == NULL);
  }
}
END_TEST

START_TEST(suite_fsm_test8) {
  action result = NULL;
  fsm_state state = game_over;
  for (UserAction_t i = None; i < Action; i++) {
    result = fsm(state, i);
    if (i == 1)
      ck_assert(result == start_fn);
    else if (i == 3)
      ck_assert(result == terminate_fn);
    else
      ck_assert(result == NULL);
  }
}
END_TEST

Suite *suite_fsm() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_fsm=-\x1b[0m");
  tc = tcase_create("suite_fsm");

  if (s && tc) {
    tcase_add_test(tc, suite_fsm_test1);
    tcase_add_test(tc, suite_fsm_test2);
    tcase_add_test(tc, suite_fsm_test3);
    tcase_add_test(tc, suite_fsm_test4);
    tcase_add_test(tc, suite_fsm_test5);
    tcase_add_test(tc, suite_fsm_test6);
    tcase_add_test(tc, suite_fsm_test7);
    tcase_add_test(tc, suite_fsm_test8);
    suite_add_tcase(s, tc);
  }

  return s;
}