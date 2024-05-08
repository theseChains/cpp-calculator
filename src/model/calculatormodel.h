#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_CALCULATORMODEL_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_CALCULATORMODEL_H_

#include "../common/creditinput.h"
#include "calculationresult.h"
#include "calculatorcore.h"
#include "creditcalculator.h"

namespace s21 {
class CalculatorModel {
 public:
  CalculatorModel() = default;

  CalculationResult GetCalculationResult(const std::string& expression,
                                         bool convert_to_degrees);

  void SetXValue(double x_value);
  double GetXValue() const;

  CreditCalculationResult GetCreditCalculationResult(MonthlyPaymentType type,
                                                     const CreditInput& input);

 private:
  CalculatorCore calculator_core_{};
  CreditCalculator credit_calculator_{};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_MODEL_CALCULATORMODEL_H_
