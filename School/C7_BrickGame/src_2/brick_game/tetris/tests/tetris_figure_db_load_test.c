#include <check.h>
#include <errno.h>

#include "tetris.h"
#include "tetris_test.h"

START_TEST(suite_figure_db_load_test1) {
  int result = 0;
  result = figure_db_load(NULL, NULL);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_figure_db_load_test2) {
  int result = 0;
  figures_db_t db = {0};
  result = figure_db_load("./wrong_path/", &db);
  ck_assert_int_eq(result, ENOENT);
}
END_TEST

START_TEST(suite_figure_db_load_test3) {
  int result = 0;
  result = figure_db_load("./figures/", NULL);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_figure_db_load_test4) {
  int result = 0;
  figures_db_t db = {0};
  memory_locked(4106, 1);
  result = figure_db_load("./figures/", &db);
  memory_locked(0, -1);
  figure_db_destroy(&db);
  ck_assert_int_eq(result, ENOMEM);
}
END_TEST

START_TEST(suite_figure_db_load_test5) {
  int result = 0;
  figures_db_t db = {0};
  result = figure_db_load("./figures/", &db);
  figure_db_destroy(&db);
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *suite_figure_db_load() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_figure_db_load=-\x1b[0m");

  tc = tcase_create("suite_figure_db_load");
  tcase_add_test(tc, suite_figure_db_load_test1);
  tcase_add_test(tc, suite_figure_db_load_test2);
  tcase_add_test(tc, suite_figure_db_load_test3);
  tcase_add_test(tc, suite_figure_db_load_test4);
  tcase_add_test(tc, suite_figure_db_load_test5);

  suite_add_tcase(s, tc);

  return s;
}