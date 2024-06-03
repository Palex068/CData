#include <check.h>
#include <errno.h>
#include <time.h>

#include "common.h"

START_TEST(suite_signals_unblock_test1) {
  unsigned long result = 0;
  result = signals_unblock();
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *suite_signals_unblock() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_signals_unblock=-\x1b[0m");
  tc = tcase_create("suite_signals_unblock");

  tcase_add_test(tc, suite_signals_unblock_test1);

  suite_add_tcase(s, tc);

  return s;
}