//
// Created by Robert on 05/12/2021.
//

#include <iostream>
#include "FourierAnalysis.h"
#include <chrono>
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    auto C = FourierAnalysis(10000, 1).C(1, 1, 1);
    std::cout << C.first << ", " << C.second << std::endl;
    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << duration.count() << std::endl;
    return 0;
}