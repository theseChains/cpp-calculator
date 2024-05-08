#include "creditcalculator.h"

#include <cmath>

namespace s21 {
CreditCalculationResult CreditCalculator::CalculateCredit(
    MonthlyPaymentType type, const CreditInput& input) {
  CreditCalculationResult result{};

  if (type == MonthlyPaymentType::kAnnuity) {
    result = CalculateAnnuityPaymentCredit(input);
  } else {
    result = CalculateDifferentialPaymentCredit(input);
  }

  return result;
}

CreditCalculationResult CreditCalculator::CalculateAnnuityPaymentCredit(
    const CreditInput& input) {
  CreditCalculationResult result{};
  double monthly_payment{
      input.credit_amount * input.interest_rate / 12 *
      std::pow(1 + input.interest_rate / 12, input.number_of_months) /
      (std::pow(1 + input.interest_rate / 12, input.number_of_months) - 1)};
  monthly_payment = std::round(monthly_payment * 100) / 100;

  result.montly_payment = monthly_payment;
  result.total_payment = monthly_payment * input.number_of_months;
  result.overpayment_on_credit = result.total_payment - input.credit_amount;

  return result;
}

CreditCalculationResult CreditCalculator::CalculateDifferentialPaymentCredit(
    const CreditInput& input) {
  CreditCalculationResult result{};
  double credit_payment_for_each_month{input.credit_amount /
                                       input.number_of_months};
  double total_payment{0.0};
  for (int i{0}; i < input.number_of_months; ++i) {
    double month_overpayment{
        (input.credit_amount - credit_payment_for_each_month * i) *
        input.interest_rate / 12};
    double total_month_payment =
        month_overpayment + credit_payment_for_each_month;
    if (i == 0) {
      result.first_payment = total_month_payment;
    } else if (i == input.number_of_months - 1) {
      result.last_payment = total_month_payment;
    }

    total_payment += total_month_payment;
  }

  result.total_payment = total_payment;
  result.overpayment_on_credit = total_payment - input.credit_amount;

  return result;
}
}  // namespace s21
