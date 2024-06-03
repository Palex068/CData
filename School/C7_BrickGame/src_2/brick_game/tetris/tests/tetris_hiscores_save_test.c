#include <check.h>
#include <errno.h>

#include "tetris.h"

START_TEST(suite_hi_scores_save_test1) {
  int result = 0;
  result = hi_scores_save(NULL, NULL);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_hi_scores_save_test2) {
  int result = 0;
  result = hi_scores_save("test", NULL);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_hi_scores_save_test3) {
  int result = 0;
  int temp = 0;
  result = hi_scores_save("..", &temp);
  ck_assert_int_eq(result, EACCES);
}
END_TEST

Suite *suite_hi_scores_save() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_hi_scores_save=-\x1b[0m");

  tc = tcase_create("suite_hi_scores_save");
  tcase_add_test(tc, suite_hi_scores_save_test1);
  tcase_add_test(tc, suite_hi_scores_save_test2);
  tcase_add_test(tc, suite_hi_scores_save_test3);

  suite_add_tcase(s, tc);

  return s;
}