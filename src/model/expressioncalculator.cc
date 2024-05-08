#include "expressioncalculator.h"

#include "modelconstants.h"
#include "tokenclassifier.h"

namespace s21 {
std::pair<ExpressionErrorCode, double> ExpressionCalculator::CalculateResult(
    const std::stack<Token>& tokens, bool convert_to_degrees) {
  ExpressionErrorCode error_code{ExpressionErrorCode::kOk};
  double result{};

  std::stack<Token> operands{};
  std::stack<Token> current_tokens{tokens};
  while (!current_tokens.empty() && error_code == ExpressionErrorCode::kOk) {
    Token current_token{current_tokens.top()};
    if (TokenClassifier::TokenIsNumber(current_token)) {
      operands.push(current_token);
    } else if (TokenClassifier::TokenIsFunction(current_token)) {
      double current_number{std::get<double>(operands.top().data)};
      operands.pop();
      Token new_token{
          EvaluateFunction(std::get<FunctionType>(current_token.data),
                           current_number, convert_to_degrees)};
      operands.push(new_token);
    } else if (TokenClassifier::TokenIsUnaryOperator(current_token)) {
      Token new_token{EvaluateUnaryOperator(
          current_token, std::get<double>(operands.top().data))};
      operands.pop();
      operands.push(new_token);
    } else if (TokenClassifier::TokenIsOperator(current_token)) {
      double right_number{std::get<double>(operands.top().data)};
      operands.pop();
      double left_number{std::get<double>(operands.top().data)};
      operands.pop();
      auto [error, new_token]{
          EvaluateBinaryOperator(current_token, right_number, left_number)};
      error_code = error;
      if (error_code == ExpressionErrorCode::kOk) {
        operands.push(new_token);
      }
    }
    current_tokens.pop();
  }

  if (error_code == ExpressionErrorCode::kOk) {
    result = std::get<double>(operands.top().data);
  }

  return {error_code, result};
}

double ExpressionCalculator::EvaluateFunction(FunctionType type,
                                              double current_number,
                                              bool convert_to_degrees) {
  if (IsTrigonometricFunction(type) && convert_to_degrees) {
    current_number = ToDegrees(current_number);
  }

  return constants::kFunctionMap.find(type)->second(current_number);
}

bool ExpressionCalculator::IsTrigonometricFunction(FunctionType type) {
  return (type == FunctionType::kSine || type == FunctionType::kCosine ||
          type == FunctionType::kTangent);
}

double ExpressionCalculator::ToDegrees(double number) {
  return (number * constants::kPi / 180.0);
}

Token ExpressionCalculator::EvaluateUnaryOperator(const Token& current_token,
                                                  double number) {
  Token new_token{};
  if (std::get<char>(current_token.data) == constants::kUnaryMinus) {
    new_token.data = -number;
  } else {
    new_token.data = +number;
  }

  return new_token;
}

std::pair<ExpressionErrorCode, Token>
ExpressionCalculator::EvaluateBinaryOperator(const Token& current_token,
                                             double right_number,
                                             double left_number) {
  ExpressionErrorCode error_code{ExpressionErrorCode::kOk};
  Token new_token{};

  if (std::get<char>(current_token.data) == '+') {
    new_token = {left_number + right_number};
  } else if (std::get<char>(current_token.data) == '-') {
    new_token = {left_number - right_number};
  } else if (std::get<char>(current_token.data) == '*') {
    new_token = {left_number * right_number};
  } else if (std::get<char>(current_token.data) == '/') {
    if (right_number == 0.0) {
      error_code = ExpressionErrorCode::kInvalidExpression;
    } else {
      new_token = {left_number / right_number};
    }
  } else if (std::get<char>(current_token.data) == '%') {
    if (right_number == 0.0) {
      error_code = ExpressionErrorCode::kInvalidExpression;
    } else {
      new_token = {std::fmod(left_number, right_number)};
    }
  } else if (std::get<char>(current_token.data) == '^') {
    new_token = {std::pow(left_number, right_number)};
  }

  return {error_code, new_token};
}
}  // namespace s21
