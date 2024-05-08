#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_EXPRESSIONVALIDATOR_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_EXPRESSIONVALIDATOR_H_

#include <string>

#include "calculationresult.h"

namespace s21 {
class ExpressionValidator {
 public:
  static ExpressionErrorCode ExpressionIsValid(const std::string& expresion);
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_MODEL_EXPRESSIONVALIDATOR_H_
