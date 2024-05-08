#ifndef CPP3_SMARTCALC_V2_0_1_VIEW_PLOTMANAGER_H_
#define CPP3_SMARTCALC_V2_0_1_VIEW_PLOTMANAGER_H_

#include <QVector>
#include <string>

#include "../controller/calculatorcontroller.h"
#include "trigonometrycalculationtype.h"
#include "ui_calculatorview.h"

namespace s21 {
class PlotManager {
 public:
  PlotManager(const Ui::CalculatorView& ui, CalculatorController& controller);
  ~PlotManager() = default;

  void SetUpPlotSettings();
  void DrawPlot(TrigonometryCalculationType calculation_type);
  void ClearPlot();

  void UpdateXAxisPlotRange(double absolute_x_value);
  void UpdateYAxisPlotRange(double absolute_y_value);

  void SetAbsoluteXValue(double absolute_x_value);
  void SetAbsoluteYValue(double absolute_y_value);

 private:
  const Ui::CalculatorView& ui_;
  CalculatorController& controller_;
  double absolute_x_value_{};
  double absolute_y_value_{};
  QVector<double> x_values_{};
  QVector<double> y_values_{};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_VIEW_PLOTMANAGER_H_
