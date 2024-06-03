#include "../../../../includes/brick_game/v1/logic/tetris.h"

TTRS_RETURN_TYPE TTRS_createBoard(BG_GI_CEIL_TYPE ***board) {
  TTRS_RETURN_TYPE return_result = TTRS_Ok;
  {
    *board = (BG_GI_CEIL_TYPE **)calloc(
        (BG_BOARD_ROWS_COUNT * sizeof(BG_GI_CEIL_TYPE *)) +
            (BG_BOARD_COLUMNS_COUNT * BG_BOARD_ROWS_COUNT *
             sizeof(BG_GI_CEIL_TYPE)),
        1);

    if (*board) {
      (*board)[0] = (int *)(*board + BG_BOARD_ROWS_COUNT);
      for (BG_POINT2D_TYPE i = 1; i < BG_BOARD_ROWS_COUNT; i++) {
        (*board)[i] = (*board)[0] + i * BG_BOARD_COLUMNS_COUNT;
      }

    } else {
      return_result = TTRS_MemoryError;
    }
  }

  return return_result;
}

void TTRS_removeBoard(BG_GI_CEIL_TYPE ***board) {
  free(*board);

  *board = NULL;
}

// 0 == false / 1 == true, 2 == leftBoard, 3 == rightBoard, 4 == buttonBoard
char TTRS_checkingCollisionTetrominoWithBoard(BG_GI_CEIL_TYPE **tetromino,
                                              BG_Point2D_t tetromino_pos,
                                              BG_GI_CEIL_TYPE **board) {
  if (!tetromino || !board) {
    return 0;
  }
  char result = 0;

  for (ssize_t i = 0; !result && i < BG_TETROMINO_SIZE; i++) {
    for (ssize_t j = 0; !result && j < BG_TETROMINO_SIZE; j++) {
      if (tetromino[i][j] != TTRS_EMPTY) {
        if ((tetromino_pos.x + j >= 0 && tetromino_pos.y + i >= 0) &&
            (tetromino_pos.x + j < BG_BOARD_COLUMNS_COUNT &&
             tetromino_pos.y + i < BG_BOARD_ROWS_COUNT) &&
            board[tetromino_pos.y + i][tetromino_pos.x + j]) {
          result = 1;
        } else if (tetromino_pos.x + j < 0) {
          result = 2;
        } else if (tetromino_pos.x + j >= BG_BOARD_COLUMNS_COUNT) {
          result = 3;
        } else if (tetromino_pos.y + i >= BG_BOARD_ROWS_COUNT) {
          result = 4;
        }
      }
    }
  }

  return result;
}

void TTRS_copyBoard(BG_GI_CEIL_TYPE ***board, BG_GI_CEIL_TYPE ***board_copy) {
  if (board && board_copy) {
    for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; i++) {
      for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; j++) {
        (*board_copy)[i][j] = (*board)[i][j];
      }
    }
  }
}

void TTRS_addTetrominoInBoard(BG_GI_CEIL_TYPE **tetromino,
                              BG_Point2D_t tetromino_pos,
                              BG_GI_CEIL_TYPE **board) {
  if (tetromino && board) {
    for (BG_POINT2D_TYPE i = 0; i < BG_TETROMINO_SIZE; i++) {
      for (BG_POINT2D_TYPE j = 0; j < BG_TETROMINO_SIZE; j++) {
        if (tetromino[i][j] != TTRS_EMPTY &&
            (tetromino_pos.x + j >= 0 && tetromino_pos.y + i >= 0) &&
            (tetromino_pos.x + j < BG_BOARD_COLUMNS_COUNT &&
             tetromino_pos.y + i < BG_BOARD_ROWS_COUNT)) {
          board[tetromino_pos.y + i][tetromino_pos.x + j] = tetromino[i][j];
        }
      }
    }
  }
}
