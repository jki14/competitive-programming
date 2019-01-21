#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

#define N 300
#define T 10000

const double eps=1e-4;

const double pi=acos(-1.0);
const double g=9.8;

int n,ans;
double h,el,er,fl,fr;
double a[N];

inline double sqr(const double &x){ return x*x; }

int main(){
	//printf("pi=%.6f\n",pi);
	while(scanf("%d",&n)!=EOF && n){ans=0;
		scanf("%lf%lf%lf%lf%lf",&h,&el,&er,&fl,&fr);
		for(int i=0;i<n;i++)scanf("%lf",&a[i]);
		for(int i=0;i<=T;i++){
			int res=0;double p=pi*((double)i)/((double)T);
			for(int i=0;i<n;i++){
				double vx=a[i]*sin(p),vy=a[i]*cos(p);
				double t=(vy+sqrt(sqr(vy)+2.0*g*h))/g;
				double d=vx*t;
				if(d>fl-eps && d<fr+eps){ res=0;break; }
				if(d>el-eps && d<er+eps){
					res++;
					//printf("hint d=%.6f\n",d);
				}
				//if(i==0)printf("vx=%.6f vy=%.6f t=%.6f\n",vx,vy,t);
				//if(i==0)printf("d=%.6f\n",d);
			}
			if(ans<res)ans=res;
		}
		printf("%d\n",ans);
	}
	return 0;
}
