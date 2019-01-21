#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 1100

const double inf=1e20;
const double eps=1e-3;
const double af=0.88;
const int p=15;
const int l=25;

int n,rid; 

double a,b,delta;
double px[maxn],py[maxn];
double rx[maxn],ry[maxn],d[maxn];

double sqr(double x){
	return x*x;
}

double func(double x,double y){
	double res=inf;
	for(int i=0;i<n;i++)
		res=min(res,sqrt(sqr(x-px[i])+sqr(y-py[i])));
	return res;
}

int allow(double x,double y){
	if(x<0.0-eps || x>a+eps)return 0;
	if(y<0.0-eps || y>b+eps)return 0;
	return 1;
}

void work(){
	int i,j;
	double x,y,tmpd;
	double x0,y0;
	scanf("%lf%lf%d",&a,&b,&n);
	for(i=0;i<n;i++)scanf("%lf%lf",&px[i],&py[i]);
	delta=max(a,b)/(sqrt((double)n));
	for(i=0;i<p;i++){
		rx[i]=((double)(rand()%1001))/1000.0*a;
		ry[i]=((double)(rand()%1001))/1000.0*b;
		rx[i]=fabs(rx[i]);ry[i]=fabs(ry[i]);
		d[i]=func(rx[i],ry[i]);
	}
	for(;delta>eps;delta*=af){
		for(i=0;i<p;i++){x0=rx[i];y0=ry[i];
			for(j=0;j<l;j++){
				//seed=((double)(rand()%2000))/1000.0*pi;
				//seed=double(rand()%1000+1)/1000.000*10*pi;
				//x=rx[i]+cos(seed)*delta;
				//y=ry[i]+sin(seed)*delta;	
				//x=x0+cos(seed)*delta;
				//y=y0+sin(seed)*delta;	
				x=((double)((rand()%2001)-1000))/1000.0*delta;
				//if(sqr(delta)<sqr(x))printf("d=%.6lf x=%.6lf",delta,x);
				y=sqrt(fabs(sqr(delta)-sqr(x)));
				y*=((rand()%2)==0)?1.0:-1.0;
				x+=x0;y+=y0;x=fabs(x);y=fabs(y);
				if(!allow(x,y))continue;
				tmpd=func(x,y);
				//if(n==1)printf("%.1lf %.1lf tmpd=%.1lf\n",x,y,tmpd);
				if(tmpd>d[i]){
					rx[i]=x;
					ry[i]=y;
					d[i]=tmpd;
				}
			}
		}
	}
	for(i=rid=0;i<p;i++){
		if(d[rid]<d[i])rid=i;
	}
	printf("The safest point is (%.1f, %.1f).\n",rx[rid],ry[rid]);
}

int main(){
	int t;scanf("%d",&t);
	srand(152);
	while(t--)work();
	return 0;
}

