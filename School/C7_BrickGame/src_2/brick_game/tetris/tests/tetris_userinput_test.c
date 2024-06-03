#include <check.h>
#include <errno.h>

#include "tetris.h"

START_TEST(suite_userInput_test1) { userInput(-1, -1); }
END_TEST

START_TEST(suite_userInput_test2) { userInput(1, -1); }
END_TEST

START_TEST(suite_userInput_test3) { userInput(-1, 1); }
END_TEST

START_TEST(suite_userInput_test4) { userInput(1, 1); }
END_TEST

START_TEST(suite_userInput_test5) {
  int check = 0;
  game_t *game = NULL;
  game_init(&game);
  userInput(Start, 1);
  ck_assert(game->state == moving);
  userInput(Pause, 1);
  ck_assert(game->state == pause);
  userInput(Pause, 1);
  ck_assert(game->state == moving);
  check = game->figure_pos.x;
  userInput(Left, 1);
  ck_assert(game->figure_pos.x != check);
  check = game->figure_pos.x;
  userInput(Right, 1);
  ck_assert(game->figure_pos.x != check);
  check = game->figure_pos.y;
  userInput(Down, 1);
  ck_assert(game->figure_pos.y != check);
  userInput(Terminate, 1);
  ck_assert(game->state == none);
  game_destroy(game);
}
END_TEST

Suite *suite_userInput() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_userInput=-\x1b[0m");
  tc = tcase_create("suite_userInput");

  if (s && tc) {
    tcase_add_test(tc, suite_userInput_test1);
    tcase_add_test(tc, suite_userInput_test2);
    tcase_add_test(tc, suite_userInput_test3);
    tcase_add_test(tc, suite_userInput_test4);
    tcase_add_test(tc, suite_userInput_test5);

    suite_add_tcase(s, tc);
  }

  return s;
}