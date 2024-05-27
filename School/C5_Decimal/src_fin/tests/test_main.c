#include "test_main.h"

int main() {
  int nf = 0;

  runtest(s21_arithmetic_add_suite(), &nf);
  runtest(s21_arithmetic_sub_suite(), &nf);
  runtest(s21_arithmetic_mul_suite(), &nf);
  runtest(s21_arithmetic_div_suite(), &nf);
  runtest(s21_convertations_int_to_decimal(), &nf);
  runtest(s21_convertations_decimal_to_int(), &nf);
  runtest(s21_convertations_float_to_decimal(), &nf);
  runtest(s21_convertations_decimal_to_float(), &nf);
  runtest(s21_other_negate(), &nf);
  runtest(s21_other_floor(), &nf);
  runtest(s21_other_round(), &nf);
  runtest(s21_other_truncate(), &nf);
  runtest(s21_other_comparison(), &nf);

  return nf == 0 ? 0 : 1;
}

void runtest(Suite *make_suite, int *result) {
  SRunner *sr = srunner_create(make_suite);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  *result += srunner_ntests_failed(sr);
  srunner_free(sr);
}