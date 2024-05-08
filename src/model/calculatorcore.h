#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_CALCULATORCORE_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_CALCULATORCORE_H_

#include <string>

#include "calculationresult.h"
#include "expressioncalculator.h"
#include "tokenizer.h"

namespace s21 {
class CalculatorCore {
 public:
  CalculationResult CalculateExpression(const std::string& expression,
                                        bool convert_to_degrees);

  void SetXValue(double x_value);
  double GetXValue() const;

 private:
  std::string ConvertXToValue(const std::string& expression);

 private:
  double x_value_{};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_MODEL_CALCULATORCORE_H_
