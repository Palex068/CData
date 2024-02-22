#include "test_matrix.h"

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
  matrix_t A = {0};
  double B = 0, R = -69.0 / 4.0;
  s21_create_matrix(5, 5, &A);
  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[0][3] = 3.25;
  A.matrix[0][4] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 10;
  A.matrix[1][2] = 5.25;
  A.matrix[1][3] = 5.25;
  A.matrix[1][4] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;
  A.matrix[2][3] = 6.25;
  A.matrix[2][4] = 6.25;
  A.matrix[3][0] = 6.25;
  A.matrix[3][1] = 7.25;
  A.matrix[3][2] = 8.25;
  A.matrix[3][3] = 6.25;
  A.matrix[3][4] = 7.25;
  A.matrix[4][0] = 6.25;
  A.matrix[4][1] = 7.25;
  A.matrix[4][2] = 8.25;
  A.matrix[4][3] = 6;
  A.matrix[4][4] = 8.25;
  s21_determinant(&A, &B);
  ck_assert(fabs(B - R) < 1e-7);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4) {
  matrix_t *A = NULL;
  double B;
  int res = s21_determinant(A, &B);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(determinant_5) {
  matrix_t A = {0};
  double B = 0;
  s21_create_matrix(1, 2, &A);
  int res = s21_determinant(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_1) {
  int res = 0;
  matrix_t A = {0}, B = {0}, C = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 112.0;
  A.matrix[0][1] = 243.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = -8.0;
  A.matrix[1][0] = 47.0;
  A.matrix[1][1] = 51.0;
  A.matrix[1][2] = -66.0;
  A.matrix[1][3] = 99.0;
  A.matrix[2][0] = -74.0;
  A.matrix[2][1] = 85.0;
  A.matrix[2][2] = 97.0;
  A.matrix[2][3] = 63.0;
  A.matrix[3][0] = -13.0;
  A.matrix[3][1] = 79.0;
  A.matrix[3][2] = -99.0;
  A.matrix[3][3] = -121.0;
  s21_calc_complements(&A, &B);
  s21_create_matrix(4, 4, &C);
  C.matrix[0][0] = -2879514.0;
  C.matrix[0][1] = -1236631.0;
  C.matrix[0][2] = -1685096.0;
  C.matrix[0][3] = 880697.0;
  C.matrix[1][0] = 1162090.0;
  C.matrix[1][1] = -714015.0;
  C.matrix[1][2] = 4046255.0;
  C.matrix[1][3] = -3901600.0;
  C.matrix[2][0] = 4362897.0;
  C.matrix[2][1] = -2049432.0;
  C.matrix[2][2] = -532912.0;
  C.matrix[2][3] = -1370781.0;
  C.matrix[3][0] = 3412773.0;
  C.matrix[3][1] = -1569493.0;
  C.matrix[3][2] = 3144517.0;
  C.matrix[3][3] = 1284666.0;
  res = s21_eq_matrix(&B, &C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(calc_complements_2) {
  int res = 0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;
  s21_calc_complements(&A, &Z);
  s21_create_matrix(4, 4, &X);
  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = -30.0;
  X.matrix[0][2] = -108.0;
  X.matrix[0][3] = 106.0;
  X.matrix[1][0] = 138.0;
  X.matrix[1][1] = -726.0;
  X.matrix[1][2] = -1137.0;
  X.matrix[1][3] = 1061.0;
  X.matrix[2][0] = 0.0;
  X.matrix[2][1] = 12.0;
  X.matrix[2][2] = 57.0;
  X.matrix[2][3] = -47.0;
  X.matrix[3][0] = 0.0;
  X.matrix[3][1] = 6.0;
  X.matrix[3][2] = -75.0;
  X.matrix[3][3] = 57.0;
  res = s21_eq_matrix(&X, &Z);
  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(calc_complements_3) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 2, &A);
  int res = s21_calc_complements(&A, &B);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(calc_complements_4) {
  matrix_t *A = NULL;
  matrix_t B = {0};
  int res = s21_calc_complements(A, &B);
  ck_assert_int_eq(res, 1);
}
END_TEST

START_TEST(inverse_1) {
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

START_TEST(inverse_2) {
  matrix_t A = {0}, R = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1431.12312331;
  int res = s21_inverse_matrix(&A, &R);
  ck_assert_double_eq(R.matrix[0][0], (1.0 / A.matrix[0][0]));
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&R);
}
END_TEST

START_TEST(inverse_3) {
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

Suite *test_another() {
  Suite *s = suite_create("another");
  TCase *o = tcase_create("another");

  tcase_add_test(o, determinant_1);
  tcase_add_test(o, determinant_2);
  tcase_add_test(o, determinant_3);
  tcase_add_test(o, determinant_4);
  tcase_add_test(o, determinant_5);

  tcase_add_test(o, calc_complements_1);
  tcase_add_test(o, calc_complements_2);
  tcase_add_test(o, calc_complements_3);
  tcase_add_test(o, calc_complements_4);

  tcase_add_test(o, inverse_1);
  tcase_add_test(o, inverse_2);
  tcase_add_test(o, inverse_3);

  suite_add_tcase(s, o);
  return s;
}
