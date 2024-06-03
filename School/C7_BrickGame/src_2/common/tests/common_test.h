#ifndef COMMON_TEST_H
#define COMMON_TEST_H

#include <check.h>

Suite* suite_thread_wait();
Suite* suite_time_msec();
Suite* suite_signals_block();
Suite* suite_signals_unblock();
Suite* suite_set_signal_handler();

void run_tests();
void run_test_case(Suite*);

int memory_locked(int);

#endif