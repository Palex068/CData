#include "test_main.h"

START_TEST(s21_moves_00_ok) {
  moveDown(false);
  moveDown(true);

  moveLeft();
  moveRight();
  rotate();
}
END_TEST

START_TEST(s21_moves_01_ok) {
  for (int i = 0; i <= 2; i++) {
    rotate();
  }
  for (int i = 0; i <= 6; i++) {
    moveRight();
  }
  for (int i = 0; i <= 3; i++) {
    rotate();
  }
  for (int i = 0; i <= 10; i++) {
    moveLeft();
  }
  for (int i = 0; i <= 15; i++) {
    moveDown(false);
  }

  delFigure();
}
END_TEST

Suite *s21_moves_suite() {
  Suite *s = suite_create("s21_moves");
  TCase *tc = tcase_create("s21_tetris");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_moves_00_ok);
  tcase_add_test(tc, s21_moves_01_ok);
  return s;
}