#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_CREDITCALCULATOR_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_CREDITCALCULATOR_H_

#include "../common/creditinput.h"
#include "../common/monthlypaymenttype.h"
#include "calculationresult.h"

namespace s21 {
class CreditCalculator {
 public:
  static CreditCalculationResult CalculateCredit(MonthlyPaymentType type,
                                                 const CreditInput& input);

 private:
  static CreditCalculationResult CalculateAnnuityPaymentCredit(
      const CreditInput& input);

  static CreditCalculationResult CalculateDifferentialPaymentCredit(
      const CreditInput& input);
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_MODEL_CREDITCALCULATOR_H_
