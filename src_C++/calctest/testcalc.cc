#include <gtest/gtest.h>

#include "../model/calcmodel.h"

TEST(VALIDATOR, case1) {
  std::string expression = "2+2";
  scientific_calc::Model check(expression);

  EXPECT_NO_THROW(check.Validator());
}

TEST(VALIDATOR, case2) {
  std::string expression = "2+-2";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case3) {
  std::string expression = "2+*2";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case4) {
  std::string expression = "2^*2";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case5) {
  std::string expression = "(5+5)";
  scientific_calc::Model check(expression);
  EXPECT_NO_THROW(check.Validator());
}

TEST(VALIDATOR, case6) {
  std::string expression = "(+5)";
  scientific_calc::Model check(expression);
  EXPECT_NO_THROW(check.Validator());
}

TEST(VALIDATOR, case7) {
  std::string expression = "(-5)";
  scientific_calc::Model check(expression);
  EXPECT_NO_THROW(check.Validator());
}

TEST(VALIDATOR, case8) {
  std::string expression = "(^5)";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case9) {
  std::string expression = "2+mod2";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case10) {
  std::string expression = "2mod+2";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case11) {
  std::string expression = "5+3*(6-2))";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case12) {
  std::string expression = "5+3*((6-2)";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case13) {
  std::string expression = "5+3*(6-2)+(-1)";
  scientific_calc::Model check(expression);
  EXPECT_NO_THROW(check.Validator());
}

TEST(VALIDATOR, case14) {
  std::string expression = "(-6-9)+(-1)";
  scientific_calc::Model check(expression);
  EXPECT_NO_THROW(check.Validator());
}

TEST(VALIDATOR, case15) {
  std::string expression = "(6-9)+(+1)";
  scientific_calc::Model check(expression);
  EXPECT_NO_THROW(check.Validator());
}

TEST(VALIDATOR, case16) {
  std::string expression = "sin(+6)";
  scientific_calc::Model check(expression);
  EXPECT_NO_THROW(check.Validator());
}

TEST(VALIDATOR, case17) {
  std::string expression = "asin(-6)";
  scientific_calc::Model check(expression);
  EXPECT_NO_THROW(check.Validator());
}

TEST(VALIDATOR, case18) {
  std::string expression = "atan(*6)";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case19) {
  std::string expression = "log(/6)";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case20) {
  std::string expression = "ln(^6)";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case21) {
  std::string expression = "acos(mod6)";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case22) {
  std::string expression = "sin(6+)";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case23) {
  std::string expression = "5.9+10.3";
  scientific_calc::Model check(expression);
  EXPECT_NO_THROW(check.Validator());
}

TEST(VALIDATOR, case24) {
  std::string expression = "5..9+10.3";
  scientific_calc::Model check(expression);
  std::vector<std::string> lol;
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case25) {
  std::string expression = ".9+10.3";
  scientific_calc::Model check(expression);

  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case26) {
  std::string expression = "9+10.3.";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case27) {
  std::string expression = ")";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case28) {
  std::string expression = "()";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case29) {
  std::string expression = "5-";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case30) {
  std::string expression = "5m";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case31) {
  std::string expression = "^5";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case32) {
  std::string expression = "5mod-";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case33) {
  std::string expression = "-mod";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case34) {
  std::string expression = "sincos()";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case35) {
  std::string expression = "((5+1))";
  scientific_calc::Model check(expression);
  EXPECT_NO_THROW(check.Validator());
}

TEST(VALIDATOR, case36) {
  std::string expression = "(5+5+(5+1))";
  scientific_calc::Model check(expression);
  EXPECT_NO_THROW(check.Validator());
}

TEST(VALIDATOR, case37) {
  std::string expression = "5+5+5.";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(VALIDATOR, case38) {
  std::string expression = "mod";
  scientific_calc::Model check(expression);
  EXPECT_THROW(check.Validator(), std::logic_error);
}

TEST(CALC, case1) {
  std::string expression = "2+5";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(7, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case2) {
  std::string expression = "2+4*(10+46-7)";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(198, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case3) {
  std::string expression = "(2.2)^(-2.2)";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(0.17647, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case4) {
  std::string expression = "5+(3+sin(8/2-3.5))*2";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(11.958851, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case5) {
  std::string expression = "sin(9)-(-2)";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(2.41211848524, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case6) {
  std::string expression = "5+7-1";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(11, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case7) {
  std::string expression = "5.76+43-11";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(37.76, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case8) {
  std::string expression = "1237.55+13.3+(-6)";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(1244.85, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case9) {
  std::string expression = "0.88-54";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(-53.12, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case10) {
  std::string expression = "34+99.56-1.1111";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(132.4489, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case11) {
  std::string expression = "1.054356663+0.00004";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(1.054396663, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case12) {
  std::string expression = "11+7^2-(45+sin(0.7))";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(14.355782312762308, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case13) {
  std::string expression = "sin(cos(0.75))+1.5^3/4.5";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(1.418127185211, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case14) {
  std::string expression = "sin(0.2^4)*cos(100-95*1.5)";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(0.000141414, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case15) {
  std::string expression = "5mod3*6/12+3*(log(3)+tan(3))";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(2.00372413494, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case16) {
  std::string expression = "5*9+(4+2)/5.4";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(46.111111111111, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case17) {
  std::string expression = "3+155.40905+ln(30/2)^2";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(165.74258589, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case18) {
  std::string expression = "cos(1)+sin(2)*sin(1)/14";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(0.594956, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case19) {
  std::string expression = "43.987+11*(atan(2)+sqrt(4))+1.5mod2";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(79.665636, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case20) {
  std::string expression = "(1.654+0.00034)/sqrt(2)";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(1.1697959323882, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case21) {
  std::string expression = "(1.654+0.00034)/sqrt(2)";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(1.1697959323882, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case22) {
  std::string expression = "0.03*(-4)^2";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(0.48, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case23) {
  std::string expression = "sin(cos(4))";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(-0.608083, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case24) {
  std::string expression = "tan(log(0.4))+cos(1.2)";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(-0.05800935062, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case25) {
  std::string expression = "asin(1)*tan(2)-(atan(2)+ln(4))";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(-5.9256956700264893, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case26) {
  std::string expression = "2.11^log(2)*ln(0.5)";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(-0.867849, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case27) {
  std::string expression = "asin(cos(3^3))";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(-0.296462, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case28) {
  std::string expression = "cos(0.65+sqrt(2+1))+1";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(0.274848433242, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case29) {
  std::string expression = "(+atan(5+2mod3))-(+sin(5.23))";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(2.297903011222649, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case30) {
  std::string expression = "(-cos(2-4)^3)";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(0.072067555748, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case31) {
  std::string expression = "4mod3+ln(0.67)";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(0.5995224334028748, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case32) {
  std::string expression = "acos(0.2)+5";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(6.369438406005, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case33) {
  std::string expression = "sqrt(2)+89-6542.6666^0.2";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(84.6179121902894822, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case34) {
  std::string expression = "(-cos(2-4)^3)";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(0.0720676, check.Calc(notation, 0), 1e-6);
}

TEST(CALC, case35) {
  std::string expression = "(+atan(x+2mod3))-(+sin(5.23))";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);
  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(2.297903011222649, check.Calc(notation, 5), 1e-6);
}

TEST(CALC, case36) {
  std::string expression = "4mod3+ln(x)";
  std::vector<std::string> notation;
  scientific_calc::Model check(expression);

  check.Validator();
  notation = check.Parcer();
  ASSERT_NEAR(0.5995224334028748, check.Calc(notation, 0.67), 1e-6);
}
