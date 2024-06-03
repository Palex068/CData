/*Модуль Контроллер.
Является точкой входа в программу.
Управляет потоками tetris и gui_cli.*/

#ifndef CONROLLER_H
#define CONROLLER_H

#include "common/runtime_t.h"
#include "common/useraction_t.h"

int controller_init(runtime_t *);
void *controller_loop(runtime_t *);
int controller_destroy(runtime_t *);

int canonical_mode(int);
int get_action(UserAction_t *, char *);

#endif