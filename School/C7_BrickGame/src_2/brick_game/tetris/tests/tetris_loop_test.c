#include <check.h>
#include <errno.h>
#include <pthread.h>
#include <stdatomic.h>
#include <stdbool.h>

#include "common/common.h"
#include "tetris.h"
#include "tetris_test.h"

START_TEST(suite_tetris_loop_test1) {
  void *result = NULL;
  result = tetris_loop(NULL);
  ck_assert_ptr_eq(result, (void *)EFAULT);
}
END_TEST

START_TEST(suite_tetris_loop_test2) {
  void *result = NULL;
  runtime_t runtime = {0};
  pthread_barrier_init(&runtime.barrier, NULL, 1);
  memory_locked(sizeof(game_t), 1);
  pthread_create(&runtime.model, NULL, (void *(*)(void *))tetris_loop,
                 (void *)&runtime);
  thread_wait(110);
  atomic_store(&runtime.msg_to_model, 1);
  thread_wait(300);
  atomic_store(&runtime.msg_to_model, 3);
  // userInput(Terminate, 0);
  atomic_store(&runtime.game_stop, 1);
  pthread_join(runtime.model, (void *)result);
  memory_locked(0, -1);
  pthread_barrier_destroy(&runtime.barrier);
  ck_assert_ptr_eq(result, (void *)0);
}
END_TEST

START_TEST(suite_tetris_loop_test3) {
  void *result = NULL;
  runtime_t runtime = {0};
  pthread_barrier_init(&runtime.barrier, NULL, 1);
  pthread_create(&runtime.model, NULL, (void *(*)(void *))tetris_loop,
                 (void *)&runtime);
  thread_wait(110);
  atomic_store(&runtime.msg_to_model, 1);
  thread_wait(1000);
  userInput(Terminate, 0);
  thread_wait(150);
  atomic_store(&runtime.game_stop, 1);
  pthread_join(runtime.model, (void *)result);
  pthread_barrier_destroy(&runtime.barrier);
  ck_assert_ptr_eq(result, (void *)0);
}
END_TEST

Suite *suite_tetris_loop() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_tetris_loop=-\x1b[0m");

  tc = tcase_create("suite_tetris_loop");
  tcase_add_test(tc, suite_tetris_loop_test1);
  tcase_add_test(tc, suite_tetris_loop_test2);
  tcase_add_test(tc, suite_tetris_loop_test3);

  suite_add_tcase(s, tc);

  return s;
}