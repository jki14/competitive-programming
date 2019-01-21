// Sample input 1, in CPP.

#include <cassert>

long long GetIndex() {
  return 1LL;
}

long long GetMultiplier(long long index) {
  switch ((int)index) {
    case 0: return 1LL;
    default: assert(0);
  }
}
