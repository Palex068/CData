#include "tetris_test.h"

#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

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
  Suite *list_cases[] = {suite_hi_scores_load(),
                         suite_hi_scores_save(),
                         suite_tetris_loop(),
                         suite_game_locate(),
                         suite_game_init(),
                         suite_game_destroy(),
                         suite_game_info_init(),
                         suite_game_info_clean(),
                         suite_game_info_destroy(),
                         suite_game_info_next_init(),
                         suite_game_info_next_clean(),
                         suite_game_info_next_destroy(),
                         suite_figure_db_load(),
                         suite_figure_db_insert(),
                         suite_figure_db_destroy(),
                         suite_figure_create(),
                         suite_figure_destroy(),
                         suite_figure_load(),
                         suite_figure_copy(),
                         suite_figure_copy_body(),
                         suite_figure_set(),
                         suite_figure_unset(),
                         suite_figure_rotate(),
                         suite_figure_check(),
                         suite_kaboom(),
                         suite_fsm(),
                         suite_start_fn(),
                         suite_pause_fn(),
                         suite_spawn_fn(),
                         suite_move_fn(),
                         suite_shift_fn(),
                         suite_connect_fn(),
                         suite_game_over_fn(),
                         suite_terminate_fn(),
                         suite_left_fn(),
                         suite_right_fn(),
                         suite_up_fn(),
                         suite_down_fn(),
                         suite_action_fn(),
                         suite_userInput(),
                         suite_update_current_state(),
                         NULL};

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
  if (!memory_locked(__size, 0)) result = libc_malloc(__size);
  return result;
}

void *calloc(size_t __nmemb, size_t __size) {
  void *result = NULL;
  void *(*libc_calloc)(size_t, size_t) = NULL;
  *(void **)(&libc_calloc) = dlsym((void *)-1l, "calloc");
  if (!memory_locked(__size, 0)) result = libc_calloc(__nmemb, __size);
  return result;
}

void *memset(void *__s, int __c, size_t __n) {
  void *result = NULL;
  void *(*libc_memset)(void *, int, size_t) = NULL;
  *(void **)(&libc_memset) = dlsym((void *)-1l, "memset");
  if (!memory_locked(__n, 0)) result = libc_memset(__s, __c, __n);
  return result;
}

void *memcpy(void *__dest, const void *__src,
		     size_t __n) {
  void *result = NULL;
  void *(*libc_memcpy)(void*, const void*, size_t) = NULL;
  *(void **)(&libc_memcpy) = dlsym((void *)-1l, "memcpy");
  if (!memory_locked(__n, 0)) result = libc_memcpy(__dest, __src, __n);
  return result;
}

int memory_locked(size_t size, int locked) {
  static size_t value = 0;
  int result = 0;
  if (locked == 1) value = size;
  if (locked == -1) value = 0;
  if (locked == 0 && value == size) result = 1;
  return result;
}
