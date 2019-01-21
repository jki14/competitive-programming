// Sample input 2, in CPP.

#include <cassert>

long long GetLength() {
  return 3LL;
}

char GetScrollOne(long long i) {
  switch ((int)i) {
    case 0: return 'B';
    case 1: return 'A';
    case 2: return 'A';
    default: assert(0);
  }
}

char GetScrollTwo(long long i) {
  switch ((int)i) {
    case 0: return 'A';
    case 1: return 'B';
    case 2: return 'A';
    default: assert(0);
  }
}
