//
// Created by Robert on 05/12/2021.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>

#include "FourierAnalysis.h"
#include "Coefficient.h"
#include "CoefficientCollection.h"
#include "ThreadSafeQueue.h"
#include "Result.hpp"
#include "Chunker.hpp"

#define DEBUG false

//std::cout << std::thread::hardware_concurrency() << std::endl;

//  important these are declared on the heap so it can be shared
auto fa = new FourierAnalysis(1000, 100);
auto coefficients = new CoefficientCollection(fa);
auto outQueue = new codepi::ThreadSafeQueue<Result>();

void cleanUp () {
    delete fa;
    delete coefficients;
    delete outQueue;
}

void JobRunner(std::pair<int, int> bounds, int maxValue, int thread) {
    for(int k = bounds.first; k <= bounds.second; k++) {
        for(int n = -maxValue; n <= maxValue; n++) {
            for(int m = 1; m <= maxValue; m++) {
                auto coeff = coefficients->get(k, n, m);

                outQueue->enqueue({k, n, m, coeff.F, coeff.G});
            }
        }
    }

    for(int k = bounds.first; k <= bounds.second; k++) {
        for(int n = 1; n <= maxValue; n++) {
            auto coeff = coefficients->get(k, n, 0);

            outQueue->enqueue({k, n, 0, coeff.F, coeff.G});
        }
    }

    for(int k = std::max(1, bounds.first); k <= bounds.second; k++) {
        auto coeff = coefficients->get(k, 0, 0);

        outQueue->enqueue({k, 0, 0, coeff.F, coeff.G});
    }
}

void writeResultsToFile(std::string filename = "results.csv") {
    std::cout << "Results Calculated: " << outQueue->size() << std::endl;

    std::ofstream outfile("results.csv", std::ios::out | std::ios::trunc);
    outfile << "k,m,n,F,G" << std::endl;

    while (!outQueue->empty()) {
        outfile << serializeResult(outQueue->dequeue()) << std::endl;
    }

    outfile.close();
}

int main() {
    const int num_threads = 4;
    const int maxValue = 99;

    std::thread threads[num_threads];

    // Print all the intervals
    auto intervals = Chunker(maxValue, num_threads);
    if (DEBUG) {
        for (int i = 0; i < num_threads; i++) {
            std::cout << intervals[i].first << " - " << intervals[i].second << std::endl;
        }
    }
    

    // Start threads
    for (int i = 0; i < num_threads; i++) {
        threads[i] = std::thread([intervals, maxValue, i] {
            if(DEBUG) std::cout << "Starting job (" << i << "): " << intervals[i].first << " - " << intervals[i].second << std::endl;
            
            JobRunner(intervals[i], maxValue, i);
        
            if(DEBUG) std::cout << "Finished job (" << i << "): " << intervals[i].first << " - " << intervals[i].second << std::endl;
        });
    } 

    // Wait to close all threads
    for (int i = 0; i < num_threads; i++) {
        threads[i].join();
        if(DEBUG) std::cout << "Closed thread (" << i << "): " << intervals[i].first << " - " << intervals[i].second << std::endl;
    } 

    writeResultsToFile();

    cleanUp();
    delete intervals;

    return 0;
}

