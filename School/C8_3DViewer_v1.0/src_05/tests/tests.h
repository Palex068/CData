#ifndef TESTS_H
#define TESTS_H

#include <check.h>

#include "../common/common.h"
#include "../parser/parser.h"
#include "../transformations/transformations.h"

Suite *test_parser();
Suite *test_scale();
Suite *test_move();
Suite *test_rotate();

#endif
