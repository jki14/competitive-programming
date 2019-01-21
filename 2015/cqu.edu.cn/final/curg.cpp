#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
using namespace std;

const double eps = 1e-6;
struct pnt {
	double x, y;
	pnt operator+(const pnt &p) const {
		pnt ret; ret.x=x+p.x;
		ret.y=y+p.y; return ret;
	}
	pnt operator-(const pnt &p) const {
		pnt ret; ret.x=x-p.x;
		ret.y=y-p.y; return ret;
	}
	pnt operator*(const double c) const {
		pnt ret; ret.x=x*c;
		ret.y=y*c; return ret;
	}
	pnt operator/(const double c) const {
		pnt ret; ret.x=x/c;
		ret.y=y/c; return ret;
	}
};
#define N 1010
pnt p[N];
int n;

double submul(const pnt &p1, const pnt &p2) { return p1.x*p2.y-p2.x*p1.y; }

void conduct() {
	scanf("%d", &n);
	for (int i = 0; i<n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
	int a, b, c;
	for (int i=a=0; i<n; ++i)
		if (p[i].y-p[a].y<-eps) a=i;
	for (int i=b=c=0; i<n; ++i) {
		if (i==0 && a==0) { ++i; ++b; ++c; }
		if (submul(p[i]-p[a], p[b]-p[a])>eps) b=i;
		if (submul(p[i]-p[a], p[c]-p[a])<-eps) c=i;
	}
	for (int i=0; i<n; ++i)
		if (submul(p[c]-p[b], p[i]-p[b])<-eps) {
			printf("N\n");
			return;
		}
	printf("Y\n");
}

int main() {
	int time; scanf("%d", &time);
	while (time--) {
		conduct();
	}
}
