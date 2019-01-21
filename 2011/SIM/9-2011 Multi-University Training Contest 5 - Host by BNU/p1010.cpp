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
#define N 10010
double x[N], y[N];
int p, n;

void conduct()
{
	int i;
	double avg1, avg2, mid, sdx, sdy, r, a, b;
	switch (p) {
		case 1:
			for (i = 1; i <= n; ++i) scanf("%lf", &x[i]);
			for (avg1 = 0, i = 1; i <= n; ++i) avg1 += x[i]; avg1 /= n;
			for (sdx = 0, i = 1; i <= n; ++i) sdx += square(x[i]-avg1); sdx = sqrt(sdx/n);
			printf("%.2f", (x[1]-avg1)/sdx); for (i = 2; i <= n; ++i) printf(" %.2f", (x[i]-avg1)/sdx); printf("\n");
			break;
		case 2:
			scanf("%lf", &mid); for (i = 1; i <= n; ++i) scanf("%lf", &x[i]);
			for (avg1 = 0, i = 1; i <= n; ++i) avg1 += x[i]; avg1 /= n;
			for (sdx = 0, i = 1; i <= n; ++i) sdx += square(x[i]-avg1); sdx = sqrt(sdx/(n*(n-1)));
			printf("%.2f\n", (avg1-mid)/sdx);
			break;
		case 3:
		case 4:
			for (i = 1; i <= n; ++i) scanf("%lf", &x[i]);
			for (i = 1; i <= n; ++i) scanf("%lf", &y[i]);
			for (avg1 = avg2 = 0, i = 1; i <= n; ++i) { avg1 += x[i]; avg2 += y[i]; } avg1 /= n; avg2 /= n;
			for (sdx = sdy = 0, i = 1; i <= n; ++i) {
				sdx += square(x[i]-avg1); sdy += square(y[i]-avg2);
			} sdx = sqrt(sdx); sdy = sqrt(sdy);
			for (r = 0, i = 1; i <= n; ++i) r += (x[i]-avg1)*(y[i]-avg2); r /= sdx * sdy;
			b = r * sdy / sdx; a = avg2 - b * avg1;
			if (p == 3) printf("%.2f\n", r); else printf("%.2f %.2f\n", a, b);
	}
}

int main()
{
	while (scanf("%d%d", &p, &n) != EOF) conduct();
	return 0;
}
