#include "s21_calculations.h"

// subfoo to reverse stack elements order
void reverse_polish(s21_stack_t* polish) {
  s21_stack_t temp_stack = {0};
  s21_node_t temp_node = {0};
  while (!show(polish, &temp_node)) {
    pop(polish, &temp_node);
    push(&temp_stack, &temp_node);
  }
  *polish = temp_stack;
}

long double get_number(s21_node_t* node) { return node->value; }

// subfoo to unary operators
void unary_calculations(s21_stack_t* polish, s21_stack_t* temp_stack) {
  s21_node_t last_node = {0}, temp_node = {0};

  pop(polish, &last_node);
  if (last_node.operators == '-') {
    pop(temp_stack, &temp_node);
    temp_node.value *= -1;
    push(temp_stack, &temp_node);
  } else if (last_node.operators == '+') {
    ;
  } else {
    pop(temp_stack, &temp_node);
    switch (last_node.math_foo) {
      case sin_foo:
        temp_node.value = sinl(temp_node.value);
        break;
      case cos_foo:
        temp_node.value = cosl(temp_node.value);
        break;
      case tan_foo:
        temp_node.value = tanl(temp_node.value);
        break;
      case asin_foo:
        temp_node.value = asinl(temp_node.value);
        break;
      case acos_foo:
        temp_node.value = acosl(temp_node.value);
        break;
      case atan_foo:
        temp_node.value = atanl(temp_node.value);
        break;
      case sqrt_foo:
        temp_node.value = sqrtl(temp_node.value);
        break;
      case ln_foo:
        temp_node.value = logl(temp_node.value);
        break;
      case log_foo:
        temp_node.value = log10l(temp_node.value);
        break;
      default:
        break;
    }
    push(temp_stack, &temp_node);
  }
}

// subfoo to binary operators
void binary_calculations(s21_stack_t* polish, s21_stack_t* temp_stack) {
  s21_node_t last_node = {0};
  pop(temp_stack, &last_node);
  long double second_num = get_number(&last_node);
  pop(temp_stack, &last_node);
  long double first_num = get_number(&last_node);
  pop(polish, &last_node);
  char operator= last_node.operators;
  clear_node(&last_node);
  switch (operator) {
    case '-':
      last_node.value = first_num - second_num;
      break;
    case '+':
      last_node.value = first_num + second_num;
      break;
    case '*':
      last_node.value = first_num * second_num;
      break;
    case '/':
      last_node.value = first_num / second_num;
      break;
    case '^':
      last_node.value = powl(first_num, second_num);
      break;
    case '%':
      last_node.value = fmodl(first_num, second_num);
      break;
    default:
      break;
  }
  push(temp_stack, &last_node);
}

int calculations(s21_stack_t* polish, long double* result) {
  reverse_polish(polish);
  bool err_flag = false;
  s21_stack_t temp_stack = {0};
  s21_node_t last_node = {0};

  while (!show(polish, &last_node)) {
    if (is_number(&last_node)) {
      pop(polish, &last_node);
      push(&temp_stack, &last_node);
    } else if (last_node.is_unary) {
      unary_calculations(polish, &temp_stack);
    } else {
      binary_calculations(polish, &temp_stack);
    }
  }
  show(&temp_stack, &last_node);
  *result = last_node.value;

  return err_flag;
}