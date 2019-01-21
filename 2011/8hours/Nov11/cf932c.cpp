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

const double eps=1e-8;
const double inf=1e8;

int ans1,ans2;
double best;
double t1,t2,x1,x2,t0;

void work(){
	best=inf;ans1=ans2=0;
	for(double r1=0.0;r1<x1+eps;r1+=1.0){
		double rig=r1*t1-r1*t0,lef=t0-t2;
		//printf("rig=%.5f lef=%.5f\n",rig,lef);
		double r2;
		if(r1<eps || fabs(lef)<eps)
			r2=x2;
		else r2=rig/lef;
		//printf("r1=%.2f r2=%.2f\n",r1,r2);
		int y1=r1,y2=ceil(r2-eps);
		//printf("y1=%d y2=%d\n",y1,y2);	
		double val=(((double)y1)*t1+((double)y2)*t2)/((double)(y1+y2))-t0;
		while(val+eps<0.0){ val+=t2;y2++; }
		//printf("r1=%.5f r2=%.5f y1=%d y2=%d best=%.10f val=%.10f\n",r1,r2,y1,y2,best,val);
		if(y2>x2)continue;
		if(best>val+eps || (fabs(best-val)<eps && ans1+ans2<y1+y2)){
			best=val;ans1=y1;ans2=y2;
		}
	}
	printf("%d %d\n",ans1,ans2);
}

int main(){
	while(scanf("%lf%lf%lf%lf%lf",&t1,&t2,&x1,&x2,&t0)!=EOF)
			work();
	return 0;
}

