#include <errno.h>
#include <stddef.h>
#include <string.h>

#include "game_t.h"
#include "tetris.h"

/**
 * @ingroup Functions_for_manage_figures_on_field
 * @brief Функция копирования фигуры
 * @param[in] figure_t* Указатель на фигуру-источник
 * @param[in] figure_t* Указатель на фигуру-назначение
 * @return Код ошибки: Согласно errno
 */
int figure_copy(const figure_t *src, figure_t **dst) {
  int code = 0;

  code = (!src || !src->body || !dst) * EINVAL;

  if (!code) {
    if (*dst == NULL) {
      *dst = figure_create(src->size);
      code = figure_copy_body(src->body, (*dst)->body, src->size);
    } else if ((*dst)->size != src->size) {
      figure_destroy(*dst);
      *dst = figure_create(src->size);
      code = figure_copy_body(src->body, (*dst)->body, src->size);
    } else if ((*dst)->size == src->size) {
      code = figure_copy_body(src->body, (*dst)->body, src->size);
    }
    (*dst)->id = src->id;
    (*dst)->size = src->size;
  }

  return code;
}