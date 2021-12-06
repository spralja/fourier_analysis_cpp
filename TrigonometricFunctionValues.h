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
    const FourierAnalysis* parent;

    const std::vector<double> sinValues;
    const std::vector<double> cosValues;
    const std::vector<double> tanValues;

    std::vector<double> getSinValues() const;
    std::vector<double> getCosValues() const;
    std::vector<double> getTanValues() const;

public:
    explicit TrigonometricFunctionValues(FourierAnalysis* parent);

    double sin(int index) const;
    double cos(int index) const;
    double tan(int index) const;
};


#endif //FOURIER_ANALYSIS_CPP_TRIGONOMETRICFUNCTIONVALUES_H
