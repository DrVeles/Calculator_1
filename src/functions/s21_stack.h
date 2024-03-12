#ifndef _S21_STACK_H_
#define _S21_STACK_H_

#define STACK_SIZE 255

#include <stdbool.h>
#include <stdio.h>

// result of working foo
typedef enum result { success, failure } result_e;

/**
operation priority:
0 - x, n
1 - sum, sub
2 - div, mod, mult
3 - brackets, pow, unary plus, unary minus
4 - sin, cos, tan, asin, acos, atan, sqrt, ln, log
*/
typedef enum priority { zero, first, second, third, fourt } priority_e;

// enum for math functions
typedef enum multi_character {
  not_foo,
  sin_foo,
  cos_foo,
  tan_foo,
  asin_foo,
  acos_foo,
  atan_foo,
  sqrt_foo,
  ln_foo,
  log_foo
} multi_character_e;

// node of stack
typedef struct {
  int math_foo;
  // (, ), -, +, *, /, ^, %
  char operators;
  bool is_unary;
  int priority;
  long double value;
} s21_node_t;

// stack array and top of array
typedef struct {
  int top;
  s21_node_t array[STACK_SIZE];
} s21_stack_t;

// foo to validate node is number? return: true or false
bool is_number(s21_node_t *node);

// pushing node to top of stack
int push(s21_stack_t *stack, s21_node_t *node);

// take node from top of stack
int pop(s21_stack_t *stack, s21_node_t *node);

// only show last node
int show(s21_stack_t *stack, s21_node_t *node);

// clearing node
void clear_node(s21_node_t *node);

// clearing stack
void clear_stack(s21_stack_t *stack);

#endif  //_S21_STACK_H_
