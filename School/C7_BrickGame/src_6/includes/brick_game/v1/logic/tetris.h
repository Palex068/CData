
/**
 * @mainpage BrickGame v1.0 Ludivinp
 *  Проект разделён на два отдельных независимых модуля (Model - View).
 * Модули взаимодействуют с друг другом через контроллер с помощью специальных
 * интерфейсов.
 *
 * Проект был написан руководствуясь "7 principles of structural programming.md"
 * и "library-specification.md".
 *
 */

#ifndef S21_TETRIS_H
#define S21_TETRIS_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

#include "../constants.h"
#include "../interfaces.h"
#include "../objects.h"
#include "ttrs_constants.h"
#include "ttrs_objects.h"

//// interfaces
TTRS_RETURN_TYPE TTRS_initTetris(TTRS_tetris_t *tetris);
void TTRS_removeTetris(TTRS_tetris_t *tetris);

void TTRS_userInput(BG_UserAction_t action, bool hold);

BG_GameInfo_t TTRS_updateCurrentState(void);
BG_GameInfo_t TTRS_createGameInfoByTetris(TTRS_tetris_t *tetris);

void TTRS_gameStart(void);
char TTRS_isGameEnd(void);

void TTRS_setHighScore(int score);
int TTRS_getHighScore(void);

char TTRS_isPause(void);
//

//// Tetromino
TTRS_RETURN_TYPE TTRS_createTetromino(BG_GI_CEIL_TYPE ***tetromino);
void TTRS_removeTetromino(BG_GI_CEIL_TYPE ***tetromino);

void TTRS_copyTetromino(BG_GI_CEIL_TYPE ***tetromino,
                        BG_GI_CEIL_TYPE ***tetromino_copy);

TTRS_RETURN_TYPE TTRS_rotateTetromino(BG_GI_CEIL_TYPE **tetromino, char left);
//

///// Board
TTRS_RETURN_TYPE TTRS_createBoard(BG_GI_CEIL_TYPE ***board);
void TTRS_removeBoard(BG_GI_CEIL_TYPE ***board);

void TTRS_copyBoard(BG_GI_CEIL_TYPE ***board, BG_GI_CEIL_TYPE ***board_copy);

char TTRS_checkingCollisionTetrominoWithBoard(BG_GI_CEIL_TYPE **tetromino,
                                              BG_Point2D_t tetromino_pos,
                                              BG_GI_CEIL_TYPE **board);

void TTRS_addTetrominoInBoard(BG_GI_CEIL_TYPE **tetromino,
                              BG_Point2D_t tetromino_pos,
                              BG_GI_CEIL_TYPE **board);
//

//// Gameplay!
void TTRS_getAllStaticTetromino(
    BG_GI_CEIL_TYPE tetrominos[BG_TETROMINOS_COUNT][BG_TETROMINO_SIZE]
                              [BG_TETROMINO_SIZE]);

TTRS_RETURN_TYPE TTRS_getRandomTetromino(BG_GI_CEIL_TYPE **tetromino);

char TTRS_completeLineInBoard(BG_GI_CEIL_TYPE **board);

int TTRS_getRewardByCompleteLines(char lines_count);

char TTRS_isTetrominoOutsideBoard(BG_GI_CEIL_TYPE **tetromino,
                                  BG_Point2D_t tetromino_pos);
//

//// fsm
TTRS_RETURN_TYPE TTRS_selectNextState(TTRS_tetris_t *tetris);

void TTRS_startState(TTRS_tetris_t *tetris);
void TTRS_spawnState(TTRS_tetris_t *tetris);

void TTRS_movingState(TTRS_tetris_t *tetris);
void TTRS_movingLeft(TTRS_tetris_t *tetris);
void TTRS_movingRight(TTRS_tetris_t *tetris);
void TTRS_movingDown(TTRS_tetris_t *tetris);
void TTRS_movingAction(TTRS_tetris_t *tetris);

void TTRS_attachingState(TTRS_tetris_t *tetris);
void TTRS_attachingState(TTRS_tetris_t *tetris);
void TTRS_gameOverState(TTRS_tetris_t *tetris);
//

// Keepers
void TTRS_tetrisInfoKeeper(TTRS_tetris_t **tetris);

#endif
