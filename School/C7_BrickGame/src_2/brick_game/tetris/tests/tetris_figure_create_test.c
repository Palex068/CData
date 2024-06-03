#include <check.h>

#include "tetris.h"
#include "tetris_test.h"

START_TEST(suite_figure_create_test1) {
  figure_t *figure = NULL;
  figure = figure_create(0);
  ck_assert_ptr_null(figure);
}
END_TEST

START_TEST(suite_figure_create_test2) {
  figure_t *figure = NULL, *check = NULL;
  memory_locked(sizeof(figure_t), 1);
  figure = figure_create(10);
  memory_locked(0, -1);
  check = figure;
  figure_destroy(figure);
  ck_assert_ptr_null(check);
}
END_TEST

START_TEST(suite_figure_create_test3) {
  figure_t *figure = NULL, *check = NULL;
  memory_locked(sizeof(int*), 1);
  figure = figure_create(10);
  memory_locked(0, -1);
  check = figure;
  figure_destroy(figure);
  ck_assert_ptr_null(check);
}
END_TEST

START_TEST(suite_figure_create_test4) {
  figure_t *figure = NULL, *check = NULL;
  memory_locked(sizeof(int), 1);
  figure = figure_create(10);
  memory_locked(0, -1);
  check = figure;
  figure_destroy(figure);
  ck_assert_ptr_null(check);
}
END_TEST

START_TEST(suite_figure_create_test5) {
  figure_t *figure = NULL;
  for (int i = 1; i < 11; i++) {
    figure = figure_create(i);
    ck_assert_ptr_nonnull(figure);
    figure_destroy(figure);
  }
}
END_TEST

Suite *suite_figure_create() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_figure_create=-\x1b[0m");
  tc = tcase_create("suite_figure_create");

  if (s && tc) {
    tcase_add_test(tc, suite_figure_create_test1);
    tcase_add_test(tc, suite_figure_create_test2);
    tcase_add_test(tc, suite_figure_create_test3);
    tcase_add_test(tc, suite_figure_create_test4);
    tcase_add_test(tc, suite_figure_create_test5);
    suite_add_tcase(s, tc);
  }

  return s;
}