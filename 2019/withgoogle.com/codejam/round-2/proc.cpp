#include "bits/stdc++.h"
using namespace std;

//NUMBERIC
template<class T> inline T GCD(const T x, const T y){
  if(x<0)return GCD(-x, y);
  if(y<0)return GCD(x, -y);
  return (!y)?x:GCD(y, x%y);
}

constexpr int64_t inf = 0x3f3f3f3f3f3f3f3fLL;

struct foo_t {
  int c, j, p;
} a[512];

struct bar_t {
  int64_t x, y;
  bar_t(int64_t const& lhs, int64_t const& rhs) : x(lhs), y(rhs) { }
  bool operator < (bar_t const& rhs) {
    if (y * rhs.y > 0) {
      return x * rhs.y < y * rhs.x;
    } else {
      return x * rhs.y > y * rhs.x;
    }
  }
  void update() {
    int64_t g = GCD(x, y);
    x /= g;
    y /= g;
  }
};

int n;
unordered_set<string> bar;

int main() {
  int case_num;
  scanf("%d", &case_num);
  for (int case_id = 1; case_id <= case_num; ++case_id) {
    bar.clear();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", &a[i].c, &a[i].j);
      a[i].p = i;
    }
    int err = 0;
    bar_t lt(inf, 1), gt(1, inf);
    auto const lambda = [&lt, &gt, &err](foo_t const& lhs, foo_t const& rhs) {
      int64_t const dx = lhs.c - rhs.c;
      int64_t const dy = lhs.j - rhs.j;
      if (dx == 0) {
        err += (dy < 0) ? 0 : 1;
        return false;
      }
      if (dy == 0) {
        err += (dx < 0) ? 0 : 1;
        return false;
      }
      if (dx > 0 && dy > 0) {
        ++err;
        return false;
      }
      bar_t cur(-dy, dx);
      if (dx > 0) {
        if (cur < lt) lt = cur;
      } else {
        if (gt < cur) gt = cur;
      }
      return true;
    };
    for (int i = 0; i + 1 < n; ++i) {
      if (!lambda(a[i], a[i + 1]) && err != 0) break;
    }
    gt.update();
    lt.update();
    if (err == 0 && gt < lt && lt.x * lt.y > 0) {
      if (gt.x == 1 && gt.y == inf) {
        printf("Case #%d: 1 %lld\n", case_id, lt.y / lt.x + 1);
      } else if (lt.x == inf && lt.y == 1) {
        printf("Case #%d: %lld 1\n", case_id, gt.x / gt.y + 1);
      } else {
        for (int64_t wc = 1; wc <= 10000; ++wc) {
          bool comp = false;
          for (int64_t wj = 1; wj <= 10000; ++wj) {
            bar_t cur(wc, wj);
            if (gt < cur && cur < lt) {
              printf("Case #%d: \n", case_id);
              comp = true;
              break;
            }
          }
          if (comp) break;
        }
      }
    } else {
      printf("Case #%d: IMPOSSIBLE\n", case_id);
    }
  }
  return 0;
}
