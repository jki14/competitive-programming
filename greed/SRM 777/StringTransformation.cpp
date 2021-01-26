#include "bits/stdc++.h"
using namespace std;

int f[2600][2600];

class StringTransformation {
public:
  string getResult(string const& lhs_, string const& rhs_) {
    vector<pair<char, int>> lhs, rhs;
    static const auto enroll = [](string const& foo,
                                      vector<pair<char,int>> &bar) -> void {
      bar.reserve(foo.length());
      bar.clear();
      for (auto const chr : foo) {
        if (!bar.empty() && bar.back().first == chr) {
          ++bar.back().second;
        } else {
          bar.emplace_back(chr, 1);
        }
      }
    };
    enroll(lhs_, lhs);
    enroll(rhs_, rhs);
    int n = lhs.size();
    int m = rhs.size();
    if (m == 1) {
      return lhs_ == rhs_ ? "YES" : "NO";
    }
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        f[i][j] = 0;
      }
    }
    static const auto match = [](pair<char, int> const& lhs,
                                     pair<char, int> const& rhs) -> int {
      if (lhs.first != rhs.first) return 0;
      if (lhs.second < rhs.second) return 0;
      if ((lhs.second & 1) != (rhs.second & 1)) return 0;
      return 1;
    };
    static const auto bic = [](char const c) -> int {
      if (c == 'R') return 1;
      if (c == 'G') return 2;
      return 4;
    };
    f[1][1] = match(lhs.front(), rhs.front());
    for (int j = 1; j < m; ++j) {
      int mask = 0;
      for (int i = 1; i < n; ++i) {
        if (lhs[i - 1].second & 1) {
          mask = 0;
        } else if (mask) {
          mask |= bic(lhs[i - 1].first);
        }
        if (f[i][j]) {
          if (match(lhs[i], rhs[j])) f[i + 1][j + 1] = 1;
          if (!mask) {
            mask = bic(lhs[i - 1].first);
          }
        };
        // fprintf(stderr, "f[%d][%d] = %d, mask = %d\n", i, j, f[i][j], mask);
        if (match(lhs[i], rhs[j]) && (mask | bic(lhs[i].first)) == 7) {
          f[i + 1][j + 1] = 1;
        }
      }
    }
    return f[n][m] ? "YES" : "NO";
  }
};

int main() {
  StringTransformation foo;
  assert("YES" == foo.getResult("RGBRGGRRBGB", "RGBRBGB"));
  return 0;
}
