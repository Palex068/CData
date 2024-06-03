#include <check.h>
#include <errno.h>

#include "tetris.h"

START_TEST(suite_right_fn_test1) {
  game_t *game = NULL;
  right_fn(game);
}
END_TEST

START_TEST(suite_right_fn_test2) {
  game_t *game = NULL;
  game_init(&game);
  spawn_fn(game);
  for (int i = game->figure_pos.x; i > 0; i--) right_fn(game);
  ck_assert(game->figure_pos.x == field_width - game->figure_cur->size);
  game_destroy(game);
}
END_TEST

START_TEST(suite_right_fn_test3) {
  // game_t *game = NULL;
  // game_init(&game);
  // game->game_info->field[0][9] = 1;
  // game->game_info->field[1][9] = 1;
  // game->game_info->field[2][9] = 1;
  // game->game_info->field[3][9] = 1;
  // spawn_fn(game);
  // right_fn(game);
  // right_fn(game);
  // right_fn(game);
  // ck_assert(game->figure_pos.x == 9 - game->figure_cur->size);
  // ck_assert(game->modified == 1);
  // game_destroy(game);
}
END_TEST

Suite *suite_right_fn() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_right_fn=-\x1b[0m");
  tc = tcase_create("suite_right_fn");

  if (s && tc) {
    tcase_add_test(tc, suite_right_fn_test1);
    tcase_add_test(tc, suite_right_fn_test2);
    tcase_add_test(tc, suite_right_fn_test3);

    suite_add_tcase(s, tc);
  }

  return s;
}