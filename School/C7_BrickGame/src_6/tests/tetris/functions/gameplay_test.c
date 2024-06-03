#include "../s21_tests_runner.h"

START_TEST(gameplay_getAllTetromino_00) {
  BG_GI_CEIL_TYPE tetrominos[BG_TETROMINOS_COUNT][BG_TETROMINO_SIZE]
                            [BG_TETROMINO_SIZE] = {};

  TTRS_getAllStaticTetromino(tetrominos);

  ck_assert_int_eq(tetrominos[0][0][0], 0);

  ck_assert_int_ne(tetrominos[0][1][0], 0);
  ck_assert_int_ne(tetrominos[0][1][1], 0);
  ck_assert_int_ne(tetrominos[0][1][2], 0);
  ck_assert_int_ne(tetrominos[0][1][3], 0);
}
END_TEST

START_TEST(gameplay_getRandomTetromino_00) {
  BG_GI_CEIL_TYPE **tetromino = NULL;

  ck_assert_int_eq(TTRS_createTetromino(&tetromino), TTRS_Ok);

  ck_assert_int_eq(TTRS_getRandomTetromino(tetromino), TTRS_Ok);
}
END_TEST

START_TEST(gameplay_getRandomTetromino_01) {
  BG_GI_CEIL_TYPE **tetromino = NULL;

  ck_assert_int_eq(TTRS_createTetromino(&tetromino), TTRS_Ok);

  ck_assert_int_eq(TTRS_getRandomTetromino(tetromino), TTRS_Ok);

  int is_full = 0;
  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      if (tetromino[i][j] != TTRS_EMPTY) {
        is_full = 1;
        break;
      }
    }
  }
  ck_assert_int_eq(is_full, 1);
}
END_TEST

START_TEST(gameplay_completeLineInBoard_00) {
  BG_GI_CEIL_TYPE **board = NULL;

  ck_assert_int_eq(TTRS_createBoard(&board), TTRS_Ok);

  ck_assert_int_eq(TTRS_completeLineInBoard(board), 0);

  TTRS_removeBoard(&board);
}
END_TEST

START_TEST(gameplay_completeLineInBoard_01) {
  BG_GI_CEIL_TYPE **board = NULL;

  ck_assert_int_eq(TTRS_createBoard(&board), TTRS_Ok);

  for (size_t i = 0; i < BG_BOARD_COLUMNS_COUNT; ++i) {
    board[0][i] = TTRS_FULL;
  }

  ck_assert_int_eq(TTRS_completeLineInBoard(board), 1);

  for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; ++i) {
    for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; ++j) {
      ck_assert_int_eq(board[i][j], TTRS_EMPTY);
    }
  }

  TTRS_removeBoard(&board);
}
END_TEST

START_TEST(gameplay_completeLineInBoard_02) {
  BG_GI_CEIL_TYPE **board = NULL;

  ck_assert_int_eq(TTRS_createBoard(&board), TTRS_Ok);

  for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; ++i) {
    for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; ++j) {
      board[i][j] = TTRS_FULL;
    }
  }

  ck_assert_int_eq(TTRS_completeLineInBoard(board), BG_BOARD_ROWS_COUNT);

  for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; ++i) {
    for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; ++j) {
      ck_assert_int_eq(board[i][j], TTRS_EMPTY);
    }
  }

  TTRS_removeBoard(&board);
}
END_TEST

START_TEST(gameplay_completeLineInBoard_03) {
  BG_GI_CEIL_TYPE **board = NULL;

  ck_assert_int_eq(TTRS_createBoard(&board), TTRS_Ok);

  board[0][0] = TTRS_FULL;

  ck_assert_int_eq(TTRS_completeLineInBoard(board), 0);

  ck_assert_int_eq(board[0][0], TTRS_FULL);

  TTRS_removeBoard(&board);
}
END_TEST

START_TEST(gameplay_completeLineInBoard_04) {
  BG_GI_CEIL_TYPE **board = NULL;

  ck_assert_int_eq(TTRS_createBoard(&board), TTRS_Ok);

  for (size_t i = 0; i < BG_BOARD_COLUMNS_COUNT - 1; ++i) {
    board[0][i] = TTRS_FULL;
  }

  ck_assert_int_eq(TTRS_completeLineInBoard(board), 0);

  ck_assert_int_eq(board[0][BG_BOARD_COLUMNS_COUNT - 1], TTRS_EMPTY);

  for (size_t i = 0; i < BG_BOARD_COLUMNS_COUNT - 1; ++i) {
    ck_assert_int_eq(board[0][i], TTRS_FULL);
  }

  TTRS_removeBoard(&board);
}
END_TEST

START_TEST(gameplay_isTetrominoOutsideBoard_00) {
  BG_GI_CEIL_TYPE **tetromino = NULL;
  BG_Point2D_t tetromino_pos = {.x = 0, .y = 0};

  ck_assert_int_eq(TTRS_createTetromino(&tetromino), TTRS_Ok);

  ck_assert_int_eq(TTRS_isTetrominoOutsideBoard(tetromino, tetromino_pos), 0);

  TTRS_removeBoard(&tetromino);
}
END_TEST

START_TEST(gameplay_isTetrominoOutsideBoard_01) {
  BG_GI_CEIL_TYPE **tetromino = NULL;
  BG_Point2D_t tetromino_pos = {.x = 0, .y = 0};

  ck_assert_int_eq(TTRS_createTetromino(&tetromino), TTRS_Ok);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      tetromino[i][j] = TTRS_FULL;
    }
  }

  ck_assert_int_eq(TTRS_isTetrominoOutsideBoard(tetromino, tetromino_pos), 0);

  TTRS_removeBoard(&tetromino);
}
END_TEST

START_TEST(gameplay_isTetrominoOutsideBoard_02) {
  BG_GI_CEIL_TYPE **tetromino = NULL;
  BG_Point2D_t tetromino_pos = {.x = BG_BOARD_COLUMNS_COUNT / 2,
                                .y = BG_BOARD_ROWS_COUNT / 2};

  ck_assert_int_eq(TTRS_createTetromino(&tetromino), TTRS_Ok);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      tetromino[i][j] = TTRS_FULL;
    }
  }

  ck_assert_int_eq(TTRS_isTetrominoOutsideBoard(tetromino, tetromino_pos), 0);

  TTRS_removeBoard(&tetromino);
}
END_TEST

START_TEST(gameplay_isTetrominoOutsideBoard_03) {
  BG_GI_CEIL_TYPE **tetromino = NULL;
  BG_Point2D_t tetromino_pos = {.x = BG_BOARD_COLUMNS_COUNT + BG_TETROMINO_SIZE,
                                .y = BG_BOARD_ROWS_COUNT + BG_TETROMINO_SIZE};

  ck_assert_int_eq(TTRS_createTetromino(&tetromino), TTRS_Ok);

  ck_assert_int_eq(TTRS_isTetrominoOutsideBoard(tetromino, tetromino_pos), 0);

  TTRS_removeBoard(&tetromino);
}
END_TEST

START_TEST(gameplay_isTetrominoOutsideBoard_04) {
  BG_GI_CEIL_TYPE **tetromino = NULL;
  BG_Point2D_t tetromino_pos = {.x = -BG_TETROMINO_SIZE,
                                .y = -BG_TETROMINO_SIZE};

  ck_assert_int_eq(TTRS_createTetromino(&tetromino), TTRS_Ok);

  ck_assert_int_eq(TTRS_isTetrominoOutsideBoard(tetromino, tetromino_pos), 0);

  TTRS_removeBoard(&tetromino);
}
END_TEST

START_TEST(gameplay_isTetrominoOutsideBoard_05) {
  BG_GI_CEIL_TYPE **tetromino = NULL;
  BG_Point2D_t tetromino_pos = {.x = -1, .y = 0};

  ck_assert_int_eq(TTRS_createTetromino(&tetromino), TTRS_Ok);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      tetromino[i][j] = TTRS_FULL;
    }
  }

  ck_assert_int_eq(TTRS_isTetrominoOutsideBoard(tetromino, tetromino_pos), 1);

  TTRS_removeBoard(&tetromino);
}
END_TEST

START_TEST(gameplay_isTetrominoOutsideBoard_06) {
  BG_GI_CEIL_TYPE **tetromino = NULL;
  BG_Point2D_t tetromino_pos = {.x = 0, .y = -1};

  ck_assert_int_eq(TTRS_createTetromino(&tetromino), TTRS_Ok);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      tetromino[i][j] = TTRS_FULL;
    }
  }

  ck_assert_int_eq(TTRS_isTetrominoOutsideBoard(tetromino, tetromino_pos), 1);

  TTRS_removeBoard(&tetromino);
}
END_TEST

START_TEST(gameplay_isTetrominoOutsideBoard_07) {
  BG_GI_CEIL_TYPE **tetromino = NULL;
  BG_Point2D_t tetromino_pos = {.x = BG_BOARD_COLUMNS_COUNT,
                                .y = BG_BOARD_ROWS_COUNT};

  ck_assert_int_eq(TTRS_createTetromino(&tetromino), TTRS_Ok);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      tetromino[i][j] = TTRS_FULL;
    }
  }

  ck_assert_int_eq(TTRS_isTetrominoOutsideBoard(tetromino, tetromino_pos), 1);

  TTRS_removeBoard(&tetromino);
}
END_TEST

START_TEST(gameplay_isTetrominoOutsideBoard_08) {
  BG_GI_CEIL_TYPE **tetromino = NULL;
  BG_Point2D_t tetromino_pos = {.x = -1, .y = -1};

  ck_assert_int_eq(TTRS_createTetromino(&tetromino), TTRS_Ok);

  tetromino[0][0] = TTRS_FULL;

  ck_assert_int_eq(TTRS_isTetrominoOutsideBoard(tetromino, tetromino_pos), 1);

  TTRS_removeBoard(&tetromino);
}
END_TEST

START_TEST(gameplay_getRewardByCompleteLines_00) {
  ck_assert_int_eq(TTRS_getRewardByCompleteLines(1), 100);
  ck_assert_int_eq(TTRS_getRewardByCompleteLines(2), 300);
  ck_assert_int_eq(TTRS_getRewardByCompleteLines(3), 700);
  ck_assert_int_eq(TTRS_getRewardByCompleteLines(4), 1500);

  ck_assert_int_eq(TTRS_getRewardByCompleteLines(-1), 0);

  ck_assert_int_eq(TTRS_getRewardByCompleteLines(100), 0);
}
END_TEST

Suite *gameplay_suite() {
  TCase *tcase = tcase_create("gameplay_tcase");
  Suite *suite = suite_create("gameplay");

  tcase_add_test(tcase, gameplay_getAllTetromino_00);

  tcase_add_test(tcase, gameplay_getRandomTetromino_00);
  tcase_add_loop_test(tcase, gameplay_getRandomTetromino_01, 0, 5);

  tcase_add_test(tcase, gameplay_completeLineInBoard_00);
  tcase_add_test(tcase, gameplay_completeLineInBoard_01);
  tcase_add_test(tcase, gameplay_completeLineInBoard_02);
  tcase_add_test(tcase, gameplay_completeLineInBoard_03);
  tcase_add_test(tcase, gameplay_completeLineInBoard_04);

  tcase_add_test(tcase, gameplay_isTetrominoOutsideBoard_00);
  tcase_add_test(tcase, gameplay_isTetrominoOutsideBoard_01);
  tcase_add_test(tcase, gameplay_isTetrominoOutsideBoard_02);
  tcase_add_test(tcase, gameplay_isTetrominoOutsideBoard_03);
  tcase_add_test(tcase, gameplay_isTetrominoOutsideBoard_04);
  tcase_add_test(tcase, gameplay_isTetrominoOutsideBoard_05);
  tcase_add_test(tcase, gameplay_isTetrominoOutsideBoard_06);
  tcase_add_test(tcase, gameplay_isTetrominoOutsideBoard_07);
  tcase_add_test(tcase, gameplay_isTetrominoOutsideBoard_08);

  tcase_add_test(tcase, gameplay_getRewardByCompleteLines_00);

  suite_add_tcase(suite, tcase);
  return suite;
}
