/**********************************************************************
Author: Xay
Created Time:  2009-9-28 22:36:25
File Name: Nova.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxint = 0x7FFFFFFF;
const int maxn = 200 + 5;
const double eps = 1e-8;

int sgn(double x) {
    return (x>eps) - (x<-eps);
}
struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y): x(_x), y(_y) {}
    Point operator + (const Point &a) const {
        return Point(x + a.x, y + a.y);
    }
    Point operator - (const Point &a) const {
        return Point(x - a.x, y - a.y);
    }
    double operator * (const Point &a) const {
        return x * a.y - y * a.x;
    }
    double dot(const Point &a) const {
        return x * a.x + y * a.y;
    }
    double lenth() const {
        return sqrt(dist());
    }
    double dist() const {
        return x * x + y * y;
    }
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    void output() const {
        printf("%lf %lf\n", x, y);
    }
};
int mat[maxn], now[maxn], r[maxn], t[maxn], br[maxn];
bool used[maxn], g[maxn][maxn];
int n, m, c;
Point lich[maxn], tree[maxn], wisp[maxn];

bool dfs(int x) {
    for (int i = 0; i < m; ++i) {
        if (used[i] || !g[x][i]) continue;
        used[i] = true;
        if (mat[i] == -1 || dfs(mat[i])) {
            mat[i] = x;
            return true;
        }
    }
    return false;
}
void match() {
    memset(mat, -1, sizeof(mat));
    memset(now, 0, sizeof(now));
    int cnt = 0, ans = 0;
    while (cnt < m) {
        int v = -1;
        for (int i = 0; i < n; ++i) {
            if (now[i] == maxint) continue;
            if (v == -1 || now[i] < now[v]) {
                v = i;
            }
        }
        if (v == -1) break;
        memset(used, 0, sizeof(used));
        if (dfs(v)) {
            ans = now[v];
            now[v] += t[v];
            ++cnt;
        } else {
            now[v] = maxint;
        }
    }
    if (cnt == m) {
        printf("%d\n", ans);
    } else {
        printf("-1\n");
    }
}
double cross(const Point &a, const Point &b, const Point &c) {
    return (b - a) * (c - a);
}
bool nova(const Point &a, const Point &b, double r) {
    if (sgn((a - b).dist() - r * r) > 0) return false;
    for (int i = 0; i < c; ++i) {
        if (sgn(fabs(cross(a, b, tree[i])) / (a - b).lenth() - br[i]) > 0) continue;
        if (sgn((tree[i] - a).dot(b - a)) < 0 || sgn((tree[i] - b).dot(a - b)) < 0) continue;
        return false;
    }
    return true;
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while (ca--) {
        scanf("%d%d%d", &n, &m, &c);
        for (int i = 0; i < n; ++i) {
            lich[i].input();
            scanf("%d%d", &r[i], &t[i]);
        }
        for (int i = 0; i < m; ++i) {
            wisp[i].input();
        }
        for (int i = 0; i < c; ++i) {
            tree[i].input();
            scanf("%d", &br[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                g[i][j] = nova(lich[i], wisp[j], r[i]);
            }
        }
        match();
    }
    return 0;
}

