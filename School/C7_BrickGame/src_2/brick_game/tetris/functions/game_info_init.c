#include <errno.h>
#include <malloc.h>
#include <stddef.h>

#include "tetris.h"

/**
 * @ingroup Functions_for_manage_game_structures
 * @brief Функция созания структуры обмена
 * @param[in] game_info_t** Указатель на структуру обмена
 * @return Код ошибки: Согласно errno
 */
int game_info_init(game_info_t **game_info) {
  if (game_info == NULL) return EINVAL;

  int code = 0;

  // Аллоцируем структуру game_info_t
  game_info_t *temp = calloc(1, sizeof(game_info_t));
  code = (temp == NULL) * ENOMEM;
  if (!code) *game_info = temp;

  // Аллоцируем строки поля
  if (!code) {
    int **temp = NULL;
    temp = (int **)calloc(field_height, sizeof(int *));
    code = (temp == NULL) * ENOMEM;
    if (!code) (*game_info)->field = temp;
  }
  // Аллоцируем столбцы поля
  if (!code) {
    int *temp = NULL;
    for (int row = 0; !code && row < field_height; row++) {
      temp = (int *)calloc(field_width, sizeof(int));
      code = (temp == NULL) * ENOMEM;
      if (!code) (*game_info)->field[row] = temp;
    }
  }

  if (code) game_info_destroy(*game_info), *game_info = NULL;

  return code;
}