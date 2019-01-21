// Sample input 3, in CPP.

#include <cassert>

long long GetN() {
  return 6LL;
}

long long GetLeftNeighbour(long long i) {
  switch ((int)i) {
    case 0: return 3LL;
    case 3: return 1LL;
    case 1: return 4LL;
    case 4: return 5LL;
    case 5: return 2LL;
    case 2: return 0LL;
    default: assert(0);
  }
}

long long GetRightNeighbour(long long i) {
  switch ((int)i) {
    case 0: return 2LL;
    case 2: return 5LL;
    case 5: return 4LL;
    case 4: return 1LL;
    case 1: return 3LL;
    case 3: return 0LL;
    default: assert(0);
  }
}
