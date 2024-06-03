#include "../s21_tests_runner.h"

START_TEST(interfaces_initTetris_00) {
  ck_assert_int_eq(TTRS_initTetris(NULL), TTRS_Error);
}
END_TEST

START_TEST(interfaces_initTetris_01) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  ck_assert_int_eq(tetris.state, TTRS_START_STATE);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(interfaces_userInput_00) { TTRS_userInput(BG_Action, true); }
END_TEST

START_TEST(interfaces_userInput_01) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  tetris.last_user_input.action = BG_Start;
  tetris.last_user_input.hold = false;

  TTRS_userInput(BG_Action, true);

  ck_assert_int_eq(tetris.last_user_input.action, BG_Action);
  ck_assert_int_eq(tetris.last_user_input.hold, true);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(interfaces_userInput_02) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  TTRS_userInput(BG_Action, false);

  ck_assert_int_eq(tetris.last_user_input.action, BG_Action);
  ck_assert_int_eq(tetris.last_user_input.hold, false);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(interfaces_userInput_03) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  TTRS_userInput(BG_Start, false);

  ck_assert_int_eq(tetris.last_user_input.action, BG_Start);
  ck_assert_int_eq(tetris.last_user_input.hold, false);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(interfaces_updateCurrentState_00) {
  BG_GameInfo_t game_info = TTRS_updateCurrentState();

  ck_assert_ptr_null(game_info.field);
}
END_TEST

START_TEST(interfaces_updateCurrentState_01) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  TTRS_gameStart();
  tetris.last_user_input.action = BG_Start;
  tetris.last_user_input.hold = true;

  BG_GameInfo_t game_info = TTRS_updateCurrentState();

  ck_assert_int_eq(tetris.state, TTRS_SPAWN_STATE);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; j++) {
      ck_assert_int_eq(tetris.next_tetromino[i][j], game_info.next[i][j]);
    }
  }

  ck_assert_int_eq(tetris.high_score, game_info.high_score);
  ck_assert_int_eq(tetris.score, game_info.score);

  ck_assert_int_eq(tetris.level, game_info.level);
  ck_assert_int_eq(tetris.speed, game_info.speed);

  ck_assert_int_eq(tetris.pause, game_info.pause);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(interfaces_updateCurrentState_02) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  TTRS_gameStart();
  tetris.last_user_input.action = BG_Start;
  tetris.last_user_input.hold = true;

  TTRS_updateCurrentState();
  BG_GameInfo_t game_info = TTRS_updateCurrentState();

  ck_assert_int_eq(tetris.state, TTRS_MOVING_STATE);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; j++) {
      ck_assert_int_eq(tetris.next_tetromino[i][j], game_info.next[i][j]);
    }
  }

  ck_assert_int_eq(tetris.high_score, game_info.high_score);
  ck_assert_int_eq(tetris.score, game_info.score);

  ck_assert_int_eq(tetris.level, game_info.level);
  ck_assert_int_eq(tetris.speed, game_info.speed);

  ck_assert_int_eq(tetris.pause, game_info.pause);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(interfaces_isGameEnd_00) { ck_assert_int_eq(TTRS_isGameEnd(), 1); }
END_TEST

START_TEST(interfaces_isGameEnd_01) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  ck_assert_int_eq(TTRS_isGameEnd(), 0);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(interfaces_isGameEnd_02) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  tetris.state = TTRS_EXIT_STATE;

  ck_assert_int_eq(TTRS_isGameEnd(), 1);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(interfaces_game_start_00) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  TTRS_gameStart();

  ck_assert_int_eq(tetris.is_game_start, 1);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(interfaces_setHighScore_00) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  tetris.high_score = 0;

  TTRS_setHighScore(100);

  ck_assert_int_eq(tetris.high_score, 100);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(interfaces_getHighScore_00) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  tetris.high_score = 100;

  ck_assert_int_eq(TTRS_getHighScore(), 100);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(interfaces_isPause_00) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  tetris.pause = 0;

  ck_assert_int_eq(TTRS_isPause(), 0);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(interfaces_isPause_01) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  tetris.pause = 1;

  ck_assert_int_eq(TTRS_isPause(), 1);

  TTRS_removeTetris(&tetris);
}
END_TEST

Suite *interfaces_suite() {
  TCase *tcase = tcase_create("interfaces_tcase");
  Suite *suite = suite_create("interfaces");

  tcase_add_test(tcase, interfaces_initTetris_00);
  tcase_add_test(tcase, interfaces_initTetris_01);

  tcase_add_test(tcase, interfaces_userInput_00);
  tcase_add_test(tcase, interfaces_userInput_01);
  tcase_add_test(tcase, interfaces_userInput_02);
  tcase_add_test(tcase, interfaces_userInput_03);

  tcase_add_test(tcase, interfaces_updateCurrentState_00);
  tcase_add_test(tcase, interfaces_updateCurrentState_01);
  tcase_add_test(tcase, interfaces_updateCurrentState_02);

  tcase_add_test(tcase, interfaces_isGameEnd_00);
  tcase_add_test(tcase, interfaces_isGameEnd_01);
  tcase_add_test(tcase, interfaces_isGameEnd_02);

  tcase_add_test(tcase, interfaces_game_start_00);

  tcase_add_test(tcase, interfaces_setHighScore_00);
  tcase_add_test(tcase, interfaces_getHighScore_00);

  tcase_add_test(tcase, interfaces_isPause_00);
  tcase_add_test(tcase, interfaces_isPause_01);

  suite_add_tcase(suite, tcase);
  return suite;
}
