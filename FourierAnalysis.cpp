//
// Created by Robert on 04/12/2021.
//

#include "FourierAnalysis.h"
#include <cmath>
#include <utility>
#include <iostream>

FourierAnalysis::FourierAnalysis(const int& _n_beta, const int& _n_sigma)
        : n_beta(_n_beta), n_sigma(_n_sigma) {}

std::pair<double, double> FourierAnalysis::getC(int k, int n, int m) const {
    const double a = -M_PI / 4.0;
    const double b = M_PI / 4.0;
    const double d_phi = (b - a) / n_beta;
    const double d_theta = (b - a) / n_beta;
    double f_sum = 0.0;
    double g_sum = 0.0;

    const double mu = 0.75 / (M_PI * M_PI * M_PI);

    int kappa = -1;
    if(k % 2 == 0)
        kappa = -1;

    for(int i = 0; i < n_beta; ++i) {
        const double phi = a + d_phi * (i + 0.5);

        for(int j = 0; j < n_beta; ++j) {
            const double theta = a + d_theta * (j + 0.5);

            const double alpha = M_PI * (m * std::tan(phi) / std::cos(theta) + n * std::tan(theta));
            const double t1 = std::sin(alpha);
            const double t2 = std::cos(alpha);
            const double p =
                    m * std::sin(phi) + std::cos(phi) * (k * std::cos(theta) + n * std::sin(theta));


            const double q =
                    m * m * std::sin(phi) * std::tan(phi) +
                    2 * m * std::sin(phi) * (k * std::cos(theta) + n * std::sin(theta)) +
                    std::cos(phi) *
                    (k * std::cos(theta) + n * std::sin(theta)) *
                    (k * std::cos(theta) + n * std::sin(theta));

            f_sum += -M_PI * kappa * t1 / p + (kappa * t2 - 1) / q;
            g_sum += M_PI * kappa * t2 / p + kappa * t1 / q;
        }
    }
    return std::pair<double, double>(mu * f_sum * d_phi * d_theta, mu * g_sum * d_phi * d_theta);

}

