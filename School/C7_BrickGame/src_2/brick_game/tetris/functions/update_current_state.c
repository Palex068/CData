#include "common/game_info_t.h"
#include "tetris.h"

/**
 * @ingroup Functions_of_user_input
 * @brief Функции получения данных в виде структуры
 * @return Структура обмена game_info_t
 */
game_info_t update_current_state() {
  game_info_t game_info = {0};
  game_t *game_ptr = game_locate(NULL);

  if (game_ptr) {
    game_info.field = game_ptr->game_info->field;
    game_info.high_score = game_ptr->game_info->high_score;
    game_info.level = game_ptr->game_info->level;
    game_info.next = game_ptr->game_info->next;
    game_info.pause = game_ptr->game_info->pause;
    game_info.score = game_ptr->game_info->score;
    game_info.speed = game_ptr->game_info->speed;
  }

  return game_info;
}