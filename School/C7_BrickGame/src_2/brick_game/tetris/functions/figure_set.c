#include <errno.h>
#include <stddef.h>

#include "tetris.h"

/**
 * @ingroup Functions_for_manage_figures_on_field
 * @brief Функция нанесения фигуры на поле
 * @param[in] game_t* Указатель на структуру игры
 * @return Код ошибки: Согласно errno
 */
int figure_set(game_t *game) {
  if (!game || !game->figure_cur || !game->figure_cur->body ||
      !game->game_info || !game->game_info->field)
    return EINVAL;

  int code = 0;

  for (int row = 0; row < game->figure_cur->size; row++) {
    for (int col = 0; col < game->figure_cur->size; col++) {
      if (game->figure_cur->body[row][col])
        game->game_info
            ->field[game->figure_pos.y + row][game->figure_pos.x + col] =
            game->figure_cur->body[row][col];
    }
  }

  return code;
}