#include "bits/stdc++.h"
using namespace std;

int n, m;
int f[2600][2600], g[2600][2600];

class StringTransformation {
public:
  string getResult(string const& lhs, string const& rhs) {
    n = lhs.length();
    m = rhs.length();
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        f[i][j] = 0;
        g[i][j] = 0;
      }
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (lhs[i - 1] == rhs[j - 1]) {
          f[i][j] |= f[i - 1][j - 1];
          if (j > 1 && rhs[j - 1] != rhs[j - 2]) {
            f[i][j] |= g[i - 1][j - 1];
          }
          // fprintf(stderr, "f[%d][%d] = %d\n", i, j, f[i][j]);
        }
        if (i > 2 && lhs[i - 1] == lhs[i - 2]) {
          g[i][j] |= f[i - 2][j];
          g[i][j] |= g[i - 2][j];
          // fprintf(stderr, "g[%d][%d] = %d\n", i, j, g[i][j]);
        }
      }
    }
    if (f[n][m]) return "YES";
    return "NO";
  }
};

int main() {
  StringTransformation foo;
  assert("YES" == foo.getResult("RGGG", "RG"));
  return 0;
}
