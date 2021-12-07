//
// Created by Robert on 06/12/2021.
//

#include <iostream>
#include "Alphas.h"
#include "FourierAnalysis.h"

std::map<int, std::map<int, std::map<int, std::map<int, double>>>> Alphas::getAlphaValues() const {
    std::map<int, std::map<int, std::map<int, std::map<int, double>>>> _alphaValues =
            std::map<int, std::map<int, std::map<int, std::map<int, double>>>>();

    for(int n = -parent->n_sigma; n <= parent->n_sigma; ++n)
        for(int m = -parent->n_sigma; m <= parent->n_sigma; ++m)
            for(int phi = 0; phi < parent->n_beta; ++phi)
                for(int theta = 0; theta < parent->n_beta; ++theta)
                    _alphaValues[n][m][phi][theta] = INFINITY;

    return _alphaValues;
}

Alphas::Alphas(FourierAnalysis *_parent):
    parent(_parent),
    alphaValues(getAlphaValues())
{}

double Alphas::get(int n, int m, int phi, int theta) const {
    if(alphaValues[n][m][phi][theta] == INFINITY)
        alphaValues[n][m][phi][theta] = parent->alpha(n, m, phi, theta);

    return alphaValues[n][m][phi][theta];
}
