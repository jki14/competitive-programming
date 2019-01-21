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

#define N 50010
#define square(x) (x)*(x)
const double EPS = 1, eps = 1e-7, inf = 1e20;
struct pnt { double x, y; };
pnt p[N];
int n;

double getmin(double x, double y) { return x < y ? x : y; }
double getmax(double x, double y) { return x > y ? x : y; }
double getdis(const pnt &p1, const pnt &p2) { return sqrt(square(p2.x-p1.x)+square(p2.y-p1.y)); }

double valuate(double dx) {
	int i; double ret; pnt dp = { dx, 0 };
	for (ret = i = 0; i < n; ++i) ret = getmax(ret, getdis(dp, p[i]));
	return ret;
}

void conduct()
{
	int i; double lst, mst, lmid, rmid, lv, rv, offset;
	lst = inf; mst = -inf;
	for (i = 0; i < n; ++i) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
		lst = getmin(lst, p[i].x); mst = getmax(mst, p[i].x);
	} lv = valuate(lst); rv = valuate(mst);
	while (mst-lst > EPS) {
		lmid = (lst+mst) / 2.0; rmid = (lmid+mst) / 2.0;
		lv = valuate(lmid); rv = valuate(rmid);
		if (lv-rv > eps) lst = lmid; else mst = rmid;
	} for (i = 0; i < n; ++i) p[i].x -= lst; mst -= lst; offset = lst; lst = 0;
	while (mst-lst > eps || fabs(lv-rv) > eps) {
		lmid = (lst+mst) / 2.0; rmid = (lmid+mst) / 2.0;
		lv = valuate(lmid); rv = valuate(rmid);
		if (lv-rv > eps) lst = lmid; else mst = rmid;
	} printf("%.6f %.6f\n", offset+lst, valuate(lst));
}

int main()
{
	while (scanf("%d", &n) != EOF && n) conduct();
	return 0;
}
