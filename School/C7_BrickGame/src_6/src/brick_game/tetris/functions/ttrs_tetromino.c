#include "../../../../includes/brick_game/v1/logic/tetris.h"

TTRS_RETURN_TYPE TTRS_createTetromino(BG_GI_CEIL_TYPE ***tetromino) {
  TTRS_RETURN_TYPE return_result = TTRS_Ok;
  {
    *tetromino = (BG_GI_CEIL_TYPE **)calloc(
        (BG_TETROMINO_SIZE * sizeof(BG_GI_CEIL_TYPE *)) +
            (BG_TETROMINO_SIZE * BG_TETROMINO_SIZE * sizeof(BG_GI_CEIL_TYPE)),
        1);

    if (*tetromino) {
      (*tetromino)[0] = (BG_GI_CEIL_TYPE *)(*tetromino + BG_TETROMINO_SIZE);
      for (BG_POINT2D_TYPE i = 1; i < BG_TETROMINO_SIZE; i++) {
        (*tetromino)[i] = (*tetromino)[0] + i * BG_TETROMINO_SIZE;
      }

    } else {
      return_result = TTRS_MemoryError;
    }
  }

  return return_result;
}

void TTRS_removeTetromino(BG_GI_CEIL_TYPE ***tetromino) {
  free(*tetromino);

  *tetromino = NULL;
}

void TTRS_copyTetromino(BG_GI_CEIL_TYPE ***tetromino,
                        BG_GI_CEIL_TYPE ***tetromino_copy) {
  if (tetromino && tetromino_copy) {
    for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
      for (size_t j = 0; j < BG_TETROMINO_SIZE; j++) {
        (*tetromino_copy)[i][j] = (*tetromino)[i][j];
      }
    }
  }
}

TTRS_RETURN_TYPE TTRS_rotateTetromino(BG_GI_CEIL_TYPE **tetromino, char left) {
  if (!tetromino) {
    return TTRS_Error;
  }

  static BG_GI_CEIL_TYPE temp_tetromino[BG_TETROMINO_SIZE][BG_TETROMINO_SIZE] =
      {};

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      temp_tetromino[i][j] = tetromino[(BG_TETROMINO_SIZE - 1) - j][i];
      if (left) {
        temp_tetromino[i][j] = tetromino[j][(BG_TETROMINO_SIZE - 1) - i];
      } else {
        temp_tetromino[i][j] = tetromino[(BG_TETROMINO_SIZE - 1) - j][i];
      }
    }
  }

  for (size_t i = 0; i < BG_TETROMINO_SIZE; ++i) {
    for (size_t j = 0; j < BG_TETROMINO_SIZE; ++j) {
      tetromino[i][j] = temp_tetromino[i][j];
    }
  }

  return TTRS_Ok;
}
