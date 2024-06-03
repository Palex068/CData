#include "../../../../includes/brick_game/v1/logic/tetris.h"

TTRS_RETURN_TYPE TTRS_initTetris(TTRS_tetris_t *tetris) {
  TTRS_RETURN_TYPE return_result = TTRS_Error;

  srand(time(NULL));

  if (tetris) {
    memset(tetris, 0, sizeof(*tetris));

    {
      TTRS_createBoard(&tetris->board);
      TTRS_createBoard(&tetris->preview_board);

      TTRS_createTetromino(&tetris->cur_tetromino);
      TTRS_createTetromino(&tetris->next_tetromino);
    }

    tetris->is_game_start = false;
    tetris->state = TTRS_START_STATE;
    tetris->level = -1;

    tetris->last_user_input.action = BG_Start;
    tetris->last_user_input.hold = false;

    // заносим в кипер
    TTRS_tetrisInfoKeeper(&tetris);

    return_result = TTRS_Ok;
  }

  return return_result;
}

void TTRS_removeTetris(TTRS_tetris_t *tetris) {
  if (tetris) {
    TTRS_removeBoard(&tetris->board);
    TTRS_removeBoard(&tetris->preview_board);

    TTRS_removeTetromino(&tetris->cur_tetromino);
    TTRS_removeTetromino(&tetris->next_tetromino);

    memset(tetris, 0, sizeof(*tetris));
  }
}

void TTRS_userInput(BG_UserAction_t action, bool hold) {
  TTRS_tetris_t *tetris = NULL;
  TTRS_tetrisInfoKeeper(&tetris);
  if (tetris) {
    tetris->last_user_input.action = action;
    tetris->last_user_input.hold = hold;
  }
}

BG_GameInfo_t TTRS_updateCurrentState(void) {
  BG_GameInfo_t return_game_info = {};

  TTRS_tetris_t *tetris = NULL;
  TTRS_tetrisInfoKeeper(&tetris);
  if (tetris && TTRS_selectNextState(tetris) == TTRS_Ok) {
    return_game_info = TTRS_createGameInfoByTetris(tetris);
  }

  return return_game_info;
}

BG_GameInfo_t TTRS_createGameInfoByTetris(TTRS_tetris_t *tetris) {
  BG_GameInfo_t return_game_info = {};

  if (tetris) {
    TTRS_copyBoard(&tetris->board, &tetris->preview_board);
    TTRS_addTetrominoInBoard(tetris->cur_tetromino, tetris->cur_tetromino_pos,
                             tetris->preview_board);

    return_game_info.field = tetris->preview_board;
    return_game_info.next = (int **)tetris->next_tetromino;

    return_game_info.high_score = tetris->high_score;
    return_game_info.score = tetris->score;

    return_game_info.level = tetris->level;
    return_game_info.speed = tetris->speed;

    return_game_info.pause = tetris->pause;
  }

  return return_game_info;
}

char TTRS_isGameEnd(void) {
  TTRS_tetris_t *tetris = NULL;
  TTRS_tetrisInfoKeeper(&tetris);

  return tetris ? tetris->state == TTRS_EXIT_STATE : 1;
}

void TTRS_gameStart(void) {
  TTRS_tetris_t *tetris = NULL;
  TTRS_tetrisInfoKeeper(&tetris);

  if (tetris) {
    tetris->is_game_start = true;
  }
}

void TTRS_setHighScore(int score) {
  TTRS_tetris_t *tetris = NULL;
  TTRS_tetrisInfoKeeper(&tetris);

  if (tetris && score > tetris->high_score) {
    tetris->high_score = score;
  }
}
int TTRS_getHighScore(void) {
  TTRS_tetris_t *tetris = NULL;
  TTRS_tetrisInfoKeeper(&tetris);

  return tetris ? tetris->high_score : 0;
}

char TTRS_isPause(void) {
  char result = 0;

  TTRS_tetris_t *tetris = NULL;
  TTRS_tetrisInfoKeeper(&tetris);

  if (tetris) {
    result = !!tetris->pause;
  }

  return result;
}