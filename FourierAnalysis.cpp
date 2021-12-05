//
// Created by Robert on 04/12/2021.
//

#include "FourierAnalysis.h"
#include <cmath>
#include <utility>
#include <iostream>

FourierAnalysis::FourierAnalysis(const int _n_beta, const int _n_sigma)
        : n_beta(_n_beta), n_sigma(_n_sigma), trigs(_n_beta) {}

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

    for(int phi = 0; phi < n_beta; ++phi)
        for(int theta = 0; theta < n_beta; ++theta) {
            const double alpha = M_PI * (m * trigs.tan(phi) / trigs.cos(theta) + n * trigs.tan(theta));
            const double t1 = std::sin(alpha);
            const double t2 = std::cos(alpha);
            const double p =
                    m * trigs.sin(phi) + trigs.cos(phi) * (k * trigs.cos(theta) + n * trigs.sin(theta));


            const double q =
                    m * m * trigs.sin(phi) * trigs.tan(phi) +
                    2 * m * trigs.sin(phi) * (k * trigs.cos(theta) + n * trigs.sin(theta)) +
                    trigs.cos(phi) *
                    (k * trigs.cos(theta) + n * trigs.sin(theta)) *
                    (k * trigs.cos(theta) + n * trigs.sin(theta));

            f_sum += -M_PI * kappa * t1 / p + (kappa * t2 - 1) / q;
            g_sum += M_PI * kappa * t2 / p + kappa * t1 / q;
        }

    return std::pair<double, double>(mu * f_sum * d_phi * d_theta, mu * g_sum * d_phi * d_theta);

}

