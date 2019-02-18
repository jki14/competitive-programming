#include "bits/stdc++.h"
using namespace std;

int n, m, k;
int x[110000];
int y[110000];

int main() {
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    int len = max(n, m);
    for (int i = 0; i < len; ++i) x[i] = y[i] = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x[len - n + i]);
    }
    for (int i = 0; i < m; ++i) {
      scanf("%d", &y[len - m + i]);
    }
    int same = 1;
    for (int i = 0; i < len; ++i) {
      if (x[i] != y[i]) {
        if (x[i] < y[i]) {
          printf("X\n");
        } else {
          printf("Y\n");
        }
        same = 0;
        break;
      }
    }
    if (same) {
      printf("Same\n");
    }
  }
  return 0;
}
