#include "../s21_tests_runner.h"

START_TEST(board_createBoard_00) {
  BG_GI_CEIL_TYPE **board = NULL;

  ck_assert_int_eq(TTRS_createBoard(&board), TTRS_Ok);

  ck_assert_int_eq(board[0][0], 0);

  TTRS_removeBoard(&board);
}
END_TEST

START_TEST(board_removeBoard_00) {
  BG_GI_CEIL_TYPE **board = NULL;

  TTRS_removeBoard(&board);
}
END_TEST

START_TEST(board_copyBoard_00) {
  BG_GI_CEIL_TYPE **board1;
  ck_assert_int_eq(TTRS_createBoard(&board1), TTRS_Ok);

  BG_GI_CEIL_TYPE **board2;
  ck_assert_int_eq(TTRS_createBoard(&board2), TTRS_Ok);

  TTRS_copyBoard(&board1, &board2);

  for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; ++i) {
    for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; ++j) {
      ck_assert_int_eq(board2[i][j], board1[i][j]);
    }
  }

  TTRS_removeTetromino(&board1);
  TTRS_removeTetromino(&board2);
}
END_TEST

START_TEST(board_copyBoard_01) {
  BG_GI_CEIL_TYPE **board1;
  ck_assert_int_eq(TTRS_createBoard(&board1), TTRS_Ok);

  BG_GI_CEIL_TYPE **board2;
  ck_assert_int_eq(TTRS_createBoard(&board2), TTRS_Ok);

  for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; ++i) {
    for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; ++j) {
      board1[i][j] = TTRS_FULL;
    }
  }

  TTRS_copyBoard(&board1, &board2);

  for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; ++i) {
    for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; ++j) {
      ck_assert_int_eq(board2[i][j], board1[i][j]);
    }
  }

  TTRS_removeTetromino(&board1);
  TTRS_removeTetromino(&board2);
}
END_TEST

START_TEST(board_copyBoard_02) {
  BG_GI_CEIL_TYPE **board1;
  ck_assert_int_eq(TTRS_createBoard(&board1), TTRS_Ok);

  BG_GI_CEIL_TYPE **board2;
  ck_assert_int_eq(TTRS_createBoard(&board2), TTRS_Ok);

  for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; ++i) {
    for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; ++j) {
      board1[i][j] = TTRS_EMPTY;
      board2[i][j] = TTRS_FULL;
    }
  }

  TTRS_copyBoard(&board1, &board2);

  for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; ++i) {
    for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; ++j) {
      ck_assert_int_eq(board2[i][j], board1[i][j]);
    }
  }

  TTRS_removeTetromino(&board1);
  TTRS_removeTetromino(&board2);
}
END_TEST

START_TEST(board_checkingCollisionTetrominoWithBoard_00) {
  TTRS_tetris_t tetris;
  TTRS_initTetris(&tetris);

  ck_assert_int_eq(
      TTRS_checkingCollisionTetrominoWithBoard(
          tetris.cur_tetromino, tetris.cur_tetromino_pos, tetris.board),
      0);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(board_checkingCollisionTetrominoWithBoard_01) {
  TTRS_tetris_t tetris;
  TTRS_initTetris(&tetris);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; j++) {
      tetris.cur_tetromino[i][j] = TTRS_FULL;
    }
  }

  ck_assert_int_eq(
      TTRS_checkingCollisionTetrominoWithBoard(
          tetris.cur_tetromino, tetris.cur_tetromino_pos, tetris.board),
      0);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(board_checkingCollisionTetrominoWithBoard_02) {
  TTRS_tetris_t tetris;
  TTRS_initTetris(&tetris);

  for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; i++) {
    for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; j++) {
      tetris.board[i][j] = TTRS_FULL;
    }
  }

  ck_assert_int_eq(
      TTRS_checkingCollisionTetrominoWithBoard(
          tetris.cur_tetromino, tetris.cur_tetromino_pos, tetris.board),
      0);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(board_checkingCollisionTetrominoWithBoard_03) {
  TTRS_tetris_t tetris;
  TTRS_initTetris(&tetris);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; j++) {
      tetris.cur_tetromino[i][j] = TTRS_FULL;
    }
  }

  for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; i++) {
    for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; j++) {
      tetris.board[i][j] = TTRS_FULL;
    }
  }

  ck_assert_int_ne(
      TTRS_checkingCollisionTetrominoWithBoard(
          tetris.cur_tetromino, tetris.cur_tetromino_pos, tetris.board),
      0);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(board_checkingCollisionTetrominoWithBoard_04) {
  TTRS_tetris_t tetris;
  TTRS_initTetris(&tetris);

  tetris.cur_tetromino[0][0] = TTRS_FULL;

  for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; i++) {
    for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; j++) {
      tetris.board[i][j] = TTRS_FULL;
    }
  }

  ck_assert_int_ne(
      TTRS_checkingCollisionTetrominoWithBoard(
          tetris.cur_tetromino, tetris.cur_tetromino_pos, tetris.board),
      0);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(board_addCurrentTetrominoInBoard_00) {
  TTRS_tetris_t tetris;
  TTRS_initTetris(&tetris);

  TTRS_addTetrominoInBoard(tetris.cur_tetromino,
                           tetris.cur_tetromino_pos, tetris.board);

  for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; i++) {
    for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; j++) {
      ck_assert_int_eq(tetris.board[i][j], 0);
    }
  }

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(board_addCurrentTetrominoInBoard_01) {
  TTRS_tetris_t tetris;
  TTRS_initTetris(&tetris);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; j++) {
      tetris.cur_tetromino[i][j] = TTRS_FULL;
    }
  }

  TTRS_addTetrominoInBoard(tetris.cur_tetromino,
                           tetris.cur_tetromino_pos, tetris.board);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; j++) {
      ck_assert_int_ne(tetris.board[tetris.cur_tetromino_pos.x + i]
                                   [tetris.cur_tetromino_pos.y + j],
                       0);
    }
  }

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(board_addCurrentTetrominoInBoard_02) {
  TTRS_tetris_t tetris;
  TTRS_initTetris(&tetris);

  tetris.cur_tetromino[0][0] = TTRS_FULL;

  TTRS_addTetrominoInBoard(tetris.cur_tetromino,
                           tetris.cur_tetromino_pos, tetris.board);

  ck_assert_int_ne(tetris.board[tetris.cur_tetromino_pos.y]
                               [tetris.cur_tetromino_pos.x],
                   0);

  for (size_t i = 1; i < BG_BOARD_ROWS_COUNT; i++) {
    ck_assert_int_eq(tetris.board[tetris.cur_tetromino_pos.y]
                                 [tetris.cur_tetromino_pos.x + i],
                     0);
  }

  for (size_t i = 1; i < BG_BOARD_ROWS_COUNT; i++) {
    for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; j++) {
      ck_assert_int_eq(tetris.board[i][j], 0);
    }
  }

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(board_addCurrentTetrominoInBoard_03) {
  TTRS_tetris_t tetris;
  TTRS_initTetris(&tetris);

  tetris.cur_tetromino[BG_TETROMINO_SIZE - 1][BG_TETROMINO_SIZE - 1] =
      TTRS_FULL;

  TTRS_addTetrominoInBoard(tetris.cur_tetromino,
                           tetris.cur_tetromino_pos, tetris.board);

  ck_assert_int_ne(tetris.board[tetris.cur_tetromino_pos.y + 3]
                               [tetris.cur_tetromino_pos.x + 3],
                   0);

  TTRS_removeTetris(&tetris);
}
END_TEST

START_TEST(board_addCurrentTetrominoInBoard_04) {
  TTRS_tetris_t tetris;
  TTRS_initTetris(&tetris);

  tetris.cur_tetromino_pos.x = 2;
  tetris.cur_tetromino_pos.y = 2;

  tetris.cur_tetromino[0][0] = TTRS_FULL;

  TTRS_addTetrominoInBoard(tetris.cur_tetromino,
                           tetris.cur_tetromino_pos, tetris.board);

  ck_assert_int_ne(tetris.board[tetris.cur_tetromino_pos.y]
                               [tetris.cur_tetromino_pos.x],
                   0);

  TTRS_removeTetris(&tetris);
}
END_TEST

Suite *board_suite() {
  TCase *tcase = tcase_create("board_tcase");
  Suite *suite = suite_create("board");

  tcase_add_test(tcase, board_createBoard_00);
  tcase_add_test(tcase, board_removeBoard_00);

  tcase_add_test(tcase, board_copyBoard_00);
  tcase_add_test(tcase, board_copyBoard_01);
  tcase_add_test(tcase, board_copyBoard_02);

  tcase_add_test(tcase, board_checkingCollisionTetrominoWithBoard_00);
  tcase_add_test(tcase, board_checkingCollisionTetrominoWithBoard_01);
  tcase_add_test(tcase, board_checkingCollisionTetrominoWithBoard_02);
  tcase_add_test(tcase, board_checkingCollisionTetrominoWithBoard_03);
  tcase_add_test(tcase, board_checkingCollisionTetrominoWithBoard_04);

  tcase_add_test(tcase, board_addCurrentTetrominoInBoard_00);
  tcase_add_test(tcase, board_addCurrentTetrominoInBoard_01);
  tcase_add_test(tcase, board_addCurrentTetrominoInBoard_02);
  tcase_add_test(tcase, board_addCurrentTetrominoInBoard_03);
  tcase_add_test(tcase, board_addCurrentTetrominoInBoard_04);

  suite_add_tcase(suite, tcase);
  return suite;
}
