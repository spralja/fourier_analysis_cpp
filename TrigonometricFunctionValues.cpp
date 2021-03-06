//
// Created by Robert on 05/12/2021.
//

#include <iostream>
#include "TrigonometricFunctionValues.h"
#include "FourierAnalysis.h"

std::vector<double> TrigonometricFunctionValues::getSinValues() const {
    std::vector<double> _sinValues = std::vector<double>();
    _sinValues.reserve(parent->n_beta);
    for(int i = 0; i < parent->n_beta; ++i)
        _sinValues.push_back(std::sin(parent->beta(i)));

    return _sinValues;
}

std::vector<double> TrigonometricFunctionValues::getCosValues() const {
    std::vector<double> _cosValues = std::vector<double>();
    _cosValues.reserve(parent->n_beta);
    for(int i = 0; i < parent->n_beta; ++i)
        _cosValues.push_back(std::cos(parent->beta(i)));

    return _cosValues;
}

std::vector<double> TrigonometricFunctionValues::getTanValues() const {
    std::vector<double> _tanValues = std::vector<double>();
    _tanValues.reserve(parent->n_beta);
    for(int i = 0; i < parent->n_beta; ++i)
        _tanValues.push_back(std::tan(parent->beta(i)));

    return _tanValues;
}

TrigonometricFunctionValues::TrigonometricFunctionValues(FourierAnalysis* _parent):
    parent(_parent),
    sinValues(getSinValues()),
    cosValues(getCosValues()),
    tanValues(getTanValues())
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