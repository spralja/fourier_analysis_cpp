//
// Created by Robert on 07/12/2021.
//

#include <iostream>
#include "CoefficientCollection.h"
#include "FourierAnalysis.h"
#include "Coefficient.h"

CoefficientCollection::CoefficientCollection(const FourierAnalysis* parent): parent(parent) {
    const int& z_size = parent->z_size;

    coefficientList = std::list<Coefficient>();

    coefficients = std::vector<Coefficient*>(z_size * z_size * z_size, nullptr);
    coefficients.reserve(z_size * z_size * z_size);
}

const Coefficient& CoefficientCollection::get(const int &k, const int &n, const int &m) {
    const int& hash = this->hash(k, n, m);
    if(coefficients[hash] == nullptr) {
        const Coefficient C = parent->C(k, n, m);
        coefficientList.emplace_back(C);
        coefficients[hash] = &coefficientList.back();

        const Coefficient C_ = C.conjugate();
        coefficientList.push_back(C_);
        coefficients[this->hash(-k, -n, -m)] = &coefficientList.back();
    }

    return *coefficients[hash];
}

int CoefficientCollection::hash(const int &k, const int &n, const int &m) const {
    const int& n_sigma = parent->n_sigma;
    const int& z_end = parent->z_end;

    return (k + n_sigma) * z_end * z_end + (n + n_sigma) * z_end + (m + n_sigma);
}

