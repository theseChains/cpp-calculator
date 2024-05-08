#ifndef CPP3_SMARTCALC_V_2_0_1_MODEL_RPNCONVERTER_H_
#define CPP3_SMARTCALC_V_2_0_1_MODEL_RPNCONVERTER_H_

#include <stack>

#include "../common/expressionerrorcode.h"
#include "token.h"
#include "tokenclassifier.h"

namespace s21 {
class RPNConverter {
 public:
  static std::pair<ExpressionErrorCode, std::stack<Token>>
  ConvertToReversePolishNotation(const std::stack<Token>& tokens);

 private:
  struct ShuntingYardResult {
    ExpressionErrorCode error_code;
    std::stack<Token> converted_tokens;
    std::stack<Token> operators;
  };

 private:
  static ShuntingYardResult PerformShuntingYardAlgorithm(
      const std::stack<Token>& tokens);

  static int GetOperatorPrecedence(const Token& token);
  static std::stack<Token> ReverseTokenStack(const std::stack<Token>& tokens);
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V_2_0_1_MODEL_RPNCONVERTER_H_
