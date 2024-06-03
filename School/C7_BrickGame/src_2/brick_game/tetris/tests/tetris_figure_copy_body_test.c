#include <check.h>
#include <errno.h>

#include "tetris.h"

START_TEST(suite_figure_copy_body_test1) {
  int result = 0;
  result = figure_copy_body(NULL, NULL, 0);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_figure_copy_body_test2) {
  int result = 0;
  figure_t *src = NULL;
  figure_t *dst = NULL;
  src = figure_create(10);
  dst = figure_create(10);
  result = figure_copy_body(src->body, dst->body, 0);
  ck_assert_int_eq(result, 0);
  figure_destroy(src);
  figure_destroy(dst);
}
END_TEST

START_TEST(suite_figure_copy_body_test3) {
  int result = 0;
  figure_t *src = NULL;
  figure_t *dst = NULL;
  src = figure_create(10);
  dst = figure_create(10);
  result = figure_copy_body(src->body, dst->body, 10);
  ck_assert_int_eq(result, 0);
  figure_destroy(src);
  figure_destroy(dst);
}
END_TEST

START_TEST(suite_figure_copy_body_test4) {
  int result = 0;
  figure_t *src = NULL;
  figure_t *dst = NULL;
  src = figure_create(10);
  dst = figure_create(10);
  result = figure_copy_body(src->body, dst->body, 1);
  ck_assert_int_eq(result, 0);
  figure_destroy(src);
  figure_destroy(dst);
}
END_TEST

Suite *suite_figure_copy_body() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_figure_copy_body=-\x1b[0m");
  tc = tcase_create("suite_figure_copy_body");

  if (s && tc) {
    tcase_add_test(tc, suite_figure_copy_body_test1);
    tcase_add_test(tc, suite_figure_copy_body_test2);
    tcase_add_test(tc, suite_figure_copy_body_test3);
    tcase_add_test(tc, suite_figure_copy_body_test4);
    suite_add_tcase(s, tc);
  }

  return s;
}