#include "game.h"

int main() {
  initscr();
  curs_set(0);
  cbreak();
  keypad(stdscr, TRUE);
  noecho();

  initialize_state();
  render(updateCurrentState());

  while (1) {
    State_t *state = get_current_state();

    if (state->status == Initial) {
      updateUserAction();
    } else if (state->status == Spawn) {
      spawn_new_block();
    } else if (state->status == Moving) {
      updateUserAction();
    } else if (state->status == Shifting) {
      shift_block();
    } else if (state->status == Attaching) {
      attach_block();
    } else if (state->status == GameOver) {
      finish_game();
    }

    render(updateCurrentState());
  }

  return 0;
}

void updateUserAction() {
  State_t *state = get_current_state();

  unsigned long long time_left = process_timer();
  
  timeout(time_left);
  int c = getch();

  if (c == START_BUTTON) {
    userInput(Start);
  } else if (c == KEY_LEFT) {
    userInput(Left);
  } else if (c == KEY_RIGHT) {
    userInput(Right);
  } else if ((c == KEY_DOWN) && (state->status == Moving)) {
    while (block_is_attached() == 0) {
      (state->coord_x)++;
      render(updateCurrentState());
      usleep(10000);
    }
    userInput(Down);
  } else if (c == ACTION_BUTTON) {
    userInput(Action);
  } else if ((c == PAUSE_BUTTON) && (state->status != Initial)) {
    userInput(Pause);
    render(updateCurrentState());
    char c = getch();
    while ((c != PAUSE_BUTTON) && (c != TERMINATE_BUTTON)) {
      c = getch();
    }
    if (c == PAUSE_BUTTON) {
      userInput(Pause);
    } else {
      userInput(Terminate);
      terminate_game();
    }
  } else if (c == TERMINATE_BUTTON) {
    userInput(Terminate);
    terminate_game();
  } else if (c == ERR) {
    state->status = Shifting;
  }
}
