//============================================================================
// Name        : LinkCutTree
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 例为HDU4010(点权动态树),cmd1为连接操作,cmd2为切分操作,
//cmd3为统计路径总和操作,cmd4为查询路径上极值操作
//============================================================================

/** ` Micro Mezzo Macro Flation -- Overheated Economy ., **/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define FOR_C(i, a, b) for (int b____=int(b),i=a;i<b____;++i)
#define REP_1_C(i, n) for (int n____=int(n),i=1;i<=n____;++i)
#define DO(n) while(n--)
#define DO_C(n) int n____ = n; while(n____--)
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define Rush int T____; RD(T____); DO(T____)
//#pragma comment(linker, "/STACK:36777216")
#pragma GCC optimize ("O2")

template<class T> inline void RD(T &);
inline int RD(){ int x; RD(x); return x;}
template<class T> inline void OT(const T &);
template<class T> inline T& _RD(T &x){ RD(x); return x;}
inline void RS(char *s){scanf("%s", s);}
template<class T0, class T1> inline void RD(T0 &x0, T1 &x1){RD(x0), RD(x1);}
template<class T0, class T1, class T2> inline void RD(T0 &x0, T1 &x1, T2 &x2){RD(x0), RD(x1), RD(x2);}
template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T0, class T1, class T2, class T3> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3){RST(A0), RST(A1), RST(A2), RST(A3);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T> inline void CLR(T &A){A.clear();}
template<class T> inline void checkMax(T &a,const T b){if (b>a) a=b;}
inline int _1(int i){return 1<<i;}
template<class T> inline void RD(T &x){char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';}
template<class T> inline void OT(const T &x){printf("%d\n", x);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
/* .................................................................................................................................. */
const int N = 300009, M = 2 * N;

int l[N], r[N], p[N], w0[N], w1[N], delay[N], rev[N]; bool rt[N];
// Link-cut tree
int hd[N], nxt[M], a[M], b[M];
// Adjacent list
int n;

#define lx l[x]
#define rx r[x]

inline void Inc(int x, int d){
    if (x == 0) return;

    w0[x] += d, w1[x] += d, delay[x] += d;
}

inline void Release(int x){

    if (x == 0) return;

    if (rev[x]){
        swap(lx, rx);
        rev[lx] ^= 1, rev[rx] ^= 1;
        rev[x] = 0;
    }

    if (delay[x]){
        Inc(lx, delay[x]), Inc(rx, delay[x]);
        delay[x] = 0;
    }
}

inline void Update(int x){
    w1[x] = max(w0[x], w1[lx], w1[rx]);
}

inline void Set(int l[], int y, int x){
    l[y] = x, p[x] = y;
}

#define z p[y]
inline void Rotate(int x){
    int y = p[x];

    if (!rt[y]) Release(z), Set(y == l[z] ? l : r, z, x);
    else p[x] = z;

    Release(y), Release(x);

    if (x == l[y]) Set(l, y, rx), Set(r, x, y);
    else Set(r, y, lx), Set(l, x, y);

    if (rt[y]) rt[y] = false, rt[x] = true;
    //rt[x] = rt[y], rt[y] = false;

    Update(y); //Update(x);
}

inline void Splay(int x){
    while (!rt[x]) Rotate(x);
    Update(x);
}

void Access(int x){
    int y = 0; do{
        Splay(x), Release(x);
        rt[rx] = true, rt[rx = y] = false, Update(x);
        x = p[y = x];
    } while (x);
}

int _Access(int x){
    int y = 0; do{
        Splay(x), Release(x);
        rt[rx] = true, rt[rx = y] = false, Update(x);
        x = p[y = x];
    } while (x);
    return y;
}

inline int Root(int x) {
    x = _Access(x);
    while (Release(x), lx)
        x = lx;
    return x;
}

inline void Evert(int x) {
    rev[_Access(x)] ^= 1;
}

// Public :

void Link(int x, int y){
    if (Root(x) == Root(y)){
        puts("-1");
    }
    else {
        Evert(x), Splay(x), p[x] = y, Access(x);
    }
}

void Cut(int y, int x){
    if (x == y || Root(x) != Root(y)){
        puts("-1");
    }
    else {
        Evert(y), Splay(y), Access(x), Splay(x);
        p[lx] = p[x], rt[lx] = true, p[x] = lx = 0;
        //Update(x);
    }
}

void Modify(int x, int y, int w){
    if (Root(x) != Root(y)){
        puts("-1");
    }
    else {
        Access(y); y = 0; do{
            Splay(x), Release(x); if (!p[x]) Inc(rx, w), w0[x] += w, Inc(y, w);
            rt[rx] = true, rt[rx = y] = false, Update(x);
            x = p[y = x];
        } while (x);
    }
}

void Query(int x, int y){
    if (Root(x) != Root(y)){
        puts("-1");
    }
    else {
        Access(y); y = 0; do{
            Splay(x), Release(x); if (!p[x]) OT(max(w1[rx], w0[x], w1[y]));
            rt[rx] = true, rt[rx = y] = false, Update(x);
            x = p[y = x];
        } while (x);
    }
}

#define v b[i]
#define w w[i]

inline void dfs(int u = 1){
    for(int i=hd[u];i;i=nxt[i]) if (!p[v]){
        p[v] = u, dfs(v);
    }
}

#undef x
#undef w

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios::sync_with_stdio(false);

    while (scanf("%d", &n) != EOF){

        // Initializing Phase ...

        FOR_C(i, 2, n << 1){
            RD(a[i], b[i]), a[i|1] = b[i], b[i|1] = a[i];
            nxt[i] = hd[a[i]], hd[a[i]] = i; ++i;
            nxt[i] = hd[a[i]], hd[a[i]] = i;
        }

        //FLC(rt, true);
        fill(rt + 1, rt + n + 1, true);
        REP_1(i, n) RD(w0[i]);
        p[1] = -1, dfs(), p[1] = 0;

        // Interaction Phase ...

        int a, b, cmd; DO_C(RD()){
            RD(cmd, a, b); if (cmd == 1) Link(a, b);
            else if (cmd == 2) Cut(a, b);
            else if (cmd == 3) Modify(b, RD(), a);
            else Query(a, b);
        }

        puts("");

        // Rececling ....

        RST(hd, p, l, r, delay, rev);
    }
}
