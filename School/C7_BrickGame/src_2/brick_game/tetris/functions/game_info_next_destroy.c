#include <errno.h>
#include <malloc.h>
#include <stddef.h>

#include "tetris.h"

/**
 * @ingroup Functions_for_manage_game_structures
 * @brief Функция удаления поля следующей фигуры
 * @param[in] int* Указатель на поле следующей фигуры
 * @return Код ошибки: Согласно errno
 */
int game_info_next_destroy(int **next) {
  if (!next) return EINVAL;

  int code = 0;

  for (int row = 0; row < 4; row++) {
    free(next[row]);
  }

  free(next);

  return code;
}