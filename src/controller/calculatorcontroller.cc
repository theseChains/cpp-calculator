#include "calculatorcontroller.h"

namespace s21 {
CalculatorController::CalculatorController(CalculatorModel& model)
    : model_{model} {}

CalculationResult CalculatorController::EvaluateExpression(
    const std::string& expression, bool convert_to_degrees) {
  return model_.GetCalculationResult(expression, convert_to_degrees);
}

void CalculatorController::SetXValue(double x_value) {
  model_.SetXValue(x_value);
}

double CalculatorController::GetXValue() const { return model_.GetXValue(); }

CreditCalculationResult CalculatorController::CalculateCreditDetails(
    MonthlyPaymentType type, const CreditInput& input) {
  return model_.GetCreditCalculationResult(type, input);
}
}  // namespace s21
