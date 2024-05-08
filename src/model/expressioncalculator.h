#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_EXPRESSIONCALCULATOR_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_EXPRESSIONCALCULATOR_H_

#include <stack>
#include <string>

#include "../common/expressionerrorcode.h"
#include "token.h"

namespace s21 {
class ExpressionCalculator {
 public:
  static std::pair<ExpressionErrorCode, double> CalculateResult(
      const std::stack<Token>& tokens, bool convert_to_degrees);

 private:
  static double EvaluateFunction(FunctionType type, double current_number,
                                 bool convert_to_degrees);
  static bool IsTrigonometricFunction(FunctionType type);
  static double ToDegrees(double number);
  static Token EvaluateUnaryOperator(const Token& current_token, double number);
  static std::pair<ExpressionErrorCode, Token> EvaluateBinaryOperator(
      const Token& current_token, double right_number, double left_number);
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_MODEL_EXPRESSIONCALCULATOR_H_
