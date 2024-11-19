#include <gtest/gtest.h>

#include "Model.h"

using namespace s21;

TEST(SmartCalc, test1) {
  Model model;
  double res = 0;
  bool flag = model.Calculate("((cos(x)+0.853))", "1", res);
  EXPECT_TRUE(flag);
  EXPECT_FLOAT_EQ(res, 1.3933023058681397);
}

TEST(SmartCalc, test2) {
  Model model;
  double res = 0;
  bool flag = model.Calculate("((css(1)+0.853))", "", res);
  EXPECT_FALSE(flag);
}

TEST(SmartCalc, test3) {
  Model model;
  double res = 0;
  bool flag = model.Calculate("((cos(1)+0.853)))", "", res);
  EXPECT_FALSE(flag);
}

TEST(SmartCalc, test4) {
  double res = 0;
  Model m;
  bool flag = m.Calculate("((sin(1)+0.853))", "", res);
  EXPECT_TRUE(flag);
  EXPECT_FLOAT_EQ(res, 1.6944709848078965);
}

TEST(SmartCalc, test5) {
  Model model;
  double res = 0;
  bool flag = model.Calculate("+((cos(log(-1+777.777)+.853)-865.))", "", res);
  EXPECT_TRUE(flag);
  EXPECT_FLOAT_EQ(res, -865.824372433783);
}

TEST(SmartCalc, test6) {
  Model model;
  double res = 0;
  bool flag = model.Calculate("+((cos(log(-1/.777.777)+.853)-865.))", "", res);
  EXPECT_FALSE(flag);
}

TEST(SmartCalc, test7) {
  Model model;
  double res = 0;
  bool flag =
      model.Calculate("+((asin((ln(+.1^.777777)+5)mod2-1)-865.))", "", res);
  EXPECT_TRUE(flag);
  EXPECT_FLOAT_EQ(res, -864.7893431503167);
}

TEST(SmartCalc, test8) {
  Model model;
  double res = 0;
  bool flag = model.Calculate("sqrt((6^atan(9))*9)", "", res);
  EXPECT_TRUE(flag);
  EXPECT_FLOAT_EQ(res, 11.097516262125971);
}

TEST(SmartCalc, test9) {
  Model model;
  double res = 0;
  bool flag = model.Calculate("sqrt((6^atan())*9)", "", res);
  EXPECT_FALSE(flag);
}

TEST(SmartCalc, test10) {
  Model model;
  double res = 0;
  bool flag = model.Calculate("(6+3)(7-9)", "", res);
  EXPECT_FALSE(flag);
}

TEST(SmartCalc, test11) {
  Model model;
  double res = 0;
  bool flag = model.Calculate("tan(6)", "", res);
  EXPECT_TRUE(flag);
  EXPECT_FLOAT_EQ(res, -0.2910061);
}

TEST(SmartCalc, test12) {
  Model model;
  double res = 0;
  bool flag = model.Calculate("sqrt)6)", "", res);
  EXPECT_FALSE(flag);
}

TEST(SmartCalc, test13) {
  Model model;
  double res = 0;
  bool flag = model.Calculate("*sqrt(6)", "", res);
  EXPECT_FALSE(flag);
}

TEST(SmartCalc, test14) {
  Model model;
  double res = 0;
  bool flag = model.Calculate("sqrt(6)mod", "", res);
  EXPECT_FALSE(flag);
}

TEST(SmartCalc, test15) {
  Model model;
  double res = 0;
  bool flag = model.Calculate("acos(sin(3))", "", res);
  EXPECT_TRUE(flag);
  EXPECT_FLOAT_EQ(res, 1.4292036732051034);
}

TEST(SmartCalc, test16) {
  Model model;
  double res = 0;
  bool flag = model.Calculate(
      "15.4121212121212/(7.1-(1.1+1.1))*3-(2+(1+1))*15.4/"
      "(7-(200.1+1))*3-(2+(1+1))*(15.0/"
      "(7-(1.1+1))*3.4-(2+(1+1))+15.23456789101112/(7.5-(1+1))*3.5-(2+(1+1)))",
      "", res);
  EXPECT_TRUE(flag);
  EXPECT_FLOAT_EQ(res, -38.0234740);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}