//
// Created by Robert on 07/12/2021.
//

#ifndef FOURIER_ANALYSIS_CPP_COEFFICIENT_H
#define FOURIER_ANALYSIS_CPP_COEFFICIENT_H


#include <utility>
#include <string>

class FourierAnalysis;

class Coefficient {
public:
    const double F;
    const double G;

    explicit Coefficient(const double& F,const double& G);

    Coefficient(const std::pair<double, double>& that);

    Coefficient conjugate() const;
};


#endif //FOURIER_ANALYSIS_CPP_COEFFICIENT_H
