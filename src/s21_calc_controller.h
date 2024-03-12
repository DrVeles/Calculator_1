#ifndef _S21_CALC_CONTROLLER_H_
#define _S21_CALC_CONTROLLER_H_

#include "functions/s21_calculations.h"
#include "functions/s21_converter.h"

/**
 * @brief func to send string from front to backend
 * @param input_str - string from frontend
 * @param result - result of backend works
 * @return `0` - success
 * @return `1` - failure
 */
int api_to_calculate(const char* input_str, long double* result);

/**
 * @brief func to validate frontend string
 * @param input_str - string from frontend
 * @return `0` - success
 * @return `1` - failure
 */
int api_to_validate(const char* input_str);

#endif  //_S21_CALC_CONTROLLER_H_