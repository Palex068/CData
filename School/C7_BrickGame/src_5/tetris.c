/*!
 * \mainpage
 * \author ananar27
 * \version 1.0
 *
 * \section intro_sec Tetris
 * Проект создан при помощи:
 * 1. C language
 * 2. ncurses
 * 3. Doxygen
 *
 * \section brief_sec Brief
 * BrickGame — популярная портативная консоль 90-ых годов с несколькими тысячами
 * встроенными играми, разработанная в Китае. Изначально была копией
 * разработанной в СССР и выпущенной Nintendo в рамках платформы GameBoy игры
 * «Тетрис», но включала в себя также и множество других игр, которые
 * добавлялись с течением времени. Консоль имела небольшой экранчик с игровым
 * полем размера 10х20, представляющим из себя матрицу «пикселей». Справа от
 * поля находилось табло с цифровой индикацией состояния текущей игры, рекордами
 * и прочей дополнительной информацией. Самыми распространенными играми на
 * BrickGame были: тетрис, танки, гонки, фроггер и змейка.
 *
 * В данном проекте реализована самая популярная игра из серии BrickGame -
 * Tetris.
 *
 */
#include "tetris.h"

void gameLoop() {
  GameInfo_t *stats = getGameInfo_t();
  if (stats->pause == 0 && stats->started == 1 && stats->stop == 0) {
    deleteLines();
    if (stats->ticks == changeSpeed(stats->level)) {
      stats->ticks = 0;
      mvDown();
    }
    stats->high_score =
        stats->score > stats->high_score ? stats->score : stats->high_score;
    stats->ticks++;
  }
  updateField();
}

void setTimer() {
  struct itimerval it;
  timerclear(&it.it_interval);
  timerclear(&it.it_value);
  it.it_interval.tv_usec = TIMESTEP;
  it.it_value.tv_usec = TIMESTEP;
  setitimer(ITIMER_REAL, &it, NULL);
}

void setSignals() {
  struct sigaction sa;
  sa.sa_handler = handler;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);
  sigaction(SIGTERM, &sa, NULL);
  sigaction(SIGINT, &sa, NULL);
  sigaction(SIGALRM, &sa, NULL);
  sa.sa_handler = SIG_IGN;
  sigaction(SIGTSTP, &sa, NULL);
}

void handler(int signum) {
  switch (signum) {
    case SIGALRM:
      gameLoop();
      return;
    case SIGTERM:
    case SIGINT:
      quitNcurses();
      freeMap();
      exit(EXIT_SUCCESS);
  }
}

int main() {
  getGameInfo_t();
  setTimer();
  setSignals();
  initGame();
  return 0;
}
