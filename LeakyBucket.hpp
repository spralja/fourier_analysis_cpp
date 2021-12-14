#ifndef LEAKY_BUCKET
#define LEAKY_BUCKET

#include "ThreadSafeQueue.h"
#include <string>
#include <unordered_map>


struct Triplet {
  int k;
  int n;
  int m;
};

typedef std::string string;

class LeakyBucket {
private:
    codepi::ThreadSafeQueue<Triplet> bucket;

public:
    LeakyBucket() = default;

    void fill(std::pair<int, int> bounds, int maxValue, const string& infile = "results.csv") {
        //                  vvv Can probably be a better type
        std::unordered_map<string, bool> alreadyComputedMap;
        std::ifstream alreadyComputedFile(infile);

        if( alreadyComputedFile.is_open() ) {
            bool firstLine = true;

            for(string line; getline(alreadyComputedFile, line); ) {
                if (firstLine) { firstLine = false; continue; }

                unsigned long pos = 0;
                pos = line.find(',');
                string index = line.substr(0, pos);
                line.erase(0, pos += 1);

                pos = line.find(',');
                index += line.substr(0, pos);
                line.erase(0, pos += 1);

                pos = line.find(',');
                index += line.substr(0, pos);
                line.erase(0, pos += 1);

                alreadyComputedMap[index] = true;
            }
        }

        alreadyComputedFile.close();

        for(int k = bounds.first; k <= bounds.second; k++) {
            for(int n = -maxValue; n <= maxValue; n++) {
                for(int m = 1; m <= maxValue; m++) {
                    std::stringstream ss;
                    ss << k << n << m;

                    auto finder = alreadyComputedMap.find(ss.str());

                    if (finder != alreadyComputedMap.end()) {
                        this->bucket.enqueue({k, n, m});
                    }
                }
            }
        }

        for(int k = bounds.first; k <= bounds.second; k++) {
            for(int n = 1; n <= maxValue; n++) {
                std::stringstream ss;
                ss << k << n << 0;

                auto finder = alreadyComputedMap.find(ss.str());

                if (finder != alreadyComputedMap.end()) {
                    this->bucket.enqueue({k, n, 0});
                }
            }
        }

        for(int k = std::max(1, bounds.first); k <= bounds.second; k++) {
            std::stringstream ss;
            ss << k << 0 << 0;

            auto finder = alreadyComputedMap.find(ss.str());

            if (finder != alreadyComputedMap.end()) {
                this->bucket.enqueue({k, 0, 0});
            }
        }
    }

    bool leak(Triplet& returnVal) {
        return this->bucket.dequeue(0.1, returnVal);
    }
};

#endif