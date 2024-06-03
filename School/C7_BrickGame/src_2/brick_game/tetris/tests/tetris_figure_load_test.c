#include <check.h>
#include <stdio.h>

#include "tetris.h"
#include "tetris_test.h"

START_TEST(suite_figure_load_test1) {
  figure_t *figure = NULL;
  figure = figure_load(NULL);
  ck_assert_ptr_null(figure);
}
END_TEST

START_TEST(suite_figure_load_test2) {
  figure_t *figure = NULL;
  FILE *file = NULL;
  file = fopen("./figures/hero.tet", "r");
  if (file) {
    memory_locked(sizeof(int), 1);
    figure = figure_load(file);
    memory_locked(0, -1);
    figure_destroy(figure);
    fclose(file);
  }
  ck_assert_ptr_null(figure);
}
END_TEST

START_TEST(suite_figure_load_test3) {
  figure_t *figure = NULL;
  FILE *file = NULL;
  file = fopen("./figures/bad1.tests", "r");
  if (file) {
    memory_locked(sizeof(int), 1);
    figure = figure_load(file);
    memory_locked(0, -1);
    figure_destroy(figure);
    fclose(file);
  }
  ck_assert_ptr_null(figure);
}
END_TEST

START_TEST(suite_figure_load_test4) {
  figure_t *figure = NULL;
  FILE *file = NULL;
  file = fopen("./figures/bad2.tests", "r");
  if (file) {
    memory_locked(sizeof(int), 1);
    figure = figure_load(file);
    memory_locked(0, -1);
    figure_destroy(figure);
    fclose(file);
  }
  ck_assert_ptr_null(figure);
}
END_TEST

START_TEST(suite_figure_load_test5) {
  figure_t *figure = NULL;
  FILE *file = NULL;
  file = fopen("./figures/hero.tet", "r");
  if (file) {
    figure = figure_load(file);
    figure_destroy(figure);
    fclose(file);
  }
  ck_assert_ptr_nonnull(figure);
}
END_TEST

Suite *suite_figure_load() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_figure_load=-\x1b[0m");
  tc = tcase_create("suite_figure_load");

  if (s && tc) {
    tcase_add_test(tc, suite_figure_load_test1);
    tcase_add_test(tc, suite_figure_load_test2);
    tcase_add_test(tc, suite_figure_load_test3);
    tcase_add_test(tc, suite_figure_load_test4);
    tcase_add_test(tc, suite_figure_load_test5);
    suite_add_tcase(s, tc);
  }

  return s;
}