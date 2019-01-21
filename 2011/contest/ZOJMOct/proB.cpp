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
#include<set>
#include<map>
using namespace std;

double v;
const double pi = acos(-1.0), eps = 1e-10, inf = 1e5;

double valuate(double tg, double h) {
	double tmp = 0.0, R = sqrt(v/pi/h/2.0-5.0*tg/48.0)+sqrt(tg)/4.0, r = R - sqrt(tg);
	tmp = 2*pi*R*h;
	tmp += pi * (R+r) * sqrt(h*h+tg);
	tmp += pi*r*r; return tmp;
}

double hvaluate(double h) {
	double lst, mst, lmid, rmid, rv, lv;
	lst = eps*10; mst = v/pi/h * 0.75; lv = 0; rv = inf;
	while (mst-lst > eps || fabs(lv-rv) > eps) {
		lmid = (mst+lst)/2.0; rmid = (lmid+mst)/2.0;
		lv = valuate(lmid, h); rv = valuate(rmid, h);
		if (lv - rv < eps) mst = rmid; else lst = lmid;
	} return valuate(lst, h);
}

void conduct()
{
	if (v < eps) { printf("0.00000000\n"); return; }
	double lst, mst, lmid, rmid, rv, lv;
	lst = 0; mst = inf; lv = 0; rv = inf;
	while (mst-lst>eps || fabs(lv-rv) > eps) {
		lmid = (mst+lst)/2.0; rmid = (lmid+mst)/2.0;
		lv = hvaluate(lmid); rv = hvaluate(rmid);
		if (lv - rv < eps) mst = rmid; else lst = lmid;
	} printf("%.8f\n", hvaluate(lst)+eps);
}

int main()
{
	while (scanf("%lf", &v) != EOF) conduct();
	return 0;
}
