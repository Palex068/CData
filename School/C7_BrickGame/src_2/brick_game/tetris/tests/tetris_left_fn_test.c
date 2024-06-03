#include <check.h>
#include <errno.h>

#include "tetris.h"

START_TEST(suite_left_fn_test1) {
  game_t *game = NULL;
  left_fn(game);
}
END_TEST

START_TEST(suite_left_fn_test2) {
  game_t *game = NULL;
  game_init(&game);
  spawn_fn(game);
  for (int i = game->figure_pos.x; i > 0; i--) left_fn(game);
  ck_assert(game->figure_pos.x == 0);
  game_destroy(game);
}
END_TEST

START_TEST(suite_left_fn_test3) {
  // game_t *game = NULL;
  // game_init(&game);
  // spawn_fn(game);
  // game->game_info->field[0][3] = 1;
  // game->game_info->field[1][3] = 1;
  // game->game_info->field[2][3] = 1;
  // game->game_info->field[3][3] = 1;
  // left_fn(game);
  // left_fn(game);
  // left_fn(game);
  // ck_assert(game->figure_pos.x == 4);
  // ck_assert(game->modified == 1);
  // game_destroy(game);
}
END_TEST

Suite *suite_left_fn() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_left_fn=-\x1b[0m");
  tc = tcase_create("suite_left_fn");

  if (s && tc) {
    tcase_add_test(tc, suite_left_fn_test1);
    tcase_add_test(tc, suite_left_fn_test2);
    tcase_add_test(tc, suite_left_fn_test3);

    suite_add_tcase(s, tc);
  }

  return s;
}