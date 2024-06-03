#include <errno.h>
#include <string.h>

#include "tetris.h"

/**
 * @ingroup Functions_for_manage_game_structures
 * @brief Функция очистки поля следующей фигуры
 * @param[in] int** Указатель на поле следующей фигуры
 * @return Код ошибки: Согласно errno
 */
int game_info_next_clean(int **next) {
  if (!next) return EINVAL;

  int code = 0;

  void *ptr = NULL;
  for (int row = 0; !code && row < 4; row++) {
    ptr = memset(next[row], 0, 4 * sizeof(int));
    code = (ptr != next[row]) * ECANCELED;
  }

  return code;
}