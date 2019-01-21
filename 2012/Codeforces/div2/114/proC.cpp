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

int n;
double a,d,nec;

int main(){
	scanf("%d%lf%lf",&n,&a,&d);nec=0.0;
	for(int i=0;i<n;i++){
		double t,v;scanf("%lf%lf",&t,&v);
		double atim=v/a,time;
		if(atim*v/2.0>d+eps){
			time=sqrt(2*d/a);
		}else{
			time=atim+((d-atim*v/2.0)/v);
		}
		nec=max(time+t,nec);
		printf("%.6f\n",nec);
	}
	return 0;
}
