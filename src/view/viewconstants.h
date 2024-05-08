#ifndef CPP3_SMARTCALC_V2_0_1_VIEW_VIEWCONSTANTS_H_
#define CPP3_SMARTCALC_V2_0_1_VIEW_VIEWCONSTANTS_H_

#include <QColor>
#include <QString>

namespace s21::constants {
inline constexpr int kMainWindowWidth{460};
inline constexpr int kMainWindowHeight{610};

inline constexpr double kAbsoluteMaxRangeValue{1000000.0};
inline constexpr double kInitialFunctionRangeValue{10.0};

inline constexpr char kResultNumberFormat{'g'};
inline constexpr int kNumberPrecision{10};

inline constexpr QColor kPlotLineColor{0, 128, 255};
inline constexpr int kPlotLinePenWidth{2};

inline constexpr QColor kPlotBackgroundColor{45, 45, 45};
inline constexpr QColor kPlotTickColor{200, 200, 200};
inline constexpr int kPlotTickPenWidth{1};
inline constexpr int kNumberOfPlotPoints{500};

inline constexpr int kMonthsInYear{12};
inline constexpr int kMaximumNumberOfMonths{600};
inline constexpr int kMaximumInterestRate{999};
inline constexpr int kCreditOutputNumberPrecision{2};
inline constexpr char kCreditOutputNumberFormat{'f'};

inline const QString kChosenLabelStyleString{
    "QLabel {"
    "border-style: solid;"
    "border-width: 2px;"
    "border-color: rgb(204, 255, 204);"
    "color: white;"
    "}"};

inline const QString kDefaultLabelStyleString{
    "QLabel {"
    "border-style: solid;"
    "border-width: 2px;"
    "border-color: rgb(118, 130, 144);"
    "color: white;"
    "}"};

inline const QString kErroneousLineEditStyleString{
    "color: rgb(246, 245, 244);"
    "background-color: rgb(36, 31, 49);"
    "border-style: solid;"
    "border-color: rgb(197, 72, 66);"
    "border-width: 1px;"
    "border-radius: 0px;"};

inline const QString kDefaultLineEditStyleString{
    "color: rgb(246, 245, 244);"
    "background-color: rgb(36, 31, 49);"
    "border-style: solid;"
    "border-color: rgb(118, 130, 144);"
    "border-width: 1px;"
    "border-radius: 0px;"};
}  // namespace s21::constants

#endif  // CPP3_SMARTCALC_V2_0_1_VIEW_VIEWCONSTANTS_H_
