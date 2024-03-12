#include "s21_stack.h"

bool is_number(s21_node_t *node) {
  bool flag = false;
  if ((!node->math_foo && node->operators == '\0') &&
      (!node->is_unary && !node->priority)) {
    flag = true;
  }
  return flag;
}

int push(s21_stack_t *stack, s21_node_t *node) {
  if (stack->top == STACK_SIZE - 1) {
    fprintf(stderr, "stack overflow\n");
    return failure;
  }

  stack->array[stack->top] = *node;
  stack->top++;

  return success;
}

int pop(s21_stack_t *stack, s21_node_t *node) {
  if (stack->top == 0) {
    fprintf(stderr, "stack underflow\n");
    return failure;
  }

  clear_node(node);
  *node = stack->array[stack->top - 1];
  clear_node(&stack->array[stack->top - 1]);
  stack->top--;

  return success;
}

int show(s21_stack_t *stack, s21_node_t *node) {
  if (stack->top == 0) {
    return failure;
  }

  clear_node(node);
  *node = stack->array[stack->top - 1];

  return success;
}

void clear_node(s21_node_t *node) {
  node->math_foo = 0;
  node->operators = '\0';
  node->is_unary = false;
  node->priority = 0;
  node->value = 0.0;
}

void clear_stack(s21_stack_t *stack) {
  for (int i = 0; i < STACK_SIZE; i++) {
    clear_node(&stack->array[i]);
  }
  stack->top = 0;
}
