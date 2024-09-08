#ifndef SRC_TESTS_TESTS_H_
#define SRC_TESTS_TESTS_H_

#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../core/scientific_calc.h"

Suite *make_master_suite(void);

Suite *suite_validator(void);
Suite *suite_calc(void);

#endif  // SRC_TESTS_INCLUDES_S21_TESTS_H_