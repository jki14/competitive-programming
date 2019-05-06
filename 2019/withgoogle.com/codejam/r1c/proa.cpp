#include "bits/stdc++.h"
using namespace std;

constexpr char rps[] = { 'R', 'P', 'S' };
constexpr int m = 500;

struct node_t {
  node_t* nxt[3];
  void clear() {
    nxt[0] = nullptr;
    nxt[1] = nullptr;
    nxt[2] = nullptr;
  }
  int count() {
    int foo = 0;
    for (int i = 0; i < 3; ++i) {
      if (nxt[i] != nullptr) ++foo;
    }
    return foo;
  }
  int undefeat() {
    for (int i = 0; i < 3; ++i) {
      if (nxt[i] != nullptr && nxt[(i + 2) % 3] != nullptr) return i;
    }
    return -1;
  }
  int winner() {
    for (int i = 0; i < 3; ++i) {
      if (nxt[(i + 2) % 3] != nullptr) return i;
    }
    return -1;
  }
} pool[210000], *root, *last;

int n;
char buf[512];
int arr[512];
char foo[512];

int main() {
  int case_num;
  scanf("%d", &case_num);
  for (int case_id = 1; case_id <= case_num; ++case_id) {
    scanf("%d", &n);
    last = pool;
    root = last;
    last->clear();
    ++last;
    for (int i = 0; i < n; ++i) {
      scanf("%s", buf);
      int l = strlen(buf);
      for (int j = 0; j < l; ++j) {
        static unordered_map<char, int> c2i{{'R', 0}, {'P', 1}, {'S', 2}};
        arr[j] = c2i[buf[j]];
      }
      node_t* node = root;
      for (int p = 0; p < m; ++p) {
        int const k = arr[p % l];
        if (node->nxt[k] == nullptr) {
          node->nxt[k] = last;
          last->clear();
          ++last;
        }
        node = node->nxt[k];
      }
    }
    foo[500] = '?';
    node_t* node = root;
    for (int i = 0; i < 500; ++i){
      int const cnt = node->count();
      if (cnt == 3 || cnt == 0) {
        break;
      } else if (cnt == 2) {
        int const k = node->undefeat();
        foo[i] = rps[k];
        node = node->nxt[k];
      } else if (cnt == 1) {
        foo[i] = rps[node->winner()];
        foo[i + 1] = 0;
        foo[500] = 0;
        break;
      }
    }
    if (foo[500] != '?') {
      printf("Case #%d: %s\n", case_id, foo);
    } else {
      printf("Case #%d: IMPOSSIBLE\n", case_id);
    }
  }
  return 0;
}
