#ifndef CPP3_SMARTCALC_V2_0_1_VIEW_CREDITRCALCULATORWINDOW_H_
#define CPP3_SMARTCALC_V2_0_1_VIEW_CREDITRCALCULATORWINDOW_H_

#include <QDialog>
#include <QLineEdit>
#include <array>
#include <optional>

#include "../common/creditinput.h"
#include "../common/monthlypaymenttype.h"
#include "../controller/calculatorcontroller.h"

namespace Ui {
class CreditCalculatorWindow;
}

namespace s21 {
class CreditCalculatorWindow : public QDialog {
  Q_OBJECT

 public:
  explicit CreditCalculatorWindow(CalculatorController& controller,
                                  QWidget* parent = nullptr);
  ~CreditCalculatorWindow();

 private slots:
  void CalculateButtonSlot();
  void MonthlyPaymentTypeSlot();

 private:
  Ui::CreditCalculatorWindow* ui_{};
  CalculatorController& controller_;
  MonthlyPaymentType monthly_payment_type_{};

 private:
  void SetLineEditStyleToErroneous(QLineEdit* line_edit);
  void SetLineEditStyleToDefault(QLineEdit* line_edit);

  std::array<QString, 3> GetCreditOutputStrings();
  std::optional<CreditInput> GetCreditInput();
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_VIEW_CREDITRCALCULATORWINDOW_H_
