//
// Created by Robert on 07/12/2021.
//

#ifndef FOURIER_ANALYSIS_CPP_COEFFICIENTCOLLECTION_H
#define FOURIER_ANALYSIS_CPP_COEFFICIENTCOLLECTION_H

#include <list>
#include <vector>

#include "Coefficient.h"

class FourierAnalysis;

class CoefficientCollection {
private:
    const FourierAnalysis* parent;
    std::list<Coefficient> coefficientList;
    std::vector<Coefficient*> coefficients;

public:
    CoefficientCollection(const FourierAnalysis* parent);

    const Coefficient& get(const int& k, const int& n, const int& m);

private:
    int hash(const int& k, const int& n, const int& m) const;
};


#endif //FOURIER_ANALYSIS_CPP_COEFFICIENTCOLLECTION_H
