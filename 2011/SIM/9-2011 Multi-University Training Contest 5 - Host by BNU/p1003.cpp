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

struct pnt { long long x, y; };
typedef pnt vec;
#define square(x) (x)*(x)
#define N 100010
const double eps = 1e-8, pi = acos(-1.0);
pnt p[N];
typedef pnt vec;
int seq[N], ss[N];
int n;
vec v, vv;

void input()
{
	for (int i = 1; i <= n; ++i) scanf("%I64d%I64d", &p[i].x, &p[i].y);
}

vec getvec(const pnt &p1, const pnt &p2) {
	vec ret; ret.x = p2.x - p1.x;
	ret.y = p2.y - p1.y; return ret;
}

long long nummul(const vec &v1, const vec &v2) { return v1.x * v2.x + v1.y * v2.y; }
long long submul(const vec &v1, const vec &v2) { return v1.x * v2.y - v2.x * v1.y; }

int cmp(const int &x, const int &y) { 
	long long val1, val2;
	val1 = nummul(p[x], vv); val2 = nummul(p[y], vv); 
	if (val1 == val2) return nummul(getvec(p[x],p[y]), v) > 0;
	return val1 < val2;
}

void conduct()
{
	double val, ang; vec tv;
	int i, j, s, t, ts, tt, lft, rit;
	vv.x = -v.y; vv.y = v.x;
	for (i = 1; i <= n; ++i) seq[i] = i; sort(seq+1, seq+n+1, cmp);
	for (ang = pi, i = 1; i < n;) {
		tv = getvec(p[seq[i]], p[seq[i+1]]);
		for (lft = i, rit = i+1; rit < n &&!submul(tv, getvec(p[seq[rit]],p[seq[rit+1]])); ++rit);
		val = (long double)nummul(tv, v) / (sqrtl(square(v.x)+square(v.y))*sqrtl(square(tv.x)+square(tv.y)));
		if (fabs(val) <eps) {
			val = fabs(val);
			for (ts = seq[j = lft]; j <= rit; ++j) if (seq[j] < ts) ts = seq[j];
			for (tt = n+1, j = lft; j <= rit; ++j) if (seq[j] != ts && seq[j] < tt) tt = seq[j];
		} else if (val < -eps) { 
			val = -val;
			for (ts = seq[j = rit]; j > lft; --j) if (seq[j] < ts) ts = seq[j];
			for (tt = seq[j = lft]; seq[j] != ts; ++j) if (seq[j] < tt) tt = seq[j];
		} else {
			for (ts = seq[j = lft]; j < rit; ++j) if (seq[j] < ts) ts = seq[j];
			for (tt = seq[j = rit]; seq[j] != ts; --j) if (seq[j] < tt) tt = seq[j];
		} val = acos(val);
		if (ang - val > eps || (fabs(ang-val)<eps && (ts < s || (ts == s && tt < t)))) {
			ang = val; s = ts; t = tt; 
		} i = rit;
	} printf("%d %d\n", s, t);
}

int main()
{
	while (scanf("%d%I64d%I64d", &n, &v.x, &v.y) != EOF) { input(); conduct(); }
	return 0;
}
