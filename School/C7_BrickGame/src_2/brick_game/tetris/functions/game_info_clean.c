#include <errno.h>
#include <string.h>

#include "tetris.h"

/**
 * @ingroup Functions_for_manage_game_structures
 * @brief Функция очистки структуры обмена
 * @param[in] game_info_t* Указатель на структуру обмена
 * @return Код ошибки: Согласно errno
 */
int game_info_clean(game_info_t *game_info) {
  if (!game_info) return EINVAL;

  int code = 0;

  game_info->score = 0;
  game_info->level = 1;
  game_info->speed = 1000;
  game_info->pause = 0;

  if (game_info->field) {
    void *ptr = NULL;
    for (int row = 0; !code && row < field_height; row++) {
      ptr = memset(game_info->field[row], 0, field_width * sizeof(int));
      code = (ptr != game_info->field[row]) * ECANCELED;
    }
  }

  return code;
}