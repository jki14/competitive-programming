#include "bits/stdc++.h"
using namespace std;

//NUMBERIC
template<class T> inline T GCD(const T x, const T y){
  if(x<0)return GCD(-x, y);
  if(y<0)return GCD(x, -y);
  return (!y)?x:GCD(y, x%y);
}

struct foo_t {
  int c, j;
} a[512];

struct plsh {
  size_t operator() (pair<int64_t, int64_t> const& obj) const {
    return (obj.first << 30) + obj.second;
  }
};

int n;
unordered_set<pair<int64_t, int64_t>, plsh> bar, che;

int main() {
  int case_num;
  scanf("%d", &case_num);
  for (int case_id = 1; case_id <= case_num; ++case_id) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &a[i].c, &a[i].j);
    }
    bar.clear();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int64_t dx = a[i].c - a[j].c;
        int64_t dy = a[i].j - a[j].j;
        if (dx * dy >= 0) continue;
        dx = abs(dx);
        dy = abs(dy);
        auto const gv = GCD(dx, dy);
        bar.insert(make_pair(dx / gv, dy / gv));
      }
    }
    int ans = 0;
    for (auto const& el : bar) {
      /*fprintf(stderr, "====%lld, %lld====\n",
          static_cast<long long>(el.first),
          static_cast<long long>(el.second));*/
      che.clear();
      for (int i = 0; i < n; ++i) {
        /*fprintf(stderr, "+ (%d, %d) => (%lld, %lld)\n",
            a[i].c, a[i].j,
            static_cast<long long>(a[i].c * el.first + a[i].j * el.second),
            static_cast<long long>(a[i].c - a[i].j));*/
        che.insert(make_pair(a[i].c * el.first + a[i].j * el.second, a[i].c - a[i].j));
      }
      if (che.size() == static_cast<size_t>(n)) {
        ans += (ans != 0) ? 1 : 2;
      }
    }
    if (bar.empty()) ans = 1;
    printf("Case #%d: %d\n", case_id, ans);
  }
  return 0;
}
