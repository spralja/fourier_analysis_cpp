//
// Created by Robert on 04/12/2021.
//

#ifndef FOURIER_ANALYSIS_2_FOURIERANALYSIS_H
#define FOURIER_ANALYSIS_2_FOURIERANALYSIS_H

#include "utility"

#include "TrigonometricFunctionValues.h"

class FourierAnalysis {
private:
    const TrigonometricFunctionValues trigs;
public:
    const int n_beta;
    const int n_sigma;
    FourierAnalysis(int _n_beta, int _n_sigma);
    std::pair<double, double> getC(int k, int n, int m) const;
};


#endif //FOURIER_ANALYSIS_2_FOURIERANALYSIS_H
