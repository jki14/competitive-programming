// Sample input 3, in CPP.

#include <cassert>

long long GetNumSegments() {
  return 4LL;
}

long long GetSafeDistance() {
  return 1LL;
}

long long GetPosition(long long airplane, long long i) {
  if (airplane == 0 && i == 0) return 10485770LL;
  if (airplane == 0 && i == 1) return 9437194LL;
  if (airplane == 0 && i == 2) return 8388618LL;
  if (airplane == 0 && i == 3) return 7340042LL;
  if (airplane == 0 && i == 4) return 10LL;
  if (airplane == 1 && i == 0) return 10485770LL;
  if (airplane == 1 && i == 1) return 3145738LL;
  if (airplane == 1 && i == 2) return 3145739LL;
  if (airplane == 1 && i == 3) return 2097163LL;
  if (airplane == 1 && i == 4) return 1048587LL;
  assert(0);
}

long long GetTime(long long airplane, long long i) {
  if (airplane == 0 && i == 0) return 1LL;
  if (airplane == 0 && i == 1) return 1LL;
  if (airplane == 0 && i == 2) return 1LL;
  if (airplane == 0 && i == 3) return 7LL;
  if (airplane == 1 && i == 0) return 7LL;
  if (airplane == 1 && i == 1) return 1LL;
  if (airplane == 1 && i == 2) return 1LL;
  if (airplane == 1 && i == 3) return 1LL;
  assert(0);
}
