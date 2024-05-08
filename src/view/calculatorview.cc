#include "calculatorview.h"

#include <QMouseEvent>
#include <cmath>
#include <optional>

#include "ui_calculatorview.h"
#include "viewconstants.h"

namespace s21 {
CalculatorView::CalculatorView(CalculatorController &controller,
                               QWidget *parent)
    : QMainWindow{parent},
      ui_{new Ui::CalculatorView},
      controller_{controller},
      label_manager_{*ui_},
      plot_manager_{*ui_, controller_},
      calculation_type_{TrigonometryCalculationType::kRadians},
      credit_calculator_{controller_} {
  ui_->setupUi(this);
  setFixedSize(
      QSize{constants::kMainWindowWidth, constants::kMainWindowHeight});
  label_manager_.SetLabelStyleToChosen(ui_->result);
  label_manager_.SetUpDefaultLabelTexts();
  plot_manager_.SetUpPlotSettings();

  ConnectButtonsToSlots();
}

CalculatorView::~CalculatorView() { delete ui_; }

void CalculatorView::ConnectButtonsToSlots() {
  ConnectButtonsToNumberSlot();
  ConnectButtonsToOperationsSlot();
  ConnectButtonsToFunctionSlot();

  connect(ui_->pushButtonDot, SIGNAL(clicked()), this, SLOT(DotSlot()));
  connect(ui_->pushButtonSign, SIGNAL(clicked()), this, SLOT(SignSlot()));
  connect(ui_->pushButtonClear, SIGNAL(clicked()), this, SLOT(ClearSlot()));
  connect(ui_->pushButtonExp, SIGNAL(clicked()), this, SLOT(ExponentSlot()));
  connect(ui_->pushButtonEquals, SIGNAL(clicked()), this, SLOT(EqualsSlot()));
  connect(ui_->pushButtonRightBracket, SIGNAL(clicked()), this,
          SLOT(BracketSlot()));
  connect(ui_->pushButtonLeftBracket, SIGNAL(clicked()), this,
          SLOT(BracketSlot()));
  connect(ui_->pushButtonX, SIGNAL(clicked()), this, SLOT(XSlot()));
  connect(ui_->pushButtonDrawPlot, SIGNAL(clicked()), this,
          SLOT(DrawPlotSlot()));
  connect(ui_->pushButtonClearPlot, SIGNAL(clicked()), this,
          SLOT(ClearPlotSlot()));
  connect(ui_->pushButtonTrigonometryCalculation, SIGNAL(clicked()), this,
          SLOT(TrigonometryCalculationSlot()));
  connect(ui_->pushButtonShowCreditCalculator, SIGNAL(clicked()), this,
          SLOT(ShowCreditCalculatorSlot()));
}

void CalculatorView::ConnectButtonsToNumberSlot() {
  connect(ui_->pushButtonZero, SIGNAL(clicked()), this, SLOT(NumberSlot()));
  connect(ui_->pushButtonOne, SIGNAL(clicked()), this, SLOT(NumberSlot()));
  connect(ui_->pushButtonTwo, SIGNAL(clicked()), this, SLOT(NumberSlot()));
  connect(ui_->pushButtonThree, SIGNAL(clicked()), this, SLOT(NumberSlot()));
  connect(ui_->pushButtonFour, SIGNAL(clicked()), this, SLOT(NumberSlot()));
  connect(ui_->pushButtonFive, SIGNAL(clicked()), this, SLOT(NumberSlot()));
  connect(ui_->pushButtonSix, SIGNAL(clicked()), this, SLOT(NumberSlot()));
  connect(ui_->pushButtonSeven, SIGNAL(clicked()), this, SLOT(NumberSlot()));
  connect(ui_->pushButtonEight, SIGNAL(clicked()), this, SLOT(NumberSlot()));
  connect(ui_->pushButtonNine, SIGNAL(clicked()), this, SLOT(NumberSlot()));
}

void CalculatorView::ConnectButtonsToOperationsSlot() {
  connect(ui_->pushButtonPlus, SIGNAL(clicked()), this, SLOT(OperationsSlot()));
  connect(ui_->pushButtonMinus, SIGNAL(clicked()), this,
          SLOT(OperationsSlot()));
  connect(ui_->pushButtonMultiply, SIGNAL(clicked()), this,
          SLOT(OperationsSlot()));
  connect(ui_->pushButtonDivide, SIGNAL(clicked()), this,
          SLOT(OperationsSlot()));
  connect(ui_->pushButtonModulus, SIGNAL(clicked()), this,
          SLOT(OperationsSlot()));
  connect(ui_->pushButtonPower, SIGNAL(clicked()), this,
          SLOT(OperationsSlot()));
}

void CalculatorView::ConnectButtonsToFunctionSlot() {
  connect(ui_->pushButtonSine, SIGNAL(clicked()), this, SLOT(FunctionSlot()));
  connect(ui_->pushButtonArcSine, SIGNAL(clicked()), this,
          SLOT(FunctionSlot()));
  connect(ui_->pushButtonCosine, SIGNAL(clicked()), this, SLOT(FunctionSlot()));
  connect(ui_->pushButtonArcCosine, SIGNAL(clicked()), this,
          SLOT(FunctionSlot()));
  connect(ui_->pushButtonTangent, SIGNAL(clicked()), this,
          SLOT(FunctionSlot()));
  connect(ui_->pushButtonArcTangent, SIGNAL(clicked()), this,
          SLOT(FunctionSlot()));
  connect(ui_->pushButtonSquareRoot, SIGNAL(clicked()), this,
          SLOT(FunctionSlot()));
  connect(ui_->pushButtonLog, SIGNAL(clicked()), this, SLOT(FunctionSlot()));
  connect(ui_->pushButtonLn, SIGNAL(clicked()), this, SLOT(FunctionSlot()));
}

double CalculatorView::HandleFunctionSpaceNumberOverflow(QLabel *label,
                                                         double label_number) {
  if (label_number >= constants::kAbsoluteMaxRangeValue) {
    label_number = constants::kAbsoluteMaxRangeValue;
    label->setText(QString::number(label_number, 'f', 0));
  }

  return label_number;
}

void CalculatorView::UpdateDomainLabel(double label_number) {
  label_number =
      HandleFunctionSpaceNumberOverflow(ui_->domainLabel, label_number);
  plot_manager_.UpdateXAxisPlotRange(label_number);
}

void CalculatorView::UpdateCodomainLabel(double label_number) {
  label_number =
      HandleFunctionSpaceNumberOverflow(ui_->codomainLabel, label_number);
  plot_manager_.UpdateYAxisPlotRange(label_number);
}

void CalculatorView::NumberSlot() {
  if (ui_->result->text().back() == 'x') return;

  QPushButton *button{static_cast<QPushButton *>(sender())};

  QString old_label{label_manager_.GetActiveLabelText()};
  QString updated_label_text{};
  int new_number{button->text().toInt()};
  if (old_label == "0" || old_label == "Error") {
    updated_label_text =
        QString::number(new_number, constants::kResultNumberFormat,
                        constants::kNumberPrecision);
  } else {
    updated_label_text =
        old_label + QString::number(new_number, constants::kResultNumberFormat,
                                    constants::kNumberPrecision);
  }

  label_manager_.SetTextToActiveLabel(updated_label_text);

  if (label_manager_.DomainIsActiveLabel()) {
    UpdateDomainLabel(updated_label_text.toDouble());
  } else if (label_manager_.CodomainIsActiveLabel()) {
    UpdateCodomainLabel(updated_label_text.toDouble());
  } else if (label_manager_.XInputIsActiveLabel()) {
    controller_.SetXValue(updated_label_text.toDouble());
  }
}

void CalculatorView::DotSlot() { label_manager_.HandleDotSlot(); }

void CalculatorView::SignSlot() {
  label_manager_.HandleSignSlot();

  if (label_manager_.XInputIsActiveLabel()) {
    controller_.SetXValue(-controller_.GetXValue());
  }
}

void CalculatorView::OperationsSlot() {
  QPushButton *button{static_cast<QPushButton *>(sender())};
  label_manager_.HandleOperationsSlot(button->text());
}

void CalculatorView::ClearSlot() { label_manager_.HandleClearSlot(); }

void CalculatorView::ExponentSlot() { label_manager_.HandleExponentSlot(); }

void CalculatorView::EqualsSlot() {
  if (!label_manager_.ResultIsActiveLabel()) return;

  std::string expression{ui_->result->text().toStdString()};
  bool convert_to_degrees{
      calculation_type_ == TrigonometryCalculationType::kRadians ? false
                                                                 : true};
  auto [result, error_code]{
      controller_.EvaluateExpression(expression, convert_to_degrees)};
  label_manager_.HandleEqualsSlot(error_code, result);
}

void CalculatorView::BracketSlot() {
  QPushButton *button{static_cast<QPushButton *>(sender())};
  label_manager_.HandleBracketSlot(button->text());
}

void CalculatorView::FunctionSlot() {
  QPushButton *button{static_cast<QPushButton *>(sender())};
  label_manager_.HandleFunctionSlot(button->text());
}

void CalculatorView::XSlot() {
  QPushButton *button{static_cast<QPushButton *>(sender())};
  label_manager_.HandleXSlot(button->text());
}

void CalculatorView::DrawPlotSlot() {
  plot_manager_.DrawPlot(calculation_type_);
}

void CalculatorView::ClearPlotSlot() { plot_manager_.ClearPlot(); }

void CalculatorView::TrigonometryCalculationSlot() {
  if (calculation_type_ == TrigonometryCalculationType::kRadians) {
    ui_->pushButtonTrigonometryCalculation->setText("Deg");
    calculation_type_ = TrigonometryCalculationType::kDegrees;
  } else {
    ui_->pushButtonTrigonometryCalculation->setText("Rad");
    calculation_type_ = TrigonometryCalculationType::kRadians;
  }
}

void CalculatorView::mousePressEvent(QMouseEvent *event) {
  QWidget *const widget{childAt(event->pos())};
  if (!widget) return;

  QLabel *const chosen_label{qobject_cast<QLabel *>(widget)};
  if (!chosen_label) return;

  QString name_of_previously_chosen_label{label_manager_.GetActiveLabelName()};
  QLabel *previously_chosen_label{
      findChild<QLabel *>(name_of_previously_chosen_label)};

  label_manager_.ChangeChosenLabel(chosen_label, previously_chosen_label);
}

void CalculatorView::ShowCreditCalculatorSlot() { credit_calculator_.exec(); }
}  // namespace s21
