#include "plotmanager.h"

#include <QPen>

#include "viewconstants.h"

namespace s21 {
PlotManager::PlotManager(const Ui::CalculatorView& ui,
                         CalculatorController& controller)
    : ui_{ui},
      controller_{controller},
      absolute_x_value_{constants::kInitialFunctionRangeValue},
      absolute_y_value_{constants::kInitialFunctionRangeValue} {}

void PlotManager::SetUpPlotSettings() {
  ui_.plot->xAxis->setRange(-absolute_x_value_, absolute_x_value_);
  ui_.plot->yAxis->setRange(-absolute_y_value_, absolute_y_value_);
  ui_.plot->setBackground(QBrush{constants::kPlotBackgroundColor});
  ui_.plot->xAxis->setTickPen(
      QPen{constants::kPlotTickColor, constants::kPlotTickPenWidth});
  ui_.plot->yAxis->setTickPen(
      QPen{constants::kPlotTickColor, constants::kPlotTickPenWidth});
  ui_.plot->xAxis->setSubTickPen(
      QPen{constants::kPlotTickColor, constants::kPlotTickPenWidth});
  ui_.plot->yAxis->setSubTickPen(
      QPen{constants::kPlotTickColor, constants::kPlotTickPenWidth});
  ui_.plot->xAxis->setBasePen(
      QPen{constants::kPlotTickColor, constants::kPlotTickPenWidth});
  ui_.plot->yAxis->setBasePen(
      QPen{constants::kPlotTickColor, constants::kPlotTickPenWidth});
  ui_.plot->xAxis->setTickLabelColor(constants::kPlotTickColor);
  ui_.plot->yAxis->setTickLabelColor(constants::kPlotTickColor);
  ui_.plot->addGraph();
}

void PlotManager::DrawPlot(TrigonometryCalculationType calculation_type) {
  x_values_.clear();
  y_values_.clear();
  ui_.plot->clearGraphs();

  ui_.plot->addGraph();
  ui_.plot->xAxis->setRange(-absolute_x_value_, absolute_x_value_);
  ui_.plot->yAxis->setRange(-absolute_y_value_, absolute_y_value_);

  std::string expression{ui_.result->text().toStdString()};
  bool convert_to_degrees{
      calculation_type == TrigonometryCalculationType::kRadians ? false : true};
  double step{absolute_x_value_ * 2.0 / constants::kNumberOfPlotPoints};
  int error_count{0};
  double previous_x_value{controller_.GetXValue()};
  for (double current_x{-absolute_x_value_}; current_x <= absolute_x_value_;
       current_x += step) {
    x_values_.push_back(current_x);
    controller_.SetXValue(current_x);
    auto [value, error_code]{
        controller_.EvaluateExpression(expression, convert_to_degrees)};
    if (error_code != ExpressionErrorCode::kOk) {
      value = 0.0;
      ++error_count;
    }
    y_values_.push_back(value);
  }
  controller_.SetXValue(previous_x_value);

  if (error_count < constants::kNumberOfPlotPoints) {
    ui_.plot->graph(0)->addData(x_values_, y_values_);
    ui_.plot->graph(0)->setPen(
        QPen{constants::kPlotLineColor, constants::kPlotLinePenWidth});
    ui_.plot->replot();
  } else {
    x_values_.clear();
    y_values_.clear();
    ui_.plot->clearGraphs();
    ui_.plot->replot();
    ui_.result->setText("Error");
  }
}

void PlotManager::ClearPlot() {
  x_values_.clear();
  y_values_.clear();
  ui_.plot->clearGraphs();
  ui_.plot->replot();
}

void PlotManager::UpdateXAxisPlotRange(double absolute_x_value) {
  SetAbsoluteXValue(absolute_x_value);
  ui_.plot->xAxis->setRange(-absolute_x_value_, absolute_x_value);
  ui_.plot->replot();
}

void PlotManager::UpdateYAxisPlotRange(double absolute_y_value) {
  SetAbsoluteYValue(absolute_y_value);
  ui_.plot->yAxis->setRange(-absolute_y_value_, absolute_y_value);
  ui_.plot->replot();
}

void PlotManager::SetAbsoluteXValue(double absolute_x_value) {
  absolute_x_value_ = absolute_x_value;
}

void PlotManager::SetAbsoluteYValue(double absolute_y_value) {
  absolute_y_value_ = absolute_y_value;
}
}  // namespace s21
