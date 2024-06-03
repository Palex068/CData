#ifndef S21_INTERFACES_H
#define S21_INTERFACES_H

#include <stdbool.h>

typedef enum {
  BG_Start,
  BG_Pause,
  BG_Terminate,
  BG_Left,
  BG_Right,
  BG_Up,
  BG_Down,
  BG_Action

} BG_UserAction_t;

#define BG_GI_CEIL_TYPE int
typedef struct {
  BG_GI_CEIL_TYPE **field;
  BG_GI_CEIL_TYPE **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;

} BG_GameInfo_t;

typedef struct {
  BG_UserAction_t action;
  bool hold;

} BG_UserInput_t;

#endif
