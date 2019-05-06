#include "bits/stdc++.h"
using namespace std;

constexpr uint64_t num[] = { 120, 24, 6, 2, 1, 0, 0, 0 };

vector<int> ch[8];

char foo[8];
int vst[8];

char buf[16];

void process(int const k, vector<int> sl) {
  if (k == 5) {
    for (int i = 0; i < 5; ++i) {
      if (!vst[i]) {
        foo[k - 1] = 'A' + i;
        return;
      }
    }
    assert(false);
  }
  for (int i = 0; i < 5; ++i) {
    ch[i].clear();
    ch[i].reserve(32);
  }
  for (auto const r : sl) {
    int const p = r * 5 + k;
    cout << p << endl;
    fflush(stdout);
    cin >> buf[0];
    int const c = buf[0] - 'A';
    ch[c].push_back(r);
  }
  for (int i = 0; i < 5; ++i) {
    if (vst[i]) continue;
    if (ch[i].size() + 1 == num[k]) {
      foo[k - 1] = 'A' + i;
      vst[i] = 1;
      process(k + 1, ch[i]);
      return;
    }
  }
  foo[k - 1] = 0;
  assert(false);
}

int main() {
  int case_num, limits;
  cin >> case_num >> limits;
  for (int case_id = 1; case_id <= case_num; ++case_id) {
    for (int i = 0; i < 5; ++i) vst[i] = 0;
    vector<int> r(119, 0);
    for (int i = 0; i < 119; ++i) {
      r[i] = i;
    }
    process(1, r);
    foo[5] = 0;
    cout << foo << endl;;
    fflush(stdout);
    cin >> buf;
  }
  return 0;
}
