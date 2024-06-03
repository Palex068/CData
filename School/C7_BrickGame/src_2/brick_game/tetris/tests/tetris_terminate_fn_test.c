#include <check.h>
#include <errno.h>

#include "tetris.h"

START_TEST(suite_terminate_fn_test1) {
  game_t *game = NULL;
  terminate_fn(game);
}
END_TEST

START_TEST(suite_terminate_fn_test2) {
  game_t *game = NULL;
  game_init(&game);
  for (fsm_state i = none; i <= game_over; i++) {
    game->state = i;
    terminate_fn(game);
    ck_assert(game->state == none);
  }
  game_destroy(game);
}
END_TEST

Suite *suite_terminate_fn() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_terminate_fn=-\x1b[0m");
  tc = tcase_create("suite_terminate_fn");

  if (s && tc) {
    tcase_add_test(tc, suite_terminate_fn_test1);
    tcase_add_test(tc, suite_terminate_fn_test2);

    suite_add_tcase(s, tc);
  }

  return s;
}