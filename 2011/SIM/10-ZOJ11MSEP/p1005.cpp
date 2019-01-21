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
struct pnt { double x, y; };
double eps = 1e-9, inf = 1e9;
pnt p, q;
double a, b, w, h, ans;

double getdis(const pnt &p1, const pnt &p2) { return fabs(p2.x-p1.x)+fabs(p2.y-p1.y); }

bool judge(const pnt &p, int st) {
	double up, dn, lft, rit;
	if (st == 1) { up = h-b; dn = b; lft = a; rit = w-a; }
	else { up = h-a; dn = a; lft = b; rit = w-b; }
	if (lft-p.x>eps || rit-p.x<-eps || dn-p.y>eps || up-p.y<-eps) return false;
	return true;
}

void getans(const pnt &p1, const pnt &p2) {
	pnt lft, rit, m1, m2; double val1, val2;
	lft = p1; rit = p2;
	while (fabs(lft.x-rit.x)>eps || fabs(lft.y-rit.y)>eps) {
		m1.x = (lft.x+rit.x)/2; m1.y = (lft.y+rit.y)/2;
		m2.x = (m1.x+rit.x)/2; m2.y = (m1.y+rit.y)/2;
		val1 = getdis(p, m1)+getdis(q, m1); val2 = getdis(p, m2)+getdis(q, m2);
		if (val1-val2 > eps) lft = m1; else rit = m2;
	} if (val1 < ans) ans = val1;
}
	
int main() {
	pnt p1, p2, p3, p4; double c; int st1, st2;
	while (scanf("%lf%lf%lf%lf", &w, &h, &a, &b) != EOF) {
		scanf("%lf%lf%d", &p.x, &p.y, &st1);
		scanf("%lf%lf%d", &q.x, &q.y, &st2);
		if (!judge(p, st1) || !judge(q, st2)) { printf("-1\n"); continue; }
		//c = sqrt(a*a+b*b) / 2;
		if (a < b) c = b; else c = a;
		p1.x = c; p1.y = h-c; p2.x = w-c; p2.y = h-c;
		p3.x = w-c; p3.y = c; p4.x = c; p4.y = c;
		if (st1 == st2) printf("%.3f\n", getdis(p, q));
		else {
			if (2*c-h > eps || 2*c-w > eps) { printf("-1\n"); continue; }
			ans = inf;
			if ((p.x-c)*(p.x+c-w)>eps || (p.y-c)*(p.y+c-h)>eps ||
			    (q.x-c)*(q.x+c-w)>eps || (q.y-c)*(q.y+c-h)>eps) {
			getans(p1, p2); getans(p2, p3); getans(p3, p4); getans(p4, p1);
			} else ans = getdis(p, q);
			printf("%.3f\n", ans+eps);
		}
	}
}
