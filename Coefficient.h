//
// Created by Robert on 07/12/2021.
//

#ifndef FOURIER_ANALYSIS_CPP_COEFFICIENT_H
#define FOURIER_ANALYSIS_CPP_COEFFICIENT_H

#include <utility>
#include <list>

class FourierAnalysis;

class Coefficient {
private:
    static std::list<std::pair<double, double>> values;

    const FourierAnalysis* parent;

    const std::pair<double, double>& value;

    const std::pair<double, double>& calculateValue(const int& k, const int& n, const int& m) ;
public:


    explicit Coefficient(FourierAnalysis* parent, const int& k, const int& n, const int& m);

    const double& getF() const;
    const double& getG() const;
};


#endif //FOURIER_ANALYSIS_CPP_COEFFICIENT_H
