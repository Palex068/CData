#include <errno.h>
#include <malloc.h>
#include <stddef.h>

#include "tetris.h"

/**
 * @ingroup Functions_for_manage_game_structures
 * @brief Функция уничтожения структуры игры
 * @param[in] game_t* Указатель на структуру игры
 * @return Код ошибки: Согласно errno
 */
int game_destroy(game_t *game) {
  if (!game) return EINVAL;

  int code = 0;

  game->figure_pos.x = 0;
  game->figure_pos.y = 0;
  game->last_op = 0;
  game->modified = 0;

  // Удаляем базу данных фигур
  if (game->database.figures) {
    code = figure_db_destroy(&game->database);
    game->database.count = 0;
  }

  // Удаляем текущую фигуру
  if (game->figure_cur) {
    figure_destroy(game->figure_cur);
  }

  if (game->game_info) {
    code = game_info_destroy(game->game_info);
  }

  // Check the game locate clean
  if (game_locate(NULL)) game_locate(game);

  free(game);

  return code;
}