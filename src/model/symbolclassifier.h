#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_SYMBOLCLASSIFIER_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_SYMBOLCLASSIFIER_H_

namespace s21 {
class SymbolClassifier {
 public:
  static bool IsWhitespace(char symbol);
  static bool IsBracket(char symbol);
  static bool IsOpeningBracket(char symbol);
  static bool IsClosingBracket(char symbol);
  static bool IsOperator(char symbol);
  static bool IsUnaryOperator(char symbol);
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_MODEL_SYMBOLCLASSIFIER_H_
