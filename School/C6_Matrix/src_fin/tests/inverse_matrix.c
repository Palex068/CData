#include "test.h"

START_TEST(inverse_matrix_1) {
  matrix_t A = {0}, C = {0}, B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_matrix_2) {
  // Checking matrix in the task
  matrix_t test = {0};
  matrix_t check = {0};
  matrix_t total = {0};
  s21_create_matrix(3, 3, &test);
  s21_create_matrix(3, 3, &total);
  test.matrix[0][0] = 2;
  test.matrix[0][1] = 5;
  test.matrix[0][2] = 7;
  test.matrix[1][0] = 6;
  test.matrix[1][1] = 3;
  test.matrix[1][2] = 4;
  test.matrix[2][0] = 5;
  test.matrix[2][1] = -2;
  test.matrix[2][2] = -3;
  total.matrix[0][0] = 1;
  total.matrix[0][1] = -1;
  total.matrix[0][2] = 1;
  total.matrix[1][0] = -38;
  total.matrix[1][1] = 41;
  total.matrix[1][2] = -34;
  total.matrix[2][0] = 27;
  total.matrix[2][1] = -29;
  total.matrix[2][2] = 24;
  ck_assert_int_eq(s21_inverse_matrix(&test, &check), OK);
  ck_assert_int_eq(s21_eq_matrix(&total, &check), SUCCESS);
  s21_remove_matrix(&test);
  s21_remove_matrix(&check);
  s21_remove_matrix(&total);
}
END_TEST

START_TEST(inverse_matrix_3) {
  // Result matrix is NULL
  const int rows = rand() % 100 + 1;
  matrix_t test = {0};
  s21_create_matrix(rows, rows, &test);
  ck_assert_int_eq(s21_inverse_matrix(&test, NULL), ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(inverse_matrix_4) {
  // Set matrix is NULL
  matrix_t check = {0};
  ck_assert_int_eq(s21_inverse_matrix(NULL, &check), ERROR);
}
END_TEST

START_TEST(inverse_matrix_5) {
  // The matrix isn't square
  const int rows = 4;
  const int columns = 5;
  matrix_t test = {0};
  matrix_t check = {0};
  s21_create_matrix(rows, columns, &test);
  ck_assert_int_eq(s21_inverse_matrix(&test, &check), CALC_ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(inverse_matrix_6) {
  // Checking random matrix
  matrix_t test = {0};
  matrix_t check = {0};
  matrix_t total = {0};
  s21_create_matrix(3, 3, &test);
  s21_create_matrix(3, 3, &total);
  test.matrix[0][0] = 1;
  test.matrix[0][1] = 2;
  test.matrix[0][2] = 2;
  test.matrix[1][0] = 4;
  test.matrix[1][1] = 4;
  test.matrix[1][2] = 6;
  test.matrix[2][0] = 7;
  test.matrix[2][1] = 8;
  test.matrix[2][2] = 9;
  total.matrix[0][0] = -1.5;
  total.matrix[0][1] = -0.25;
  total.matrix[0][2] = 0.5;
  total.matrix[1][0] = 0.75;
  total.matrix[1][1] = -0.625;
  total.matrix[1][2] = 0.25;
  total.matrix[2][0] = 0.5;
  total.matrix[2][1] = 0.75;
  total.matrix[2][2] = -0.5;
  ck_assert_int_eq(s21_inverse_matrix(&test, &check), OK);
  ck_assert_int_eq(s21_eq_matrix(&total, &check), SUCCESS);
  s21_remove_matrix(&test);
  s21_remove_matrix(&check);
  s21_remove_matrix(&total);
}
END_TEST

START_TEST(inverse_matrix_7) {
  matrix_t A = {0}, R = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  int res = s21_inverse_matrix(&A, &R);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

Suite *s21_tests_inverse_matrix(void) {
  Suite *s = suite_create("s21_inverse_matrix");
  TCase *tc = tcase_create("s21_matrix");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, inverse_matrix_1);
  tcase_add_test(tc, inverse_matrix_2);
  tcase_add_test(tc, inverse_matrix_3);
  tcase_add_test(tc, inverse_matrix_4);
  tcase_add_test(tc, inverse_matrix_5);
  tcase_add_test(tc, inverse_matrix_6);
  tcase_add_test(tc, inverse_matrix_7);

  return s;
}