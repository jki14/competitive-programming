/*
 * Author: momodi
 * Created Time:  2009/9/5 22:31:02
 * File Name: Nova.cpp
 * Description: 
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define out(x) fprintf(stderr, "%s: %I64d\n", #x, (long long)(x))
#define SZ(v) ((int)(v).size())
const int maxint=-1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
#define SQR(v) ((long long)(v) * (v))
const int maxn = 310;
int n, m, t;
int lichx[maxn], lichy[maxn], lichr[maxn], licht[maxn];
int wispx[maxn], wispy[maxn];
int treex[maxn], treey[maxn], treer[maxn];
bool adj[maxn][maxn];
int now[maxn];

long long sqr(long long a) {
    return a * a;
}
long long dist2(int ax, int ay, int bx, int by) {
    return SQR(ax - bx) + SQR(ay - by);
}
int cross(int ax, int ay, int bx, int by, int cx, int cy) {
    return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}
int mul(int  ax, int ay, int bx, int by, int cx, int cy) {
    return (bx - ax) * (cx - ax) + (by - ay) * (cy - ay);
}

bool block(int a, int b, int c) {
    if (sqr(cross(lichx[a], lichy[a], wispx[b], wispy[b], treex[c], treey[c])) > SQR(treer[c]) * dist2(lichx[a], lichy[a], wispx[b], wispy[b])) {
        return false;
    }
    return mul(lichx[a], lichy[a], wispx[b], wispy[b], treex[c], treey[c]) >= 0 &&
        mul(wispx[b], wispy[b], lichx[a], lichy[a], treex[c], treey[c]) >= 0;
}

bool can_see(int a, int b) {
    int d2 = SQR(lichx[a] - wispx[b]) + SQR(lichy[a] - wispy[b]);
    if (d2 > SQR(lichr[a])) {
        return false;
    }
    for (int i = 0; i < t; ++i) {
        if (block(a, b, i)) {
            return false;
        }
    }
    return true;
}
int match[maxn], flag[maxn];
bool dfs(int v) {
    for (int i = 0; i < m; ++i) {
        if (adj[v][i] && flag[i] == false) {
            flag[i] = true;
            if (match[i] == -1 || dfs(match[i])) {
                match[i] = v;
                return true;
            }
        }
    }
    return false;
}
int main() {
    int ca;
    scanf("%d", &ca);
    while (ca--) {
        scanf("%d %d %d", &n, &m, &t);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d %d", lichx + i, lichy + i, lichr + i, licht + i);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", wispx + i, wispy + i);
        }
        for (int i = 0; i < t; ++i) {
            scanf("%d %d %d", treex + i, treey + i, treer + i);
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                adj[i][j] = can_see(i, j);
            }
        }
        int tot = 0;
        int ans = 0;
        memset(match, -1, sizeof(match));
        memset(now, 0, sizeof(now));
        while (tot < m) {
            int mmin = maxint;
            int v = -1;
            for (int i = 0; i < n; ++i) {
                if (get_min(mmin, now[i])) {
                    v = i;
                }
            }
            if (v == -1) {
                break;
            }
            memset(flag, 0, sizeof(flag));
            if (dfs(v)) {
                ans = now[v];
                now[v] += licht[v];
                ++tot;
            } else {
                now[v] = maxint;
            }
        }
        if (tot == m) {
            printf("%d\n", ans);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}

