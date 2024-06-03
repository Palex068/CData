#include <errno.h>
#include <stddef.h>
#include <string.h>

#include "game_t.h"
#include "tetris.h"

/**
 * @ingroup Functions_for_manage_figures_on_field
 * @brief Функция копирования тела фигуры
 * @param[in] int** Указатель на массив источника
 * @param[in] int** Указатель на массив назначения
 * @param[in] unsigned short Размер тела
 * @return Код ошибки: Согласно errno
 */
int figure_copy_body(int **src, int **dst, unsigned short size) {
  int code = 0;

  code = (src == NULL || dst == NULL) * EINVAL;

  if (!code) {
    for (int row = 0; row < size; row++) {
      for (int col = 0; col < size; col++) {
        dst[row][col] = src[row][col];
      }
    }
  }

  return code;
}