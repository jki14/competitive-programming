// Sample input 3, in CPP.

#include <cassert>

long long GetNecklaceLength() {
  return 5LL;
}

long long GetMessageLength() {
  return 8LL;
}

int GetNecklaceElement(long long index) {
  switch ((int)index) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 0;
    case 3: return 2;
    case 4: return 0;
    default: assert(0);
  }
}

int GetMessageElement(long long index) {
  switch ((int)index) {
    case 0: return 0;
    case 1: return 0;
    case 2: return 0;
    case 3: return 1;
    case 4: return 2;
    case 5: return 0;
    case 6: return 0;
    case 7: return 0;
    default: assert(0);
  }
}
