#ifndef RESULT_TYPE
#define RESULT_TYPE

#include <string>

#include <sstream>

struct Result {
  int k;
  int n;
  int m;

  double F;
  double G;
};

std::string serializeResult(Result r) {
  std::stringstream str;
  
  str << r.k << ',' << r.m << ',' << r.n << ',' << r.F << ',' << r.G;

  return str.str();
}

#endif