#include <check.h>

#include "../functions/s21_converter.h"

START_TEST(stack_tests) {
  s21_stack_t test_stack = {0};
  s21_node_t test_node = {0};

  ck_assert_int_eq(1, pop(&test_stack, &test_node));
  test_node.math_foo = 1;
  ck_assert_int_eq(0, push(&test_stack, &test_node));
  test_node.math_foo = cos_foo;
  ck_assert_int_eq(0, push(&test_stack, &test_node));
  clear_node(&test_node);
  ck_assert_int_eq(0, show(&test_stack, &test_node));
  ck_assert_int_eq(2, test_node.math_foo);
  ck_assert_int_eq(0, pop(&test_stack, &test_node));
  ck_assert_int_eq(2, test_node.math_foo);
  ck_assert_int_eq(0, pop(&test_stack, &test_node));
  ck_assert_int_eq(1, test_node.math_foo);
  ck_assert_int_eq(1, pop(&test_stack, &test_node));
  ck_assert_int_eq(1, show(&test_stack, &test_node));
  test_node.math_foo = 1;
  ck_assert_int_eq(0, push(&test_stack, &test_node));
  ck_assert_int_eq(0, push(&test_stack, &test_node));
  ck_assert_int_eq(0, push(&test_stack, &test_node));
  ck_assert_int_eq(0, push(&test_stack, &test_node));
  ck_assert_int_eq(0, push(&test_stack, &test_node));
  ck_assert_int_eq(0, push(&test_stack, &test_node));
  clear_stack(&test_stack);
  ck_assert_int_eq(1, show(&test_stack, &test_node));
}
END_TEST

START_TEST(validate_string_tests) {
  char* str1 = {"3 + 1"};
  char* str2 = {"3 + ( - 1)"};
  char* str3 = {"sin(1) : (2 + 1)"};
  char* str4 = {"3 + 1."};
  char* str5 = {".3 + 1"};
  char* str6 = {"3 + ( - 1))"};
  char* str7 = {"sin(1) : (.2 + 1"};

  ck_assert_int_eq(0, validate_string(str1));
  ck_assert_int_eq(0, validate_string(str2));
  ck_assert_int_eq(0, validate_string(str3));
  ck_assert_int_eq(1, validate_string(str4));
  ck_assert_int_eq(1, validate_string(str5));
  ck_assert_int_eq(1, validate_string(str6));
  ck_assert_int_eq(1, validate_string(str7));
}
END_TEST

START_TEST(converting_to_polish_tests) {
  s21_stack_t test_polish;
  char* str0 = {"45^log(2)"};
  char* str1 = {"3 + 1"};
  char* str2 = {"3 + (-1 )"};
  char* str3 = {"sin(1) / (((((((( 2 + (((-1)))))))))))"};

  ck_assert_int_eq(0, converting_to_polish(str0, &test_polish));
  ck_assert_int_eq(3, test_polish.array[3].priority);
  ck_assert_int_eq(9, test_polish.array[2].math_foo);
  ck_assert_int_eq(4, test_polish.array[2].priority);
  ck_assert_ldouble_eq(2.0, test_polish.array[1].value);
  ck_assert_ldouble_eq(45.0, test_polish.array[0].value);
  ck_assert_int_eq(0, converting_to_polish(str1, &test_polish));
  ck_assert_int_eq(1, test_polish.array[2].priority);
  ck_assert_ldouble_eq(1.0, test_polish.array[1].value);
  ck_assert_ldouble_eq(3.0, test_polish.array[0].value);
  ck_assert_int_eq(0, converting_to_polish(str2, &test_polish));
  ck_assert_int_eq(1, test_polish.array[3].priority);
  ck_assert_int_eq(3, test_polish.array[2].priority);
  ck_assert_ldouble_eq(1.0, test_polish.array[1].value);
  ck_assert_ldouble_eq(3.0, test_polish.array[0].value);
  ck_assert_int_eq(0, converting_to_polish(str3, &test_polish));
  ck_assert_int_eq(2, test_polish.array[6].priority);
  ck_assert_int_eq(1, test_polish.array[5].priority);
  ck_assert_int_eq(3, test_polish.array[4].priority);
  ck_assert_ldouble_eq(1, test_polish.array[3].value);
  ck_assert_ldouble_eq(2, test_polish.array[2].value);
  ck_assert_int_eq(1, test_polish.array[1].math_foo);
  ck_assert_ldouble_eq(1, test_polish.array[0].value);
}
END_TEST

int main() {
  Suite* s1 = suite_create("Core");
  TCase* s21_test = tcase_create("Test");
  SRunner* sr = srunner_create(s1);

  suite_add_tcase(s1, s21_test);

  tcase_add_test(s21_test, stack_tests);
  tcase_add_test(s21_test, validate_string_tests);
  tcase_add_test(s21_test, converting_to_polish_tests);

  fprintf(stdout, "==========  TESTING CONVERTERS  ============\n");
  srunner_run_all(sr, CK_VERBOSE);
  fprintf(stdout, "========== END TESTING CONVERTERS ==========\n");
  int errors = srunner_ntests_failed(sr);
  srunner_free(sr);

  return errors == 0 ? 0 : 1;
}
