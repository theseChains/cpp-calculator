#include "calculatorcore.h"

#include "expressioncalculator.h"
#include "expressionvalidator.h"
#include "modelconstants.h"
#include "rpnconverter.h"
#include "tokenizer.h"

namespace s21 {
CalculationResult CalculatorCore::CalculateExpression(
    const std::string& expression, bool convert_to_degrees) {
  if (expression.length() > constants::kMaxExpressionLength)
    return {0.0, ExpressionErrorCode::kInvalidExpression};

  CalculationResult result{};
  std::string converted{ConvertXToValue(expression)};

  result.error_code = ExpressionValidator::ExpressionIsValid(converted);
  std::stack<Token> tokens{};

  if (result.error_code == ExpressionErrorCode::kOk) {
    std::tie(result.error_code, tokens) =
        Tokenizer::TokenizeExpression(converted);
  }

  if (result.error_code == ExpressionErrorCode::kOk) {
    std::tie(result.error_code, tokens) =
        RPNConverter::ConvertToReversePolishNotation(tokens);
  }

  if (result.error_code == ExpressionErrorCode::kOk) {
    std::tie(result.error_code, result.value) =
        ExpressionCalculator::CalculateResult(tokens, convert_to_degrees);
  }

  return result;
}

void CalculatorCore::SetXValue(double x_value) { x_value_ = x_value; }

double CalculatorCore::GetXValue() const { return x_value_; }

std::string CalculatorCore::ConvertXToValue(const std::string& expression) {
  if (expression.find('x') == std::string::npos) return expression;

  std::setlocale(LC_ALL, "C");
  std::string converted_expression{expression};
  std::string x_value_string{std::to_string(x_value_)};
  for (std::size_t i{0}; i < converted_expression.length(); ++i) {
    if (converted_expression[i] == 'x') {
      converted_expression.replace(i, 1, x_value_string);
      i += x_value_string.length();
    }
  }

  return converted_expression;
}
}  // namespace s21
