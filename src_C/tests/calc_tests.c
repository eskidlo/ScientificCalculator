#include <check.h>

#include "tests.h"

START_TEST(rand0) {
  double res;
  double true_res = 6;
  char *text = "2+4";
  char *pn_text;
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand1) {
  double res;
  double true_res = 198;
  char *text = "2+4*(10+46-7)";
  char *pn_text;
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand2) {
  double res;
  char *pn_text;
  double true_res = 0.176469681;
  char *text = "(2.2)^(-2.2)";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand3) {
  double res;
  char *pn_text;
  double true_res = 11.958851;
  char *text = "5+(3+sin(8/2-3.5))*2";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand4) {
  double res;
  char *pn_text;
  double true_res = 2.41211848524;
  char *text = "sin(9)-(-2)";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand5) {
  double res;
  char *pn_text;
  double true_res = 0.98992582956;
  char *text = "cos(sin(tan(3)))";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand6) {
  double res;
  char *pn_text;
  double true_res = 11;
  char text[30] = "5+7-1";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand7) {
  double res;
  char *pn_text;
  double true_res = 37.76;
  char text[30] = "5.76+43-11";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand8) {
  double res;
  char *pn_text;
  double true_res = 1244.85;
  char text[30] = "1237.55+13.3+(-6)";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand9) {
  double res;
  char *pn_text;
  double true_res = -53.12;
  char text[30] = "0.88-54";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand10) {
  double res;
  char *pn_text;
  double true_res = 132.4489;
  char text[30] = "34+99.56-1.1111";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand11) {
  double res;
  char *pn_text;
  double true_res = 1.054396663;
  char text[30] = "1.054356663+0.00004";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand12) {
  double res;
  char *pn_text;
  double true_res = 14.355782312762308;
  char text[30] = "11+7^2-(45+sin(0.7))";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand13) {
  double res;
  char *pn_text;
  double true_res = 1.418127185211;
  char text[30] = "sin(cos(0.75))+1.5^3/4.5";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand14) {
  double res;
  char *pn_text;
  double true_res = 0.000141414;
  char text[30] = "sin(0.2^4)*cos(100-95*1.5)";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand15) {
  double res;
  char *pn_text;
  double true_res = 2.00372413494;
  ;
  char text[30] = "5mod3*6/12+3*(log(3)+tan(3))";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand16) {
  double res;
  char *pn_text;
  double true_res = 46.1111111111;
  char text[30] = "5*9+(4+2)/5.4";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand17) {
  double res;
  char *pn_text;
  double true_res = 57599.650844034542;
  char text[30] = "3+155.40905+ln(30/2)^11";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand19) {
  double res;
  char *pn_text;
  double true_res = 0.594956;
  char text[30] = "cos(1)+sin(2)*sin(1)/14";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand20) {
  double res;
  char *pn_text;
  double true_res = 79.665636;
  char text[40] = "43.987+11*(atan(2)+sqrt(4))+1.5mod2";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand32) {
  double res;
  char *pn_text;
  double true_res = 1.1697959323882;
  char text[30] = "(1.654+0.00034)/sqrt(2)";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand21) {
  double res;
  char *pn_text;
  double true_res = 0.48;
  char text[30] = "0.03*(-4)^2";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand22) {
  double res;
  char *pn_text;
  double true_res = -0.608083;
  char text[30] = "sin(cos(4))";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand23) {
  double res;
  char *pn_text;
  double true_res = -0.05800935062;
  char text[30] = "tan(log(0.4))+cos(1.2)";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand24) {
  double res;
  char *pn_text;
  double true_res = -5.9256956700264893;
  char *text = "asin(1)*tan(2)-(atan(2)+ln(4))";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand25) {
  double res;
  char *pn_text;
  double true_res = 0.823538;
  char text[30] = "log(3)^ln(1.3)";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand26) {
  double res;
  char *pn_text;
  double true_res = -0.867849;
  char text[30] = "2.11^log(2)*ln(0.5)";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand27) {
  double res;
  char *pn_text;
  double true_res = -0.296462;
  char text[30] = "asin(cos(3^3))";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand28) {
  double res;
  char *pn_text;
  double true_res = 0.274848433242;
  char text[30] = "cos(0.65+sqrt(2+1))+1";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand29) {
  double res;
  char *pn_text;
  double true_res = 2.297903011222649;
  char text[30] = "(+atan(5+2mod3))-(+sin(5.23))";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand30) {
  double res;
  char *pn_text;
  double true_res = 0.072067555748;
  char text[30] = "(-cos(2-4)^3)";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand31) {
  double res;
  char *pn_text;
  double true_res = 0.5995224334028748;
  char text[30] = "4mod3+ln(0.67)";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand33) {
  double res;
  char *pn_text;
  double true_res = 6.369438406005;
  char text[30] = "acos(0.2)+5";
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, 0.0);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(rand34) {
  double res;
  char *pn_text;
  double true_res = 6;
  char text[30] = "x+5";
  double true_x = 1;
  int error = validator(text);
  pn_text = parcer(text);
  res = calc(pn_text, true_x);
  ck_assert_double_eq(fabs(res - true_res) > 1e-6, 0);
  ck_assert_int_eq(error, 0);
}
END_TEST
Suite *suite_calc(void) {
  Suite *s = suite_create("Checking calculator...");
  TCase *tc = tcase_create("calc_tc");

  tcase_add_test(tc, rand0);
  tcase_add_test(tc, rand1);
  tcase_add_test(tc, rand2);
  tcase_add_test(tc, rand3);
  tcase_add_test(tc, rand4);
  tcase_add_test(tc, rand5);
  tcase_add_test(tc, rand6);
  tcase_add_test(tc, rand7);
  tcase_add_test(tc, rand8);
  tcase_add_test(tc, rand9);
  tcase_add_test(tc, rand10);
  tcase_add_test(tc, rand11);
  tcase_add_test(tc, rand12);
  tcase_add_test(tc, rand13);
  tcase_add_test(tc, rand14);
  tcase_add_test(tc, rand15);
  tcase_add_test(tc, rand16);
  tcase_add_test(tc, rand17);
  tcase_add_test(tc, rand19);
  tcase_add_test(tc, rand20);
  tcase_add_test(tc, rand21);
  tcase_add_test(tc, rand22);
  tcase_add_test(tc, rand23);
  tcase_add_test(tc, rand24);
  tcase_add_test(tc, rand25);
  tcase_add_test(tc, rand26);
  tcase_add_test(tc, rand27);
  tcase_add_test(tc, rand28);
  tcase_add_test(tc, rand29);
  tcase_add_test(tc, rand30);
  tcase_add_test(tc, rand31);
  tcase_add_test(tc, rand32);
  tcase_add_test(tc, rand33);
  tcase_add_test(tc, rand34);
  suite_add_tcase(s, tc);
  return s;
}