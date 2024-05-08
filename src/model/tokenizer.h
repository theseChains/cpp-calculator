#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_TOKENIZER_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_TOKENIZER_H_

#include <stack>
#include <string>
#include <tuple>

#include "../common/expressionerrorcode.h"
#include "token.h"

namespace s21 {
class Tokenizer {
 public:
  static std::pair<ExpressionErrorCode, std::stack<Token>> TokenizeExpression(
      const std::string& expression);

 private:
  static char CheckForUnarySymbol(char current_symbol, char previous_symbol);
  static ExpressionErrorCode HandleNumber(std::string::const_iterator& iter,
                                          std::stack<Token>& tokens);
  static ExpressionErrorCode HandleFunction(std::string::const_iterator& iter,
                                            std::stack<Token>& tokens,
                                            char previous_symbol);
  static std::pair<ExpressionErrorCode, double> ExtractNumber(
      std::string::const_iterator& iterator);
  static std::pair<ExpressionErrorCode, FunctionType> ExtractFunction(
      std::string::const_iterator& iterator);
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_MODEL_TOKENIZER_H_
