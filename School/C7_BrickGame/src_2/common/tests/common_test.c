#include "common_test.h"

#include <dlfcn.h>
#include <stdio.h>

void run_test_case(Suite *testcase) {
  SRunner *srunner = {0};
  srunner = srunner_create(testcase);
  if (srunner) {
    srunner_set_fork_status(srunner, CK_NOFORK);
    srunner_run_all(srunner, CK_NORMAL);
    srunner_free(srunner);
  }
}

void run_tests() {
  int testcase_counter = 0;
  Suite *list_cases[] = {suite_thread_wait(),        suite_time_msec(),
                         suite_signals_block(),      suite_signals_unblock(),
                         suite_set_signal_handler(), NULL};

  while (list_cases[testcase_counter] != NULL) {
    run_test_case(list_cases[testcase_counter]);
    putc('\n', stdout);
    testcase_counter++;
  }
}

int main() {
  run_tests();
  return 0;
}

void *malloc(size_t __size) {
  void *result = NULL;
  void *(*libc_malloc)(size_t) = NULL;
  *(void **)(&libc_malloc) = dlsym((void *)-1l, "malloc");
  if (!memory_locked(0)) result = libc_malloc(__size);
  return result;
}

void *calloc(size_t __nmemb, size_t __size) {
  void *result = NULL;
  void *(*libc_calloc)(size_t, size_t) = NULL;
  *(void **)(&libc_calloc) = dlsym((void *)-1l, "calloc");
  if (!memory_locked(0)) result = libc_calloc(__nmemb, __size);
  return result;
}

int memory_locked(int enabled) {
  static int value = 0;
  if (enabled == 1) value = 1;
  if (enabled == -1) value = 0;
  return value;
}
