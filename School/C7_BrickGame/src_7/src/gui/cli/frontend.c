#include "frontend.h"

/**
 * @brief Entry point of program
 */
int main(void) {
  /** 
  * @brief Сочетание `srand(time(NULL))` устанавливает
  * в качестве базы генератора псевдослучайных чисел
  * текущее время,  используется для того, чтобы при
  * разных запусках генератора псевдослучайных чисел
  * была всякий раз разная база и, соответственно, 
  * разный ряд получаемых значений.
  */
  srand(time(NULL));
  updateCurrentState();
  updateCurrentFigure(true);
  updateNextFigure(true);
  initScore();
  initScreen();

  UserAction_t action = Start;
  WINDOW* field = createWindow(HEIGHT + 3, WIDTH * 2 + 4, 0, 15, true);
  WINDOW* next = createWindow(5, 5 * 2, 8, 2, false);

  while (true) {
    userInput(action, false);
    refreshScreen(field, next);
    action = isPress(getch());
    if (action == Terminate) break;
  }

  destroyWindow(field);
  destroyWindow(next);
  clearMatrix();
  return 0;
}

void refreshScreen(WINDOW* win, WINDOW* next) {
  drawInfo(updateCurrentState());
  drawField(win);
  drawNext(next);
}

/** @brief
 * Инициализация библиотеки экрана средствами ncurses
 * @note cbreak(); Making characters typed by the user immediately available
 *          to the program
 * @note curs_set(0); Hide cursor
 * @note keypad(stdscr, true); If enabled (bf is TRUE), the user can press
 *          a function key (such as an arrow key) and wgetch returns
 *          a single value representing the function key, as in KEY_LEFT.
 * @note noecho(); The echo and noecho routines control whether characters
 *          typed by the user are echoed by getch as they are typed.
 * @note nodelay(stdscr, true); Don't wait until key pressing
 */
void initScreen() {
  initscr();
  cbreak();
  curs_set(0);
  keypad(stdscr, true);
  noecho();

  timeout(100);
  refresh();

  /* color initialization */
  use_default_colors();
  start_color();
  init_pair(1, COLOR_CYAN, -1);
  init_pair(2, COLOR_YELLOW, -1);
  init_pair(3, COLOR_WHITE, -1);
  init_pair(4, COLOR_BLUE, -1);
  init_pair(5, COLOR_MAGENTA, -1);
  init_pair(6, COLOR_GREEN, -1);
  init_pair(7, COLOR_RED, -1);

  init_pair(8, COLOR_BLACK, COLOR_RED);  // for blinking pause
  // TODO Почитать о atexit()
  atexit((void (*)(void))endwin);
}

char* scorePath(char* buffer) {
  snprintf(buffer, BUFFER, "%s/db.txt", getenv("PWD"));
  return buffer;
}

void initScore() {
  loadScore();
  // TODO Почитать о atexit() - позволяет выполнять код при завершении
  atexit(saveScore);
}

void loadScore() {
  char buffer[BUFFER] = {0};
  char* path = scorePath(buffer);
  FILE* f;
  GameInfo_t* state = stateWrapper();
  if ((f = fopen(path, "r"))) {
    if (fscanf(f, "%d", &state->high_score) != 1) state->high_score = 0;
    fclose(f);
  } else {
    /* open fail for other reason than non existing file */
    if (errno != ENOENT)
      perror("Error: Can't open high score file in read mode!");
  }
}

void saveScore() {
  char buffer[BUFFER] = {0};
  char* path = scorePath(buffer);
  FILE* f;
  GameInfo_t state = updateCurrentState();
  if ((f = fopen(path, "w"))) {
    fprintf(f, "%d\n", state.high_score);
    fclose(f);
  } else {
    perror("Error: Can't open high score file in write mode!");
  }
}

WINDOW* createWindow(int H, int W, int y, int x, bool frame) {
  WINDOW* win = newwin(H, W, y, x);
  if (frame) box(win, 0, 0);
  return win;
}

void destroyWindow(WINDOW* win) {
  delwin(win);
  clear();
  refresh();
}

void drawField(WINDOW* win) {
  box(win, 0, 0);
  for (int y = 0; y <= HEIGHT; y++) {
    mvwaddch(win, y + 1, 1, '!');
    mvwaddch(win, y + 1, WIDTH * 2 + 2, '!');
  }

  for (int x = 0; x < WIDTH * 2; x++) {
    mvwaddch(win, HEIGHT + 1, x + 2, '=');
    if ((x + 1) % 2)
      mvwaddch(win, HEIGHT + 2, x + 2, '\\');
    else
      mvwaddch(win, HEIGHT + 2, x + 2, '/');
  }

  GameInfo_t state = updateCurrentState();
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (state.field[y][x]) {
        wattron(win, COLOR_PAIR(state.field[y][x]));
        mvwaddch(win, y + 1, x * 2 + 2, '[');
        mvwaddch(win, y + 1, x * 2 + 3, ']');
        wattroff(win, COLOR_PAIR(state.field[y][x]));
      } else {
        mvwaddch(win, y + 1, x * 2 + 2, ' ');
        mvwaddch(win, y + 1, x * 2 + 3, '.');
      }
    }
  }
  wrefresh(win);
}

void drawNext(WINDOW* win) {
  GameInfo_t state = updateCurrentState();
  for (int y = 0; y < MAX_BLOCKS - 1; y++) {
    for (int x = 0; x < MAX_BLOCKS; x++) {
      if (state.next[y][x]) {
        wattron(win, COLOR_PAIR(state.next[y][x]));
        mvwaddch(win, y + 1, x * 2 + 1, '[');
        mvwaddch(win, y + 1, x * 2 + 2, ']');
        wattroff(win, COLOR_PAIR(state.next[y][x]));
      } else {
        mvwaddch(win, y + 1, x * 2 + 1, ' ');
        mvwaddch(win, y + 1, x * 2 + 2, ' ');
      }
    }
  }
  wrefresh(win);
}

void drawInfo(GameInfo_t info) {
  int y = 0;
  mvprintw(y + 1, 1, "Level:\t%d", info.level);
  mvprintw(y + 2, 1, "Score:\t%d", info.score);
  mvprintw(y + 3, 1, "High:\t%d", info.high_score);

  mvprintw(y + 7, 1, "Next:");

  mvprintw(y + 14, 1, "Left:\t left");
  mvprintw(y + 15, 1, "Right:\t right");
  mvprintw(y + 16, 1, "Down:\t down");
  mvprintw(y + 17, 1, "Drop:\t space");
  mvprintw(y + 18, 1, "Rotate: up");
  mvprintw(y + 20, 1, "Pause:\t p");
  mvprintw(y + 21, 1, "Quit: \t q");
}
