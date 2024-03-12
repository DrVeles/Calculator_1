#ifndef _S21_CALCULATIONS_H_
#define _S21_CALCULATIONS_H_

#include <math.h>

#include "s21_stack.h"

/**
 * @brief func to calculate polish notation
 * @param polish reverse polish notation to calculate
 * @param result result of calculations
 * @return `0` - success
 * @return `1` - error
 */
int calculations(s21_stack_t* polish, long double* result);

#endif  // _S21_CALCULATIONS_H_