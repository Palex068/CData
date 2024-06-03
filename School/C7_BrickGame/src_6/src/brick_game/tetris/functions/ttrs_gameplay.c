#include "../../../../includes/brick_game/v1/logic/tetris.h"

void TTRS_getAllStaticTetromino(
    BG_GI_CEIL_TYPE tetrominos[BG_TETROMINOS_COUNT][BG_TETROMINO_SIZE]
                              [BG_TETROMINO_SIZE]) {
  {
    static BG_GI_CEIL_TYPE all_tetrominos
        [BG_TETROMINOS_COUNT][BG_TETROMINO_SIZE][BG_TETROMINO_SIZE] = {
            // I
            {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
            // O
            {{0, 0, 0, 0}, {0, 2, 2, 0}, {0, 2, 2, 0}, {0, 0, 0, 0}},
            // T
            {{0, 0, 0, 0}, {0, 3, 0, 0}, {3, 3, 3, 0}, {0, 0, 0, 0}},
            // J
            {{0, 0, 0, 0}, {4, 0, 0, 0}, {4, 4, 4, 0}, {0, 0, 0, 0}},
            // L
            {{0, 0, 0, 0}, {0, 0, 5, 0}, {5, 5, 5, 0}, {0, 0, 0, 0}},
            // Z
            {{0, 0, 0, 0}, {0, 6, 6, 0}, {6, 6, 0, 0}, {0, 0, 0, 0}},
            // S
            {{0, 0, 0, 0}, {7, 7, 0, 0}, {0, 7, 7, 0}, {0, 0, 0, 0}},
        };

    memcpy(tetrominos, all_tetrominos,
           BG_TETROMINOS_COUNT * BG_TETROMINO_SIZE * BG_TETROMINO_SIZE *
               sizeof(BG_GI_CEIL_TYPE));
  }
}

TTRS_RETURN_TYPE TTRS_getRandomTetromino(BG_GI_CEIL_TYPE **tetromino) {
  if (!tetromino) {
    return TTRS_Error;
  }

  BG_GI_CEIL_TYPE all_tetrominos[BG_TETROMINOS_COUNT][BG_TETROMINO_SIZE]
                                [BG_TETROMINO_SIZE];

  TTRS_getAllStaticTetromino(all_tetrominos);

  static BG_GI_CEIL_TYPE last_randoms[3] = {};
  BG_GI_CEIL_TYPE random_index = abs((rand() - rand()) % BG_TETROMINOS_COUNT);
  {
    while (last_randoms[2] == random_index || last_randoms[1] == random_index) {
      random_index = abs((rand() - rand()) % BG_TETROMINOS_COUNT);
    }

    if (random_index == last_randoms[0] &&
        (last_randoms[2] == last_randoms[1] ||
         last_randoms[1] == last_randoms[0])) {
      random_index = abs((rand() - rand()) % BG_TETROMINOS_COUNT);
    }

    last_randoms[2] = last_randoms[1];
    last_randoms[1] = last_randoms[0];
    last_randoms[0] = random_index;
  }

  for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
    memcpy(tetromino[i], all_tetrominos[random_index][i],
           BG_TETROMINO_SIZE * sizeof(BG_GI_CEIL_TYPE));
  }

  return TTRS_Ok;
}

// Get complete lines count
char TTRS_completeLineInBoard(BG_GI_CEIL_TYPE **board) {
  char complete_lines_count = 0;

  if (board) {
    char is_line_complete = 0;

    for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; i++) {
      is_line_complete = 1;

      for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; j++) {
        if (board[i][j] == TTRS_EMPTY) {
          is_line_complete = 0;
          break;
        }
      }

      if (is_line_complete) {
        for (size_t j = 0; j < BG_BOARD_COLUMNS_COUNT; j++) {
          board[i][j] = TTRS_EMPTY;
        }

        for (size_t j = i; j > 0; j--) {
          memcpy(board[j], board[j - 1],
                 BG_BOARD_COLUMNS_COUNT * sizeof(BG_GI_CEIL_TYPE));
        }
        memset(board[0], 0, BG_BOARD_COLUMNS_COUNT * sizeof(BG_GI_CEIL_TYPE));

        ++complete_lines_count;
      }
    }
  }

  return complete_lines_count;
}

char TTRS_isTetrominoOutsideBoard(BG_GI_CEIL_TYPE **tetromino,
                                  BG_Point2D_t tetromino_pos) {
  char result = 0;

  if (tetromino) {
    for (int_fast32_t i = 0; !result && i < BG_TETROMINO_SIZE; i++) {
      for (int_fast32_t j = 0; !result && j < BG_TETROMINO_SIZE; j++) {
        if (tetromino[i][j] != TTRS_EMPTY &&
            (tetromino_pos.x + j < 0 || tetromino_pos.y + i < 0 ||
             tetromino_pos.x + j >= BG_BOARD_COLUMNS_COUNT ||
             tetromino_pos.y + i >= BG_BOARD_ROWS_COUNT)) {
          result = 1;
          break;
        }
      }
    }
  }

  return result;
}

int TTRS_getRewardByCompleteLines(char lines_count) {
  int reward = 0;

  switch (lines_count) {
    case 1:
      reward = 100;
      break;
    case 2:
      reward = 300;
      break;
    case 3:
      reward = 700;
      break;
    case 4:
      reward = 1500;
      break;

    default:
      reward = 0;
      break;
  }

  return reward;
}