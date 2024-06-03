#include <check.h>
#include <stdio.h>

#include "../brick_game/tetris/tetris.h"

START_TEST(tetris_test_1) {
  GameInfo_t *game = create_game();
  ck_assert_int_eq(game->status, Start);
  userInput(game, KEY_UP);
  ck_assert_int_eq(game->status, Rotation);
  userInput(game, KEY_DOWN);
  ck_assert_int_eq(game->status, Down);
  userInput(game, KEY_LEFT);
  ck_assert_int_eq(game->status, Left);
  userInput(game, KEY_RIGHT);
  ck_assert_int_eq(game->status, Right);
  userInput(game, ' ');
  ck_assert_int_eq(game->status, Pause);
  game->status = Terminate;
  free_gameinfo(game);
}
END_TEST

START_TEST(tetris_test_2) {
  GameInfo_t *game = create_game();
  update_score(game, 1);
  ck_assert_int_eq(game->score, 100);
  game->score = 0;
  update_score(game, 2);
  ck_assert_int_eq(game->score, 300);
  game->score = 0;
  update_score(game, 3);
  ck_assert_int_eq(game->score, 700);
  game->score = 0;
  update_score(game, 4);
  ck_assert_int_eq(game->score, 1500);
}
END_TEST

START_TEST(tetris_test_3) {
  GameInfo_t *game = create_game();
  for (int i = HEIGHT_WF - 1; i > 21; i--) {
    for (int j = 0; j < WIDTH; j++) {
      game->field[i][j] = 1;
    }
  }
  int pukish = 400;
  updateCurrentState(game, &pukish);
  ck_assert_int_eq(game->speed, 2);
}

END_TEST

int main() {
  Suite *s1 = suite_create("test_suite");
  TCase *tc1_1 = tcase_create("test_suite");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, tetris_test_1);
  tcase_add_test(tc1_1, tetris_test_2);
  tcase_add_test(tc1_1, tetris_test_3);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}