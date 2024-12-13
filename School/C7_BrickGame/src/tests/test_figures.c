#include "test_main.h"

START_TEST(s21_figures_00_ok) {
  updateCurrentFigure(true);
  updateNextFigure(true);
}
END_TEST

START_TEST(s21_figures_01_ok) {
  delFigure();
  delNext();
}
END_TEST

START_TEST(s21_figures_02_ok) { takeNextFigure(); }
END_TEST

Suite *s21_figures_suite() {
  Suite *s = suite_create("s21_figures");
  TCase *tc = tcase_create("s21_tetris");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_figures_00_ok);
  tcase_add_test(tc, s21_figures_01_ok);
  tcase_add_test(tc, s21_figures_02_ok);
  return s;
}