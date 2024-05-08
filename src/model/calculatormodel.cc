#include "calculatormodel.h"

namespace s21 {
CalculationResult CalculatorModel::GetCalculationResult(
    const std::string& expression, bool convert_to_degrees) {
  return calculator_core_.CalculateExpression(expression, convert_to_degrees);
}

void CalculatorModel::SetXValue(double x_value) {
  calculator_core_.SetXValue(x_value);
}

double CalculatorModel::GetXValue() const {
  return calculator_core_.GetXValue();
}

CreditCalculationResult CalculatorModel::GetCreditCalculationResult(
    MonthlyPaymentType type, const CreditInput& input) {
  return credit_calculator_.CalculateCredit(type, input);
}
}  // namespace s21
