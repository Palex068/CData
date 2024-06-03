#ifndef BACKEND_H
#define BACKEND_H

#include <locale.h>
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FIG_NUM 7
#define FIELD_W 10
#define FIELD_H 20
#define FIGURE_SIZE 4
#define SPEED_FRACTION 1.1
#define R_R 1
#define M_L 0
#define M_R 1
#define M_D 2

#define BACK_INIT() \
  { srand(time(NULL)); }

#define FIGURE_INIT() \
  {                   \
    I.fig[1][0] = 1;  \
    I.fig[1][1] = 1;  \
    I.fig[1][2] = 1;  \
    I.fig[1][3] = 1;  \
                      \
    O.fig[1][2] = 1;  \
    O.fig[2][2] = 1;  \
    O.fig[2][1] = 1;  \
    O.fig[1][1] = 1;  \
                      \
    J.fig[1][0] = 1;  \
    J.fig[2][0] = 1;  \
    J.fig[2][1] = 1;  \
    J.fig[2][2] = 1;  \
                      \
    L.fig[1][1] = 1;  \
    L.fig[2][1] = 1;  \
    L.fig[2][2] = 1;  \
    L.fig[3][2] = 1;  \
                      \
    S.fig[1][1] = 1;  \
    S.fig[2][1] = 1;  \
    S.fig[2][2] = 1;  \
    S.fig[3][2] = 1;  \
                      \
    Z.fig[1][2] = 1;  \
    Z.fig[2][1] = 1;  \
    Z.fig[2][2] = 1;  \
    Z.fig[3][1] = 1;  \
                      \
    T.fig[1][2] = 1;  \
    T.fig[2][0] = 1;  \
    T.fig[2][1] = 1;  \
    T.fig[2][2] = 1;  \
  }

struct Figure {
  int fig[4][4];
};
typedef struct Figure figure;

typedef struct {
  int** field;
  int** next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

typedef struct {
  int** cur_fig;
} matrix;

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

void init_gameinfo_t();
void create_field_next(GameInfo_t* gameInfo_t);
void delete_field_next(GameInfo_t* gameInfo_t);
int testline(const int line[FIELD_W]);
void delline(int** field, int line);
void fill_test(int** field, int* score);
void save_high_score(int high_score);
void rotate_fig(int** field, int** F, int* x, int* y, int dir);
void rotateaux(int** F, int dir);
int freeplace(int** field, int** F, int y, int x);
int move_fig(int** field, int** F, int* x, int* y, int dir);
void putfig(int** field, int** F, int y, int x);
void delfig(int** field, int** F, int y, int x);
GameInfo_t* getInstance_GameInfo_t();
UserAction_t* getInstance_UserAction_t();
int* getInstance_ch();
int* getInstance_x();
int* getInstance_y();
matrix* getInstance_cur_fig();
int* getInstance_hold();
void init_matrix();
void uninit_matrix(matrix* matr);
void copy_data_1(int** to, int from[FIGURE_SIZE][FIGURE_SIZE]);
void copy_data_2(int** to, int** from);
void userInput(UserAction_t action, bool hold);
GameInfo_t updateCurrentState();
void go_to(UserAction_t* action, int* hold, int pause);
void check_the_end();
void set_high_score();
void set_speed(double* delay);

#endif  // BACKEND_H