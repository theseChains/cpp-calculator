#include "creditcalculatorwindow.h"

#include <QDate>
#include <iostream>

#include "ui_creditcalculatorwindow.h"
#include "viewconstants.h"

namespace s21 {
CreditCalculatorWindow::CreditCalculatorWindow(CalculatorController& controller,
                                               QWidget* parent)
    : QDialog{parent},
      ui_{new Ui::CreditCalculatorWindow},
      controller_{controller},
      monthly_payment_type_{MonthlyPaymentType::kAnnuity} {
  ui_->setupUi(this);

  connect(ui_->calculatePushButton, SIGNAL(clicked()), this,
          SLOT(CalculateButtonSlot()));
  connect(ui_->radioButtonAnnuity, SIGNAL(clicked()), this,
          SLOT(MonthlyPaymentTypeSlot()));
  connect(ui_->radioButtonDifferentiated, SIGNAL(clicked()), this,
          SLOT(MonthlyPaymentTypeSlot()));

  ui_->termLineEdit->setValidator(
      new QIntValidator(0, constants::kMaximumNumberOfMonths, this));
  ui_->interestRateLineEdit->setValidator(
      new QIntValidator(0, constants::kMaximumInterestRate, this));
}

CreditCalculatorWindow::~CreditCalculatorWindow() { delete ui_; }

void CreditCalculatorWindow::CalculateButtonSlot() {
  auto [monthly_payment, overpayment_on_credit,
        total_payment]{GetCreditOutputStrings()};
  ui_->calculationResultLabel->setText(monthly_payment + overpayment_on_credit +
                                       total_payment);
}

void CreditCalculatorWindow::MonthlyPaymentTypeSlot() {
  QRadioButton* button{static_cast<QRadioButton*>(sender())};
  if (button->objectName() == "radioButtonAnnuity") {
    monthly_payment_type_ = MonthlyPaymentType::kAnnuity;
  } else {
    monthly_payment_type_ = MonthlyPaymentType::kDifferentiated;
  }
}

void CreditCalculatorWindow::SetLineEditStyleToErroneous(QLineEdit* lineEdit) {
  lineEdit->setStyleSheet(constants::kErroneousLineEditStyleString);
}

void CreditCalculatorWindow::SetLineEditStyleToDefault(QLineEdit* lineEdit) {
  lineEdit->setStyleSheet(constants::kDefaultLineEditStyleString);
}

std::optional<CreditInput> CreditCalculatorWindow::GetCreditInput() {
  bool conversion_successful{true};
  bool all_conversions_were_successful{true};
  double credit_amount{
      ui_->creditAmountLineEdit->text().toDouble(&conversion_successful)};
  if (!conversion_successful) {
    all_conversions_were_successful = false;
    SetLineEditStyleToErroneous(ui_->creditAmountLineEdit);
  } else {
    SetLineEditStyleToDefault(ui_->creditAmountLineEdit);
  }

  int number_of_months{ui_->termLineEdit->text().toInt(&conversion_successful)};
  if (conversion_successful &&
      ui_->termTimeTypeComboBox->currentText() == "years")
    number_of_months *= constants::kMonthsInYear;
  if (!conversion_successful ||
      number_of_months > constants::kMaximumNumberOfMonths) {
    all_conversions_were_successful = false;
    SetLineEditStyleToErroneous(ui_->termLineEdit);
  } else {
    SetLineEditStyleToDefault(ui_->termLineEdit);
  }

  double interest_rate{
      ui_->interestRateLineEdit->text().toInt(&conversion_successful) / 100.0};
  if (!conversion_successful) {
    all_conversions_were_successful = false;
    SetLineEditStyleToErroneous(ui_->interestRateLineEdit);
  } else {
    SetLineEditStyleToDefault(ui_->interestRateLineEdit);
  }

  CreditInput input{credit_amount, number_of_months, interest_rate};
  return (all_conversions_were_successful ? std::make_optional(input)
                                          : std::nullopt);
}

std::array<QString, 3> CreditCalculatorWindow::GetCreditOutputStrings() {
  QString monthly_payment_string{"Monthly payment: "};
  QString overpayment_on_credit_string{"Overpayment on credit: "};
  QString total_payment_string{"Total payment: "};
  auto credit_input{GetCreditInput()};
  if (credit_input.has_value()) {
    CreditInput input{credit_input.value()};
    auto result{
        controller_.CalculateCreditDetails(monthly_payment_type_, input)};
    if (monthly_payment_type_ == MonthlyPaymentType::kAnnuity) {
      monthly_payment_string += QString::number(
          result.montly_payment, constants::kCreditOutputNumberFormat,
          constants::kCreditOutputNumberPrecision);
      overpayment_on_credit_string += QString::number(
          result.overpayment_on_credit, constants::kCreditOutputNumberFormat,
          constants::kCreditOutputNumberPrecision);
      total_payment_string += QString::number(
          result.total_payment, constants::kCreditOutputNumberFormat,
          constants::kCreditOutputNumberPrecision);
    } else {
      monthly_payment_string += QString::number(
          result.first_payment, constants::kCreditOutputNumberFormat,
          constants::kCreditOutputNumberPrecision);
      monthly_payment_string += "P ... ";
      monthly_payment_string += QString::number(
          result.last_payment, constants::kCreditOutputNumberFormat,
          constants::kCreditOutputNumberPrecision);
      overpayment_on_credit_string += QString::number(
          result.overpayment_on_credit, constants::kCreditOutputNumberFormat,
          constants::kCreditOutputNumberPrecision);
      total_payment_string += QString::number(
          result.total_payment, constants::kCreditOutputNumberFormat,
          constants::kCreditOutputNumberPrecision);
    }

    monthly_payment_string += "P\n";
    overpayment_on_credit_string += "P\n";
    total_payment_string += "P";
  } else {
    monthly_payment_string += '\n';
    overpayment_on_credit_string += '\n';
  }

  return {monthly_payment_string, overpayment_on_credit_string,
          total_payment_string};
}
}  // namespace s21
