#include <stddef.h>

#include "game_t.h"

enum is_set { not_set = 0, set = 1 };

struct locate {
  game_t *addr;
  enum is_set value;
};

/**
 * @ingroup Distributors
 * @brief Функция поставщик адресов данных структуры игры
 * Для выключения поставщика необходимо послать ему тот же
 * указатель повторно
 * @param[in] game_t* Указатель на структуру игры
 * @return game_t* Указатель на структуру игры
 */
game_t *game_locate(game_t *game) {
  static struct locate location = {0};
  game_t *result = NULL;

  if (game == location.addr && location.value) {
    location.value = not_set;
    location.addr = NULL;
  } else if (game) {
    location.value = set;
    location.addr = game;
  }

  if (location.value == set && location.addr) result = location.addr;

  return result;
}