#include <gtest/gtest.h>

#include <cmath>
#include <string>
#include <vector>

#include "../common/expressionerrorcode.h"
#include "../model/calculatormodel.h"

namespace s21 {
TEST(ArithmeticTest, CosineTest) {
  std::vector<std::string> expressions{
      "cos(1.5)", "cos(123432)", "cos(-1.5)", "cos(0)",
      "cos(-0)",  "cos(1)",      "cos(-1)",   "cos(-234234)",
  };

  double desiredResults[]{0.999657325, 0.669130606, 0.999657325, 1,
                          1,           0.999847695, 0.999847695, -0.587785252};

  ExpressionErrorCode desiredErrorCode{ExpressionErrorCode::kOk};

  CalculatorModel model{};
  for (std::size_t i{0}; i < expressions.size(); ++i) {
    auto [myResult,
          myErrorCode]{model.GetCalculationResult(expressions[i], true)};

    ASSERT_NEAR(desiredResults[i], myResult, 1e-6);
    ASSERT_EQ(desiredErrorCode, myErrorCode);
  }
}

TEST(ArithmeticTest, SineTest) {
  std::vector<std::string> expressions{
      "sin(1.5)", "sin(123432)", "sin(-1.5)",    "sin(0)",      "sin(-0)",
      "sin(1)",   "sin(-1)",     "sin(-234234)", "sin(sin(6))",
  };

  double desiredResults[]{0.026176948, -0.743144825, -0.026176948, 0,         0,
                          0.017452406, -0.017452406, 0.809016994,  0.00182464};

  ExpressionErrorCode desiredErrorCode{ExpressionErrorCode::kOk};

  s21::CalculatorModel model{};
  for (std::size_t i{0}; i < expressions.size(); ++i) {
    auto [myResult,
          myErrorCode]{model.GetCalculationResult(expressions[i], true)};

    ASSERT_NEAR(desiredResults[i], myResult, 1e-6);
    ASSERT_EQ(desiredErrorCode, myErrorCode);
  }
}

TEST(ArithmeticTest, TangentTest) {
  std::vector<std::string> expressions{
      "tan(1.5)", "tan(123432)", "tan(-1.5)", "tan(0)",
      "tan(-0)",  "tan(1)",      "tan(-1)",   "tan(-234234)",
  };

  double desiredResults[]{
      0.026185922, -1.110612515, -0.026185922, 0,
      0,           0.017455065,  -0.017455065, -1.37638192,
  };

  ExpressionErrorCode desiredErrorCode{ExpressionErrorCode::kOk};

  s21::CalculatorModel model{};
  for (std::size_t i{0}; i < expressions.size(); ++i) {
    auto [myResult,
          myErrorCode]{model.GetCalculationResult(expressions[i], true)};

    ASSERT_NEAR(desiredResults[i], myResult, 1e-6);
    ASSERT_EQ(desiredErrorCode, myErrorCode);
  }
}

TEST(ArithmeticTest, TrigonometryRadiansTest) {
  std::vector<std::string> expressions{
      "sin(1.5)", "sin(123432)", "sin(-1.5)", "cos(0)",
      "cos(-0)",  "tan(1)",      "tan(-1)",   "tan(-234234)",
  };

  double desiredResults[]{
      0.9974949866,  -0.92282839833, -0.9974949866, 1, 1,
      1.55740772465, -1.55740772465, 0.00665909982,
  };

  ExpressionErrorCode desiredErrorCode{ExpressionErrorCode::kOk};

  s21::CalculatorModel model{};
  for (std::size_t i{0}; i < expressions.size(); ++i) {
    auto [myResult,
          myErrorCode]{model.GetCalculationResult(expressions[i], false)};

    ASSERT_NEAR(desiredResults[i], myResult, 1e-6);
    ASSERT_EQ(desiredErrorCode, myErrorCode);
  }
}

TEST(ArithmeticTest, ArcCosineTest) {
  std::vector<std::string> expressions{
      "acos(0.5)",      "acos(0)", "acos(-0)", "acos(0.3)",
      "acos(0.234234)", "acos(1)", "acos(-1)", "acos(-0.234234)",
  };

  double desiredResults[]{
      1.047197551, 1.570796327, 1.570796327, 1.266103673,
      1.334365753, 0,           3.141592653, 1.8072269,
  };

  ExpressionErrorCode desiredErrorCode{ExpressionErrorCode::kOk};

  s21::CalculatorModel model{};
  for (std::size_t i{0}; i < expressions.size(); ++i) {
    auto [myResult,
          myErrorCode]{model.GetCalculationResult(expressions[i], true)};

    ASSERT_NEAR(desiredResults[i], myResult, 1e-6);
    ASSERT_EQ(desiredErrorCode, myErrorCode);
  }
}

TEST(ArithmeticTest, ArcSineTest) {
  std::vector<std::string> expressions{
      "asin(0.5)",      "asin(0)", "asin(-0)", "asin(0.3)",
      "asin(0.234234)", "asin(1)", "asin(-1)", "asin(-0.234234)",
  };

  double desiredResults[]{
      0.523598776,  0, 0, 0.304692654, 0.236430573, 1.570796327, -1.570796327,
      -0.236430573,
  };

  ExpressionErrorCode desiredErrorCode{ExpressionErrorCode::kOk};

  s21::CalculatorModel model{};
  for (std::size_t i{0}; i < expressions.size(); ++i) {
    auto [myResult,
          myErrorCode]{model.GetCalculationResult(expressions[i], true)};

    ASSERT_NEAR(desiredResults[i], myResult, 1e-6);
    ASSERT_EQ(desiredErrorCode, myErrorCode);
  }
}

TEST(ArithmeticTest, ArcTangentTest) {
  std::vector<std::string> expressions{
      "atan(0.5)",      "atan(0)", "atan(-0)", "atan(0.3)",
      "atan(0.234234)", "atan(1)", "atan(-1)", "atan(-0.234234)",
  };

  double desiredResults[]{
      0.463647609,  0, 0, 0.291456794, 0.230085925, 0.785398163, -0.785398163,
      -0.230085925,
  };

  ExpressionErrorCode desiredErrorCode{ExpressionErrorCode::kOk};

  s21::CalculatorModel model{};
  for (std::size_t i{0}; i < expressions.size(); ++i) {
    auto [myResult,
          myErrorCode]{model.GetCalculationResult(expressions[i], true)};

    ASSERT_NEAR(desiredResults[i], myResult, 1e-6);
    ASSERT_EQ(desiredErrorCode, myErrorCode);
  }
}

TEST(ArithmeticTest, SqrtTest) {
  std::vector<std::string> expressions{
      "sqrt(1.5)", "sqrt(123432)", "sqrt(2)",   "sqrt(0)",
      "sqrt(-0)",  "sqrt(1)",      "sqrt(125)", "sqrt(234234)",
  };

  double desiredResults[]{
      1.22474487139, 351.328905728, 1.41421356237, 0, 0, 1,
      11.1803398875, 483.977272194,
  };

  ExpressionErrorCode desiredErrorCode{ExpressionErrorCode::kOk};

  s21::CalculatorModel model{};
  for (std::size_t i{0}; i < expressions.size(); ++i) {
    auto [myResult,
          myErrorCode]{model.GetCalculationResult(expressions[i], true)};

    ASSERT_NEAR(desiredResults[i], myResult, 1e-6);
    ASSERT_EQ(desiredErrorCode, myErrorCode);
  }
}

TEST(ArithmeticTest, LnTest) {
  std::vector<std::string> expressions{
      "ln(1.5)", "ln(123432)", "ln(2)",   "ln(0.1)",
      "ln(0.5)", "ln(1)",      "ln(125)", "ln(234234)",
  };

  double desiredResults[]{
      0.4054651081,   11.7234456761,  0.69314718056,
      -2.30258509299, -0.69314718056, 0,
      4.8283137373,   12.3640758947,
  };

  ExpressionErrorCode desiredErrorCode{ExpressionErrorCode::kOk};

  s21::CalculatorModel model{};
  for (std::size_t i{0}; i < expressions.size(); ++i) {
    auto [myResult,
          myErrorCode]{model.GetCalculationResult(expressions[i], true)};

    ASSERT_NEAR(desiredResults[i], myResult, 1e-6);
    ASSERT_EQ(desiredErrorCode, myErrorCode);
  }
}

TEST(ArithmeticTest, LogTest) {
  std::vector<std::string> expressions{
      "log(1.5)", "log(123432)", "log(2)",   "log(0.1)",
      "log(0.5)", "log(1)",      "log(125)", "log(234234)",
  };

  double desiredResults[]{
      0.17609125905, 5.09142776603, 0.30102999566, -1, -0.30102999566, 0,
      2.09691001301, 5.36964993489,
  };

  ExpressionErrorCode desiredErrorCode{ExpressionErrorCode::kOk};

  s21::CalculatorModel model{};
  for (std::size_t i{0}; i < expressions.size(); ++i) {
    auto [myResult,
          myErrorCode]{model.GetCalculationResult(expressions[i], true)};

    ASSERT_NEAR(desiredResults[i], myResult, 1e-6);
    ASSERT_EQ(desiredErrorCode, myErrorCode);
  }
}

TEST(ArithmeticTest, FunctionEdgeCaseTest) {
  std::vector<std::string> expressions{
      "acos(5)", "asin(5)", "log(-5)", "sqrt(-5)", "ln(-5)",
  };

  ExpressionErrorCode desiredErrorCode{ExpressionErrorCode::kOk};

  s21::CalculatorModel model{};
  for (std::size_t i{0}; i < expressions.size(); ++i) {
    auto [myResult,
          myErrorCode]{model.GetCalculationResult(expressions[i], true)};

    ASSERT_TRUE(std::isnan(myResult));
    ASSERT_EQ(desiredErrorCode, myErrorCode);
  }
}

TEST(ArithmeticTest, UnaryOperatorsTest) {
  std::vector<std::string> expressions{
      "-10", "-(-10)", "+10", "+10-(-10+(+10))", "-(-(-(-10)))+(+10)",
  };

  double desiredResults[] = {
      -10, 10, 10, 10, 20,
  };

  ExpressionErrorCode desiredErrorCode{ExpressionErrorCode::kOk};

  s21::CalculatorModel model{};
  for (std::size_t i{0}; i < expressions.size(); ++i) {
    auto [myResult,
          myErrorCode]{model.GetCalculationResult(expressions[i], true)};

    ASSERT_NEAR(desiredResults[i], myResult, 1e-6);
    ASSERT_EQ(desiredErrorCode, myErrorCode);
  }
}

TEST(ArithmeticTest, BinaryOperatorsTest) {
  std::vector<std::string> expressions{
      "-10+5.5", "8*88",   "4%5",         "5-2343*4+15",
      "5^2^2",   "4/2*22", "11111-11111", "4444%5",
  };
  // TODO: add tests for power to power to power and scientific notation

  double desiredResults[] = {
      -4.5, 704, 4, -9352, 625, 44, 0, 4,
  };

  ExpressionErrorCode desiredErrorCode{ExpressionErrorCode::kOk};

  s21::CalculatorModel model{};
  for (std::size_t i{0}; i < expressions.size(); ++i) {
    auto [myResult,
          myErrorCode]{model.GetCalculationResult(expressions[i], true)};

    ASSERT_NEAR(desiredResults[i], myResult, 1e-6);
    ASSERT_EQ(desiredErrorCode, myErrorCode);
  }
}

TEST(ArithmeticTest, IncorrectExpressionsTest) {
  std::vector<std::string> expressions{
      "1/0",
      "1%0",
      "()",
      "5 +",
      "5+(5",
      "(5+5)sin(8)",
      "abc",
      "",
      ")",
      "$",
      "5**5",
      "555555555555555555555555555555555555555555555555555555555555555555555555"
      "555555555555555555555555555555555555555555555555555555555555555555555555"
      "555555555555555555555555555555555555555555555555555555555555555555555555"
      "55555555555555555555555555555555555555555555",
  };

  ExpressionErrorCode desiredErrorCode{ExpressionErrorCode::kInvalidExpression};

  s21::CalculatorModel model{};
  for (std::size_t i{0}; i < expressions.size(); ++i) {
    auto [myResult,
          myErrorCode]{model.GetCalculationResult(expressions[i], true)};

    ASSERT_EQ(desiredErrorCode, myErrorCode);
  }
}

TEST(CreditCalculationTest, AnnuityTest) {
  s21::CalculatorModel model{};
  CreditInput input{1000.0, 12, 0.1};
  auto result{
      model.GetCreditCalculationResult(MonthlyPaymentType::kAnnuity, input)};
  ASSERT_NEAR(result.montly_payment, 87.92, 1e-2);
  ASSERT_NEAR(result.overpayment_on_credit, 55.04, 1e-2);
  ASSERT_NEAR(result.total_payment, 1055.04, 1e-2);
}

TEST(CreditCalculationTest, DifferentiatedTest) {
  s21::CalculatorModel model{};
  CreditInput input{1000.0, 12, 0.1};
  auto result{model.GetCreditCalculationResult(
      MonthlyPaymentType::kDifferentiated, input)};
  ASSERT_NEAR(result.first_payment, 91.67, 1e-2);
  ASSERT_NEAR(result.last_payment, 84.03, 1e-2);
  ASSERT_NEAR(result.overpayment_on_credit, 54.17, 1e-2);
  ASSERT_NEAR(result.total_payment, 1054.17, 1e-2);
}
}  // namespace s21
