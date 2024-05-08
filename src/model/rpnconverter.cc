#include "rpnconverter.h"

#include "modelconstants.h"

namespace s21 {
std::pair<ExpressionErrorCode, std::stack<Token>>
RPNConverter::ConvertToReversePolishNotation(const std::stack<Token>& tokens) {
  ExpressionErrorCode error_code{ExpressionErrorCode::kOk};
  std::stack<Token> converted{ReverseTokenStack(tokens)};
  std::stack<Token> operators{};

  auto [error, converted_tokens,
        operators_stack]{PerformShuntingYardAlgorithm(converted)};
  error_code = error;
  converted = converted_tokens;
  operators = operators_stack;

  while (!operators.empty() && error_code == ExpressionErrorCode::kOk) {
    if (TokenClassifier::TokenIsBracket(operators.top())) {
      error_code = ExpressionErrorCode::kInvalidExpression;
    }

    if (error_code == ExpressionErrorCode::kOk) {
      converted.push(operators.top());
      operators.pop();
    }
  }

  converted = ReverseTokenStack(converted);

  return {error_code, converted};
}

RPNConverter::ShuntingYardResult RPNConverter::PerformShuntingYardAlgorithm(
    const std::stack<Token>& tokens) {
  ShuntingYardResult result{ExpressionErrorCode::kOk, {}, {}};
  std::stack<Token> current_tokens{tokens};
  while (!current_tokens.empty() &&
         result.error_code == ExpressionErrorCode::kOk) {
    Token current_token{current_tokens.top()};
    if (TokenClassifier::TokenIsNumber(current_token)) {
      result.converted_tokens.push(current_token);
    } else if (TokenClassifier::TokenIsOpeningBracket(current_token) ||
               TokenClassifier::TokenIsFunction(current_token)) {
      result.operators.push(current_token);
    } else if (TokenClassifier::TokenIsOperator(current_token)) {
      while (!result.operators.empty() &&
             GetOperatorPrecedence(current_token) <=
                 GetOperatorPrecedence(result.operators.top())) {
        result.converted_tokens.push(result.operators.top());
        result.operators.pop();
      }
      result.operators.push(current_token);
    } else if (TokenClassifier::TokenIsClosingBracket(current_token)) {
      while (!TokenClassifier::TokenIsOpeningBracket(result.operators.top()) &&
             result.error_code == ExpressionErrorCode::kOk) {
        if (result.operators.empty()) {
          result.error_code = ExpressionErrorCode::kInvalidExpression;
        } else {
          result.converted_tokens.push(result.operators.top());
          result.operators.pop();
        }
      }

      if (result.error_code == ExpressionErrorCode::kOk) {
        result.operators.pop();
        if (!result.operators.empty() &&
            TokenClassifier::TokenIsFunction(current_token)) {
          result.converted_tokens.push(result.operators.top());
          result.operators.pop();
        }
      }
    }

    current_tokens.pop();
  }

  return result;
}

int RPNConverter::GetOperatorPrecedence(const Token& token) {
  int precedence{0};
  if (TokenClassifier::TokenIsFunction(token)) {
    precedence = 5;
  } else if (TokenClassifier::TokenIsOperator(token)) {
    char current_operator{std::get<char>(token.data)};
    if (current_operator == constants::kUnaryMinus ||
        current_operator == constants::kUnaryPlus) {
      precedence = 4;
    } else if (current_operator == '^') {
      precedence = 3;
    } else if (current_operator == '*' || current_operator == '/' ||
               current_operator == '%') {
      precedence = 2;
    } else if (current_operator == '+' || current_operator == '-') {
      precedence = 1;
    }
  }

  return precedence;
}

std::stack<Token> RPNConverter::ReverseTokenStack(
    const std::stack<Token>& tokens) {
  std::stack<Token> reversed{};
  std::stack<Token> original_tokens{tokens};

  while (!original_tokens.empty()) {
    reversed.push(original_tokens.top());
    original_tokens.pop();
  }

  return reversed;
}
}  // namespace s21
