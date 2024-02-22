#include "test_matrix.h"

START_TEST(sum_1) {
  int rows = 5, columns = 6;
  matrix_t A, B, C, R;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &C);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j + 1;
      B.matrix[i][j] = i + j + 1;
      C.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
    }
  int res = s21_sum_matrix(&A, &B, &R);
  int res_B = s21_eq_matrix(&R, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_B, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(sum_2) {
  int rows = 5, columns = 6;
  matrix_t B, R;
  matrix_t* A = NULL;
  s21_create_matrix(rows, columns, &B);
  int res = s21_sum_matrix(A, &B, &R);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_3) {
  matrix_t B = {0}, R = {0};
  matrix_t* A = NULL;
  int res = s21_sum_matrix(A, &B, &R);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(sub_1) {
  int rows = 5, columns = 6;
  matrix_t A, B, C, R;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &C);
  //  s21_create_matrix(rows, columns, &R);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j + 1;
      B.matrix[i][j] = i + j + 1;
      C.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
    }
  int res = s21_sub_matrix(&A, &B, &R);
  int res_B = s21_eq_matrix(&R, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_B, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(sub_2) {
  matrix_t B = {0}, R = {0};
  matrix_t* A = NULL;
  int res = s21_sub_matrix(A, &B, &R);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(sub_3) {
  int rows = 3, columns = 3;
  matrix_t A, B, R;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows - 1, columns, &B);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = 12345 + i * 10 + j;
      if (i < rows - 1) B.matrix[i][j] = 12345 + i * 10 + j;
    }
  int res = s21_sub_matrix(&A, &B, &R);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_number_1) {
  int rows = 5, columns = 6;
  matrix_t A, C, R;
  double b = 2;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &C);
  //  s21_create_matrix(rows, columns, &R);

  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = i + j + 1;
      C.matrix[i][j] = A.matrix[i][j] * b;
    }
  int res = s21_mult_number(&A, b, &R);
  int res_B = s21_eq_matrix(&R, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_B, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&C);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_number_2) {
  matrix_t R = {0};
  matrix_t* A = NULL;
  double b = 2;
  int res = s21_mult_number(A, b, &R);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(mult_matrix_1) {
  int rows = 3, columns = 2;
  matrix_t A = {0}, B = {0}, C = {0}, R = {0};
  double sum = 0;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &B);
  s21_create_matrix(rows, rows, &C);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++) {
      sum++;
      A.matrix[i][j] = sum;
    }
  sum = 0;
  for (int i = 0; i < columns; i++)
    for (int j = 0; j < rows; j++) {
      sum++;
      B.matrix[i][j] = sum;
    }
  C.matrix[0][0] = 9;
  C.matrix[0][1] = 12;
  C.matrix[0][2] = 15;
  C.matrix[1][0] = 19;
  C.matrix[1][1] = 26;
  C.matrix[1][2] = 33;
  C.matrix[2][0] = 29;
  C.matrix[2][1] = 40;
  C.matrix[2][2] = 51;
  int res = s21_mult_matrix(&A, &B, &R);
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) printf("%lf\n", R.matrix[i][j]);
  int res_B = s21_eq_matrix(&R, &C);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(res_B, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(mult_matrix_2) {
  matrix_t A = {0}, B = {0}, R = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 3, &B);
  int res = s21_mult_matrix(&A, &B, &R);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  ck_assert_int_eq(res, 2);
}
END_TEST

START_TEST(mult_matrix_3) {
  matrix_t B = {0}, R = {0};
  matrix_t* A = NULL;
  int res = s21_mult_matrix(A, &B, &R);
  ck_assert_int_eq(res, 1);
}
END_TEST

Suite* test_arithmetic() {
  Suite* s = suite_create("arithmetic");
  TCase* o = tcase_create("arithmetic");

  tcase_add_test(o, sum_1);
  tcase_add_test(o, sum_2);
  tcase_add_test(o, sum_3);

  tcase_add_test(o, sub_1);
  tcase_add_test(o, sub_2);
  tcase_add_test(o, sub_3);

  tcase_add_test(o, mult_number_1);
  tcase_add_test(o, mult_number_2);

  tcase_add_test(o, mult_matrix_1);
  tcase_add_test(o, mult_matrix_2);
  tcase_add_test(o, mult_matrix_3);
  suite_add_tcase(s, o);
  return s;
}
