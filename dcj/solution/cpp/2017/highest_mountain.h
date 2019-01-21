// Sample input 3, in CPP.

#include <cassert>

int NumberOfPeaks() {
  return 1;
}

int GetHeight(long long i) {
  switch ((int)i) {
    case 0: return 1;
    case 1: return 2;
    case 2: return 3;
    case 3: return 4;
    case 4: return 5;
    case 5: return 4;
    case 6: return 3;
    case 7: return 2;
    case 8: return 1;
    default: assert(0);
  }
}
