//
// Created by Robert on 06/12/2021.
//

#ifndef FOURIER_ANALYSIS_CPP_ALPHAS_H
#define FOURIER_ANALYSIS_CPP_ALPHAS_H

#include <map>

class FourierAnalysis;

class Alphas {
private:
    const FourierAnalysis* parent;

    mutable std::map<int, std::map<int, std::map<int, std::map<int, double>>>> alphaValues;

    std::map<int, std::map<int, std::map<int, std::map<int, double>>>> getAlphaValues() const;

public:
    explicit Alphas(FourierAnalysis* parent);

    double get(int n, int m, int phi, int theta) const;
};


#endif //FOURIER_ANALYSIS_CPP_ALPHAS_H
