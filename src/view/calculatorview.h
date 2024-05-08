#ifndef CPP3_SMARTCALC_V2_0_1_VIEW_CALCULATORVIEW_H_
#define CPP3_SMARTCALC_V2_0_1_VIEW_CALCULATORVIEW_H_

#include <QLabel>
#include <QMainWindow>

#include "../controller/calculatorcontroller.h"
#include "creditcalculatorwindow.h"
#include "labelmanager.h"
#include "labeltype.h"
#include "plotmanager.h"
#include "trigonometrycalculationtype.h"

namespace Ui {
class CalculatorView;
}

namespace s21 {
class CalculatorView : public QMainWindow {
  Q_OBJECT

 public:
  CalculatorView(CalculatorController& controller, QWidget* parent = nullptr);
  ~CalculatorView();

 private slots:
  void NumberSlot();
  void DotSlot();
  void SignSlot();
  void OperationsSlot();
  void ClearSlot();
  void ExponentSlot();
  void EqualsSlot();
  void BracketSlot();
  void FunctionSlot();
  void XSlot();
  void DrawPlotSlot();
  void ClearPlotSlot();
  void TrigonometryCalculationSlot();
  void ShowCreditCalculatorSlot();

 private:
  void mousePressEvent(QMouseEvent* event) override;
  void UpdateDomainLabel(double label_number);
  void UpdateCodomainLabel(double label_number);
  double HandleFunctionSpaceNumberOverflow(QLabel* label, double label_number);

  void ConnectButtonsToNumberSlot();
  void ConnectButtonsToOperationsSlot();
  void ConnectButtonsToFunctionSlot();
  void ConnectButtonsToSlots();
  void SetUpPlotSettings();
  void SetUpDefaultLabelTexts();

 private:
  Ui::CalculatorView* ui_{};
  CalculatorController& controller_;
  LabelManager label_manager_;
  PlotManager plot_manager_;
  TrigonometryCalculationType calculation_type_{};
  CreditCalculatorWindow credit_calculator_;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_VIEW_CALCULATORVIEW_H_
