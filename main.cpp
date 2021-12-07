//
// Created by Robert on 05/12/2021.
//

#include <iostream>
#include "FourierAnalysis.h"
#include "Coefficient.h"
#include "CoefficientCollection.h"
#include <chrono>
int main() {
    auto fa = FourierAnalysis(1000, 100);
    auto coefficients = CoefficientCollection(&fa);
    std::cout << coefficients.get(1, 1, 1).F << std::endl;
    std::cout << coefficients.get(1, 1, 1).G << std::endl;
    return 0;
}