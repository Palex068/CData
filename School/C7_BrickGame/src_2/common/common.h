#ifndef COMMON_H
#define COMMON_H

int thread_wait(int msec);
unsigned long time_msec();
int signals_block();
int signals_unblock();
void set_signal_handler(void (*)(int, void *, void *));

#endif