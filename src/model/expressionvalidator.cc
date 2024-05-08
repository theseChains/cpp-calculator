#include "expressionvalidator.h"

#include "modelconstants.h"
#include "symbolclassifier.h"

namespace s21 {
ExpressionErrorCode ExpressionValidator::ExpressionIsValid(
    const std::string& expression) {
  if (expression.length() > constants::kMaxExpressionLength)
    return ExpressionErrorCode::kInvalidExpression;

  ExpressionErrorCode error_code{ExpressionErrorCode::kOk};

  int bracket_balance{0};
  char previous_symbol{};
  for (const auto& symbol : expression) {
    if (SymbolClassifier::IsOperator(symbol) &&
        SymbolClassifier::IsOperator(previous_symbol) && symbol != '-') {
      error_code = ExpressionErrorCode::kInvalidExpression;
    }

    if (SymbolClassifier::IsClosingBracket(symbol) &&
        SymbolClassifier::IsOpeningBracket(previous_symbol)) {
      error_code = ExpressionErrorCode::kInvalidExpression;
    }

    if (SymbolClassifier::IsOpeningBracket(symbol)) {
      ++bracket_balance;
    } else if (SymbolClassifier::IsClosingBracket(symbol)) {
      --bracket_balance;
    }

    if (bracket_balance < 0) {
      error_code = ExpressionErrorCode::kInvalidExpression;
    }

    if (error_code != ExpressionErrorCode::kOk) break;

    previous_symbol = symbol;
  }

  if (bracket_balance != 0) {
    error_code = ExpressionErrorCode::kInvalidExpression;
  }

  return error_code;
}
}  // namespace s21
