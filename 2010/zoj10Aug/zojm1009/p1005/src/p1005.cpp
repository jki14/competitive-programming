#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <set>
using namespace std;

const int maxn=1100;
const double eps=1e-8;

int dcmp(double x);

struct TPoint{
	double x,y;
	bool operator =(const TPoint &a) const {
		return dcmp(a.x-x)==0;
	}
	bool operator <(const TPoint &a) const {
		return a.x+eps<x || (dcmp(a.x-x)==0 && a.y+eps<y);
	}
};

struct TSeg{
	TPoint u,v;
};

int n,ans;
TSeg a[maxn];
set<TPoint> s;
//map<TPoint,int>::iterator it;

int dcmp(double x){
	if(x<-eps)return -1;else return (x>eps);
}

double cross(TPoint p0,TPoint p1,TPoint p2){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double dot(TPoint p0,TPoint p1,TPoint p2){
	return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}

double PointOnSegment(TPoint p0,TPoint p1,TPoint p2){
	return dcmp(cross(p0,p1,p2))==0 && dcmp(dot(p0,p1,p2))<=0;
}

double LineIntersection(TPoint p1,TPoint p2,TPoint p3,TPoint p4,TPoint &cp){
	int u=cross(p1,p2,p3),v=cross(p2,p1,p4);
	if(dcmp(u+v)){
		cp.x=(p3.x*v+p4.x*u)/(v+u);
		cp.y=(p3.y*v+p4.y*u)/(v+u);
		return 1;
	}
	return 0;
	/*if(dcmp(u))return 0;
	if(dcmp(cross(p3,p4,p1)))return 0;
	return -1;*/
}

double SegmentIntersection(TPoint p1,TPoint p2,TPoint p3,TPoint p4,TPoint &cp){
	int ret=LineIntersection(p1,p2,p3,p4,cp);
	if(ret==1)return PointOnSegment(cp,p1,p2) && PointOnSegment(cp,p3,p4);
	//if(ret==-1 && ( PointOnSegment(p1,p3,p4)||PointOnSegment(p2,p3,p4)||PointOnSegment(p3,p1,p2)||PointOnSegment(p4,p1,p2)))
		//return -1;
	return 0;
}

void doit(){
	int i,j;ans=0;
	int x1,y1,x2,y2;
	TPoint cp;
	s.clear();
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		a[i].u.x=(double)x1;a[i].u.y=(double)y1;
		a[i].v.x=(double)x2;a[i].v.y=(double)y2;
	}
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(SegmentIntersection(a[i].u,a[i].v,a[j].u,a[j].v,cp)==1){
				//s.insert(cp);
				//it=s.find(cp);
				/*if(it==s.end()){
					ans++;
					s.insert(pair<TPoint,int>(cp,1));
				}else
					(*it).second++;*/
				ans++;
			}
	//printf("%d\n",s.size());
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF)doit();
	return 0;
}
