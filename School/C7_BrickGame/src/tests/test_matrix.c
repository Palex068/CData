#include "test_main.h"

START_TEST(s21_matrix_00_ok) {
  int **matrix = mallocMatrix(WIDTH, HEIGHT);
  ck_assert_ptr_nonnull(matrix);
  free(matrix);
}
END_TEST

START_TEST(s21_matrix_01_ok) {
  GameInfo_t state = updateCurrentState();
  ck_assert_ptr_nonnull(state.field);
  ck_assert_ptr_nonnull(state.next);
}
END_TEST

Suite *s21_matrix_suite() {
  Suite *s = suite_create("s21_matrix");
  TCase *tc = tcase_create("s21_tetris");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_matrix_00_ok);
  tcase_add_test(tc, s21_matrix_01_ok);
  return s;
}