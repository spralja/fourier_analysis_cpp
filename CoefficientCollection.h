//
// Created by Robert on 07/12/2021.
//

#ifndef FOURIER_ANALYSIS_CPP_COEFFICIENTCOLLECTION_H
#define FOURIER_ANALYSIS_CPP_COEFFICIENTCOLLECTION_H

#include <unordered_map>
#include <string>

#include "Coefficient.h"

class FourierAnalysis;

class CoefficientCollection {
private:
    const FourierAnalysis* parent;
    mutable std::unordered_map<std::string, Coefficient*> coefficients;

public:
    explicit CoefficientCollection(const FourierAnalysis* parent);
    ~CoefficientCollection();

    const Coefficient& get(const int& k, const int& n, const int& m) const;

private:
    static std::string hash(const int& k, const int& n, const int& m) ;
};


#endif //FOURIER_ANALYSIS_CPP_COEFFICIENTCOLLECTION_H
