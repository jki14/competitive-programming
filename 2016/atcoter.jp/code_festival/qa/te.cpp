#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1234567;
 
int z[N];
int a[N];
int pos[N];
int at[N];
 
int main() {
  int n, m, q;
  scanf("%d %d", &n, &m);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", z + i);
    z[i]--;
  }
  for (int i = 0; i < m; i++) {
    a[i] = -1;
    pos[i] = -1;
    at[i] = 0;
  }
  int known = 0;
  at[0] = n;
  at[m] = 0;
  for (int it = q - 1; it >= 0; it--) {
    int i = z[it];
    if (pos[i] == -1) {
      a[known] = i;
      pos[i] = known;
      at[known]--;
      known++;
      at[known]++;
      continue;
    }
    if (at[pos[i]] > 0) {
      at[pos[i]]--;
      at[pos[i] + 1]++;
    }
  }
  int first = -1;
  for (int i = 0; i <= m; i++) {
    if (at[i] > 0) {
      first = i;
      break;
    }
  }
  vector <int> all;
  for (int i = first; i < known; i++) {
    all.push_back(a[i]);
  }
  for (int i = 0; i < m; i++) {
    if (pos[i] == -1) {
      all.push_back(i);
    }
  }
  sort(all.begin(), all.end());
  for (int i = first; i < known; i++) {
    if (all[i - first] != a[i]) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}
