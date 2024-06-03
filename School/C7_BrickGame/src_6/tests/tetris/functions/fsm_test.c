#include "../s21_tests_runner.h"

START_TEST(fsm_selectNextState_00) {
  ck_assert_int_eq(TTRS_selectNextState(NULL), TTRS_Error);
}
END_TEST

START_TEST(fsm_selectNextState_01) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  TTRS_gameStart();
  tetris.last_user_input.action = BG_Start;
  tetris.last_user_input.hold = true;

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(fsm_selectNextState_02) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  TTRS_gameStart();
  tetris.last_user_input.action = BG_Start;
  tetris.last_user_input.hold = true;

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_SPAWN_STATE);

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_MOVING_STATE);

  tetris.is_fall_time = 1;
  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

  tetris.state = TTRS_ATTACHING_STATE;

  tetris.cur_tetromino_pos.x = BG_BOARD_COLUMNS_COUNT / 2;
  tetris.cur_tetromino_pos.y = BG_BOARD_ROWS_COUNT / 2;

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_SPAWN_STATE);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(fsm_selectNextState_03) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  TTRS_gameStart();
  tetris.last_user_input.action = BG_Start;
  tetris.last_user_input.hold = true;

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_SPAWN_STATE);

  for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; i++) {
    for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT - 1; j++) {
      tetris.board[i][j] = TTRS_FULL;
    }
  }

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_MOVING_STATE);

  tetris.last_user_input.action = BG_Down;
  tetris.last_user_input.hold = true;

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_GAME_OVER_STATE);

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(fsm_selectNextState_04) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  TTRS_gameStart();
  tetris.last_user_input.action = BG_Start;
  tetris.last_user_input.hold = true;

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_SPAWN_STATE);

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_MOVING_STATE);

  {
    tetris.last_user_input.action = BG_Pause;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

    tetris.last_user_input.action = BG_Pause;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

    tetris.last_user_input.action = BG_Action;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

    tetris.last_user_input.action = BG_Left;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

    tetris.last_user_input.action = BG_Right;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

    tetris.last_user_input.action = BG_Down;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

    tetris.last_user_input.action = BG_Down;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

    tetris.last_user_input.action = BG_Terminate;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

    tetris.state = TTRS_GAME_OVER_STATE;

    tetris.last_user_input.action = BG_Start;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

    tetris.state = TTRS_GAME_OVER_STATE;

    tetris.last_user_input.action = BG_Terminate;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  }

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_EXIT_STATE);

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(fsm_selectNextState_05) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  TTRS_gameStart();
  tetris.last_user_input.action = BG_Start;
  tetris.last_user_input.hold = true;

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_SPAWN_STATE);

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_MOVING_STATE);

  {
    tetris.last_user_input.action = BG_Left;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Left;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Left;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Left;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Left;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Left;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

    tetris.last_user_input.action = BG_Action;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Action;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  }

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(fsm_selectNextState_06) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  TTRS_gameStart();
  tetris.last_user_input.action = BG_Start;
  tetris.last_user_input.hold = true;

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_SPAWN_STATE);

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_MOVING_STATE);

  {
    tetris.last_user_input.action = BG_Right;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Right;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Right;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Right;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Right;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Right;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);

    tetris.last_user_input.action = BG_Action;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Action;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  }

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(fsm_selectNextState_07) {
  TTRS_tetris_t tetris;

  ck_assert_int_eq(TTRS_initTetris(&tetris), TTRS_Ok);

  TTRS_gameStart();
  tetris.last_user_input.action = BG_Start;
  tetris.last_user_input.hold = true;

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_SPAWN_STATE);

  ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  ck_assert_int_eq(tetris.state, TTRS_MOVING_STATE);

  {
    tetris.last_user_input.action = BG_Down;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Down;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Down;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Down;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Down;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
    tetris.last_user_input.action = BG_Down;
    tetris.last_user_input.hold = true;
    ck_assert_int_eq(TTRS_selectNextState(&tetris), TTRS_Ok);
  }

  TTRS_removeTetris(&tetris);
}
END_TEST

Suite *fsm_suite() {
  TCase *tcase = tcase_create("fsm_tcase");
  Suite *suite = suite_create("fsm");

  tcase_add_test(tcase, fsm_selectNextState_00);
  tcase_add_test(tcase, fsm_selectNextState_01);
  tcase_add_test(tcase, fsm_selectNextState_02);
  tcase_add_test(tcase, fsm_selectNextState_03);
  tcase_add_test(tcase, fsm_selectNextState_04);
  tcase_add_test(tcase, fsm_selectNextState_05);
  tcase_add_test(tcase, fsm_selectNextState_06);
  tcase_add_test(tcase, fsm_selectNextState_07);

  suite_add_tcase(suite, tcase);
  return suite;
}
