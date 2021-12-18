//
// Created by Robert on 04/12/2021.
//

#include "FourierAnalysis.h"
#include "Alphas.h"
#include <cmath>
#include <utility>
#include <iostream>

const double FourierAnalysis::a = -M_PI / 4.0;
const double FourierAnalysis::b = M_PI / 4.0;
const double FourierAnalysis::mu = 0.75 / (M_PI * M_PI * M_PI);
const double FourierAnalysis::correct_mu = 6 / std::sqrt(std::pow(2 * M_PI, 3));
const double FourierAnalysis::adjusted_mu = correct_mu / mu;
const double FourierAnalysis::total_mu = adjusted_mu * correct_mu;
const double FourierAnalysis::C000 = 1;

FourierAnalysis::FourierAnalysis(const int _n_beta, const int _n_sigma):
    n_beta(_n_beta),
    n_sigma(_n_sigma),
    d_beta((b - a) / _n_beta),
    z_size(2 * n_sigma + 2),
    z_end(z_size + 1),
    trigs(this),
    coefficients(this)
{}

std::pair<double, double> FourierAnalysis::C(int k, int n, int m) const {
    double f_sum = 0.0;
    double g_sum = 0.0;

    int _kappa = kappa(k);
    Alphas alphas = Alphas(this, n, m);

    for(int phi = 0; phi < n_beta; ++phi)
        for(int theta = 0; theta < n_beta; ++theta) {
            const double _alpha = alphas.get(phi, theta);
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

double FourierAnalysis::fourierSum(double x, double y, double z) const {
    double sum = 0.0;
    for(int n = -n_sigma; n <= n_sigma; ++n)
        for(int m = 1; m <= n_sigma; ++m) {
            for(int k = -n_sigma; k <= n_sigma; ++k) {
                const Coefficient& C = coefficients.get(k, n, m);
                sum += C.F * std::cos(k * x + n * y + m * z);
                sum += C.G * std::sin(k * x + n * y + m * z);
            }
        }
    for(int n = 1; n <= n_sigma; ++n) {
        for(int k = -n_sigma; k <= n_sigma; ++k) {
            const Coefficient& C = coefficients.get(k, n, 0);
            sum += C.F * std::cos(k * x + n * y);
            sum += C.G * std::sin(k * x + n * y);
        }
    }

    for(int k = 1; k <= n_sigma; ++k) {
        const Coefficient& C = coefficients.get(k, 0, 0);
        sum += C.F * std::cos(k * x);
        sum += C.G * std::sin(k * x);
    }

    sum *= 2;
    sum += C000;

    return total_mu * sum;

}

double FourierAnalysis::MSE(const int &N) const {
    double sum = 0.0;
    const double dx = 2 * M_PI / N;
    const double dy = 2 * M_PI / N;
    const double dz = 2 * M_PI / N;

    for(int i = 0; i < N; ++i) {
        const double x = -M_PI + (i + 0.5) * dx;
        for(int j = 0; j < N; ++j) {
            const double y = -M_PI + (j + 0.5) * dy;
            for(int k = 0; k < N; ++k) {
                const double z = -M_PI + (k + 0.5) * dz;
                sum += std::pow((1 / sqrt(x*x + y*y + z*z)) - fourierSum(x, y ,z), 2);
            }
        }
    }

    return sum * dx * dy * dz;
}
