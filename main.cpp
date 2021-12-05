//
// Created by Robert on 05/12/2021.
//

#include <iostream>
#include "FourierAnalysis.h"

int main() {
    auto C = FourierAnalysis(1000, 0).getC(1, 1, 1);
    std::cout << C.first << ", " << C.second << std::endl;
}