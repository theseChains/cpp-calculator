#include "tokenizer.h"

#include <stdexcept>

#include "modelconstants.h"
#include "symbolclassifier.h"
#include "token.h"

namespace s21 {
std::pair<ExpressionErrorCode, std::stack<Token>> Tokenizer::TokenizeExpression(
    const std::string& expression) {
  ExpressionErrorCode error_code{ExpressionErrorCode::kOk};
  int number_of_binary_operators{0};
  int number_of_operands{0};
  std::stack<Token> tokens{};
  char previous_symbol{};
  for (auto iter{expression.begin()};
       iter != expression.end() && error_code == ExpressionErrorCode::kOk;
       ++iter) {
    char symbol{*iter};
    if (SymbolClassifier::IsWhitespace(symbol)) {
      continue;
    }
    if (SymbolClassifier::IsOpeningBracket(symbol)) {
      tokens.push({BracketType::kOpening});
    } else if (SymbolClassifier::IsClosingBracket(symbol)) {
      tokens.push({BracketType::kClosing});
    } else if (SymbolClassifier::IsOperator(symbol)) {
      symbol = CheckForUnarySymbol(symbol, previous_symbol);
      tokens.push({symbol});
      if (!SymbolClassifier::IsUnaryOperator(symbol)) {
        ++number_of_binary_operators;
      }
    } else if (std::isdigit(symbol)) {
      error_code = HandleNumber(iter, tokens);
      ++number_of_operands;
    } else if (std::isalpha(symbol)) {
      error_code = HandleFunction(iter, tokens, previous_symbol);
    } else {
      error_code = ExpressionErrorCode::kInvalidExpression;
    }

    previous_symbol = symbol;
  }

  if (number_of_operands <= number_of_binary_operators) {
    error_code = ExpressionErrorCode::kInvalidExpression;
  }

  return {error_code, tokens};
}

char Tokenizer::CheckForUnarySymbol(char current_symbol, char previous_symbol) {
  char resulting_symbol{current_symbol};
  if (current_symbol == '-' && (previous_symbol == '\0' ||
                                SymbolClassifier::IsOperator(previous_symbol) ||
                                previous_symbol == '(')) {
    resulting_symbol = constants::kUnaryMinus;
  } else if (current_symbol == '+' &&
             (previous_symbol == '\0' ||
              SymbolClassifier::IsOperator(previous_symbol) ||
              previous_symbol == '(')) {
    resulting_symbol = constants::kUnaryPlus;
  }

  return resulting_symbol;
}

ExpressionErrorCode Tokenizer::HandleNumber(std::string::const_iterator& iter,
                                            std::stack<Token>& tokens) {
  auto [error, number]{ExtractNumber(iter)};
  if (error == ExpressionErrorCode::kOk) {
    tokens.push({number});
  }

  return error;
}

ExpressionErrorCode Tokenizer::HandleFunction(std::string::const_iterator& iter,
                                              std::stack<Token>& tokens,
                                              char previous_symbol) {
  ExpressionErrorCode error_code{ExpressionErrorCode::kOk};
  if (!(SymbolClassifier::IsOperator(previous_symbol) ||
        previous_symbol == '(' || previous_symbol == '\0') ||
      previous_symbol == ')') {
    error_code = ExpressionErrorCode::kInvalidExpression;
  } else {
    auto [error, function_type]{ExtractFunction(iter)};
    if (error == ExpressionErrorCode::kOk) {
      tokens.push({function_type});
    }
    error_code = error;
  }

  return error_code;
}

std::pair<ExpressionErrorCode, double> Tokenizer::ExtractNumber(
    std::string::const_iterator& iterator) {
  std::setlocale(LC_ALL, "C");
  ExpressionErrorCode error_code{ExpressionErrorCode::kOk};
  std::size_t number_length{};
  double number{};
  try {
    number = std::stod(&(*iterator), &number_length);
  } catch (const std::exception& exception) {
    number = 0;
    error_code = ExpressionErrorCode::kInvalidExpression;
  }
  iterator += number_length - 1;

  return {error_code, number};
}

std::pair<ExpressionErrorCode, FunctionType> Tokenizer::ExtractFunction(
    std::string::const_iterator& iterator) {
  ExpressionErrorCode error_code{ExpressionErrorCode::kOk};
  std::string function_string{};

  while (std::isalpha(*iterator)) {
    function_string.push_back(*iterator++);
  }
  --iterator;

  FunctionType function_type{FunctionType::kNone};
  auto found{constants::kFunctionStringMap.find(function_string)};
  if (found != constants::kFunctionStringMap.end()) {
    function_type = found->second;
  }

  return {error_code, function_type};
}
}  // namespace s21
