#ifndef CPP3_SMARTCALC_V2_0_1_MODEL_MODELCONSTANTS_H_
#define CPP3_SMARTCALC_V2_0_1_MODEL_MODELCONSTANTS_H_

#include <string>
#include <unordered_map>

#include "token.h"

namespace s21::constants {
inline constexpr char kUnaryMinus{'#'};
inline constexpr char kUnaryPlus{'$'};
inline constexpr int kMaxExpressionLength{255};
inline constexpr double kPi{3.14159265358979323846};

inline const std::unordered_map<FunctionType, double (*)(double)> kFunctionMap{
    {FunctionType::kSine, std::sin},
    {FunctionType::kCosine, std::cos},
    {FunctionType::kTangent, std::tan},
    {FunctionType::kArcCosine, std::acos},
    {FunctionType::kArcSine, std::asin},
    {FunctionType::kArcTangent, std::atan},
    {FunctionType::kSquareRoot, std::sqrt},
    {FunctionType::kNaturalLog, std::log},
    {FunctionType::kCommonLog, std::log10}};

inline const std::unordered_map<std::string, FunctionType> kFunctionStringMap{
    {"sin", FunctionType::kSine},        {"cos", FunctionType::kCosine},
    {"tan", FunctionType::kTangent},     {"acos", FunctionType::kArcCosine},
    {"asin", FunctionType::kArcSine},    {"atan", FunctionType::kArcTangent},
    {"sqrt", FunctionType::kSquareRoot}, {"ln", FunctionType::kNaturalLog},
    {"log", FunctionType::kCommonLog}};
}  // namespace s21::constants

#endif  // CPP3_SMARTCALC_V2_0_1_MODEL_MODELCONSTANTS_H_
