#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_CALCULATIONRESULT_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_CALCULATIONRESULT_H_

#include "../common/expressionerrorcode.h"

namespace s21 {
struct CalculationResult {
  double value{};
  ExpressionErrorCode error_code{};
};

struct CreditCalculationResult {
  double montly_payment{};
  double first_payment{};
  double last_payment{};
  double overpayment_on_credit{};
  double total_payment{};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_MODEL_CALCULATIONRESULT_H_
