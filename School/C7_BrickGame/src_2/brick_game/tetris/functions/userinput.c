#include <time.h>

#include "tetris.h"

/**
 * @ingroup Functions_getting_data_structure_for_rendering
 * @brief Функция осуществляющая передачу пользовательского ввода в МКА
 * @return Функция не возвращает значения
 */
void userInput(UserAction_t user_action, int hold) {
  int code = 0;
  action act = NULL;
  game_t *game = NULL;

  code = (user_action > 8 || hold < 0);

  if (!code) {
    game = game_locate(NULL);
    code = (game == NULL);
  }

  if (!code) {
    // Получаем указатель на функцию-обработчик события
    act = fsm(game->state, user_action);

    // Заглушка
    if (hold) hold = 1;

    // Запускаем обработчик
    if (act) act(game);
  }
}
