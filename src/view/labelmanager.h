#ifndef CPP3_SMARTCALC_V2_0_1_VIEW_LABELMANAGER_H_
#define CPP3_SMARTCALC_V2_0_1_VIEW_LABELMANAGER_H_

#include <QObject>
#include <QString>

#include "../common/expressionerrorcode.h"
#include "labeltype.h"
#include "ui_calculatorview.h"

namespace s21 {
class LabelManager : public QObject {
  Q_OBJECT

 public:
  explicit LabelManager(const Ui::CalculatorView& ui);
  ~LabelManager() = default;

  void SetUpDefaultLabelTexts();

  void HandleDotSlot();
  void HandleSignSlot();
  void HandleOperationsSlot(const QString& operator_string);
  void HandleClearSlot();
  void HandleExponentSlot();
  void HandleEqualsSlot(ExpressionErrorCode error_code, double result);
  void HandleBracketSlot(const QString& bracket);
  void HandleFunctionSlot(const QString& function);
  void HandleXSlot(const QString& x_string);

  void SetTextToActiveLabel(const QString& updated_label_text) const;
  QString GetActiveLabelText() const;

  void ChangeChosenLabel(QLabel* chosen_label, QLabel* previous_label);
  QString GetLabelNameFromType(LabelType type) const;

  void SetLabelStyleToChosen(QLabel* label);

  LabelType GetCurrentActiveLabel() const;
  QString GetActiveLabelName() const;

  bool ResultIsActiveLabel() const;
  bool XInputIsActiveLabel() const;
  bool DomainIsActiveLabel() const;
  bool CodomainIsActiveLabel() const;
  bool ResultTextIsErroneous() const;

 private:
  const Ui::CalculatorView& calculator_ui_;
  LabelType current_active_label_{LabelType::kResultLabel};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_VIEW_LABELMANAGER_H_
