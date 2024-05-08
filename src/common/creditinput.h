#ifndef CPP3_SMARTCALC_V2_0_1_COMMON_CREDITINPUT_H_
#define CPP3_SMARTCALC_V2_0_1_COMMON_CREDITINPUT_H_

namespace s21 {
struct CreditInput {
  double credit_amount{};
  int number_of_months{};
  double interest_rate{};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_COMMON_CREDITINPUT_H_
