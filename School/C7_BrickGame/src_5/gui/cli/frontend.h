/**
 * @file frontend.h
 * @brief Файл содержит функции отрисовки игры
 */

#ifndef FRONTEND_H
#define FRONTEND_H

#include <curses.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <time.h>

#include "../../brick_game/tetris/backend.h"

#define CURRENT_COLOR 1 + rand() % 4
/**
 * @brief Макрос инициализации ncurses
 */
#define CURSINIT()                          \
  {                                         \
    if (initscr() == NULL) {                \
      perror("error initialising ncurses"); \
      exit(EXIT_FAILURE);                   \
    }                                       \
    cbreak();                               \
    noecho();                               \
    keypad(stdscr, TRUE);                   \
    curs_set(0);                            \
    timeout(0);                             \
  }

/**
 * @brief конечное значение отрисовки игрового поля
 */
#define HUD_WIDTH 12

/**
 * @brief стартовое значение отрисовки игрового поля
 */
#define BOARDS_START_POINT 2

/**
 * @brief стартовое сообщение
 */
#define INTRO_MESSAGE "PRESS \"ENTER\" TO START"

/**
 * @brief длина стартового сообщения
 */
#define INTRO_MESSAGE_LEN (int)strlen(INTRO_MESSAGE)

/**
 * @brief сообщение об окончании игры
 */
#define FINAL_MESSAGE_1 "GAME OVER"

/**
 * @brief сообщение об окончании игры
 */
#define FINAL_MESSAGE_2 "Your score is %d"

/**
 * @brief сообщение об окончании игры
 */
#define FINAL_MESSAGE_3 "Your highscore is %d"

/**
 * @brief сообщение об окончании игры
 */
#define FINAL_MESSAGE_4 "Play again? [y/n]"

/**
 * @brief Макрос отрисовки заполненного блока
 */
#define MVADDCH(y, x, c) \
  mvaddch(BOARDS_START_POINT + (y), BOARDS_START_POINT + (x), c)

/**
 * @brief Макрос отрисовки частей поля
 */
#define MVPRINTW(y, x, ...) \
  mvprintw(BOARDS_START_POINT + (y), BOARDS_START_POINT + (x), __VA_ARGS__)

/**
 * @brief Функция отрисовки границ поля
 */
void printBorders(int top_y, int bottom_y, int left_x, int right_x);

/**
 * @brief Функция обновления поля
 */
void updateField();

/**
 * @brief Функция остановки работы библиотеки ncurses
 */
void quitNcurses();

/**
 * @brief Функция отрисовки стартового экрана
 */
void drawStartMessage();

/**
 * @brief Функция отрисовки стартового поля
 */
void drawBorders();

/**
 * @brief Функция отрисовки превью фигуры
 */
void DrawNext(short c);

/**
 * @brief Функция отрисовки финальных сообщений
 */
void redrawField();

/**
 * @brief Функция инициализации цветов
 */
void init_colors();
#endif