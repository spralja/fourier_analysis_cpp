//
// Created by Robert on 04/12/2021.
//

#ifndef FOURIER_ANALYSIS_2_FOURIERANALYSIS_H
#define FOURIER_ANALYSIS_2_FOURIERANALYSIS_H

#include "utility"

class FourierAnalysis {
public:
    const int n_beta;
    const int n_sigma;
    FourierAnalysis(const int& _n_beta, const int& _n_sigma);
    std::pair<double, double> getC(int k, int n, int m) const;
};


#endif //FOURIER_ANALYSIS_2_FOURIERANALYSIS_H
