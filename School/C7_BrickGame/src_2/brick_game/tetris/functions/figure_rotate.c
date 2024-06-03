#include <errno.h>
#include <malloc.h>
#include <stddef.h>

#include "tetris.h"

/**
 * @ingroup Functions_for_manage_figures_on_field
 * @brief Функция вращения фигуры
 * @param[in] game_t* Указатель на структуру игры
 * @return Код ошибки: Согласно errno
 */
int figure_rotate(game_t *game) {
  if (!game || !game->figure_cur || !game->figure_cur->body) return EINVAL;

  int code = 0;

  figure_t *temp = NULL;
  temp = figure_create(game->figure_cur->size);
  code = (temp == NULL) * ENOMEM;

  if (!code) {
    for (int col = 0; col < game->figure_cur->size; col++) {
      for (int row = game->figure_cur->size - 1, row_n = 0; row >= 0;
           row--, row_n++) {
        temp->body[col][row_n] = game->figure_cur->body[row][col];
      }
    }
  }

  if (!code)
    figure_copy_body(temp->body, game->figure_cur->body,
                     game->figure_cur->size);

  if (!code) figure_destroy(temp);

  return code;
}