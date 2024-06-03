/**
 * @brief Основная структуры игры
 * Содержит все необходимые данные для выполнения модели
 */

#ifndef GAME_T_H
#define GAME_T_H

#include <stdbool.h>
#include <sys/time.h>

#ifndef GAME_INFO_T
#include "common/game_info_t.h"
#endif

/**
 * @brief Структура фигуры
 */
typedef struct figure {
  unsigned id;          // Increment
  unsigned short size;  // In both ordinates
  int **body;           // Colors inside of int
} figure_t;

/**
 * @brief Структура базы данных фигур
 */
typedef struct figures_db_t {
  figure_t **figures;
  unsigned count;
} figures_db_t;

/**
 * @brief Структура позиции фигуры
 */
typedef struct position_t {
  int x;
  int y;
} position_t;

/**
 * @brief Тип-перечислитель состояний МКА
 */
typedef enum fsm_state {
  none,
  start,
  pause,
  spawn,
  moving,
  shift,
  connect,
  game_over
} fsm_state;

/**
 * @brief Структура игры
 */
typedef struct game_t {
  game_info_t *game_info;
  figures_db_t database;
  figure_t *figure_cur;
  position_t figure_pos;
  int next_id;
  fsm_state state;
  unsigned long last_op;
  bool modified;
} game_t;

#endif