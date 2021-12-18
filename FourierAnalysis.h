//
// Created by Robert on 04/12/2021.
//

#ifndef FOURIER_ANALYSIS_2_FOURIERANALYSIS_H
#define FOURIER_ANALYSIS_2_FOURIERANALYSIS_H

#include <utility>

#include "TrigonometricFunctionValues.h"
#include "CoefficientCollection.h"

class FourierAnalysis {

public:
    static const double a;
    static const double b;
    static const double mu;
    static double const correct_mu;
    static double const adjusted_mu;
    static double const total_mu;
    const int n_beta;
    const double d_beta;
    const int n_sigma;
    const int z_size;
    const int z_end;

private:
    const TrigonometricFunctionValues trigs;
    CoefficientCollection coefficients;

public:
    FourierAnalysis(int _n_beta, int _n_sigma);
    std::pair<double, double> C(int k, int n, int m) const;

    static int kappa(int k);
    double alpha(int n, int m, int phi, int theta) const;
    double p(int k, int n, int m, int phi, int theta) const;
    double q(int k, int n, int m, int phi, int theta) const;
    double fourierSum(double x, double y, double z) const;

    double beta(int index) const;

};


#endif //FOURIER_ANALYSIS_2_FOURIERANALYSIS_H
