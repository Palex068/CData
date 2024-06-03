
#include "../../../includes/brick_game/v1/gui/cli.h"
#include "../../../includes/brick_game/v1/logic/tetris.h"

// Controller

void main_loop(TTRS_tetris_t *tetris) {
  clock_t last_fall_time = clock();

  BG_UserInput_t last_user_input = {};

  char exit_flag = 0;
  while (!exit_flag) {
    last_user_input = CLI_getUserInput();
    TTRS_userInput(last_user_input.action, last_user_input.hold);

    CLI_printCurrentState(TTRS_updateCurrentState());

    if (!TTRS_isPause() &&
        clock() >
            last_fall_time + (1000 * (BG_DEFAULT_FALL_TIME_MS -
                                      tetris->speed * BG_SPEED_STEP_TIME_MS))) {
      tetris->is_fall_time = 1;

      last_fall_time = clock();
    } else if (TTRS_isPause()) {
      last_fall_time = clock();
    }

    if (TTRS_isGameEnd()) {
      exit_flag = 1;
      break;
    }
  }
}

int main(void) {
  TTRS_tetris_t tetris = {};
  GS_cli_t cli = {};

  {  // construct
    TTRS_initTetris(&tetris);
    CLI_createCli(&cli);
  }

  {
    FILE *high_score_file = fopen("highScore.ttrs", "rb+");
    int temp_high_score;
    if (high_score_file) {
      if (fscanf(high_score_file, "%d", &temp_high_score)) {
        if (temp_high_score > TTRS_getHighScore()) {
          TTRS_setHighScore(temp_high_score);
        }
      }
      fclose(high_score_file);
    }
  }

  main_loop(&tetris);

  {
    FILE *high_score_file = fopen("highScore.ttrs", "wb+");
    int temp_high_score;
    if (high_score_file) {
      if (fscanf(high_score_file, "%d", &temp_high_score)) {
        if (temp_high_score < TTRS_getHighScore()) {
          fseek(high_score_file, 0, SEEK_SET);
          fprintf(high_score_file, "%d", TTRS_getHighScore());
        }
      }
      fclose(high_score_file);
    }
  }

  {  // destruct
    TTRS_removeTetris(&tetris);
    CLI_removeCli(&cli);
  }

  return 0;
}
