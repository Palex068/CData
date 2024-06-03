#include <check.h>
#include <errno.h>
#include <time.h>

#include "common.h"

START_TEST(suite_time_msec_test1) {
  unsigned long result = 0;
  result = time_msec();
  ck_assert(result > 0);
}
END_TEST

START_TEST(suite_time_msec_test2) {
  unsigned long result = 0, check = 0;
  struct timespec now = {0};
  if (timespec_get(&now, TIME_UTC) != 0)
    check = (unsigned long)now.tv_sec * 1000 + now.tv_nsec / 1000000;
  result = time_msec();
  ck_assert(result - check < 0000000000010);
}
END_TEST

Suite *suite_time_msec() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_time_msec=-\x1b[0m");
  tc = tcase_create("suite_time_msec");

  tcase_add_test(tc, suite_time_msec_test1);
  tcase_add_test(tc, suite_time_msec_test2);

  suite_add_tcase(s, tc);

  return s;
}