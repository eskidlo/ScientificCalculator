#include <check.h>

#include "tests.h"

START_TEST(sum_sum) {
  int right_answer = 0;
  char expression[] = "2++2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(sum_sub) {
  int right_answer = 0;
  char expression[] = "2+-2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(sum_mult) {
  int right_answer = 0;
  char expression[] = "2+*2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(sum_div) {
  int right_answer = 0;
  char expression[] = "2+/2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(sum_degree) {
  int right_answer = 0;
  char expression[] = "2+^2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(sub_sum) {
  int right_answer = 0;
  char expression[] = "2-+2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(sub_sub) {
  int right_answer = 0;
  char expression[] = "2--2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(sub_mult) {
  int right_answer = 0;
  char expression[] = "2-*2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(sub_div) {
  int right_answer = 0;
  char expression[] = "2-/2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(sub_degree) {
  int right_answer = 0;
  char expression[] = "2-^2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(mult_sum) {
  int right_answer = 0;
  char expression[] = "2*+2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(mult_sub) {
  int right_answer = 0;
  char expression[] = "2*-2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(mult_mult) {
  int right_answer = 0;
  char expression[] = "2**2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(mult_div) {
  int right_answer = 0;
  char expression[] = "2*/2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(mult_degree) {
  int right_answer = 0;
  char expression[] = "2*^2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(div_sum) {
  int right_answer = 0;
  char expression[] = "2/+2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(div_sub) {
  int right_answer = 0;
  char expression[] = "2/-2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(div_mult) {
  int right_answer = 0;
  char expression[] = "2/*2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(div_div) {
  int right_answer = 0;
  char expression[] = "2//2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(div_degree) {
  int right_answer = 0;
  char expression[] = "2/^2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(degree_sum) {
  int right_answer = 0;
  char expression[] = "2^+2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(degree_sub) {
  int right_answer = 0;
  char expression[] = "2^-2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(degree_mult) {
  int right_answer = 0;
  char expression[] = "2^*2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(degree_div) {
  int right_answer = 0;
  char expression[] = "2^/2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(degree_degree) {
  int right_answer = 0;
  char expression[] = "2^^2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(right_brace_int) {
  int right_answer = 0;
  char expression[] = "(5+5)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(left_brace_sum) {
  int right_answer = 0;
  char expression[] = "(+5)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(left_brace_sub) {
  int right_answer = 0;
  char expression[] = "(-5)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(left_brace_degree) {
  int right_answer = 0;
  char expression[] = "(^5)";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(sum_mod) {
  int right_answer = 0;
  char expression[] = "2+mod2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(mod_sum) {
  int right_answer = 0;
  char expression[] = "2mod+2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(sub_mod) {
  int right_answer = 0;
  char expression[] = "2-mod2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(mod_sub) {
  int right_answer = 0;
  char expression[] = "2mod-2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(mult_mod) {
  int right_answer = 0;
  char expression[] = "2*mod2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(mod_mult) {
  int right_answer = 0;
  char expression[] = "2mod*2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(div_mod) {
  int right_answer = 0;
  char expression[] = "2/mod2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(mod_div) {
  int right_answer = 0;
  char expression[] = "2mod/2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(degree_mod) {
  int right_answer = 0;
  char expression[] = "2^mod2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(mod_degree) {
  int right_answer = 0;
  char expression[] = "2mod^2";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(div_zero) {
  int right_answer = 0;
  char expression[] = "2/0";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(x_sum) {
  int right_answer = 0;
  char expression[] = "2+x+x+2";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(x_sub) {
  int right_answer = 0;
  char expression[] = "2-x-x-2";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(x_mult) {
  int right_answer = 0;
  char expression[] = "2*x*x*2";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(x_div) {
  int right_answer = 0;
  char expression[] = "2/x/x/2";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(x_degree) {
  int right_answer = 0;
  char expression[] = "2^x";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(degree_x) {
  int right_answer = 0;
  char expression[] = "x^2";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(x_mod) {
  int right_answer = 0;
  char expression[] = "2modx";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(mod_x) {
  int right_answer = 0;
  char expression[] = "xmod2";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(braces_1) {
  int right_answer = 0;
  char expression[] = "5+3*(6-2))";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(braces_2) {
  int right_answer = 0;
  char expression[] = "5+3*((6-2)";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(braces_3) {
  int right_answer = 0;
  char expression[] = "5+3*(6-2)+(-1)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(unary_minus) {
  int right_answer = 0;
  char expression[] = "(-6-9)+(-1)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(unary_plus) {
  int right_answer = 0;
  char expression[] = "(6-9)+(+1)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(left_brace_plus) {
  int right_answer = 0;
  char expression[] = "sin(+6)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(left_brace_minus) {
  int right_answer = 0;
  char expression[] = "asin(-6)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(left_brace_mult) {
  int right_answer = 0;
  char expression[] = "atan(*6)";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(left_brace_div) {
  int right_answer = 0;
  char expression[] = "log(/6)";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(left_brace_degree_2) {
  int right_answer = 0;
  char expression[] = "log(^6)";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(left_brace_mod) {
  int right_answer = 0;
  char expression[] = "log(mod6)";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(right_brace_plus) {
  int right_answer = 0;
  char expression[] = "sin(6+)";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(right_brace_minus) {
  int right_answer = 0;
  char expression[] = "asin(6-)";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(right_brace_mult) {
  int right_answer = 0;
  char expression[] = "atan(6*)";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(right_brace_div) {
  int right_answer = 0;
  char expression[] = "log(6/)";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(right_brace_degree) {
  int right_answer = 0;
  char expression[] = "log(6^)";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(right_brace_mod) {
  int right_answer = 0;
  char expression[] = "log(6mod)";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(double_ok) {
  int right_answer = 0;
  char expression[] = "5.6+9.0";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(double_error) {
  int right_answer = 0;
  char expression[] = "5..6+9.0";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(one_more) {
  int right_answer = 0;
  char expression[] = "(5+x))";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(no_next_point) {
  int right_answer = 0;
  char expression[] = "5.";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(three_point) {
  int right_answer = 0;
  char expression[] = "5...1+1";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(no_next_left_brace) {
  int right_answer = 0;
  char expression[] = "(";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(no_next_right_brace) {
  int right_answer = 0;
  char expression[] = ")";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(no_next_minus) {
  int right_answer = 0;
  char expression[] = "5-";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(no_next_plus) {
  int right_answer = 0;
  char expression[] = "5+";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(no_next_mult) {
  int right_answer = 0;
  char expression[] = "5*";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(no_next_m) {
  int right_answer = 0;
  char expression[] = "5m";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(no_next_degree) {
  int right_answer = 0;
  char expression[] = "5^";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(no_next_div) {
  int right_answer = 0;
  char expression[] = "5/";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(mod_minus) {
  int right_answer = 0;
  char expression[] = "3mod-";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(minus_mod) {
  int right_answer = 0;
  char expression[] = "-mod";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(mod_right_brace) {
  int right_answer = 0;
  char expression[] = "1mod(-5)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(sqrt_mod) {
  int right_answer = 0;
  char expression[] = "2modsqrt(4)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(cos_mod) {
  int right_answer = 0;
  char expression[] = "2modcos(1)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(sin_mod) {
  int right_answer = 0;
  char expression[] = "1modsin(2)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(mod_tan) {
  int right_answer = 0;
  char expression[] = "1modtan(3)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(mod_atan) {
  int right_answer = 0;
  char expression[] = "1modatan(4)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(mod_log) {
  int right_answer = 0;
  char expression[] = "1modlog(5)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(mod_sqrt) {
  int right_answer = 0;
  char expression[] = "1modsqrt(4)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(minus_s) {
  int right_answer = 0;
  char expression[] = "-sin(6)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(minus_cos) {
  int right_answer = 0;
  char expression[] = "-cos(5)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(minus_atan) {
  int right_answer = 0;
  char expression[] = "-atan(0)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(minus_ln) {
  int right_answer = 0;
  char expression[] = "-ln(3)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(another_right_brace_plus) {
  int right_answer = 0;
  char expression[] = "(5+5)+1";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(another_right_brace_mod) {
  int right_answer = 0;
  char expression[] = "(5+5)mod1";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

START_TEST(shtuka_5) {
  int right_answer = 0;
  char expression[] = "*4";
  int my_answer = validator(expression);
  ck_assert_int_ne(right_answer, my_answer);
}
END_TEST

START_TEST(check) {
  int right_answer = 0;
  char expression[] = "1+(-5)";
  int my_answer = validator(expression);
  ck_assert_int_eq(right_answer, my_answer);
}
END_TEST

Suite *suite_validator(void) {
  Suite *s = suite_create("Checking validator...");
  TCase *tc = tcase_create("validator_tc");

  tcase_add_test(tc, sum_sum);
  tcase_add_test(tc, sum_sub);
  tcase_add_test(tc, sum_mult);
  tcase_add_test(tc, sum_div);
  tcase_add_test(tc, sum_degree);
  tcase_add_test(tc, sub_sub);
  tcase_add_test(tc, sub_mult);
  tcase_add_test(tc, sub_div);
  tcase_add_test(tc, sub_degree);
  tcase_add_test(tc, sub_sum);
  tcase_add_test(tc, mult_sum);
  tcase_add_test(tc, mult_sub);
  tcase_add_test(tc, mult_mult);
  tcase_add_test(tc, mult_div);
  tcase_add_test(tc, mult_degree);
  tcase_add_test(tc, div_sum);
  tcase_add_test(tc, div_sub);
  tcase_add_test(tc, div_mult);
  tcase_add_test(tc, div_div);
  tcase_add_test(tc, div_degree);
  tcase_add_test(tc, degree_sum);
  tcase_add_test(tc, degree_sub);
  tcase_add_test(tc, degree_mult);
  tcase_add_test(tc, degree_div);
  tcase_add_test(tc, degree_degree);
  tcase_add_test(tc, sum_mod);
  tcase_add_test(tc, mod_sum);
  tcase_add_test(tc, sub_mod);
  tcase_add_test(tc, mod_sub);
  tcase_add_test(tc, mult_mod);
  tcase_add_test(tc, mod_mult);
  tcase_add_test(tc, div_mod);
  tcase_add_test(tc, mod_div);
  tcase_add_test(tc, degree_mod);
  tcase_add_test(tc, mod_degree);
  tcase_add_test(tc, x_sum);
  tcase_add_test(tc, x_sub);
  tcase_add_test(tc, x_mult);
  tcase_add_test(tc, x_div);
  tcase_add_test(tc, x_degree);
  tcase_add_test(tc, degree_x);
  tcase_add_test(tc, x_mod);
  tcase_add_test(tc, braces_1);
  tcase_add_test(tc, braces_2);
  tcase_add_test(tc, braces_3);
  tcase_add_test(tc, unary_minus);
  tcase_add_test(tc, unary_plus);
  tcase_add_test(tc, left_brace_plus);
  tcase_add_test(tc, left_brace_minus);
  tcase_add_test(tc, left_brace_mult);
  tcase_add_test(tc, left_brace_div);
  tcase_add_test(tc, left_brace_degree);
  tcase_add_test(tc, left_brace_mod);
  tcase_add_test(tc, right_brace_plus);
  tcase_add_test(tc, right_brace_minus);
  tcase_add_test(tc, right_brace_mult);
  tcase_add_test(tc, right_brace_div);
  tcase_add_test(tc, right_brace_degree);
  tcase_add_test(tc, right_brace_mod);
  tcase_add_test(tc, double_ok);
  tcase_add_test(tc, double_error);
  tcase_add_test(tc, right_brace_int);
  tcase_add_test(tc, left_brace_sum);
  tcase_add_test(tc, left_brace_sub);
  tcase_add_test(tc, div_zero);
  tcase_add_test(tc, left_brace_degree_2);
  tcase_add_test(tc, one_more);
  tcase_add_test(tc, no_next_point);
  tcase_add_test(tc, no_next_left_brace);
  tcase_add_test(tc, no_next_right_brace);
  tcase_add_test(tc, three_point);
  tcase_add_test(tc, no_next_plus);
  tcase_add_test(tc, no_next_minus);
  tcase_add_test(tc, no_next_div);
  tcase_add_test(tc, no_next_mult);
  tcase_add_test(tc, no_next_degree);
  tcase_add_test(tc, no_next_m);
  tcase_add_test(tc, mod_x);
  tcase_add_test(tc, mod_minus);
  tcase_add_test(tc, mod_right_brace);
  tcase_add_test(tc, sqrt_mod);
  tcase_add_test(tc, cos_mod);
  tcase_add_test(tc, sin_mod);
  tcase_add_test(tc, mod_tan);
  tcase_add_test(tc, mod_log);
  tcase_add_test(tc, mod_sqrt);
  tcase_add_test(tc, minus_cos);
  tcase_add_test(tc, minus_atan);
  tcase_add_test(tc, minus_s);
  tcase_add_test(tc, minus_cos);
  tcase_add_test(tc, minus_s);
  tcase_add_test(tc, minus_cos);
  tcase_add_test(tc, minus_atan);
  tcase_add_test(tc, minus_ln);
  tcase_add_test(tc, minus_mod);
  tcase_add_test(tc, mod_atan);
  tcase_add_test(tc, another_right_brace_plus);
  tcase_add_test(tc, another_right_brace_mod);
  tcase_add_test(tc, shtuka_5);
  tcase_add_test(tc, check);
  suite_add_tcase(s, tc);
  return s;
}
