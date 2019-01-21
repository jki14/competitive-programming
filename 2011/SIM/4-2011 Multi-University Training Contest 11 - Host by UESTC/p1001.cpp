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

const double g = 9.8;
const double eps = 1e-6;

double gettime(double h, double v) { return sqrt((2*h*g+v*v)/(g*g)) + v/g; }

int main()
{
	double t0, t1, vx, vy, x1, x2, x3, h, v1, v2, v3;
	char str[10];
	while (scanf("%lf%s%lf%lf", &h, str, &vx, &vy) != EOF) {
		t1 = gettime(h, vy);
		switch (str[0]) {
			case 'R': printf("%.3f\n", t1*vx); break;
			case 'Y':
				scanf("%lf", &t0);
				if (t1 - t0 > eps) {
					h = h + vy * t0 - g * t0 * t0 / 2; x1 = vx * t0;
					vy = 2 * (vy - g * t0); vx *= 2;
					t1 = gettime(h, vy); x2 = vx * t1;
					printf("%.3f\n", x1+x2); break;
				} else { printf("%.3f\n", t1*vx); break; }
			case 'B':
				scanf("%lf%lf%lf%lf", &t0, &v1, &v2, &v3);
				if (t1 - t0 > eps) {
					x1 = vx * t0 + v1 * (t1 - t0);
					x2 = vx * t0 + v2 * (t1 - t0);
					x3 = vx * t0 + v3 * (t1 - t0);
					printf("%.3f %.3f %.3f\n", x1, x2, x3);
				} else printf("%.3f\n", t1 * vx); break;
		}
	}
}

