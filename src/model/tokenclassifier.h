#ifndef CPP3_SMARTCALC_V_2_0_1_MODEL_TOKENCLASSIFIER_H_
#define CPP3_SMARTCALC_V_2_0_1_MODEL_TOKENCLASSIFIER_H_

#include "token.h"

namespace s21 {
class TokenClassifier {
 public:
  static bool TokenIsNumber(const Token& token);
  static bool TokenIsBracket(const Token& token);
  static bool TokenIsOpeningBracket(const Token& token);
  static bool TokenIsClosingBracket(const Token& token);
  static bool TokenIsFunction(const Token& token);
  static bool TokenIsOperator(const Token& token);
  static bool TokenIsUnaryOperator(const Token& token);
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V_2_0_1_MODEL_TOKENCLASSIFIER_H_
