//
// Created by Robert on 05/12/2021.
//

#include <iostream>
#include "FourierAnalysis.h"
#include "Coefficient.h"
#include <chrono>
int main() {
    auto parent = FourierAnalysis(1000, 100);
    auto C2 = Coefficient(&parent, 2, 2, 2);
    auto C1 = Coefficient(&parent, 1, 1, 1);


    std::cout << "C1 = " << C1.getF() << std::endl;

    std::cout << "C2 = " << C2.getF() << std::endl;

    return 0;
}