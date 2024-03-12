#include <check.h>

#include "../functions/s21_calculations.h"
#include "../functions/s21_converter.h"

START_TEST(unary_operators_test) {
  s21_stack_t test_polish;
  long double res = 0;
  double epsilon = 1e-7;

  char* str0 = {"sin(2)"};
  char* str1 = {"cos(2)"};
  char* str2 = {"tan(2)"};
  char* str3 = {"asin(0.2)"};
  char* str4 = {"acos(0.2)"};
  char* str5 = {"atan(2)"};
  char* str6 = {"sqrt(2)"};
  char* str7 = {"ln(2)"};
  char* str8 = {"log(2)"};
  char* str9 = {"2-2"};
  char* str10 = {"sin(-2)"};
  char* str11 = {"cos(-2)"};
  char* str12 = {"tan(-2)"};
  char* str13 = {"asin(-0.2)"};
  char* str14 = {"acos(-0.2)"};
  char* str15 = {"atan(-2)"};

  ck_assert_int_eq(0, converting_to_polish(str0, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(0.9092974268, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str1, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(-0.4161468365, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str2, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(-2.1850398633, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str3, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(0.2013579208, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str4, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(1.369438406, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str5, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(1.1071487178, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str6, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(1.4142135624, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str7, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(0.6931471806, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str8, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(0.3010299957, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str9, &test_polish));
  ck_assert_int_eq(0, converting_to_polish(str10, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(-0.9092974268, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str11, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(-0.4161468365, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str12, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(2.1850398633, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str13, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(-0.2013579207903308, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str14, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(1.7721542475852274, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str15, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(-1.1071487177940904, res, epsilon);
}
END_TEST

START_TEST(binary_operators_test) {
  s21_stack_t test_polish;
  long double res = 0;
  double epsilon = 1e-7;

  char* str0 = {"3 - 2"};
  char* str1 = {"3 + 2"};
  char* str2 = {"3 * 2"};
  char* str3 = {"3 / 2"};
  char* str4 = {"3 ^ 2"};
  char* str5 = {"3 % 2"};
  char* str6 = {"(- 3) % 2"};

  ck_assert_int_eq(0, converting_to_polish(str0, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(1.0, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str1, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(5.0, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str2, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(6.0, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str3, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(1.5, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str4, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(9.0, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str5, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(1.0, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str6, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(-1.0, res, epsilon);
}
END_TEST

START_TEST(multi_operators_test) {
  s21_stack_t test_polish;
  long double res = 0;
  double epsilon = 1e-7;

  char* str0 = {"45^log(2)"};
  char* str1 = {"sin(1) / (((((((( 2 + (((-1)))))))))))"};
  char* str2 = {"sin(1) : (.2 + 1"};
  char* str3 = {"3 + (-1 )"};
  char* str4 = {"1-2+(+3)"};
  char* str5 = {"1-2+3*4/5"};
  char* str6 = {"2+(-1+(-1-(-1)))"};
  char* str7 = {"1-2+3*4/5^6"};
  char* str8 = {"1-2+3*4/5^6%7"};
  char* str9 = {"2^2^3"};
  char* str10 = {"2^3^2"};

  ck_assert_int_eq(0, converting_to_polish(str0, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(3.1453324524, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str1, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(0.8414709848, res, epsilon);
  ck_assert_int_eq(1, converting_to_polish(str2, &test_polish));
  ck_assert_int_eq(0, converting_to_polish(str3, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(2, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str4, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(2, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str5, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(1.4, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str6, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(1, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str7, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(-0.999232, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str8, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(-0.999232, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str9, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(256, res, epsilon);
  ck_assert_int_eq(0, converting_to_polish(str10, &test_polish));
  ck_assert_int_eq(0, calculations(&test_polish, &res));
  ck_assert_ldouble_eq_tol(512, res, epsilon);
}
END_TEST

int main() {
  Suite* s1 = suite_create("Core");
  TCase* s21_test = tcase_create("Test");
  SRunner* sr = srunner_create(s1);

  suite_add_tcase(s1, s21_test);

  tcase_add_test(s21_test, unary_operators_test);
  tcase_add_test(s21_test, binary_operators_test);
  tcase_add_test(s21_test, multi_operators_test);

  fprintf(stdout, "=========   TESTING CALCULATIONS   =========\n");
  srunner_run_all(sr, CK_VERBOSE);
  fprintf(stdout, "========= END TESTING CALCULATIONS =========\n");
  int errors = srunner_ntests_failed(sr);
  srunner_free(sr);

  return errors == 0 ? 0 : 1;
}
