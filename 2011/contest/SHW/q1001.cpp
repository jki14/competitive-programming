#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
using namespace std;

#define square(x) (x)*(x)
#define xmul(x1, y1, x2, y2) ((x1)*(y2)-(x2)*(y1))
const double eps = 1e-9;
struct pnt {
	double x, y;
	pnt operator+(const pnt &p) const {
		pnt ret; ret.x = x + p.x;
		ret.y = y + p.y; return ret;
	} pnt operator-(const pnt &p) const {
		pnt ret; ret.x = x - p.x;
		ret.y = y - p.y; return ret;
	} pnt operator*(const double c) const {
		pnt ret; ret.x = x * c;
		ret.y = y * c; return ret;
	} pnt operator/(const double c) const {
		pnt ret; ret.x = x / c;
		ret.y = y / c; return ret;
	}
};
typedef pnt vec;
struct line { double a, b, c; };
#define N 50010
pnt p[N], q[N];
int seq[N], tmp[N];
int n;

double getdis(const pnt &p1, const pnt &p2) { return sqrt(square(p2.x-p1.x)+square(p2.y-p1.y)); }
double submul(const vec &v1, const vec &v2) { return v1.x * v2.y - v2.x * v2.y; }

vec getvec(const pnt &p1, const pnt &p2) {
	vec ret; ret.x = p2.x - p1.x;
	ret.y = p2.y - p1.y; return ret;
} vec uvec(vec v) {
	double len = sqrt(square(v.x)+square(v.y));
	vec ret; ret.x = v.x / len; ret.y = v.y / len; return ret;
}

line getline(const pnt &p, const vec &sv) {
	vec v = uvec(sv);
	line ret; ret.a = -v.y; ret.b = v.x;
	ret.c = ret.a * p.x + ret.b * p.y; return ret;
}

pnt getcrs(const line &l1, const line &l2) {
	pnt ret; ret.x = xmul(l1.b, l1.c, l2.b, l2.c) / xmul(l1.b, l1.a, l2.b, l2.a);
	ret.y = xmul(l1.a, l1.c, l2.a, l2.c) / xmul(l1.a, l1.b, l2.a, l2.b); return ret;
}

pnt getpos(const pnt &p1, const pnt &p2) {
	vec v = p2-p1; pnt p = p1 + v / 2; v = (vec){ -v.y, v.x };
	line l1 = getline(p, v), l2 = { 0, 1, 0 };
	return getcrs(l1, l2);
}

int cmp(const int &i, const int &j) {
	if (fabs(p[i].y-p[j].y)<eps) return p[i].x-p[j].x < -eps;
	return p[i].y-p[j].y < -eps;
}

void conduct()
{
	int i, j, top, bot; double ret; pnt pos, tp;
	for (i = 0; i < n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
	for (i = 0; i < n; ++i) seq[i] = i; sort(seq, seq+n, cmp);
	top = bot = 0; tmp[0] = seq[0];
	for (i = 1; i < n; ++i) {
		while (top > bot && submul(getvec(p[tmp[top-1]], p[tmp[top]]), getvec(p[tmp[top]], p[seq[i]])) < eps) --top;
		tmp[++top] = seq[i];
	} bot = top;
	for (i = n-2; i >= 0; --i) {
		while (top > bot && submul(getvec(p[tmp[top-1]], p[tmp[top]]), getvec(p[tmp[top]], p[seq[i]])) < eps) --top;
		tmp[++top] = seq[i];
	} n = top; for (i = 0; i < n; ++i) q[i] = p[tmp[i]];
	for (i = 0; i < n; ++i) p[i] = q[i];
	ret = p[0].y; pos = (pnt){ p[0].x, 0 };
	for (i = 1; i < n; ++i) {
		j = rand()%(n-i) + i;
		tp = p[i]; p[i] = p[j]; p[j] = tp;
		if (getdis(pos, p[i])-ret < eps) continue;
		pos = (pnt){p[i].x, 0}; ret = p[i].y;
		for (j = 0; j < i; ++j) if (getdis(pos, p[j])-ret > eps) {
			pos = getpos(p[i], p[j]); ret = getdis(pos, p[j]);
		} for (j = 0; j <= i; ++j) if (getdis(pos, p[j])-ret > eps) while (1) printf("\n");
	} printf("%.9f %.9f\n", pos.x, ret);
}

int main()
{
	while (scanf("%d", &n) != EOF && n) conduct();
	return 0;
}
