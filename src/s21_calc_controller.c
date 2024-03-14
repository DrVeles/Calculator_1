#include "s21_calc_controller.h"

int api_to_calculate(const char* input_str, long double* result) {
  int flag = 0;
  s21_stack_t polish;
  char* copy_str = malloc(strlen(input_str) + 1);
  strcpy(copy_str, input_str);
  long double temp_res = 0;

  if (!(validate_string(copy_str)) &&
      !(converting_to_polish(copy_str, &polish)) &&
      !(calculations(&polish, &temp_res))) {
    *result = temp_res;
  } else {
    flag = 1;
  }
  free(copy_str);

  return flag;
}

int api_to_validate(const char* input_str) {
  int flag = 0;
  char* copy_str = malloc(strlen(input_str) + 1);
  strcpy(copy_str, input_str);

  if ((validate_string(copy_str))) {
    flag = 1;
  }
  free(copy_str);

  return flag;
}