#ifndef CHUNKER_H
#define CHUNKER_H

#include <utility>

std::pair<int, int>* Chunker(int max, int segments) {
  int min = -max;
  int cutoff = ((max - min) / segments);
  int count = 0;
  int which = 0;
  int last = min;

  std::pair<int, int> *result = new std::pair<int, int>[segments];

  for(int i = min; i < max; i++) {
    if (count++ == cutoff) {
      count = 0;
      result[which++] = std::pair<int, int>(last, i);
      last = i + 1;
    }
  }

  if (last != max) {
    result[which] = std::pair<int, int>(last, max);
  }

  return result;
}

#endif