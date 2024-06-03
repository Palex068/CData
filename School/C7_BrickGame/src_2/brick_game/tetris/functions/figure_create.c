#include <errno.h>
#include <malloc.h>
#include <stddef.h>

#include "game_t.h"
#include "tetris.h"

/**
 * @ingroup Functions_for_manage_figures
 * @brief Функция создания фигуры
 * @param[in] const unsigned short Размер
 * @return Указатель на созданную фигуру
 */
figure_t *figure_create(const unsigned short size) {
  if (size == 0) return NULL;

  int code = 0;

  figure_t *result = NULL;

  figure_t *temp = NULL;
  temp = calloc(1, sizeof(figure_t));
  code = (temp == NULL) * ENOMEM;
  if (!code) result = temp;

  if (!code) {
    result->size = size;
    int **temp_body = (int **)calloc(size, sizeof(int *));
    code = (temp_body == NULL) * ENOMEM;
    if (!code) result->body = temp_body;
  }

  if (!code) {
    int *temp = NULL;
    for (int row = 0; !code && row < size; row++) {
      temp = (int *)calloc(size, sizeof(int));
      code = (temp == NULL) * ENOMEM;
      if (!code) result->body[row] = temp;
    }
  }

  if (code && result) {
    figure_destroy(result);
    result = NULL;
  }

  return result;
}