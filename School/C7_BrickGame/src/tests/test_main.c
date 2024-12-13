#include "test_main.h"

int main() {
  int nf = 0;

  runtest(s21_matrix_suite(), &nf);
  runtest(s21_figures_suite(), &nf);
  runtest(s21_moves_suite(), &nf);
  runtest(s21_logic_suite(), &nf);
  runtest(s21_inputs_suite(), &nf);

  return nf == 0 ? 0 : 1;
}

void runtest(Suite *make_suite, int *result) {
  SRunner *sr = srunner_create(make_suite);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  *result += srunner_ntests_failed(sr);
  srunner_free(sr);
}