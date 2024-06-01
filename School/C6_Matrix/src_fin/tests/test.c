#include "test.h"

int main() {
  int nf = 0;

  runtest(s21_tests_create_matrix(), &nf);
  runtest(s21_tests_eq_matrix(), &nf);
  runtest(s21_tests_sum_matrix(), &nf);
  runtest(s21_tests_sub_matrix(), &nf);
  runtest(s21_tests_mult_number(), &nf);
  runtest(s21_tests_mult_matrix(), &nf);
  runtest(s21_tests_transpose(), &nf);
  runtest(s21_tests_calc_complements(), &nf);
  runtest(s21_tests_determinant(), &nf);
  runtest(s21_tests_inverse_matrix(), &nf);

  return nf == 0 ? 0 : 1;
}

void runtest(Suite *make_suite, int *result) {
  SRunner *sr = srunner_create(make_suite);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  *result += srunner_ntests_failed(sr);
  srunner_free(sr);
}