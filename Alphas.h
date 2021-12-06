//
// Created by Robert on 06/12/2021.
//

#ifndef FOURIER_ANALYSIS_CPP_ALPHAS_H
#define FOURIER_ANALYSIS_CPP_ALPHAS_H

#include <vector>

#include "FourierAnalysis.h"

class FourierAnalysis;

class Alphas {
private:
    const FourierAnalysis* parent;
    const std::vector<double> alphaValues;

    std::vector<double> getAlphaValues() const;

public:
    explicit Alphas(FourierAnalysis* parent);

    double get(int n, int m, int phi, int theta) const;
};


#endif //FOURIER_ANALYSIS_CPP_ALPHAS_H
