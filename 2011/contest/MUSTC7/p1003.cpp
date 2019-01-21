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
#include<set>
#include<map>
using namespace std;

#define maxn 110000

const double eps=1e-6;

double x[maxn],y[maxn];
double a,b,c;

int n,m,p1,p2;

int prev(const int &x){ return (x)?x-1:n-1; }
int next(const int &x){ return (x+1)%n; }
int frid(const int &x){ return x+m; }
int path(const int &x){
	int d,ret;
	d=x-p1;if(d<0)d+=n;
	ret=p1-d;
	if(ret<0)ret+=n;
	return ret;
}

int succ(){
	double xx,yy,d;
	int i,j;
	for(i=0;i<n;i++){
		if(i==p1 || i==p2)continue;
		
		j=path(i);

		d=a*a+b*b;
		xx=(b*b*x[i]-a*a*x[i]-2*a*b*y[i]-2*a*c)/d;
		yy=(a*a*y[i]-b*b*y[i]-2*a*b*x[i]-2*b*c)/d;
		
		//printf("   the pair point is (%.2f,%.2f)<->(%.2f,%.2f) in fact (%.2f,%.2f)\n",x[i],y[i],xx,yy,x[j],y[j]);		
		if(fabs(x[j]-xx)>eps || fabs(y[j]-yy)>eps)return 0;
	}
	return 1;
}

void work(){
	int i,k,t;
	n=m*2;
	for(i=1;i<n;i+=2){
		scanf("%lf%lf",&x[i],&y[i]);	
	}
	for(i=0;i<n;i+=2){
		x[i]=(x[prev(i)]+x[next(i)])/2.0;
		y[i]=(y[prev(i)]+y[next(i)])/2.0;
	}
	for(k=0;k<n;k++){t=frid(k);p1=k;p2=t;
		//printf("Line on Seg (%.2f,%.2f)->(%.2f,%.2f)\n",x[k],y[k],x[t],y[t]);
		a=y[t]-y[k];
		b=x[k]-x[t];
		c=x[t]*y[k]-x[k]*y[t];
		if(succ()){
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}

int main(){
	while(scanf("%d",&m)!=EOF)work();
	return 0;
}

