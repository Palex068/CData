/**
 * @file
 * @brief Заголовочный файл с описанием структур и функций игрового процесса
 *
 * @note Данный файл содержит в себе определения структур и функций игрового
 * процесса
 */
#ifndef BACKEND_H_SENTRY
#define BACKEND_H_SENTRY

#include <curses.h>
#include <math.h>
#include <stdbool.h>

#include "figures.h"

#define WIDTH 10
#define HEIGHT 20

#define IS_FALL 1
#define GAME_OVER 2

#define MATRIX_PTR 0

#define COLLIDE 1
#define R_BOUNCE 2  // right bounce
#define L_BOUNCE 3  // left bounce

/// Пользовательские действия
typedef enum {
  Start,      ///< Начало игры
  Pause,      ///< Пауза
  Terminate,  ///< Окончание игры
  Left,       ///< Движение влево
  Right,      ///< Движение вправо
  Up,         ///< Движение вверх
  Down,       ///< Движение вниз
  Action      ///< Окончание такта по таймеру
} UserAction_t;

/**
 * @brief Структура описывающее состояние игры
 *
 */
typedef struct {
  int** field;
  int** next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

void userInput(UserAction_t action, bool hold);
GameInfo_t updateCurrentState();

GameInfo_t* stateWrapper();

Figures* updateCurrentFigure(bool flag);
Figures* updateNextFigure(bool flag);
UserAction_t isPress(int key);
void addFigure();
void addNext();
void delFigure();
void delNext();

int moveDown(bool timeout);
void moveLeft();
void moveRight();
void rotate();

int isCollision();
void lineElimination();
void promptNewGame();
void takeNextFigure();

int** mallocMatrix(int W, int H);
void clearMatrix();

#endif