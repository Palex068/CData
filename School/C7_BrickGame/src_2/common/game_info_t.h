#ifndef GAME_INFO_T
#define GAME_INFO_T

/**
 * @brief Перечислитель размеров поля
 */
enum field_size { field_height = 20, field_width = 10 };

/**
 * @brief Структура game_info_t для обмена с потоком рендера
 */
typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} game_info_t;

#endif