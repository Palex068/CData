#include "../../../../includes/brick_game/v1/logic/tetris.h"

TTRS_RETURN_TYPE TTRS_selectNextState(TTRS_tetris_t *tetris) {
  if (!tetris) {
    return TTRS_Error;
  }

  TTRS_RETURN_TYPE return_result = TTRS_Ok;

  switch (tetris->state) {
    case TTRS_START_STATE:
      if (tetris->last_user_input.hold &&
          (tetris->last_user_input.action == BG_Start)) {
        TTRS_startState(tetris);
        tetris->state = TTRS_SPAWN_STATE;
      }
      break;

    case TTRS_SPAWN_STATE:
      TTRS_spawnState(tetris);
      break;

    case TTRS_MOVING_STATE:
      TTRS_movingState(tetris);
      break;

    case TTRS_ATTACHING_STATE:
      TTRS_attachingState(tetris);
      break;

    case TTRS_GAME_OVER_STATE:
      TTRS_gameOverState(tetris);

      if (tetris->last_user_input.hold) {
        if (tetris->last_user_input.action == BG_Start) {
          tetris->state = TTRS_START_STATE;
        } else if (tetris->last_user_input.action == BG_Terminate) {
          tetris->state = TTRS_EXIT_STATE;
        }
      }
      break;

    case TTRS_EXIT_STATE:
      break;

    default:
      return_result = TTRS_Error;
      break;
  }

  return return_result;
}

void TTRS_startState(TTRS_tetris_t *tetris) {
  tetris->level = 1;
  tetris->score = 0;

  for (size_t i = 0; i < BG_BOARD_ROWS_COUNT; i++) {
    memset(tetris->board[i], 0,
           BG_BOARD_COLUMNS_COUNT * sizeof(BG_GI_CEIL_TYPE));
  }

  TTRS_getRandomTetromino(tetris->next_tetromino);
}

void TTRS_spawnState(TTRS_tetris_t *tetris) {
  TTRS_copyTetromino(&tetris->next_tetromino, &tetris->cur_tetromino);

  tetris->cur_tetromino_pos.x = TTRS_TETROMINO_SPAWN_POS_X;
  tetris->cur_tetromino_pos.y = TTRS_TETROMINO_SPAWN_POS_Y;

  TTRS_getRandomTetromino(tetris->next_tetromino);

  tetris->last_user_input.hold = false;

  tetris->pause = 0;

  tetris->is_fall_time = 0;

  tetris->speed = BG_LEVEL_STEP_FALL_SPEED * tetris->level;

  tetris->state = TTRS_MOVING_STATE;
}

void TTRS_movingState(TTRS_tetris_t *tetris) {
  if (tetris->last_user_input.hold) {
    switch (tetris->last_user_input.action) {
      case BG_Pause:
        tetris->pause = !tetris->pause;
        break;
      case BG_Terminate:
        tetris->state = TTRS_EXIT_STATE;
        break;
      case BG_Left:
        TTRS_movingLeft(tetris);
        break;
      case BG_Right:
        TTRS_movingRight(tetris);
        break;
      case BG_Down:
        TTRS_movingDown(tetris);
        break;
      case BG_Action:
        TTRS_movingAction(tetris);
        break;

      default:
        break;
    }

    tetris->last_user_input.hold = 0;
  }

  if (tetris->is_fall_time && tetris->pause == 0) {
    ++tetris->cur_tetromino_pos.y;
    tetris->is_fall_time = false;
  }

  if (TTRS_checkingCollisionTetrominoWithBoard(
          tetris->cur_tetromino, tetris->cur_tetromino_pos, tetris->board)) {
    --tetris->cur_tetromino_pos.y;

    tetris->state = TTRS_ATTACHING_STATE;
  }
}

void TTRS_movingLeft(TTRS_tetris_t *tetris) {
  if (tetris->pause == 0) {
    --tetris->cur_tetromino_pos.x;

    if (TTRS_checkingCollisionTetrominoWithBoard(
            tetris->cur_tetromino, tetris->cur_tetromino_pos, tetris->board)) {
      ++tetris->cur_tetromino_pos.x;
    }
  }
}
void TTRS_movingRight(TTRS_tetris_t *tetris) {
  if (tetris->pause == 0) {
    ++tetris->cur_tetromino_pos.x;

    if (TTRS_checkingCollisionTetrominoWithBoard(
            tetris->cur_tetromino, tetris->cur_tetromino_pos, tetris->board)) {
      --tetris->cur_tetromino_pos.x;
    }
  }
}
void TTRS_movingDown(TTRS_tetris_t *tetris) {
  if (tetris->pause == 0) {
    ++tetris->cur_tetromino_pos.y;

    tetris->is_fall_time = false;
  }
}
void TTRS_movingAction(TTRS_tetris_t *tetris) {
  if (tetris->pause == 0) {
    TTRS_rotateTetromino(tetris->cur_tetromino, 0);

    for (size_t i = 0; i < BG_TETROMINO_SIZE; i++) {
      const char temp_collision_return =
          TTRS_checkingCollisionTetrominoWithBoard(
              tetris->cur_tetromino, tetris->cur_tetromino_pos, tetris->board);

      if (temp_collision_return == 1) {
        TTRS_rotateTetromino(tetris->cur_tetromino, 1);
      } else if (temp_collision_return == 2) {
        ++tetris->cur_tetromino_pos.x;
      } else if (temp_collision_return == 3) {
        --tetris->cur_tetromino_pos.x;
      } else if (temp_collision_return == 4) {
        --tetris->cur_tetromino_pos.y;

        tetris->state = TTRS_ATTACHING_STATE;
      }
    }
  }
}

void TTRS_attachingState(TTRS_tetris_t *tetris) {
  TTRS_addTetrominoInBoard(tetris->cur_tetromino, tetris->cur_tetromino_pos,
                           tetris->board);

  tetris->score +=
      TTRS_getRewardByCompleteLines(TTRS_completeLineInBoard(tetris->board));

  TTRS_setHighScore(tetris->score);

  tetris->level = (tetris->score / TTRS_LEVEL_SCORE_STEP) + 1;
  tetris->level =
      tetris->level > TTRS_MAX_LEVEL ? TTRS_MAX_LEVEL : tetris->level;

  if (TTRS_isTetrominoOutsideBoard(tetris->cur_tetromino,
                                   tetris->cur_tetromino_pos)) {
    tetris->state = TTRS_GAME_OVER_STATE;
  } else {
    tetris->state = TTRS_SPAWN_STATE;
  }
}

void TTRS_gameOverState(TTRS_tetris_t *tetris) { tetris->level = -2; }
