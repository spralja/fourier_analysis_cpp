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
#include "LeakyBucket.hpp"
#include "Chunker.hpp"

#define DEBUG false

//std::cout << std::thread::hardware_concurrency() << std::endl;

//  important these are declared on the heap so it can be shared
auto *fa = new FourierAnalysis(1000, 100);
auto *coefficients = new CoefficientCollection(fa);
auto *outQueue = new codepi::ThreadSafeQueue<Result>();
auto *inQueue = new LeakyBucket();

std::mutex m;

void cleanUp () {
    delete fa;
    delete coefficients;
    delete outQueue;
}

void writeResultsToFile(std::string filename = "results.csv") {
    std::cout << "Results Calculated: " << outQueue->size() << std::endl;

    std::ofstream outfile("results.csv", std::ios::out | std::ios::app);
    outfile << "k,m,n,F,G" << std::endl;

    while (!outQueue->empty()) {
        outfile << serializeResult(outQueue->dequeue()) << std::endl;
    }

    outfile.close();
}

void JobRunner() {
    Triplet job;
    while (inQueue->leak(job)) {
        auto coeff = coefficients->get(job.k, job.n, job.m);
        //auto conj = coeff.conjugate();
        //outQueue->enqueue({-job.k, -job.n, -job.m, conj.F, conj.G});

        outQueue->enqueue({job.k, job.n, job.m, coeff.F, coeff.G});

        if (outQueue->size() >= 30) {
            if(m.try_lock()) {
                writeResultsToFile();
                m.unlock();
            }
        }
    }
}

int main() {
    const int num_threads = 4;
    const int maxValue = 99;

    inQueue->fill({-5, 0}, 10);

    std::thread threads[num_threads];

    // Start threads
    for (int i = 0; i < num_threads; i++) {
        threads[i] = std::thread([i] {
            if(DEBUG) std::cout << "Starting job (" << i << "): " << std::endl;
            
            JobRunner();
        
            if(DEBUG) std::cout << "Finished job (" << i << "): " << std::endl;
        });
    } 

    // Wait to close all threads
    for (int i = 0; i < num_threads; i++) {
        threads[i].join();
        if(DEBUG) std::cout << "Closed thread (" << i << "): " << std::endl;
    } 

    writeResultsToFile();
    cleanUp();

    return 0;
}

