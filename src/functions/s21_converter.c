

#include "s21_converter.h"

int validate_string(char* str) {
  int flag = success;
  int brackets = 0;
  size_t lenght_str = strlen(str);
  for (size_t i = 0; i < lenght_str && !flag; i++) {
    if (str[i] == '(') {
      brackets++;
    } else if (str[i] == ')') {
      brackets--;
    } else if (str[i] == '.') {
      if (i == 0) {
        flag = failure;
      } else if (str[i - 1] < '0' || str[i - 1] > '9' || str[i + 1] < '0' ||
                 str[i + 1] > '9') {
        flag = failure;
      }
    } else if (i == lenght_str - 1 && str[i] != ')' &&
               !(str[i] <= '9' && str[i] >= '0')) {
      flag = failure;
    }
  }
  if (brackets != 0) {
    flag = failure;
  }

  return flag;
}

// subfoo to converting_to_polish
size_t parse_numbers(char* str, size_t i, size_t lenth_of_str,
                     s21_node_t* temp_node) {
  int lenth_num = 1;
  for (size_t j = i + 1;
       j < lenth_of_str && ((str[j] >= '0' && str[j] <= '9') || str[j] == '.');
       j++, lenth_num++) {
    ;
  }
  char str_number[lenth_num + 1];
  str_number[lenth_num] = '\0';

  strncpy(str_number, &str[i], lenth_num);
  temp_node->value = atof(str_number);

  return (i += lenth_num);
}

// subfoo to converting_to_polish
size_t parse_brackets_funcs(char* str, size_t i, s21_node_t* temp_node) {
  size_t len_str_foo = 0;
  if (str[i] == '(') {
    temp_node->operators = '(';
    temp_node->priority = third;
    len_str_foo = 1;
  } else if (str[i] == 's') {
    if (str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == '(') {
      temp_node->math_foo = sin_foo;
    } else if (str[i + 1] == 'q' && str[i + 4] == '(') {
      temp_node->math_foo = sqrt_foo;
      len_str_foo = 5;
    }
  } else if (str[i] == 'c' && str[i + 3] == '(') {
    temp_node->math_foo = cos_foo;
  } else if (str[i] == 't' && str[i + 3] == '(') {
    temp_node->math_foo = tan_foo;
  } else if (str[i] == 'a') {
    if (str[i + 1] == 's' && str[i + 4] == '(') {
      temp_node->math_foo = asin_foo;
    } else if (str[i + 1] == 'c' && str[i + 4] == '(') {
      temp_node->math_foo = acos_foo;
    } else if (str[i + 1] == 't' && str[i + 4] == '(') {
      temp_node->math_foo = atan_foo;
    }
    len_str_foo = 5;
  } else if (str[i] == 'l') {
    if (str[i + 1] == 'n' && str[i + 2] == '(') {
      temp_node->math_foo = ln_foo;
      len_str_foo = 3;
    } else if (str[i + 1] == 'o' && str[i + 3] == '(') {
      temp_node->math_foo = log_foo;
    }
  }
  if (!temp_node->priority) {
    temp_node->priority = fourt;
  }
  if (!len_str_foo) {
    len_str_foo = 4;
  }
  temp_node->is_unary = true;
  return i + len_str_foo;
}

// subfoo to converting_to_polish
void parse_operators(char* str, size_t i, s21_node_t* temp_node,
                     s21_stack_t* temp_polish, s21_stack_t* temp_stack) {
  s21_node_t last_node = {0};
  show(temp_stack, &last_node);
  if ((str[i] == '+' || str[i] == '-') &&
      (str[i - 1] == '(' || (str[i - 1] == ' ' && str[i - 2] == '('))) {
    temp_node->is_unary = true;
    temp_node->priority = third;
  } else if (str[i] == '+' || str[i] == '-') {
    temp_node->priority = first;
  } else if (str[i] == '^') {
    temp_node->priority = third;
  } else {
    temp_node->priority = second;
  }
  temp_node->operators = str[i];

  while ((!show(temp_stack, &last_node)) && (last_node.operators != '(') &&
         (((last_node.priority >= temp_node->priority) &&
           (!temp_node->is_unary && temp_node->operators != '^')))) {
    s21_node_t copy_node = {0};
    pop(temp_stack, &copy_node);
    push(temp_polish, &copy_node);
  }
  push(temp_stack, temp_node);
}

// subfoo to converting_to_polish
void parse_close_brackets(s21_stack_t* temp_polish, s21_stack_t* temp_stack) {
  s21_node_t last_node = {0};
  bool while_flag = true;
  while ((!show(temp_stack, &last_node)) && (last_node.operators != '(') &&
         while_flag) {
    pop(temp_stack, &last_node);
    push(temp_polish, &last_node);
    if (last_node.math_foo) {
      while_flag = false;
    }
  }
  if (last_node.operators == '(') {
    pop(temp_stack, &last_node);
  }
}

int converting_to_polish(char* str, s21_stack_t* polish) {
  if (validate_string(str)) {
    return failure;
  }
  int flag = success;
  s21_stack_t temp_stack = {0}, temp_polish = {0};
  size_t lenth_of_str = strlen(str);

  for (size_t i = 0; i < lenth_of_str && !flag;) {
    size_t temp_i = i;
    s21_node_t temp_node = {0};

    if (str[i] == ' ') {
      temp_i++;
    } else if (str[i] >= '0' && str[i] <= '9') {
      temp_i = parse_numbers(str, temp_i, lenth_of_str, &temp_node);
      push(&temp_polish, &temp_node);
    } else if (str[i] == '(' || str[i] == 's' || str[i] == 'c' ||
               str[i] == 't' || str[i] == 'a' || str[i] == 'l') {
      temp_i = parse_brackets_funcs(str, temp_i, &temp_node);
      push(&temp_stack, &temp_node);
    } else if ((str[i] == '+' || str[i] == '-' || str[i] == '*' ||
                str[i] == '/' || str[i] == '^' || str[i] == '%')) {
      parse_operators(str, temp_i, &temp_node, &temp_polish, &temp_stack);
      temp_i++;
    } else if (str[i] == ')') {
      parse_close_brackets(&temp_polish, &temp_stack);
      temp_i++;
    }
    if (i == lenth_of_str - 1) {
      while (!show(&temp_stack, &temp_node)) {
        pop(&temp_stack, &temp_node);
        push(&temp_polish, &temp_node);
      }
    }
    i = temp_i;
  }
  *polish = temp_polish;
  return flag;
}
