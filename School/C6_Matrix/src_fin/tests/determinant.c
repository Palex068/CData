#include "test.h"

START_TEST(determinant_1) {
  matrix_t A = {0};
  double B = 0, R = 1.5;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.5;
  s21_determinant(&A, &B);
  ck_assert(fabs(B - R) < 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_2) {
  matrix_t A = {0};
  double B = 0, R = -69;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;
  s21_determinant(&A, &B);
  ck_assert(fabs(B - R) < 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3) {
  // Check random matrix
  const int rows = 4;
  matrix_t test = {0};
  double check = 0;
  double total = 16654.35;
  s21_create_matrix(rows, rows, &test);
  test.matrix[0][0] = 4.5;
  test.matrix[0][1] = 3;
  test.matrix[0][2] = 32;
  test.matrix[0][3] = 11;
  test.matrix[1][0] = 0.1;
  test.matrix[1][1] = 3;
  test.matrix[1][2] = -5;
  test.matrix[1][3] = 12;
  test.matrix[2][0] = 1;
  test.matrix[2][1] = 8.9;
  test.matrix[2][2] = 4;
  test.matrix[2][3] = 7;
  test.matrix[3][0] = -5;
  test.matrix[3][1] = 3;
  test.matrix[3][2] = 2;
  test.matrix[3][3] = 1;
  ck_assert_int_eq(s21_determinant(&test, &check), OK);
  ck_assert_double_eq_tol(total, check, FRACTURE_CHECK);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(determinant_4) {
  // Result is NULL
  const int rows = rand() % 100 + 1;
  matrix_t test = {0};
  s21_create_matrix(rows, rows, &test);
  ck_assert_int_eq(s21_determinant(&test, NULL), ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(determinant_5) {
  // Set matrix is NULL
  double check = 0;
  ck_assert_int_eq(s21_determinant(NULL, &check), ERROR);
}
END_TEST

START_TEST(determinant_6) {
  // The matrix isn't square
  const int rows = 4;
  const int columns = 5;
  matrix_t test = {0};
  double check = 0;
  s21_create_matrix(rows, columns, &test);
  ck_assert_int_eq(s21_determinant(&test, &check), CALC_ERROR);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(determinant_7) {
  // Check matrix minor
  matrix_t test = {0};
  matrix_t total = {0};
  matrix_t check = {0};
  s21_create_matrix(4, 4, &test);
  s21_create_matrix(3, 3, &total);
  int num = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      test.matrix[i][j] = num;
      num += 1;
    }
  }
  total.matrix[0][0] = 6;
  total.matrix[0][1] = 7;
  total.matrix[0][2] = 8;
  total.matrix[1][0] = 10;
  total.matrix[1][1] = 11;
  total.matrix[1][2] = 12;
  total.matrix[2][0] = 14;
  total.matrix[2][1] = 15;
  total.matrix[2][2] = 16;
  s21_minor(&test, &check, 0, 0);
  ck_assert_int_eq(s21_eq_matrix(&check, &total), SUCCESS);
  s21_remove_matrix(&test);
  s21_remove_matrix(&check);
  s21_remove_matrix(&total);
}
END_TEST

Suite *s21_tests_determinant(void) {
  Suite *s = suite_create("s21_determinant");
  TCase *tc = tcase_create("s21_matrix");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, determinant_1);
  tcase_add_test(tc, determinant_2);
  tcase_add_test(tc, determinant_3);
  tcase_add_test(tc, determinant_4);
  tcase_add_test(tc, determinant_5);
  tcase_add_test(tc, determinant_6);
  tcase_add_test(tc, determinant_7);

  return s;
}