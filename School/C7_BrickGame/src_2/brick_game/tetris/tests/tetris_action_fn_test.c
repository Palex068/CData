#include <check.h>
#include <errno.h>

#include "tetris.h"

START_TEST(suite_action_fn_test1) {
  game_t *game = NULL;
  action_fn(game);
}
END_TEST

START_TEST(suite_action_fn_test2) {
  game_t *game = NULL;
  figure_t *figure = NULL;
  game_init(&game);
  spawn_fn(game);
  figure = figure_create(game->figure_cur->size);
  figure_copy(game->figure_cur, &figure);
  action_fn(game);
  int check = 1;
  for (int i = 0; check && i < game->figure_cur->size; i++) {
    for (int j = 0; check && j < game->figure_cur->size; j++)
      check = (figure->body[i][j] == game->figure_cur->body[i][j]);
  }
  game_destroy(game);
  figure_destroy(figure);
  ck_assert(check == 0);
}
END_TEST

START_TEST(suite_action_fn_test3) {
  // game_t *game = NULL;
  // figure_t *figure = NULL;
  // game_init(&game);
  // spawn_fn(game);
  // figure = figure_create(game->figure_cur->size);
  // figure_copy(game->figure_cur, &figure);
  // spawn_fn(game);
  // shift_fn(game);
  // shift_fn(game);
  // shift_fn(game);
  // action_fn(game);
  // int check = 1;
  // for (int i = 0; check && i < game->figure_cur->size; i++) {
  //   for (int j = 0; check && i < game->figure_cur->size; j++)
  //     check = (figure->body[i][j] == game->figure_cur->body[i][j]);
  // }
  // game_destroy(game);
  // figure_destroy(figure);
  // ck_assert(check == 0);
}
END_TEST

Suite *suite_action_fn() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_action_fn=-\x1b[0m");
  tc = tcase_create("suite_action_fn");

  if (s && tc) {
    tcase_add_test(tc, suite_action_fn_test1);
    tcase_add_test(tc, suite_action_fn_test2);
    tcase_add_test(tc, suite_action_fn_test3);

    suite_add_tcase(s, tc);
  }

  return s;
}