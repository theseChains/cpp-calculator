#ifndef CPP3_SMARTCALC_V2_0_1_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_1_CONTROLLER_CONTROLLER_H_

#include <string>

#include "../common/monthlypaymenttype.h"
#include "../model/calculationresult.h"
#include "../model/calculatormodel.h"

namespace s21 {
class CalculatorController {
 public:
  CalculatorController(CalculatorModel& model);

  CalculationResult EvaluateExpression(const std::string& expression,
                                       bool convert_to_degrees);

  void SetXValue(double x_value);
  double GetXValue() const;

  CreditCalculationResult CalculateCreditDetails(MonthlyPaymentType type,
                                                 const CreditInput& input);

 private:
  CalculatorModel& model_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_CONTROLLER_CONTROLLER_H_
