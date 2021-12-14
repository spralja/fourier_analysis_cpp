#include <iostream>
#include <sstream>
#include "LeakyBucket.hpp"

using namespace std;
int main() {
    std::string line = "1,3,-10,0,1";
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

    std::cout << index << std::endl;

    std::stringstream ss;
    ss << 1 << 3 << -10;

    cout << ss.str() << endl;

    LeakyBucket lb;

    lb.fill({0, 5}, 10, "jeff.csv");

    Triplet T;
    while(lb.leak(T)) {
        //std::cout << T.k << " - " << T.n << " - " << T.m << " - " << std::endl;
    }

  return 0;
}