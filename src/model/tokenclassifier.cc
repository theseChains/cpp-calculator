#include "tokenclassifier.h"

#include "modelconstants.h"

namespace s21 {
bool TokenClassifier::TokenIsNumber(const Token& token) {
  return (std::holds_alternative<double>(token.data));
}

bool TokenClassifier::TokenIsBracket(const Token& token) {
  return (std::holds_alternative<BracketType>(token.data));
}

bool TokenClassifier::TokenIsOpeningBracket(const Token& token) {
  return (std::holds_alternative<BracketType>(token.data) &&
          std::get<BracketType>(token.data) == BracketType::kOpening);
}

bool TokenClassifier::TokenIsClosingBracket(const Token& token) {
  return (std::holds_alternative<BracketType>(token.data) &&
          std::get<BracketType>(token.data) == BracketType::kClosing);
}

bool TokenClassifier::TokenIsFunction(const Token& token) {
  return (std::holds_alternative<FunctionType>(token.data));
}

bool TokenClassifier::TokenIsOperator(const Token& token) {
  return (std::holds_alternative<char>(token.data));
}

bool TokenClassifier::TokenIsUnaryOperator(const Token& token) {
  bool is_unary_operator{false};
  if (TokenIsOperator(token)) {
    char symbol{std::get<char>(token.data)};
    is_unary_operator =
        (symbol == constants::kUnaryMinus || symbol == constants::kUnaryPlus);
  }

  return is_unary_operator;
}
}  // namespace s21
