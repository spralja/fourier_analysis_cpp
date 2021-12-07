//
// Created by Robert on 04/12/2021.
//

#include "FourierAnalysis.h"
#include <cmath>
#include <utility>
#include <iostream>

const double FourierAnalysis::a = -M_PI / 4.0;
const double FourierAnalysis::b = M_PI / 4.0;
const double FourierAnalysis::mu = 0.75 / (M_PI * M_PI * M_PI);

FourierAnalysis::FourierAnalysis(const int _n_beta, const int _n_sigma):
    n_beta(_n_beta),
    n_sigma(_n_sigma),
    d_beta((b - a) / _n_beta),
    z_size(2 * n_sigma + 1),
    trigs(this),
    alphas(this)
{}

std::pair<double, double> FourierAnalysis::getC(int k, int n, int m) const {
    double f_sum = 0.0;
    double g_sum = 0.0;

    int _kappa = kappa(k);

    for(int phi = 0; phi < n_beta; ++phi)
        for(int theta = 0; theta < n_beta; ++theta) {
            const double _alpha = alphas.get(n, m, phi, theta);
            const double t1 = std::sin(_alpha);
            const double t2 = std::cos(_alpha);
            const double _p = p(k, n, m, phi, theta);
            const double _q = q(k, n, m, phi, theta);

            f_sum += -M_PI * _kappa * t1 / _p + (_kappa * t2 - 1) / _q;
            g_sum += M_PI * _kappa * t2 / _p + _kappa * t1 / _q;
        }

    return std::pair<double, double>(
            mu * f_sum * d_beta * d_beta,
            mu * g_sum * d_beta * d_beta
    );

}

int FourierAnalysis::kappa(int k) {
    if(k % 2 == 0)
        return 1;

    return -1;
}

double FourierAnalysis::alpha(int n, int m, int phi, int theta) const {
    return M_PI * (m * trigs.tan(phi) / trigs.cos(theta) + n * trigs.tan(theta));
}

double FourierAnalysis::p(int k, int n, int m, int phi, int theta) const {
    return m * trigs.sin(phi) + trigs.cos(phi) * (k * trigs.cos(theta) + n * trigs.sin(theta));
}

double FourierAnalysis::q(int k, int n, int m, int phi, int theta) const {
    return
        m * m * trigs.sin(phi) * trigs.tan(phi) +
        2 * m * trigs.sin(phi) * (k * trigs.cos(theta) + n * trigs.sin(theta)) +
            trigs.cos(phi) *
            (k * trigs.cos(theta) + n * trigs.sin(theta)) *
            (k * trigs.cos(theta) + n * trigs.sin(theta));
}

double FourierAnalysis::beta(int index) const {
    return a + d_beta * (index + 0.5);
}

int FourierAnalysis::indexSigma(int sigma) const {
    return sigma + n_sigma;
}