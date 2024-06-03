#include "../s21_tests_runner.h"

START_TEST(tetromino_create_Tetromino_00) {
  BG_GI_CEIL_TYPE **tetromino1;
  ck_assert_int_eq(TTRS_createTetromino(&tetromino1), TTRS_Ok);

  ck_assert_int_eq(tetromino1[0][0], 0);

  TTRS_removeTetromino(&tetromino1);
}
END_TEST

START_TEST(tetromino_remove_Tetromino_00) {
  BG_GI_CEIL_TYPE **tetromino1 = NULL;

  TTRS_removeTetromino(&tetromino1);
}
END_TEST

START_TEST(tetromino_copyTetromino_00) {
  BG_GI_CEIL_TYPE **tetromino1;
  ck_assert_int_eq(TTRS_createTetromino(&tetromino1), TTRS_Ok);

  BG_GI_CEIL_TYPE **tetromino2;
  ck_assert_int_eq(TTRS_createTetromino(&tetromino2), TTRS_Ok);

  TTRS_copyTetromino(&tetromino1, &tetromino2);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      ck_assert_int_eq(tetromino2[i][j], tetromino1[i][j]);
    }
  }

  TTRS_removeTetromino(&tetromino1);
  TTRS_removeTetromino(&tetromino2);
}
END_TEST

START_TEST(tetromino_copyTetromino_01) {
  BG_GI_CEIL_TYPE **tetromino1;
  ck_assert_int_eq(TTRS_createTetromino(&tetromino1), TTRS_Ok);

  BG_GI_CEIL_TYPE **tetromino2;
  ck_assert_int_eq(TTRS_createTetromino(&tetromino2), TTRS_Ok);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; j++) {
      tetromino1[i][j] = TTRS_FULL;
    }
  }

  TTRS_copyTetromino(&tetromino1, &tetromino2);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      ck_assert_int_eq(tetromino2[i][j], tetromino1[i][j]);
    }
  }

  TTRS_removeTetromino(&tetromino1);
  TTRS_removeTetromino(&tetromino2);
}
END_TEST

START_TEST(tetromino_copyTetromino_02) {
  BG_GI_CEIL_TYPE **tetromino1;
  ck_assert_int_eq(TTRS_createTetromino(&tetromino1), TTRS_Ok);

  BG_GI_CEIL_TYPE **tetromino2;
  ck_assert_int_eq(TTRS_createTetromino(&tetromino2), TTRS_Ok);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; j++) {
      tetromino1[i][j] = TTRS_EMPTY;
      tetromino2[i][j] = TTRS_FULL;
    }
  }

  TTRS_copyTetromino(&tetromino1, &tetromino2);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      ck_assert_int_eq(tetromino2[i][j], tetromino1[i][j]);
    }
  }

  TTRS_removeTetromino(&tetromino1);
  TTRS_removeTetromino(&tetromino2);
}
END_TEST

START_TEST(tetromino_rotateTetromino_00) {
  BG_GI_CEIL_TYPE tetromino1[BG_TETROMINO_SIZE][BG_TETROMINO_SIZE] = {
      {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  BG_GI_CEIL_TYPE **tetromino2;
  TTRS_createTetromino(&tetromino2);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    memcpy(tetromino1[i], tetromino2[i],
           BG_TETROMINO_SIZE * sizeof(BG_GI_CEIL_TYPE));
  }

  TTRS_rotateTetromino(tetromino2, false);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      ck_assert_int_eq(tetromino2[i][j],
                       tetromino1[(BG_TETROMINO_SIZE - 1) - j][i]);
    }
  }

  TTRS_removeTetromino(&tetromino2);
}
END_TEST

START_TEST(tetromino_rotateTetromino_01) {
  BG_GI_CEIL_TYPE tetromino1[BG_TETROMINO_SIZE][BG_TETROMINO_SIZE] = {
      {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  BG_GI_CEIL_TYPE **tetromino2;
  TTRS_createTetromino(&tetromino2);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    memcpy(tetromino1[i], tetromino2[i],
           BG_TETROMINO_SIZE * sizeof(BG_GI_CEIL_TYPE));
  }

  TTRS_rotateTetromino(tetromino2, false);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    memcpy(tetromino1[i], tetromino2[i],
           BG_TETROMINO_SIZE * sizeof(BG_GI_CEIL_TYPE));
  }

  TTRS_rotateTetromino(tetromino2, false);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      ck_assert_int_eq(tetromino2[i][j],
                       tetromino1[(BG_TETROMINO_SIZE - 1) - j][i]);
    }
  }

  TTRS_removeTetromino(&tetromino2);
}
END_TEST

START_TEST(tetromino_rotateTetromino_02) {
  BG_GI_CEIL_TYPE tetromino1[BG_TETROMINO_SIZE][BG_TETROMINO_SIZE] = {
      {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  BG_GI_CEIL_TYPE **tetromino2;
  TTRS_createTetromino(&tetromino2);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    memcpy(tetromino1[i], tetromino2[i],
           BG_TETROMINO_SIZE * sizeof(BG_GI_CEIL_TYPE));
  }

  TTRS_rotateTetromino(tetromino2, false);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    memcpy(tetromino1[i], tetromino2[i],
           BG_TETROMINO_SIZE * sizeof(BG_GI_CEIL_TYPE));
  }

  TTRS_rotateTetromino(tetromino2, false);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    memcpy(tetromino1[i], tetromino2[i],
           BG_TETROMINO_SIZE * sizeof(BG_GI_CEIL_TYPE));
  }

  TTRS_rotateTetromino(tetromino2, false);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      ck_assert_int_eq(tetromino2[i][j],
                       tetromino1[(BG_TETROMINO_SIZE - 1) - j][i]);
    }
  }

  TTRS_removeTetromino(&tetromino2);
}
END_TEST

START_TEST(tetromino_rotateTetromino_03) {
  BG_GI_CEIL_TYPE tetromino1[BG_TETROMINO_SIZE][BG_TETROMINO_SIZE] = {
      {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  BG_GI_CEIL_TYPE **tetromino2;
  TTRS_createTetromino(&tetromino2);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    memcpy(tetromino1[i], tetromino2[i],
           BG_TETROMINO_SIZE * sizeof(BG_GI_CEIL_TYPE));
  }

  TTRS_rotateTetromino(tetromino2, false);
  TTRS_rotateTetromino(tetromino2, false);
  TTRS_rotateTetromino(tetromino2, false);
  TTRS_rotateTetromino(tetromino2, false);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      ck_assert_int_eq(tetromino1[i][j], tetromino2[i][j]);
    }
  }

  TTRS_removeTetromino(&tetromino2);
}
END_TEST

START_TEST(tetromino_rotateTetromino_04) {
  BG_GI_CEIL_TYPE tetromino1[BG_TETROMINO_SIZE][BG_TETROMINO_SIZE] = {
      {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  BG_GI_CEIL_TYPE **tetromino2;
  TTRS_createTetromino(&tetromino2);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    memcpy(tetromino1[i], tetromino2[i],
           BG_TETROMINO_SIZE * sizeof(BG_GI_CEIL_TYPE));
  }

  TTRS_rotateTetromino(tetromino2, true);
  TTRS_rotateTetromino(tetromino2, true);
  TTRS_rotateTetromino(tetromino2, true);
  TTRS_rotateTetromino(tetromino2, true);

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      ck_assert_int_eq(tetromino1[i][j], tetromino2[i][j]);
    }
  }

  TTRS_removeTetromino(&tetromino2);
}
END_TEST

Suite *tetromino_suite() {
  TCase *tcase = tcase_create("tetromino_tcase");
  Suite *suite = suite_create("tetromino");

  tcase_add_test(tcase, tetromino_create_Tetromino_00);
  tcase_add_test(tcase, tetromino_remove_Tetromino_00);

  tcase_add_test(tcase, tetromino_copyTetromino_00);
  tcase_add_test(tcase, tetromino_copyTetromino_01);
  tcase_add_test(tcase, tetromino_copyTetromino_02);

  tcase_add_test(tcase, tetromino_rotateTetromino_00);
  tcase_add_test(tcase, tetromino_rotateTetromino_01);
  tcase_add_test(tcase, tetromino_rotateTetromino_02);
  tcase_add_test(tcase, tetromino_rotateTetromino_03);
  tcase_add_test(tcase, tetromino_rotateTetromino_04);

  suite_add_tcase(suite, tcase);
  return suite;
}
