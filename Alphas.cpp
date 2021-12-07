//
// Created by Robert on 07/12/2021.
//

#include "Alphas.h"
#include "FourierAnalysis.h"

#include <vector>

std::vector<std::vector<double>> Alphas::getAlphaValues(int n, int m) const {
    std::vector<std::vector<double>> _alphaValues = std::vector<std::vector<double>>();
    _alphaValues.reserve(parent->n_beta);
    for(int phi = 0; phi < parent->n_beta; ++phi) {
        _alphaValues.emplace_back();
        _alphaValues[phi].reserve(parent->n_beta);
        for(int theta = 0; theta < parent->n_beta; ++theta)
            _alphaValues[phi].push_back(parent->alpha(n, m, phi, theta));
    }

    return _alphaValues;
}

Alphas::Alphas(const FourierAnalysis *_parent, int n, int m):
    parent(_parent),
    alphaValues(getAlphaValues(n, m))
{}

double Alphas::get(int phi, int theta) const {
    return alphaValues[phi][theta];
}
