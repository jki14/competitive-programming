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
#define N 10010
pnt p[N], q[N];
double f[2];
int n;

double getmin(double x, double y) { return x < y ? x : y; }
double getdis(const pnt &p1, const pnt &p2) { return sqrt(square(p2.x-p1.x)+square(p2.y-p1.y)); }

void conduct()
{
	pnt pos; double x1, y1, x2; int i;
	scanf("%lf%lf", &pos.x, &pos.y);
	for (i = 0; i < n; ++i) {
		scanf("%lf%lf%lf", &y1, &x1, &x2);
		p[i] = (pnt){ x1, y1 }; q[i] = (pnt){ x2, y1 };
	} f[0] = getdis(pos, p[0]); f[1] = getdis(pos, q[0]);
	for (i = 1; i < n; ++i) {
		f[0] += getmin(getdis(p[i], p[i-1]), getdis(p[i], q[i-1]));
		f[1] += getmin(getdis(q[i], p[i-1]), getdis(q[i], q[i-1]));
	} printf("%.11f\n", getmin(f[0], f[1]));
}

int main()
{
	while (scanf("%d", &n) != EOF && n) conduct();
}
