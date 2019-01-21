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

#define getmax(x, y) (x)>(y)?(x):(y)
#define square(x) (x)*(x)
struct pnt { double x, y; };
#define N 1010
const double eps = 1e-8;
const double pi = 3.141;
double dis1[N], dis2[N];
bool vst[N];
pnt p[N], c1, c2;
int s1[N], s2[N];
int n; double tot;

void input()
{
	int i;
	scanf("%lf%lf%lf%lf%lf", &c1.x, &c1.y, &c2.x, &c2.y, &tot);
	for (i = 0; i < n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
}

double getdis(const pnt &p1, const pnt &p2) { return sqrt(square(p2.x-p1.x) + square(p2.y-p1.y)); }
int cmp1(const int &x, const int &y) { return dis1[x] - dis1[y] < -eps; }
int cmp2(const int &x, const int &y) { return dis2[x] - dis2[y] < -eps; }

void conduct(int k)
{
	int ans, tmp, i, j;
	double r1, r2;
	ans = 0;
	for (i = 0; i < n; ++i) { dis1[i] = getdis(c1, p[i]); dis2[i] = getdis(c2, p[i]); } dis1[n] = 0;
	for (i = 0; i < n; ++i) { s1[i] = s2[i] = i; } s1[n] = n;
	sort(s1, s1+n+1, cmp1); sort(s2, s2+n, cmp2);
	for (i = n; i >= 0; --i) {
		r1 = dis1[s1[i]]; r2 = tot - pi * square(r1); if (r2 < -eps) continue;
		r2 = sqrt(r2 / pi);
		//printf("r1:%.3f r2:%.3f\n", r1, r2);
		memset(vst, 0, sizeof(vst)); tmp = 0;
		for (j = 0; j <= i; ++j) vst[s1[j]] = 1; tmp = i;
		for (j = 0; j < n && dis2[s2[j]] - r2 < eps; ++j) if (!vst[s2[j]]) tmp++;
		ans = getmax(tmp, ans); 
	}
	printf("%d. %d\n", k, n-ans);
}

int main()
{
	int time; time = 0;
	while (scanf("%d", &n) != EOF && n) { input(); conduct(++time); }
	return 0;
}
