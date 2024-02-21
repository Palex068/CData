#include "s21_tests.h"

START_TEST(test_s21_exp) {
  double values[] = {-1.5, -0.5, 0.5, 1.5, 2.5, 0.0001, 0.0};
  int lengths = sizeof(values) / sizeof(values[0]);
  for (int i = 0; i < lengths; i++) {
    double value = values[i];
    ck_assert_int_eq(s21_exp(value), (int)exp(value));
  }
}
END_TEST

Suite *exp_suite(void) {
  Suite *s = suite_create("exp");
  TCase *tc_exp = tcase_create("math");
  suite_add_tcase(s, tc_exp);
  tcase_add_test(tc_exp, test_s21_exp);
  return s;
}
