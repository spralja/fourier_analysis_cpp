#include "Chunker.hpp"
#include "result.hpp"
#include <iostream>
using namespace std;
int main() {
  auto lol = Chunker(10, 2);

  cout << lol[0].first << " " << lol[0].second << endl;
  cout << lol[1].first << " " << lol[1].second << endl;

  Result x = {10, 20, 30, 10.0, 120.0};

  cout << serializeResult(x) << endl;


  return 0;
}