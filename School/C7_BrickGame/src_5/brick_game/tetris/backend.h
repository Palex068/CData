/**
 * @file backend.h
 * @brief Файл содержит объявления структур игры, всех функций backend'а и
 * макросов.
 */
#ifndef BACKEND_H
#define BACKEND_H

#include <curses.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <time.h>

#include "../../gui/cli/frontend.h"

/**
 * @brief ширина 10 пикселей
 */
#define WIDTH 10

/**
 * @brief высота 20 пикселей
 */
#define HEIGHT 20

/**
 * @brief врменной промежуток 50000
 */
#define TIMESTEP 50000

/**
 * @brief кол-во фигур
 */
#define TETRAMINOS 7

/**
 * @brief кол-во ориентаций фигуры
 */
#define ORI 4

/**
 * @brief кол-во блоков фигуры
 */
#define CELLS 4

/**
 * @brief действия пользователя
 */
typedef enum UserAction_t {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

/**
 * @brief Структура, содержащая пару чисел - строчка и столбец
 */
typedef struct Tlocation {
  int row;
  int col;
} Tlocation;

/**
 * @brief Структура, описывающая фигуру
 * @param type Тип фигуры
 * @param orientation Ориентация
 * @param loc Структура столбца и строчки каждого блока
 */
typedef struct Tblock {
  int type;
  int orientation;
  Tlocation loc;
} Tblock;

/**
 * @brief Структура, содержащая показатели игры
 * @param field поле
 * @param score очки
 * @param high_score рекорд
 * @param level уровень
 * @param pause пауза
 * @param started заглушка
 * @param falling падающая фигура
 * @param next следующая фигура
 * @param ticks скорость
 */
typedef struct GameInfo_t {
  int **field;
  int score;
  int high_score;
  int level;
  int pause;
  int started;
  int ticks;
  int stop;
  Tblock *falling;
  Tblock *next;

} GameInfo_t;

/**
 * @brief Функция выделения памяти под главную структуру игры
 */
GameInfo_t *getGameInfo_t();

/**
 * @brief Функция, определяющая следующее действие в зависимости от ввода
 * пользователя
 * @param action действие игрока
 * @param hold заглушка
 */
void userInput(UserAction_t action, bool hold);

/**
 * @brief Функция начала игры
 */
void startGame();

/**
 * @brief Функция инициализации фигуры
 */
void initFigure();

/**
 * @brief Функция установки таймера
 */
void setTimer(void);

/**
 * @brief Функция устанвки сигналов
 */
void setSignals(void);

/**
 * @brief Функция, определяющая следующее действие в зависимости от полученного
 * сигнала
 */
void handler(int signum);

/**
 * @brief Функция сдвига фигуры вниз на 1 блок
 */
void mvDown(void);

/**
 * @brief Функция парсинга действий пользователя
 */
void keyboardParser(int key, UserAction_t *action);

/**
 * @brief Функция выхода из игры по выбору пользователя
 */
void quit();

/**
 * @brief Функция экстренного выхода из игры
 * @param msg сообщение об ошибке
 */
void terminateIfError(char *msg);

/**
 * @brief Функция переноса координат фигуры из координат падающей фигуры на поле
 */
void spawnFigure();

/**
 * @brief Функция чистки памяти
 */
void freeMap(void);

/**
 * @brief Функция остановки работы библиотеки ncurses
 */
void quitNcurses(void);

/**
 * @brief Функция проверки на движение вниз
 */
int figureFallThroughAbilityCheck();

/**
 * @brief Функция движения фигуры вправо/влево
 */
void moveFigure(UserAction_t direction);

/**
 * @brief Функция паузы
 */
void pauseGame();

/**
 * @brief Функция поворота фигуры
 */
void rotateFigure();

/**
 * @brief Функция получения координат в зависимоси от типа и ориентации фигуры
 * @param tetramino тип фигуры
 * @param orientation ориентация фигуры
 * @param cells блок фигуры
 */
Tlocation getFigureCoordinates(int tetramino, int orientation, int cells);

/**
 * @brief Функция удвления фигуры с поля
 */
void rmFigureFromField();

/**
 * @brief Функция проверки на поворот фигуры
 */
int figureRotationAbilityCheck();

/**
 * @brief Функция движения налево
 */
void mvLeft();

/**
 * @brief Функция движения направо
 */
void mvRight();

/**
 * @brief Функция удаления строк
 */
void deleteLines();

/**
 * @brief Функция проверки на заполненность строки поля
 * @param i индекс строки поля
 */
int fullLine(int i);

/**
 * @brief Функция возведения в степень двойки
 * @param degree степень двойки
 */
int fastPow(int degree);

/**
 * @brief Функция прекращения игры и предложения продолжить либо выйти
 */
void terminateButtonPushed();

/**
 * @brief Функция вызова новой игры
 */
void playAgain();

/**
 * @brief Функция получения нынешних показателей игры
 */
GameInfo_t updateCurrentState();

/**
 * @brief Функция получения нужного ускорения в зависимости от уровня
 * @param index индекс уровня
 */
int changeSpeed(int index);

/**
 * @brief Функция инициализации игры
 */
int initGame();

#endif  // S21_TETRIS_H