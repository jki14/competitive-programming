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

#define N 1010

const double eps = 1e-9;

struct pnt{
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
} p[N];

inline double submul(const pnt &p1, const pnt &p2) { return p1.x*p2.y-p2.x*p1.y; }
inline double dist2(const pnt &p1, const pnt &p2){ return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y); }

int main(){
	int T;scanf("%d", &T);
	while(T--){
		int n, a, b, c;
		scanf("%d", &n);
		for(int i=0; i<n; i++)scanf("%lf%lf", &p[i].x, &p[i].y);
		for(int i=a=0; i<n; i++){
			if (p[i].y-p[a].y<-eps || (p[i].y-p[a].y<eps && p[i].x-p[a].x<-eps))a=i;
		}
		for(int i=b=c=0; i<n; i++){
			if (i==0 && a==0){ i++; b++; c++; }
			double sib=submul(p[i]-p[a], p[b]-p[a]);
			if(sib>eps || (sib>-eps && dist2(p[i], p[a])-dist2(p[b], p[a])>eps))b=i;
			double sic=submul(p[i]-p[a], p[c]-p[a]);
			if(sic<-eps || (sic<eps && dist2(p[i], p[a])-dist2(p[c], p[a])>eps))c=i;
		}
		int flag=1;
		for (int i=0; i<n; i++){
			if (submul(p[c]-p[b], p[i]-p[b])<-eps){
				flag=0;
				break;
			}
		}
		if(flag){
			printf("Y\n");
		}else printf("N\n");
	}
	return 0;
}
