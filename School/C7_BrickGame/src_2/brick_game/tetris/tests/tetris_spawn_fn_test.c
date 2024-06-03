#include <check.h>
#include <errno.h>

#include "tetris.h"

START_TEST(suite_spawn_fn_test1) {
  game_t *game = NULL;
  spawn_fn(game);
}
END_TEST

START_TEST(suite_spawn_fn_test2) {
  game_t *game = NULL;
  game_init(&game);
  spawn_fn(game);
  ck_assert(game->state == moving);
  game_destroy(game);
}
END_TEST

START_TEST(suite_spawn_fn_test3) {
  game_t *game = NULL;
  game_init(&game);
  game->state = moving;
  spawn_fn(game);
  spawn_fn(game);
  ck_assert(game->state == game_over);
  game_destroy(game);
}
END_TEST

Suite *suite_spawn_fn() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_spawn_fn=-\x1b[0m");
  tc = tcase_create("suite_spawn_fn");

  if (s && tc) {
    tcase_add_test(tc, suite_spawn_fn_test1);
    tcase_add_test(tc, suite_spawn_fn_test2);
    tcase_add_test(tc, suite_spawn_fn_test3);

    suite_add_tcase(s, tc);
  }

  return s;
}