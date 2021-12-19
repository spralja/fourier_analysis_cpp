//
// Created by Robert on 07/12/2021.
//

#include <iostream>
#include "CoefficientCollection.h"
#include "FourierAnalysis.h"

CoefficientCollection::CoefficientCollection(const FourierAnalysis* parent):
    parent(parent){
    coefficients.reserve(parent->z_size * parent->z_size * parent->z_size);
}

const Coefficient& CoefficientCollection::get(const int &k, const int &n, const int &m) const {
    const std::string hash = this->hash(k, n, m);
    if(coefficients[hash] == nullptr)
        coefficients[hash] = new Coefficient(parent->C(k, n, m));
    return *coefficients[hash];
}

estd::string CoefficientCollection::hash(const int &k, const int &n, const int &m) {
    return std::to_string(k) + " " + std::to_string(n) + " " + std::to_string(m);
}

CoefficientCollection::~CoefficientCollection() {
    for(auto& coefficient : coefficients)
        delete coefficient.second;
}

