#include "bits/stdc++.h"
using namespace std;

struct foo_t {
  int c, j, p;
} a[512];

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
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        sort(a, a + n,
             [](foo_t const& lhs, foo_t const& rhs) {
                 return lhs.p < rhs.p;
             });
        int64_t dx = a[i].c - a[j].c;
        int64_t dy = a[i].j - a[j].j;
        //fprintf(stderr, "(%d, %d) < (%d, %d)\n", a[i].c, a[i].j, a[j].c, a[j].j);
        int err = 0;
        auto const lambda = [dx, dy, &err](foo_t const& lhs, foo_t const& rhs) {
          int64_t x = lhs.c - rhs.c;
          int64_t y = lhs.j - rhs.j;
          if (x == 0) return y < 0;
          if (y == 0) return x < 0;
          if (x * y > 0) {
            return x < 0;
          }
          if (dx * -dy <= 0) {
            /* fprintf(stderr,
                    "(%d, %d, %d) ? (%d, %d, %d)\n",
                    lhs.c, lhs.j, lhs.p,
                    rhs.c, rhs.j, rhs.p); */
            ++err;
            return lhs.p < rhs.p;
          }
          if (x * dy == y * dx) {
            return x * dy > 0;
          }
          //return x * -dy <= -y * dx;
          if (dx > 0) {
            return x * -dy < -y * dx;
          } else {
            return x * -dy > -y * dx;
          }
        };
        sort(a, a + n, lambda);
        for (int k = 0; k + 1 < n; ++k) {
          if (!lambda(a[k], a[k + 1])) {
            /* if (true) {
              fprintf(stderr,
                      "? (%d, %d) (%d, %d) based on dx = %lld, dy = %lld\n",
                      a[k].c, a[k].j, a[k + 1].c, a[k + 1].j,
                      dx, dy);
            } */
            ++err;
          }
        }
        if (err == 0) {
          stringstream ss;
          for (int k = 0; k < n; ++k) {
            //fprintf(stderr, " (%d, %d)", a[k].c, a[k].j);
            ss << '&' << a[k].p;
          }
          //fprintf(stderr, " based on dx = %lld, dy = %lld\n", dx, dy);
          bar.insert(ss.str());
        } else {
          // fprintf(stderr, "err = %d\n", err);
        }
      }
    }
    printf("Case #%d: %zu\n", case_id, bar.size());
  }
  return 0;
}
