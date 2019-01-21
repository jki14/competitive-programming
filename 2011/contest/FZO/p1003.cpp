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
const double eps = 1e-7, inf = 1e20;
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
#define N 1010
pnt p[N];
int seq[N], sub[N][2];
bool vst[N];
double dis[N], lft[N], rit[N], r[N], e[N][N];
int n;

double getdis(const pnt &p1, const pnt &p2) { return sqrt(square(p2.x-p1.x)+square(p2.y-p1.y)); }
double submul(const vec &v1, const vec &v2) { return v1.x * v2.y - v2.x * v1.y; }
double nummul(const vec &v1, const vec &v2) { return v1.x * v2.x + v1.y * v2.y; }
double oridis(const line &l, const pnt &p) { return l.a * p.x + l.b * p.y - l.c; }

vec uvec(vec v) {
	double len = sqrt(square(v.x)+square(v.y));
	return v / len;
}

line getline(const pnt &p1, const pnt &p2) {
	vec v = uvec(p2-p1);
	line ret; ret.a = -v.y; ret.b = v.x;
	ret.c = ret.a * p1.x + ret.b * p1.y; return ret;
}

int cmp(const int &i, const int &j) {
	if (fabs(lft[i]-lft[j])<eps) return rit[i]-rit[j] < -eps;
	return lft[i]-lft[j] < -eps;
}

void circlecrs(int i, int j, const pnt &p1, const pnt &p2, double r1, double r2, int &cnt, pnt *p)
{
	vec v; double len, ang1, ang2;
	v = uvec(p2-p1);
	len = getdis(p1, p2); if (r1 + r2 - len < -eps) return;
	if (len + r1 - r2 < -eps || len + r2 - r1 < -eps) return;
	sub[cnt][0] = sub[cnt+1][0] = i; sub[cnt][1] = sub[cnt+1][1] = j;
	if (fabs(r1+r2-len)<eps) { p[cnt++] = p1+v*r1; return; }
	ang1 = atan2(p2.y-p1.y, p2.x-p1.x);
	ang2 = acos((square(r1)+square(len)-square(r2))/(2*r1*len));
	v = (vec){ cos(ang1+ang2), sin(ang1+ang2) }; p[cnt++] = p1 + v*r1;
	v = (vec){ cos(ang1-ang2), sin(ang1-ang2) }; p[cnt++] = p1 + v*r1;
}

int linexcircle(const line &l, const pnt &cen, double rad, pnt *p) {
	vec v1, v2; double len, dis;
	v1 = (vec){l.a, l.b }; v2 = (vec){ -v1.y, v1.x };
	len = oridis(l, cen); if (fabs(len)-rad > -eps) return 0;
	dis = sqrt(square(rad)-square(len));
	p[0] = cen - v1 * len + v2 * dis; p[1] = cen - v1 * len - v2 * dis; return 2;
}

void segxcircle(const pnt &p1, const pnt &p2, const vec &v, double len, const pnt &cen, double rad, int &cnt, double *lft, double *rit)
{
	line l; int i, nc; pnt crs[2]; double ret[2], tmp;
	l = getline(p1, p2); nc = linexcircle(l, cen, rad, crs); if (nc < 2) return;
	//printf("circle:%.3f,%.3f,%.3f crs1:%.3f,%.3f crs2:%.3f,%.3f\n", cen.x, cen.y, rad, crs[0].x, crs[0].y, crs[1].x, crs[1].y);
	ret[0] = nummul(v, crs[0]-p1); ret[1] = nummul(v, crs[1]-p1);
	if (ret[1] < ret[0]) { tmp = ret[1]; ret[1] = ret[0]; ret[0] = tmp; }
	for (i = 0; i < 2; ++i) {
		if (ret[i] < -eps) ret[i] = 0;
		if (ret[i] - len > eps) ret[i] = len;
	} if (fabs(ret[1]-ret[0])<eps) return;
	lft[cnt] = ret[0]; rit[cnt++] = ret[1];
}

double setupedge(int st, int ed, const pnt &p1, const pnt &p2) {
	double len, cur; vec v; int i, j, cnt, ss[4];
	len = getdis(p1, p2); v = (p2-p1) / len;
	cnt = 0;
	if (st < n) ss[cnt++] = st; else { ss[cnt++] = sub[st][0]; ss[cnt++] = sub[st][1]; }
	if (ed < n) ss[cnt++] = ed; else { ss[cnt++] = sub[ed][0]; ss[cnt++] = sub[ed][1]; }
	for (i = 0; i < cnt; ++i) for (j = i+1; j < cnt; ++j) if (ss[i] == ss[j]) return len;
	for (cnt = i = 0; i < n; ++i) segxcircle(p1, p2, v, len, p[i], r[i], cnt, lft, rit);
	for (i = 0; i < cnt; ++i) seq[i] = i; sort(seq, seq+cnt, cmp);
	//printf(" --------------------- \n");
	//for (i = 0; i < cnt; ++i) printf("lft:%.3f rit:%.3f\n", lft[i], rit[i]);
	for (cur = i = 0; i < cnt; ++i) {
		if (lft[seq[i]]-cur > eps) return inf;
		if (rit[seq[i]] > cur) cur = rit[seq[i]];
	} if (len-cur < eps) return len; else return inf;
}

void conduct()
{
	int i, j, l, cnt; double k;
	scanf("%d", &n); for (i = 0; i < n; ++i) scanf("%lf%lf%lf", &p[i].x, &p[i].y, &r[i]);
	for (cnt = n, i = 0; i < n; ++i) for (j = i+1; j < n; ++j) circlecrs(i, j, p[i], p[j], r[i], r[j], cnt, p);
	for (i = 0; i < cnt; ++i) for (j = i+1; j < cnt; ++j) e[i][j] = e[j][i] = setupedge(i, j, p[i], p[j]);
	/*for (i = 0; i < cnt; ++i) printf("p[%d]=%.3f,%.3f\n", i, p[i].x, p[i].y);
	for (i = 0; i < cnt; ++i) {
		printf("e[%d] -----> \n", i);
		for (j = 0; j < cnt; ++j) printf("j:%d-->%.3f\n", j, e[i][j]);
	}*/
	for (i = 0; i < cnt; ++i) dis[i] = inf;
	memset(vst, 0, sizeof(vst));
	for (dis[0] = i = 0; i < cnt; ++i) {
		k = inf;
		for (j = 0; j < cnt; ++j) if (!vst[j] && dis[j] < k) { k = dis[j]; l = j; }
		vst[l] = 1; if (l == n-1) { printf("%.4f\n", dis[n-1]+eps); return; }
		for (j = 0; j < cnt; ++j) if (!vst[j] && dis[j] > dis[l] + e[l][j]) dis[j] = dis[l] + e[l][j];
	} printf("No such path.\n"); 
}

int main()
{
	int time; scanf("%d", &time);
	for (int i = 1; i <= time; ++i) {
		printf("Case %d: ", i); conduct();
	} return 0;
}
