#include "../../../../includes/brick_game/v1/logic/tetris.h"

void TTRS_tetrisInfoKeeper(TTRS_tetris_t **tetris) {
  static TTRS_tetris_t *temp_tetris = NULL;

  if (tetris) {
    if (*tetris) {
      temp_tetris = *tetris;
    } else {
      *tetris = temp_tetris;
    }
  }
}

// TTRS_RETURN_TYPE TTRS_lastErrorKeeper(TTRS_RETURN_TYPE *last_error) {
//   static TTRS_RETURN_TYPE temp_last_error = TTRS_Ok;

//   if (last_error) {
//     temp_last_error = *last_error;
//   }

//   return temp_last_error;
// }
