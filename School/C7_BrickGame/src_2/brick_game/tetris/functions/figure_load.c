#include <errno.h>
#include <malloc.h>
#include <stddef.h>
#include <stdio.h>

#include "game_t.h"
#include "tetris.h"

/**
 * @ingroup Functions_for_manage_figures
 * @brief Функция загрузки фигуры из файла
 * @param[in] FILE* Указатель на файл
 * @return Указатель на созданную структуру figure_t*
 */
figure_t *figure_load(FILE *file) {
  int code = 0;
  figure_t *result = NULL;
  unsigned short size = 0;

  code = (file == NULL) * EINVAL;

  if (!code) {
    code = (fscanf(file, "%hu\n", &size) == 0) * EBADF;
  }

  if (!code && size > 0) {
    result = figure_create(size);
    code = (result == NULL) * ENOMEM;
  }

  if (!code && size > 0) {
    int retval = 0;
    int point = 0;
    for (int row = 0; !code && row < size; row++) {
      for (int col = 0; !code && col < size; col++) {
        retval = fscanf(file, "%1d,", &point);
        code = (retval != 1) * EBADF;
        if (!code) result->body[row][col] = point;
      }
    }
  }

  if (!code && size > 0) {
    result->size = size;
  }

  return result;
}