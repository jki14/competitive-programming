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
const double eps = 1e-9, inf = 1e20;
struct pnt { double x, y; };
typedef pnt vec;
#define N 1010
pnt p[N];
int seq[N], tmp[N];
int n;

double getmin(double x, double y) { return x < y ? x : y; }
double getdis(const pnt &p1, const pnt &p2) { return sqrt(square(p2.x-p1.x)+square(p2.y-p1.y)); }
double submul(const vec &v1, const vec &v2) { return v1.x * v2.y - v2.x * v1.y; }
double nummul(const vec &v1, const vec &v2) { return v1.x * v2.x + v1.y * v2.y; }

vec getvec(const pnt &p1, const pnt &p2) {
	vec ret; ret.x = p2.x - p1.x;
	ret.y = p2.y - p1.y; return ret;
}

int cmp(const int &i, const int &j) {
	if (fabs(p[i].y-p[j].y)<eps) return p[i].x-p[j].x < -eps;
	return p[i].y-p[j].y < -eps;
}

void conduct()
{
	int i, j, top, bot; double ret;
	for (i = 0; i < n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
	for (i = 0; i < n; ++i) seq[i] = i; sort(seq, seq+n, cmp);
	top = bot = 0; tmp[0] = seq[0];
	for (i = 1; i < n; ++i) {
		while (top > bot && submul(getvec(p[tmp[top-1]],p[tmp[top]]), getvec(p[tmp[top]], p[seq[i]])) < eps) --top;
		tmp[++top] = seq[i];
	} bot = top;
	for (i = n-2; i >= 0; --i) {
		while (top > bot && submul(getvec(p[tmp[top-1]],p[tmp[top]]), getvec(p[tmp[top]], p[seq[i]])) < eps) --top;
		tmp[++top] = seq[i];
	} n = top;
	for (ret = inf, i = j = 0; i < n; ++i) {
		while (submul(getvec(p[tmp[i]], p[tmp[i+1]]), getvec(p[tmp[i]], p[tmp[j]]))-submul(getvec(p[tmp[i]],p[tmp[i+1]]),getvec(p[tmp[i]],p[tmp[j+1]])) < eps) j = (j+1)%n;
		ret = getmin(ret, submul(getvec(p[tmp[i]], p[tmp[i+1]]), getvec(p[tmp[i]], p[tmp[j]]))/getdis(p[tmp[i]], p[tmp[i+1]]));
	} printf("%.2f\n", ret+0.005);
}

int main()
{
	int time = 0;
	while (scanf("%d", &n) != EOF && n) {
		printf("Case %d: ", ++time); conduct();
	} return 0;
}
