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
const double eps = 1e-6;
struct pnt { double x, y; };
typedef pnt vec;
#define N 20010
pnt p[N], cen;
double dis[N];
int n;

double submul(const vec &v1, const vec &v2) { return v1.x * v2.y - v2.x * v1.y; }
double getdis(const pnt &p1, const pnt &p2) { return sqrt(square(p2.x-p1.x)+square(p2.y-p1.y)); }

void conduct()
{
	int i, l; double totx, toty, area, tx, ty, ta;
	for (i = 0; i < n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y); p[n] = p[0];
	for (area = totx = toty = i = 0; i < n; ++i) {
		tx = (p[i].x+p[i+1].x)/3; ty = (p[i].y+p[i+1].y)/3; ta = submul(p[i], p[i+1]);
		totx += tx * ta; toty += ty * ta; area += ta;
	} totx /= area; toty /= area; cen = (pnt){ totx, toty };
	for (i = 0; i < n; ++i) dis[i] = getdis(cen, p[i]);
	for (i = 0; i < n; ++i) {
		for (l = 0; l < n / 2; ++l) if (fabs(dis[(i+l+1)%n]-dis[(i+n-l)%n]) > eps) break;
		if (l == n / 2) { printf("YES\n"); return; }
		for (l = 1; l <= n / 2; ++l) if (fabs(dis[(i+l)%n]-dis[(i+n-l)%n]) > eps) break;
		if (l > n/2) { printf("YES\n"); return; }
	} printf("NO\n");
}


int main()
{
	while (scanf("%d", &n) != EOF) conduct();
	return 0;
}
