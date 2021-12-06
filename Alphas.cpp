//
// Created by Robert on 06/12/2021.
//

#include "Alphas.h"

#include <vector>
#include <iostream>

std::vector<double> Alphas::getAlphaValues() const {
    std::vector<double> _alphas = std::vector<double>();
    _alphas.reserve(parent->z_size * parent->z_size * parent->n_beta * parent->n_beta);
    for(int n = -parent->n_sigma; n <= parent->n_sigma; ++n)
        for(int m = -parent->n_sigma; m <= parent->n_sigma; ++m)
            for(int phi = 0; phi < parent->n_beta; ++phi)
                for(int theta = 0; theta < parent->n_beta; ++theta)
                    _alphas.push_back(parent->alpha(n, m, phi, theta));

    return _alphas;
}

Alphas::Alphas(FourierAnalysis *parent):
    parent(parent), alphaValues(getAlphaValues())
{}

double Alphas::get(int n, int m, int phi, int theta) const {
    return alphaValues[
        parent->indexSigma(n) * parent->z_size * parent->z_size * parent->n_beta +
        parent->indexSigma(m) * parent->z_size * parent->n_beta +
        phi * parent->n_beta +
        theta
    ];
}
