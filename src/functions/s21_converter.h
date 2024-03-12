#ifndef _S21_CONVERTER_H_
#define _S21_CONVERTER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_stack.h"

/**
 * @brief foo checking string to correct input
 * @param str - string to check
 * @return `0` - if string correct
 * @return `1` - if string incorrect
 */
int validate_string(char* str);

/**
 * @brief foo converts to reverse polish notation
 * @param str - string to convert
 * @param polish - polish notation stack
 * @return `0` - if convert success
 * @return `1` - if convert failed
 */
int converting_to_polish(char* str, s21_stack_t* polish);

#endif  //_S21_CONVERTER_H_