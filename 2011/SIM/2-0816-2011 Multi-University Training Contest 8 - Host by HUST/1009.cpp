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

void input()
{
	int i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
	for (i = 0; i < m; ++i) scanf("%lf%lf", &q[i].x, &q[i].y);
}

void conduct()
{
	fp.x = p[0].x; fp.y = p[0].y; fq.x = q[0].x; fq.y = q[0].y;
	cp = fp; cq = fq; i = 0; j = 0;
	np.x = p[1].x; np.y = p[1].y; nq.x = q[1].x; nq.y = q[1].y;
	while (true) {
		fp = cp; fq = cq;
		if (np.y < nq.y) {
			cp.x = np.x; cp.y = np.y; cq.y = np.y;
			cq.x = (np.y-cq.y)*(nq.x-cq.x)/(nq.y-cq.y);
		} else {
			cp.x = (nq.y-cp.y)*(np.x-cp.x)/(np.y-cp.y);
			cp.y = nq.y; cq.x = nq.x; cq.y = nq.y;
		}
		for (k = 0; k <= j; ++k) tmp[k] = q[k];
		tmp[k+1] = cq; tmp[k+2] = cp;
		for (k = i; k >= 0; --k) tmp[j+i+3-k] = p[k];
		mp = getmp(tmp, j+i+4);
		if (mp.x - p[0].x < -eps || mp.x - q[0].x > eps) {
			printf("%.3f\n",


int main()
{
	int time;
	scanf("%d", &time);
	while (time--) { input(); conduct(); }
	return 0;
}
