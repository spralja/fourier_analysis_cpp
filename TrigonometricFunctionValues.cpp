//
// Created by Robert on 05/12/2021.
//

#include <iostream>
#include "TrigonometricFunctionValues.h"

const double TrigonometricFunctionValues::a = -M_PI / 4.0;
const double TrigonometricFunctionValues::b = M_PI / 4.0;

double TrigonometricFunctionValues::getD_beta(int _n_beta) const {
    return (b - a) / _n_beta;
}

std::vector<double> TrigonometricFunctionValues::getSinValues(int _n_beta) const {
    std::vector<double> _sinValues = std::vector<double>();
    //_sinValues.reserve(n_beta);
    for(int i = 0; i < _n_beta; ++i)
        _sinValues.push_back(std::sin(beta(i, getD_beta(_n_beta))));

    return _sinValues;
}

std::vector<double> TrigonometricFunctionValues::getCosValues(int _n_beta) const {
    std::vector<double> _cosValues = std::vector<double>();
    //_cosValues.reserve(n_beta);
    for(int i = 0; i < _n_beta; ++i)
        _cosValues.push_back(std::cos(beta(i, getD_beta(_n_beta))));

    return _cosValues;
}

std::vector<double> TrigonometricFunctionValues::getTanValues(int _n_beta) const {
    std::vector<double> _tanValues = std::vector<double>();
    //_tanValues.reserve(n_beta);
    for(int i = 0; i < _n_beta; ++i)
        _tanValues.push_back(std::tan(beta(i, getD_beta(_n_beta))));

    return _tanValues;
}

double TrigonometricFunctionValues::beta(int index, double _d_beta) const {
    return a + _d_beta * (index + 0.5);
}

TrigonometricFunctionValues::TrigonometricFunctionValues(int _n_beta):
    n_beta(_n_beta),
    d_beta(getD_beta(_n_beta)),
    sinValues(getSinValues(_n_beta)),
    cosValues(getCosValues(_n_beta)),
    tanValues(getTanValues(_n_beta))
{

}

double TrigonometricFunctionValues::sin(int index) const{
    return sinValues[index];
}

double TrigonometricFunctionValues::cos(int index) const {
    return cosValues[index];
}

double TrigonometricFunctionValues::tan(int index) const {
    return tanValues[index];
}