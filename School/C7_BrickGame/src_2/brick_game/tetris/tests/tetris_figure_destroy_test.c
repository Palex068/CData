#include <check.h>
#include <errno.h>

#include "tetris.h"

START_TEST(suite_figure_destroy_test1) {
  int result = 0;
  result = figure_destroy(NULL);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_figure_destroy_test2) {
  figure_t *figure = NULL;
  for (int i = 1; i < 11; i++) {
    figure = figure_create(i);
    ck_assert_int_eq(figure_destroy(figure), 0);
  }
}
END_TEST

Suite *suite_figure_destroy() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_figure_destroy=-\x1b[0m");
  tc = tcase_create("suite_figure_destroy");

  if (s && tc) {
    tcase_add_test(tc, suite_figure_destroy_test1);
    tcase_add_test(tc, suite_figure_destroy_test2);
    suite_add_tcase(s, tc);
  }

  return s;
}