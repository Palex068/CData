#include <errno.h>
#include <malloc.h>
#include <stddef.h>

#include "game_t.h"
#include "tetris.h"

/**
 * @ingroup Functions_for_manage_figures_DB
 * @brief Функция добавления фигуры в БД
 * @param[in] figures_db_t* Указатель на БД фигур
 * @param[in] unsigned Количество
 * @return Код ошибки: Согласно errno
 */
int figure_db_insert(figures_db_t *db, unsigned count) {
  int code = 0;

  code = (db == NULL) * EINVAL;

  if (!code) {
    db->figures = realloc(db->figures, (count + 1) * sizeof(figure_t *));
    code = (db->figures == NULL) * ENOMEM;
  }

  return code;
}