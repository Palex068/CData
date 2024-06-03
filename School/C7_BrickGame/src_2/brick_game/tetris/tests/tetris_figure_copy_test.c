#include <check.h>
#include <errno.h>

#include "tetris.h"

START_TEST(suite_figure_copy_test1) {
  int result = 0;
  result = figure_copy(NULL, NULL);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_figure_copy_test2) {
  int result = 0;
  figure_t *figure = NULL;
  result = figure_copy(figure, NULL);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_figure_copy_test3) {
  int result = 0;
  figure_t *figure = NULL;
  result = figure_copy(NULL, &figure);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_figure_copy_test4) {
  int result = 0;
  figure_t src = {0};
  figure_t *dst = NULL;
  result = figure_copy(&src, &dst);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_figure_copy_test5) {
  int result = 0;
  figure_t *src = NULL;
  figure_t *dst = NULL;
  src = figure_create(10);
  result = figure_copy(src, &dst);
  ck_assert_int_eq(result, 0);
  figure_destroy(src);
  figure_destroy(dst);
}
END_TEST

START_TEST(suite_figure_copy_test6) {
  int result = 0;
  figure_t *src = NULL;
  figure_t *dst = NULL;
  src = figure_create(10);
  dst = figure_create(10);
  result = figure_copy(src, &dst);
  ck_assert_int_eq(result, 0);
  figure_destroy(src);
  figure_destroy(dst);
}
END_TEST

START_TEST(suite_figure_copy_test7) {
  int result = 0;
  figure_t *src = NULL;
  figure_t *dst = NULL;
  src = figure_create(1);
  dst = figure_create(10);
  result = figure_copy(src, &dst);
  ck_assert_int_eq(result, 0);
  figure_destroy(src);
  figure_destroy(dst);
}
END_TEST

Suite *suite_figure_copy() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_figure_copy=-\x1b[0m");
  tc = tcase_create("suite_figure_copy");

  if (s && tc) {
    tcase_add_test(tc, suite_figure_copy_test1);
    tcase_add_test(tc, suite_figure_copy_test2);
    tcase_add_test(tc, suite_figure_copy_test3);
    tcase_add_test(tc, suite_figure_copy_test4);
    tcase_add_test(tc, suite_figure_copy_test5);
    tcase_add_test(tc, suite_figure_copy_test6);
    tcase_add_test(tc, suite_figure_copy_test7);
    suite_add_tcase(s, tc);
  }

  return s;
}