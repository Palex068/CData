#include <stdio.h>
#include <stdlib.h>

#include "tetris.h"

/**
 * @ingroup FSM_functions
 * @brief Функция МКА запуска игры
 * @param[in] game_t* Указатель на структуру игры
 * @return Функция не возвращает значения
 */
void start_fn(game_t *game) {
  if (game) {
    game_info_clean(game->game_info);
    game->state = start;
    spawn_fn(game);
  }
}

/**
 * @ingroup FSM_functions
 * @brief Функция МКА паузы игры
 * @param[in] game_t* Указатель на структуру игры
 * @return Функция не возвращает значения
 */
void pause_fn(game_t *game) {
  if (game) {
    static fsm_state temp_state;
    if (game->game_info->pause) {
      game->state = temp_state;
      game->game_info->pause = 0;
      game->last_op = time_msec();
    } else {
      temp_state = game->state;
      game->game_info->pause = 1;
      game->state = pause;
    }
  }
}

/**
 * @ingroup FSM_functions
 * @brief Функция МКА создания новой фигуры на поле
 * @param[in] game_t* Указатель на структуру игры
 * @return Функция не возвращает значения
 */
void spawn_fn(game_t *game) {
  if (game) {
    game->state = spawn;
    // Spawn next figure & choose new random
    figure_copy(game->database.figures[game->next_id], &game->figure_cur);
    game->next_id = rand() % (game->database.count - 1);
    game_info_next_clean(game->game_info->next);
    figure_copy_body(game->database.figures[game->next_id]->body,
                     game->game_info->next,
                     game->database.figures[game->next_id]->size);

    game->figure_pos.x = field_width / 2 - game->figure_cur->size / 2;
    game->figure_pos.y = 0;
    if (figure_check(game))
      game_over_fn(game);
    else {
      figure_set(game);
      game->last_op = time_msec();
      game->modified = true;
      move_fn(game);
    }
  }
}

/**
 * @ingroup FSM_functions
 * @brief Функция МКА перевода игры в состояние передвижения
 * @param[in] game_t* Указатель на структуру игры
 * @return Функция не возвращает значения
 */
void move_fn(game_t *game) {
  if (game) {
    game->state = moving;
  }
}

/**
 * @ingroup FSM_functions
 * @brief Функция МКА сдвига фигуры на поле
 * @param[in] game_t* Указатель на структуру игры
 * @return Функция не возвращает значения
 */
void shift_fn(game_t *game) {
  if (game) {
    fsm_state temp_state = game->state;
    game->state = shift;
    figure_unset(game);
    // check to connect
    game->figure_pos.y += 1;
    if (figure_check(game)) {
      game->figure_pos.y -= 1;
      connect_fn(game);
    } else if (game->state != game_over) {
      figure_set(game);
      game->last_op = time_msec();
      game->state = temp_state;
    }
    game->modified = true;
  }
}

/**
 * @ingroup FSM_functions
 * @brief Функция МКА присоединения фигуры к полю
 * @param[in] game_t* Указатель на структуру игры
 * @return Функция не возвращает значения
 */
void connect_fn(game_t *game) {
  if (game) {
    game->state = connect;
    figure_set(game);
    kaboom(game);
    spawn_fn(game);
  }
}

/**
 * @ingroup FSM_functions
 * @brief Функция МКА окончания игры
 * @param[in] game_t* Указатель на структуру игры
 * @return Функция не возвращает значения
 */
void game_over_fn(game_t *game) {
  if (game) {
    game->state = game_over;
    logo_game_over(game->game_info->field);
  }
}

/**
 * @ingroup FSM_functions
 * @brief Функция МКА выхода из игры
 * @param[in] game_t* Указатель на структуру игры
 * @return Функция не возвращает значения
 */
void terminate_fn(game_t *game) {
  if (game) {
    game->state = none;
    game_locate(game);
  }
}

/**
 * @ingroup FSM_functions
 * @brief Функция МКА хода влево
 * @param[in] game_t* Указатель на структуру игры
 * @return Функция не возвращает значения
 */
void left_fn(game_t *game) {
  if (game) {
    figure_unset(game);
    game->figure_pos.x -= 1;
    game->figure_pos.x += figure_check(game);
    figure_set(game);
    game->modified = true;
    move_fn(game);
  }
}

/**
 * @ingroup FSM_functions
 * @brief Функция МКА хода вправо
 * @param[in] game_t* Указатель на структуру игры
 * @return Функция не возвращает значения
 */
void right_fn(game_t *game) {
  if (game) {
    figure_unset(game);
    game->figure_pos.x += 1;
    game->figure_pos.x -= figure_check(game);
    figure_set(game);
    game->modified = true;
    move_fn(game);
  }
}

/**
 * @ingroup FSM_functions
 * @brief Функция МКА хода вверх (отключена)
 * @param[in] game_t* Указатель на структуру игры
 * @return Функция не возвращает значения
 */
void up_fn(game_t *game) {
  if (game) {
    figure_unset(game);
    game->figure_pos.y -= 1;
    game->figure_pos.y += figure_check(game);
    figure_set(game);
    game->modified = true;
    move_fn(game);
  }
}

/**
 * @ingroup FSM_functions
 * @brief Функция МКА хода вниз
 * @param[in] game_t* Указатель на структуру игры
 * @return Функция не возвращает значения
 */
void down_fn(game_t *game) {
  if (game) {
    figure_unset(game);
    game->figure_pos.y += 1;
    game->figure_pos.y -= figure_check(game);
    figure_set(game);
    game->modified = true;
    move_fn(game);
  }
}

/**
 * @ingroup FSM_functions
 * @brief Функция МКА вызова действия в игре
 * @param[in] game_t* Указатель на структуру игры
 * @return Функция не возвращает значения
 */
void action_fn(game_t *game) {
  if (game) {
    int check = 0;
    figure_t *temp = NULL;
    temp = figure_create(game->figure_cur->size);
    if (temp) {
      figure_copy_body(game->figure_cur->body, temp->body,
                       game->figure_cur->size);
      figure_unset(game);
      figure_rotate(game);
      check = figure_check(game);
      if (check) {
        figure_copy_body(temp->body, game->figure_cur->body,
                         game->figure_cur->size);
      }
      figure_destroy(temp);
      figure_set(game);
      game->modified = true;
    }
    move_fn(game);
  }
}
