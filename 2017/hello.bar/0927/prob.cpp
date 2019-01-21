#include "bits/stdc++.h"
using namespace std;

#define N 11000
int n;
int x[N], y[N];

struct node_t {
    int x, y, lab;
    node_t(int _x = 0, int _y = 0, int _lab = 0):x(_x),y(_y),lab(_lab){}
    bool operator < (const node_t &B) const {
        return (x > B.x || (x == B.x && y > B.y)); 
    }
} s[N];

struct edge_t {
    int from, to, len;
    edge_t(int _from = 0, int _to = 0, int _len = 0):from(_from),to(_to),len(_len){}
    bool operator < (const edge_t &B) const {
        return len < B.len;
    }
}edge[N << 2];
int top;

int sa[N], pos[N], change[N];
inline bool cmp(const int &a, const int &b) {
    return s[a].y - s[a].x > s[b].y - s[b].x;
}

int a[N];
int ask(int p) {
    int res = 0;
    for(; p; p -= p & -p)
        if (s[change[res]].x + s[change[res]].y > s[change[a[p]]].x + s[change[a[p]]].y)
            res = a[p];
    return res;
}
void modify(int p, int ins) {
    for(; p <= n; p += p & -p)
        if (s[change[ins]].x + s[change[ins]].y < s[change[a[p]]].x + s[change[a[p]]].y)
            a[p] = ins;
}

void add_edge() {
    register int i, j, k;
    
    for(i = 1; i <= n; ++i)
        sa[i] = i;
    sort(sa + 1, sa + n + 1, cmp);
    int id = 0;
    for(i = 1; i <= n; ) {
        for(j = i; s[sa[j]].y - s[sa[j]].x == s[sa[j + 1]].y - s[sa[j + 1]].x && j < n; ++j);
        ++id;
        for(k = i; k <= j; ++k)
            pos[sa[k]] = id;
        i = j + 1;
    }
    
    sort(s + 1, s + n + 1);
    for(i = 1; i <= n; ++i)
        change[s[i].lab] = i;
    
    memset(a, 0, sizeof(a));
    for(i = 1; i <= n; ++i) {
        int get = ask(pos[s[i].lab]);
        if (get != 0)
            edge[++top] = edge_t(s[i].lab, get, abs(x[s[i].lab] - x[get]) + abs(y[s[i].lab] - y[get]));
        modify(pos[s[i].lab], s[i].lab);
    }
}

int root[N];
void reset() {
    for(int i = 1; i <= n; ++i)
        root[i] = i;
}
int find(int x) {
    int q = x, tmpq;
    for(; x != root[x]; x = root[x]);
    for(; q != x; q = tmpq)
        tmpq = root[q], root[q] = x;
    return x;
}
long long mst() {
    sort(edge + 1, edge + top + 1);
    reset();
    register int i;
    int ra, rb, intree = 0;
    long long res = 0;
    for(i = 1; i <= top; ++i) {
        ra = find(edge[i].from);
        rb = find(edge[i].to);
        if (ra != rb) {
            root[ra] = rb;
            res += edge[i].len;
            if (++intree == n - 1)
                return res;
        }
    }
    return -1;
}

int main() {
    while(scanf("%d", &n)!=EOF){

        top=0;

        for(int i = 1; i <= n; ++i)
            scanf("%d%d", &x[i], &y[i]);
        
        s[0].x = s[0].y = 0x3f3f3f3f;
    
        for(int i = 1; i <= n; ++i)
            s[i] = node_t(x[i], y[i], i);
        add_edge();
    
        for(int i = 1; i <= n; ++i)
            s[i] = node_t(y[i], x[i], i);
        add_edge();
    
        for(int i = 1; i <= n; ++i)
            s[i] = node_t(-y[i], x[i], i);
        add_edge();
    
        for(int i = 1; i <= n; ++i)
            s[i] = node_t(x[i], -y[i], i);
        add_edge();
    
        printf("%lld\n", mst()*2);
    }
    
    return 0;
}
