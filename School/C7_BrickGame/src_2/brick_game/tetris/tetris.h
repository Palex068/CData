#ifndef TETRIS_H
#define TETRIS_H

#include <stdio.h>

#include "common/common.h"
#include "common/runtime_t.h"
#include "common/useraction_t.h"
#include "game_t.h"

typedef void (*action)(game_t *);

/*!
  @defgroup Thread_functions Потоковые функции
  @brief Потоковые функции
    Функции основного цикла потока
  @return Функции возвращают код выполенения потока pthread
*/
void *tetris_loop(runtime_t *);

/**
 * @defgroup Distributors Поставщики адресов данных
 * @brief Поставщики адресов данных
 * Хранят и предоставляют адреса хранения структур данных
 * @return Функции возвращают адрес данных в памяти
 */
game_t *game_locate(game_t *);

/*!
  @defgroup Screens Функции графических заставок
  @brief Функции графических заставок
    Заполняют поле вывода графикой начала и завершения игры
  @return Функции не возвращают ошибок
*/
void logo_start(int **field);
void logo_game_over(int **field);

/*!
  @defgroup Functions_for_manage_game_structures Функции создают, очищают и
  удаляют игровые структуры
  @brief Функции создают, очищают и удаляют игровые структуры
    Функции создают, очищают и удаляют игровые структуры
  @return Функции возвращают ошибки согласно errno.h
*/
int game_init(game_t **game);
int game_destroy(game_t *game);
int game_info_init(game_info_t **game_info);
int game_info_destroy(game_info_t *game_info);
int game_info_clean(game_info_t *game_info);
int game_info_next_init(int ***next);
int game_info_next_destroy(int **next);
int game_info_next_clean(int **next);

/*!
  @defgroup Functions_for_manage_figures_DB Функции создают, очищают и удаляют
  базу данных фигур
  @brief Функции создают, очищают и удаляют базу данных фигур
    Функции создают, очищают и удаляют базу данных фигур
  @return Функции возвращают ошибки согласно errno.h
*/
int figure_db_load(const char *dir, figures_db_t *db);
int figure_db_insert(figures_db_t *db, unsigned count);
int figure_db_destroy(figures_db_t *db);

/*!
  @defgroup Functions_for_manage_figures Функции создания, копирования и
  удаления фигур
  @brief Функции создания, копирования и удаления фигур
    Функции создают, копируют и удаляют фигуры
  @return Функции возвращают ошибки согласно errno.h
*/
figure_t *figure_create(const unsigned short size);
int figure_destroy(figure_t *figure);
figure_t *figure_load(FILE *file);
int figure_copy(const figure_t *src, figure_t **dst);
int figure_copy_body(int **src, int **dst, unsigned short size);

/*!
  @defgroup Functions_for_manage_figures_on_field Функции нанесения, удаления и
  вращения фигур на доске
  @brief Функции нанесения, удаления и вращения фигур на доске
    Функции наносят, удаляют и вращают фигуры на доске
  @return Функции возвращают ошибки согласно errno.h
*/
int figure_set(game_t *game);
int figure_unset(game_t *game);
int figure_rotate(game_t *game);
int figure_check(game_t *game);
int kaboom(game_t *game);

/*!
  @defgroup Functions_for_save_end_load_high_scores Функции сохранения и
  загрузки результатов игры
  @brief Функции сохранения и загрузки результатов игры
    Функции сохраняют и загружают результаты игры
  @return Функции возвращают ошибки согласно errno.h
*/
int hi_scores_load(char *filename, int *hi_score);
int hi_scores_save(char *filename, int *hi_score);

/*!
  @defgroup FSM_functions Функции машины конечных автоматов
  @brief Функции машины конечных автоматов
    Функции реализующие машину конечных автоматов
  @return Функции не возвращают ошибок
*/
action fsm(fsm_state, UserAction_t);
void start_fn(game_t *);
void pause_fn(game_t *);
void spawn_fn(game_t *);
void move_fn(game_t *);
void shift_fn(game_t *);
void connect_fn(game_t *);
void game_over_fn(game_t *);
void terminate_fn(game_t *);
void left_fn(game_t *);
void right_fn(game_t *);
void up_fn(game_t *);
void down_fn(game_t *);
void action_fn(game_t *);

/*!
  @defgroup Functions_of_user_input Функции осуществляющие пользовательский ввод
  @brief Функции осуществляющие передачу пользовательского ввода в МКА
  @return Функции не возвращают ошибок
*/
void userInput(UserAction_t action, int hold);

/*!
  @defgroup Functions_getting_data_structure_for_rendering Функции получения
  данных для рендера
  @brief Функции получения данных для рендера
    Функции получают данные для рендера
  @return Функции возвращают структуру данных game_info_t
*/
game_info_t update_current_state();

#endif