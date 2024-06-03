#include <check.h>

#include "tetris.h"

START_TEST(suite_game_locate_test1) {
  void *result = NULL;
  result = (void *)game_locate(NULL);
  ck_assert_ptr_eq(result, (void *)NULL);
}
END_TEST

START_TEST(suite_game_locate_test2) {
  void *result = NULL;
  game_t game = {0};
  result = (void *)game_locate(&game);
  // Clean the location
  game_locate(&game);
  ck_assert_ptr_eq(result, (void *)&game);
}
END_TEST

START_TEST(suite_game_locate_test3) {
  void *result = NULL;
  game_t game = {0};
  game_locate(&game);
  // Clean the location
  game_locate(&game);
  result = (void *)game_locate(NULL);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

Suite *suite_game_locate() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_game_locate=-\x1b[0m");

  tc = tcase_create("suite_game_locate");
  tcase_add_test(tc, suite_game_locate_test1);
  tcase_add_test(tc, suite_game_locate_test2);
  tcase_add_test(tc, suite_game_locate_test3);

  suite_add_tcase(s, tc);

  return s;
}