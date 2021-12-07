//
// Created by Robert on 07/12/2021.
//

#include "Coefficient.h"
#include "FourierAnalysis.h"

std::list<std::pair<double, double>> Coefficient::values = std::list<std::pair<double, double>>();

const std::pair<double, double>& Coefficient::calculateValue(const int& k, const int& n, const int& m) {
    values.emplace_back();
    return values.back();
}


Coefficient::Coefficient(FourierAnalysis *parent, const int &k, const int &n, const int &m)
    : parent(parent)
    , value(calculateValue(k, n, m))
{}

const double& Coefficient::getF() const {
    return value.first;
}

const double& Coefficient::getG() const {
    return value.second;
}
