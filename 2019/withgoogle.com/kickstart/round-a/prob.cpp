#include "bits/stdc++.h"
using namespace std;

static constexpr int dx[4] = { 0, -1, 0, 1 };
static constexpr int dy[4] = { 1, 0, -1, 0 };

int r, c;
int a[256][256], d[256][256];
char foo[256];

struct tri_t {
  int x, y, w;
  tri_t(int const _x, int const _y, int const _w) {
    x = _x;
    y = _y;
    w = _w;
  }
};

int check(int const w) {
  for (int i = 0; i < r; ++i) {
    int lef = 0, rig = c - 1;
    for (int x = 0; x < r; ++x) {
      for (int y = 0; y < c; ++y) {
        if (d[x][y] <= w) continue;
        int const h = w - abs(x - i);
        if (h < 0) {
          rig = -1;
          break;
        }
        lef = max(lef, y - h);
        rig = min(rig, y + h);
      }
      if (lef > rig) break;
    }
    if (lef <= rig) return 1;
  }
  return 0;
}

int midpoint() {
  int lef = 0, rig = r + c;
  while (lef < rig) {
    int const mid = (lef + rig) >> 1;
    if (check(mid)) {
      rig = mid;
    } else {
      lef = mid + 1;
    }
  }
  return rig;
}

int solution() {
  queue<tri_t> q;
  for (int x = 0; x < r; ++x) {
    for (int y = 0; y < c; ++y) {
      if (a[x][y]) {
        d[x][y] = 0;
        q.push({x, y, 0});
      }
    }
  }
  for (; !q.empty(); q.pop()) {
    int const x = q.front().x;
    int const y = q.front().y;
    int const w = q.front().w;
    for (int i = 0; i < 4; ++i) {
      int const nx = x + dx[i];
      int const ny = y + dy[i];
      int const nw = w + 1;
      if (nx < 0 || nx >= r) continue;
      if (ny < 0 || ny >= c) continue;
      if (a[nx][ny]) continue;
      a[nx][ny] = 1;
      d[nx][ny] = nw;
      q.push({nx, ny, nw});
    }
  }
  return midpoint();
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    scanf("%d%d", &r, &c);
    for (int x = 0; x < r; ++x) {
      scanf("%s", foo);
      for (int y = 0; y < c; ++y) {
        a[x][y] = foo[y] == '1';
      }
    }
    printf("Case #%d: %d\n", i + 1, solution());
  }
  return 0;
}
