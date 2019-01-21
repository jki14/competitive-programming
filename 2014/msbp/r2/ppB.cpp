#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<map>
using namespace std;

struct node {
	double x, y;
	node operator+(const node &p) const {
		node ret; ret.x=x+p.x;
		ret.y=y+p.y; return ret;
	} node operator-(const node &p) const {
		node ret; ret.x=x-p.x;
		ret.y=y-p.y; return ret;
	} node operator*(const double c) const {
		node ret; ret.x=x*c;
		ret.y=y*c; return ret;
	} node operator/(const double c) const {
		node ret; ret.x=x/c;
		ret.y=y/c; return ret;
	}
};

#define N 2100
double st[N], ed[N];
int seq[N];
double rr, hh, rate, br, bh;
int n, m;
node cen;
const double eps = 1e-9;
const double pi = acos(-1.0);
#define SQR(x) ((x)*(x))

double getdis(const node &p1, const node &p2) { return sqrt(SQR(p2.x-p1.x)+SQR(p2.y-p1.y)); }
node unit(const node &v) { return v/sqrt(SQR(v.x)+SQR(v.y)); }

inline double check(int x) { 
	if (x<m) return st[x]; else return ed[x-m];
}
int cmp(const int &i, const int &j) {
	double x = check(i);
	double y = check(j);
	return x-y<-eps;
}

void insert(double x, double y) { st[m]=x; ed[m]=y; ++m; }

double search(const node &p, double lft, double rit, double hei) {
	node ori, vec, tp;
	double dis, mid, mid2;
	vec=unit(p-cen); ori.x=-vec.y; ori.y=vec.x;
	while (rit-lft>eps) {
		mid=(rit+lft)/2.0; mid2=sqrt(SQR(br)-SQR(mid));
		tp=p+vec*mid+ori*mid2;
		dis=getdis(tp, cen);
		if ((rr-dis)*rate-bh>eps) lft=mid;
		else rit=mid;
	}
	return lft;
}

void work() {
	int i, ove;
	double dis1, dis2, tmp, len1, len2, off1, off2, ans;
	node tp, stp, edp, ori, vec;
	scanf("%lf%lf", &rr, &hh); rate=hh/rr;
	scanf("%d", &n); m=0;
	for (i=0; i<n; ++i) {
		scanf("%lf%lf%lf%lf", &tp.x, &tp.y, &br, &bh);
		dis1=getdis(cen, tp);	dis2=sqrt(SQR(dis1)-SQR(br));
		tmp=(rr-dis1-br)*rate;
		if (tmp-bh>-eps) continue;
		tmp=(rr-dis2)*rate;
		if (tmp-bh<eps) tmp=bh;
		len2=search(tp, -br*br/dis1, br, tmp);
		len1=sqrt(SQR(br)-SQR(len2));
		vec=unit(tp-cen); ori.x=-vec.y; ori.y=vec.x;
		stp=tp+vec*len2-ori*len1; edp=tp+vec*len2+ori*len1;
		off1=atan2(stp.y, stp.x); off2=atan2(edp.y, edp.x);
		if (off1-pi>-eps) off1-=2*pi;
		if (off2-pi>-eps) off2-=2*pi;
		if (off1-off2>eps) { insert(off1, pi); insert(-pi, off2); }
		else insert(off1, off2);
	}
	for (i=0; i<2*m; ++i) seq[i]=i; sort(seq, seq+2*m, cmp);
	for (ans=ove=i=0; i<2*m; ++i)
		if (seq[i]<m) {
			if (!ove) off1=check(seq[i]);
			++ove;
		} else {
			--ove;
			if (!ove) ans+=check(seq[i])-off1;
		}
	printf("%.6f\n", (2.0*pi-ans)/(2.0*pi));
}

int main() {
	cen.x=0.0; cen.y=0.0;
	int T; scanf("%d", &T);
	for (int _T=1; _T<=T; ++_T) {
		printf("Case %d: ", _T);
		work();
	}
	return 0;
}
