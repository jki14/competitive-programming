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
const double eps = 1e-9, inf = 1e10, pi = acos(-1.0);
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
struct line { double a, b ,c; };
#define N 10010
pnt p[N], q[N];
double ang[N], rad;
int seq[N], evt[N];
line l[N];
int n, m;

const line bdr1 = { 1, 0, -inf }, bdr2 = { -1, 0, -inf }, bdr3 = { 0, 1, -inf }, bdr4 = { 0, -1, -inf };
const pnt cen = { 0, 0 };

double nummul(const vec &v1, const vec &v2) { return v1.x * v2.x + v1.y * v2.y; }
double submul(const vec &v1, const vec &v2) { return v1.x * v2.y - v2.x * v1.y; }
double oridis(const line &l, const pnt &p) { return l.a * p.x + l.b * p.y - l.c; }

vec uvec(const vec &v) {
	double len = sqrt(square(v.x)+square(v.y));
	return v / len;
}

pnt getcrs(const line &l1, const line &l2) {
	pnt ret; ret.x = (l1.b * l2.c - l2.b * l1.c) / (l1.b * l2.a - l2.b * l1.a);
	ret.y = (l1.a * l2.c - l2.a * l1.c) / (l1.a * l2.b - l2.a * l1.b); return ret;
}

line getline(const pnt &p1, const pnt &p2) {
	vec v = uvec(p2-p1);
	line ret; ret.a = -v.y; ret.b = v.x;
	ret.c = ret.a * p1.x + ret.b * p1.y; return ret;
}

int hfpcmp(const int &i, const int &j) {
	if (fabs(ang[i]-ang[j])<eps) return l[i].c-l[j].c > eps;
	return ang[i]-ang[j]<-eps;
}

int hlfplane(int n, line *l, pnt *p, int *seq, double *ang) {
	int i, j, top, bot, ret;
	l[n++] = bdr1; l[n++] = bdr2; l[n++] = bdr3; l[n++] = bdr4;
	for (i = 0; i < n; ++i) { ang[i] = atan2(l[i].b, l[i].a); if (fabs(ang[i]-pi)<eps) ang[i] = -pi; }
	for (i = 0; i < n; ++i) seq[i] = i; sort(seq, seq+n, hfpcmp);
	for (i = j = 1; i < n; ++i) if (fabs(ang[seq[i]]-ang[seq[j-1]])>eps) seq[j++] = seq[i]; n = j;
	for (i = 1, top = bot = 0; i < n; ++i) {
		while (top > bot && oridis(l[seq[i]], p[top])<-eps) --top;
		p[top+1] = getcrs(l[seq[i]], l[seq[top]]); seq[++top] = seq[i];
		if (ang[seq[i]] > eps) break;
	} p[bot] = getcrs(l[seq[top]], l[seq[bot]]);
	for (++i; i < n; ++i) {
		if (oridis(l[seq[i]], p[bot])>-eps) continue;
		while (top > bot && oridis(l[seq[i]], p[top]) < -eps) --top;
		if (top == bot) break; p[top+1] = getcrs(l[seq[i]], l[seq[top]]); seq[++top] = seq[i];
		while (oridis(l[seq[top]], p[bot+1])<-eps) ++bot; p[bot] = getcrs(l[seq[top]], l[seq[bot]]);
	} if (i < n) return 0;
	for (ret = 0, i = bot; i < top; ++i) if (fabs(p[i].x-p[i+1].x)>eps || fabs(p[i].y-p[i+1].y)>eps) {
		seq[ret] = seq[i]; p[ret] = p[i]; ret++;
	} if (!ret || fabs(p[i].x-p[0].x)>eps || fabs(p[i].y-p[0].y)>eps) {
		seq[ret] = seq[i]; p[ret] = p[i]; ret++;
	} return ret;
}

int status(const pnt &p1, const pnt &cen, double rad) {
	return sqrt(square(p1.x-cen.x)+square(p1.y-cen.y))-rad > eps;
}

bool cirincvx(const pnt &cen, double rad, int n, pnt *p) {
	int i; p[n] = p[0];
	for (i = 0; i < n; ++i) if (submul(p[i]-cen, p[i+1]-cen)<-eps) return false;
	for (i = 0; i < n; ++i) if (fabs(oridis(getline(p[i], p[i+1]), cen))-rad<-eps) return false;
	return true;
}

int linexcircle(const line &l, const pnt &cen, double rad, pnt *p) {
	double d1, d2; vec v1, v2;
	d1 = oridis(l, cen); v1 = (vec){ l.a, l.b }; if (fabs(d1)-rad > eps) return 0;
	if (fabs(fabs(d1)-rad) < eps) { p[1] = cen - v1 * d1; return 1; }
	v2 = (vec){ -v1.y, v1.x }; d2 = sqrt(square(rad)-square(d1));
	p[1] = cen - v1 * d1 + v2 * d2; p[2] = cen - v1 * d1 - v2 * d2; return 2;
}

void segxcircle(const pnt &p1, const pnt &p2, const pnt &cen, double rad, int &n, pnt *p) {
	int cnt, i, j; pnt tp; vec v1; double mst; pnt crs[4];
	cnt = linexcircle(getline(p1, p2), cen, rad, crs);
	v1 = p2-p1; mst = nummul(v1, v1);
	if (cnt == 2 && nummul(v1, crs[1]-p1)-nummul(v1, crs[2]-p1)>eps) { tp = crs[1]; crs[1] = crs[2]; crs[2] = tp; }
	for (i = 1, j = 0; i <= cnt; ++i) if (nummul(v1, crs[i]-p1)>-eps && nummul(v1, crs[i]-p1)-mst<eps) crs[++j] = crs[i];
	crs[0] = p1; cnt = j; crs[j+1] = p2;
	p[n++] = p1; for (i = 1; i <= cnt; ++i) 
		if (status(crs[i-1], cen, rad) || status(crs[i+1], cen, rad)) { evt[n] = 1; p[n++] = crs[i]; }
	p[n] = p2;
}

double circlearea(const pnt &p1, const pnt &p2, const pnt &cen, double rad) {
	double ang1, ang2;
	ang1 = atan2(p1.y-cen.y, p1.x-cen.x); ang2 = atan2(p2.y-cen.y, p2.x-cen.x);
	while (ang2-ang1<-eps) ang2 += 2*pi; return rad*rad*(ang2-ang1)/2;
}

void conduct()
{
	int i, tag; double ans; pnt pos;
	for (i = 0; i < n; ++i) scanf("%lf%lf%lf%lf", &p[i].x, &p[i].y, &q[i].x, &q[i].y);
	scanf("%lf%lf", &pos.x, &pos.y);
	for (i = 0; i < n; ++i) if (submul(q[i]-p[i], pos-p[i]) > eps) l[i] = getline(p[i], q[i]);
				else l[i] = getline(q[i], p[i]);
	n = hlfplane(n, l, p, seq, ang);
	if (cirincvx(cen, rad, n, p)) { cout << "100.00000%" << endl; return; }
	memset(evt, 0, sizeof(evt));
	for (m = i = 0; i < n; ++i) segxcircle(p[i], p[i+1], cen, rad, m, q);
	for (ans = n = i = 0, tag = status(q[0], cen, rad); i < m; ++i) {
		if (evt[i]) { p[n] = q[i]; evt[n] = tag; n++; tag = 1-tag; }
		if (!tag) ans += submul(q[i], q[i+1]);
	} p[n] = p[0]; ans /= 2;
	for (i = evt[0]; i < n; i += 2) ans += circlearea(p[i], p[i+1], cen, rad);
	printf("%.5f", ans*100.0/(pi*rad*rad)); cout << "%" << endl;
}

int main()
{
	int time; scanf("%d", &time);
	for (int i = 1; i <= time; ++i) {
		scanf("%lf%d", &rad, &n);
		printf("Case %d: ", i);
		conduct();
	} return 0;
}
