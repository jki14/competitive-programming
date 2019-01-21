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

#define N 6
#define M 2
double v;
const double pi = acos(-1.0), eps = 1e-8, inf = 1e8;

double valuate(double tg, double h) {
	double tmp = 0.0, R = sqrt(v/pi/h/2.0-5.0*h*h*tg/48.0)+h*sqrt(tg)/4.0, r = R-h*sqrt(tg);
	tmp = 2*pi*R*h;
	tmp += h*pi*sqrt(1+tg)*(R+r);
	tmp += pi*r*r; return tmp;
}

double hvaluate(double h) {
	double lst, mst, lmid, rmid, rv, lv;
	lst = 0; mst = v/h/h/h/pi*0.75; lv = 0; rv = inf;
	while (mst-lst > eps || fabs(lv-rv) > eps) {
		lmid = (mst+lst)/2.0; rmid = (lmid+mst)/2.0;
		lv = valuate(lmid, h); rv = valuate(rmid, h);
		if (lv < rv) mst = rmid; else lst = lmid;
	} return valuate(lst, h);
}

void conduct()
{
	double ret, val, pos, tv, tp, ttv, ttp, stp;
	int i, j;
	ret = inf;
	for (i = 1; i < N; ++i) {
		pos = inf/N*i; val = hvaluate(pos);
		for (stp = inf/N/M; stp > eps; stp *= 0.72) {
			for (tp = pos, tv = val, j = -M; j <= M; ++j) {
				ttp = pos - stp*j; if (ttp < -eps || ttp > inf) continue;
				ttv = hvaluate(ttp);
				if (ttv < tv) { tv = ttv; tp = ttp; }
			} pos = tp; val = tv;
		} if (val < ret) ret = val;
	} printf("%.6f\n", ret);
}

int main()
{
	while (scanf("%lf", &v) != EOF) conduct();
	return 0;
}
