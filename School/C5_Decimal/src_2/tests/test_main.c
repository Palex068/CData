#include "test_main.h"

int main() {
  int nf = 0;

  // runtest(s21_print_suite(), &nf);
  runtest(s21_arithmetic_add_suite(), &nf);
  runtest(s21_arithmetic_sub_suite(), &nf);
  runtest(s21_arithmetic_mul_suite(), &nf);
  runtest(s21_arithmetic_div_suite(), &nf);
  runtest(s21_convertations_int_to_decimal(), &nf);

  return nf == 0 ? 0 : 1;
}

void runtest(Suite *make_suite, int *result) {
  SRunner *sr = srunner_create(make_suite);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  *result += srunner_ntests_failed(sr);
  srunner_free(sr);
}