#ifndef RESULT_TYPE
#define RESULT_TYPE

#include <string>
#include <sstream>

struct Result {
  int k, m, n;
  double F, G;
};

std::string deserializeResult(Result r) {
  std::ostringstream sstream;
  
  sstream << r.k << ',' << r.m << ',' << r.n << '=' << r.F << ',' << r.G;

  return sstream.str();
}

#endif