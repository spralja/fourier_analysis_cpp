//
// Created by Robert on 05/12/2021.
//

#include <iostream>
#include "FourierAnalysis.h"
#include "Coefficient.h"
#include "CoefficientCollection.h"
#include "result.hpp"
#include "ThreadSafeQueue.h"
#include <chrono>
#include <thread>

//  important it is declared on the heap
auto fa = new FourierAnalysis(1000, 100);
auto coefficients = new CoefficientCollection(fa);
auto outQueue = new codepi::ThreadSafeQueue<Result>();

void cleanUp () {
    delete fa;
    delete coefficients;
    delete outQueue;
}

void JobRunner(int lowerBound, int upperBound) {
    for(int k = lowerBound; k <= upperBound; k++) {
        for(int m = lowerBound; m <= upperBound; m++) {
            for(int n = lowerBound; n <= upperBound; n++) {
                auto coeff = coefficients->get(k, m, n);

                outQueue->enqueue({k, m, n, coeff.F, coeff.G});
            }
        }
    }
}

int main() {
    const int num_threads = 8;
    const int minValue = -50;
    const int maxValue = 50;

    std::thread threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        threads[i] = std::thread(JobRunner, 0, 10);
    } 

    for (int i = 0; i < num_threads; i++) {
        threads[i].join();
    } 

    while (!outQueue->empty()) {
        auto R = outQueue->dequeue();
        // Change this to output to file
        std::cout << deserializeResult(R) << std::endl;
    }

    cleanUp();

    return 0;
}

