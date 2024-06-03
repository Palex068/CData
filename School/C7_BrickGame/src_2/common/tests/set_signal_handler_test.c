#include <check.h>
#include <errno.h>
#include <time.h>

#include "common.h"

void test_handler();

START_TEST(suite_set_signal_handler_test1) { set_signal_handler(test_handler); }
END_TEST

Suite *suite_set_signal_handler() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_set_signal_handler=-\x1b[0m");
  tc = tcase_create("suite_set_signal_handler");

  tcase_add_test(tc, suite_set_signal_handler_test1);

  suite_add_tcase(s, tc);

  return s;
}

void test_handler() { return; }