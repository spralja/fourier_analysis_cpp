//
// Created by Robert on 05/12/2021.
//

#ifndef FOURIER_ANALYSIS_CPP_TRIGONOMETRICFUNCTIONVALUES_H
#define FOURIER_ANALYSIS_CPP_TRIGONOMETRICFUNCTIONVALUES_H


#include <vector>
#include <cmath>

class FourierAnalysis;

class TrigonometricFunctionValues {
private:
    const std::vector<double> sinValues;
    const std::vector<double> cosValues;
    const std::vector<double> tanValues;

    static std::vector<double> getSinValues(FourierAnalysis* parent);
    static std::vector<double> getCosValues(FourierAnalysis* parent);
    static std::vector<double> getTanValues(FourierAnalysis* parent);

public:
    explicit TrigonometricFunctionValues(FourierAnalysis* parent);

    double sin(int index) const;
    double cos(int index) const;
    double tan(int index) const;
};


#endif //FOURIER_ANALYSIS_CPP_TRIGONOMETRICFUNCTIONVALUES_H
