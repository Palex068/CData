#include <errno.h>
#include <malloc.h>
#include <stddef.h>

#include "game_t.h"
#include "tetris.h"

/**
 * @ingroup Functions_for_manage_figures_DB
 * @brief Функция уничтожения БД фигур
 * @param[in] figure_t* Указатель на БД фигур
 * @return Код ошибки: Согласно errno
 */
int figure_db_destroy(figures_db_t *db) {
  int code = 0;

  code = (db == NULL) * EINVAL;

  if (!code) {
    for (unsigned i = 0; i < db->count; i++) {
      if (db->figures[i]) {
        figure_destroy(db->figures[i]);
        db->figures[i] = NULL;
      }
    }
    free(db->figures);
  }

  return code;
}