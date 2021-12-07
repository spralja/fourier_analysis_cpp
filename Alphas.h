//
// Created by Robert on 07/12/2021.
//

#ifndef FOURIER_ANALYSIS_CPP_ALPHAS_H
#define FOURIER_ANALYSIS_CPP_ALPHAS_H

#include <vector>

class FourierAnalysis;

class Alphas {
private:
    const FourierAnalysis* parent;

    const std::vector<std::vector<double>> alphaValues;
    std::vector<std::vector<double>> getAlphaValues(int n, int m) const;

public:
    Alphas(const FourierAnalysis* parent, int n, int m);

    double get(int phi, int theta) const;
};


#endif //FOURIER_ANALYSIS_CPP_ALPHAS_H
