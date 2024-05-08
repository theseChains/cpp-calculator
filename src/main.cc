#include <QApplication>
#include <clocale>

#include "controller/calculatorcontroller.h"
#include "model/calculatormodel.h"
#include "view/calculatorview.h"

int main(int argc, char** argv) {
  QApplication application{argc, argv};

  s21::CalculatorModel model{};
  s21::CalculatorController controller{model};
  s21::CalculatorView view{controller};
  view.show();

  return application.exec();
}
