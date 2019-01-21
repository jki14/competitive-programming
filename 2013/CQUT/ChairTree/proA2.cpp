#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 100010;

struct Node {
    int L, R, sum;
};
Node T[MAXN * 20];
int T_cnt;

void insert(int &num, int &x, int L, int R) {
    T[T_cnt++] = T[x]; x = T_cnt - 1;
    ++T[x].sum;
    if(L == R) return ;
    int mid = (L + R) >> 1;
    if(num <= mid) insert(num, T[x].L, L, mid);
    else insert(num, T[x].R, mid + 1, R);
}

int query(int i, int j, int k, int L, int R) {
    if(L == R) return L;
    int t = T[T[j].L].sum - T[T[i].L].sum;
    int mid = (R + L) >> 1;
    if(k <= t) return query(T[i].L, T[j].L, k, L, mid);
    else return query(T[i].R, T[j].R, k - t, mid + 1, R);
}

struct A {
    int x, idx;
    bool operator < (const A &rhs) const {
        return x < rhs.x;
    }
};

A a[MAXN];
int rank[MAXN], root[MAXN];
int n, m;

int main() {
    T[0].L = T[0].R = T[0].sum = 0;
    root[0] = 0;
    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i].x);
            a[i].idx = i;
        }
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; ++i) rank[a[i].idx] = i;
        T_cnt = 1;
        for(int i = 1; i <= n; ++i) {
            root[i] = root[i - 1];
            insert(rank[i], root[i], 1, n);
        }
        while(m--) {
            int i, j, k;
            scanf("%d%d%d", &i, &j, &k);
            printf("%d\n", a[query(root[i - 1], root[j], k, 1, n)].x);
        }
    }
}
