//
// Created by Robert on 05/12/2021.
//

#ifndef FOURIER_ANALYSIS_CPP_TRIGONOMETRICFUNCTIONVALUES_H
#define FOURIER_ANALYSIS_CPP_TRIGONOMETRICFUNCTIONVALUES_H


#include <vector>
#include <cmath>

class TrigonometricFunctionValues {
private:
    const std::vector<double> sinValues;
    const std::vector<double> cosValues;
    const std::vector<double> tanValues;

    double getD_beta(int _n_beta) const;
    std::vector<double> getSinValues(int _n_beta) const;
    std::vector<double> getCosValues(int _n_beta) const;
    std::vector<double> getTanValues(int _n_beta) const;

    double beta(int index, double _n_beta) const;
public:
    static const double a;
    static const double b;
    const int n_beta;
    const double d_beta;
    explicit TrigonometricFunctionValues(int n_beta);

    double sin(int index) const;
    double cos(int index) const;
    double tan(int index) const;
};


#endif //FOURIER_ANALYSIS_CPP_TRIGONOMETRICFUNCTIONVALUES_H
