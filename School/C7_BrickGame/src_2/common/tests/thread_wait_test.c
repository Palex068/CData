#include <check.h>
#include <errno.h>

#include "common.h"

START_TEST(suite_thread_wait_test1) {
  int retval = 0;
  retval = thread_wait(0);
  ck_assert_int_eq(retval, EINVAL);
}
END_TEST

START_TEST(suite_thread_wait_test2) {
  int retval = 0;
  retval = thread_wait(-10);
  ck_assert_int_eq(retval, EINVAL);
}
END_TEST

START_TEST(suite_thread_wait_test3) {
  int retval = 0;
  retval = thread_wait(1);
  ck_assert_int_eq(retval, 0);
}
END_TEST

START_TEST(suite_thread_wait_test4) {
  int retval = 0;
  retval = thread_wait(10);
  ck_assert_int_eq(retval, 0);
}
END_TEST

Suite *suite_thread_wait() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_thread_wait=-\x1b[0m");
  tc = tcase_create("suite_thread_wait");

  tcase_add_test(tc, suite_thread_wait_test1);
  tcase_add_test(tc, suite_thread_wait_test2);
  tcase_add_test(tc, suite_thread_wait_test3);
  tcase_add_test(tc, suite_thread_wait_test4);

  suite_add_tcase(s, tc);

  return s;
}