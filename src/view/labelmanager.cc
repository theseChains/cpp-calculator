#include "labelmanager.h"

#include <cctype>
#include <cmath>

#include "viewconstants.h"

namespace s21 {
LabelManager::LabelManager(const Ui::CalculatorView& ui) : calculator_ui_{ui} {}

void LabelManager::SetUpDefaultLabelTexts() {
  calculator_ui_.result->setText("0");
  calculator_ui_.xInput->setText("0");
  calculator_ui_.domainLabel->setText("10");
  calculator_ui_.codomainLabel->setText("10");
}

void LabelManager::HandleDotSlot() {
  if (ResultIsActiveLabel() && ResultTextIsErroneous()) return;

  std::string old_label{GetActiveLabelText().toStdString()};
  std::string last_number_string{
      old_label.substr(old_label.find_last_not_of("0123456789.") + 1)};
  if (last_number_string.find('.') == std::string::npos &&
      !last_number_string.empty()) {
    SetTextToActiveLabel(QString::fromStdString(old_label) + ".");
  }
}

void LabelManager::HandleSignSlot() {
  if ((!ResultIsActiveLabel() && !XInputIsActiveLabel()) ||
      ResultTextIsErroneous())
    return;

  bool conversion_successful{};
  double number{GetActiveLabelText().toDouble(&conversion_successful) * (-1)};
  if (conversion_successful) {
    QString updated_label{QString::number(
        number, constants::kResultNumberFormat, constants::kNumberPrecision)};
    SetTextToActiveLabel(updated_label);
  }
}

void LabelManager::HandleOperationsSlot(const QString& operator_string) {
  if (!ResultIsActiveLabel() || ResultTextIsErroneous()) return;

  QString label_text{GetActiveLabelText()};
  SetTextToActiveLabel(label_text + operator_string);
}

void LabelManager::HandleClearSlot() { SetTextToActiveLabel("0"); }

void LabelManager::HandleExponentSlot() {
  if (ResultIsActiveLabel() && ResultTextIsErroneous()) return;

  std::string old_label{GetActiveLabelText().toStdString()};
  std::string last_number_string{
      old_label.substr(old_label.find_last_not_of("0123456789.") + 1)};
  if (last_number_string.find('e') == std::string::npos &&
      !last_number_string.empty()) {
    SetTextToActiveLabel(QString::fromStdString(old_label) + "e");
  }
}

void LabelManager::HandleEqualsSlot(ExpressionErrorCode error_code,
                                    double result) {
  if (error_code == ExpressionErrorCode::kOk && std::isfinite(result)) {
    calculator_ui_.result->setText(QString::number(
        result, constants::kResultNumberFormat, constants::kNumberPrecision));
  } else {
    calculator_ui_.result->setText("Error");
  }
}

void LabelManager::HandleBracketSlot(const QString& bracket) {
  if (!ResultIsActiveLabel()) return;

  QString result_text{calculator_ui_.result->text()};
  if ((result_text == "0" || calculator_ui_.result->text() == "Error") &&
      bracket != ")") {
    result_text = bracket;
  } else if (result_text != "0" &&
             !(calculator_ui_.result->text() == "Error")) {
    result_text += bracket;
  }

  SetTextToActiveLabel(result_text);
}

void LabelManager::HandleFunctionSlot(const QString& function) {
  if (!ResultIsActiveLabel()) return;

  QString result_text{calculator_ui_.result->text()};
  if (result_text == "0" || ResultTextIsErroneous()) {
    result_text = function + "(";
  } else {
    result_text += function + "(";
  }

  SetTextToActiveLabel(result_text);
}

void LabelManager::HandleXSlot(const QString& x_string) {
  if (!ResultIsActiveLabel() || ResultTextIsErroneous()) return;

  QString label{GetActiveLabelText()};
  if (std::isdigit(calculator_ui_.result->text().back().toLatin1()) &&
      label != "0") {
    return;
  }

  if (label == "0") {
    label = x_string;
  } else {
    label += x_string;
  }

  SetTextToActiveLabel(label);
}

void LabelManager::SetTextToActiveLabel(const QString& updatedLabelText) const {
  if (current_active_label_ == LabelType::kResultLabel)
    calculator_ui_.result->setText(updatedLabelText);
  else if (current_active_label_ == LabelType::kXInputLabel)
    calculator_ui_.xInput->setText(updatedLabelText);
  else if (current_active_label_ == LabelType::kDomainLabel)
    calculator_ui_.domainLabel->setText(updatedLabelText);
  else if (current_active_label_ == LabelType::kCodomainLabel)
    calculator_ui_.codomainLabel->setText(updatedLabelText);
}

QString LabelManager::GetActiveLabelText() const {
  QString label_text{};
  if (current_active_label_ == LabelType::kResultLabel)
    label_text = calculator_ui_.result->text();
  else if (current_active_label_ == LabelType::kXInputLabel)
    label_text = calculator_ui_.xInput->text();
  else if (current_active_label_ == LabelType::kDomainLabel)
    label_text = calculator_ui_.domainLabel->text();
  else if (current_active_label_ == LabelType::kCodomainLabel)
    label_text = calculator_ui_.codomainLabel->text();

  return label_text;
}

void LabelManager::ChangeChosenLabel(QLabel* chosen_label,
                                     QLabel* previous_label) {
  QString chosen_label_name{chosen_label->objectName()};
  LabelType previous_label_type{current_active_label_};

  if (chosen_label_name == "result")
    current_active_label_ = LabelType::kResultLabel;
  else if (chosen_label_name == "xInput")
    current_active_label_ = LabelType::kXInputLabel;
  else if (chosen_label_name == "domainLabel")
    current_active_label_ = LabelType::kDomainLabel;
  else if (chosen_label_name == "codomainLabel")
    current_active_label_ = LabelType::kCodomainLabel;

  QString name_of_previous_label{GetLabelNameFromType(previous_label_type)};
  if (previous_label && current_active_label_ != previous_label_type) {
    previous_label->setStyleSheet(constants::kDefaultLabelStyleString);
  }

  SetLabelStyleToChosen(chosen_label);
}

QString LabelManager::GetLabelNameFromType(LabelType type) const {
  QString label_name{};
  if (type == LabelType::kResultLabel)
    label_name = "result";
  else if (type == LabelType::kXInputLabel)
    label_name = "xInput";
  else if (type == LabelType::kDomainLabel)
    label_name = "domainLabel";
  else if (type == LabelType::kCodomainLabel)
    label_name = "codomainLabel";

  return label_name;
}

void LabelManager::SetLabelStyleToChosen(QLabel* label) {
  QString label_name{label->objectName()};
  if (label_name != "domainText" && label_name != "codomainText")
    label->setStyleSheet(constants::kChosenLabelStyleString);
}

LabelType LabelManager::GetCurrentActiveLabel() const {
  return current_active_label_;
}

QString LabelManager::GetActiveLabelName() const {
  return GetLabelNameFromType(current_active_label_);
}

bool LabelManager::ResultIsActiveLabel() const {
  return (current_active_label_ == LabelType::kResultLabel);
}

bool LabelManager::XInputIsActiveLabel() const {
  return (current_active_label_ == LabelType::kXInputLabel);
}

bool LabelManager::DomainIsActiveLabel() const {
  return (current_active_label_ == LabelType::kDomainLabel);
}

bool LabelManager::CodomainIsActiveLabel() const {
  return (current_active_label_ == LabelType::kCodomainLabel);
}

bool LabelManager::ResultTextIsErroneous() const {
  return (calculator_ui_.result->text() == "Error");
}
}  // namespace s21
