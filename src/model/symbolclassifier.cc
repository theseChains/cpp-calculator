#include "symbolclassifier.h"

#include "modelconstants.h"

namespace s21 {
bool SymbolClassifier::IsWhitespace(char symbol) {
  return (symbol == ' ' || symbol == '\t');
}

bool SymbolClassifier::IsBracket(char symbol) {
  return (symbol == ')' || symbol == '(');
}

bool SymbolClassifier::IsOpeningBracket(char symbol) { return (symbol == '('); }

bool SymbolClassifier::IsClosingBracket(char symbol) { return (symbol == ')'); }

bool SymbolClassifier::IsOperator(char symbol) {
  return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' ||
          symbol == '^' || symbol == '%');
}

bool SymbolClassifier::IsUnaryOperator(char symbol) {
  return (symbol == constants::kUnaryMinus || symbol == constants::kUnaryPlus);
}
}  // namespace s21
