#include <check.h>
#include <errno.h>

#include "tetris.h"

START_TEST(suite_figure_db_destroy_test1) {
  int result = 0;
  result = figure_db_destroy(NULL);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_figure_db_destroy_test2) {
  int result = 0;
  figures_db_t db = {0};
  result = figure_db_destroy(&db);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(suite_figure_db_destroy_test3) {
  int result = 0;
  figures_db_t db = {0};
  figure_db_load("./figures/", &db);
  result = figure_db_destroy(&db);
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *suite_figure_db_destroy() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_figure_db_destroy=-\x1b[0m");

  tc = tcase_create("suite_figure_db_destroy");
  tcase_add_test(tc, suite_figure_db_destroy_test1);
  tcase_add_test(tc, suite_figure_db_destroy_test2);
  tcase_add_test(tc, suite_figure_db_destroy_test3);

  suite_add_tcase(s, tc);

  return s;
}