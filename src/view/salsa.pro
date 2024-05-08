QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../main.cc \
    ../controller/calculatorcontroller.cc \
    ../model/calculatorcore.cc \
    ../model/calculatormodel.cc \
    ../model/creditcalculator.cc \
    ../model/expressioncalculator.cc \
    ../model/expressionvalidator.cc \
    ../model/rpnconverter.cc \
    ../model/symbolclassifier.cc \
    ../model/tokenclassifier.cc \
    ../model/tokenizer.cc \
    qcustomplot.cc \
    calculatorview.cc \
    labelmanager.cc \
    plotmanager.cc \
    creditcalculatorwindow.cc

HEADERS += \
    ../controller/calculatorcontroller.h \
    ../common/creditinput.h \
    ../common/monthlypaymenttype.h \
    ../common/expressionerrorcode.h \
    ../model/calculationresult.h \
    ../model/calculatorcore.h \
    ../model/calculatormodel.h \
    ../model/creditcalculator.h \
    ../model/expressioncalculator.h \
    ../model/expressionerrorcode.h \
    ../model/expressionvalidator.h \
    ../model/modelconstants.h \
    ../model/rpnconverter.h \
    ../model/symbolclassifier.h \
    ../model/tokenclassifier.h \
    ../model/tokenizer.h \
    ../model/token.h \
    labeltype.h \
    qcustomplot.h \
    trigonometrycalculationtype.h \
    calculatorview.h \
    labelmanager.h \
    plotmanager.h \
    creditcalculatorwindow.h \
    viewconstants.h

FORMS += \
    calculatorview.ui \
    creditcalculatorwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
