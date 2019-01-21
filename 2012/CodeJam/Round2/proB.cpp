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

#define N 1100

#define pos id[p]

const double eps=1e-4;

int n,p,id[N];
double w,l,a[N];
double x[N],y[N];
double xb,yr,last;

inline double max(const double &x,const double &y){ return x>y?x:y; }

int cmp(const int &x,const int &y){ return a[x]>a[y]; }

int main(){
	int T;scanf("%d",&T);
	for(int tim=1;tim<=T;tim++){printf("Case #%d:",tim);
		scanf("%d%lf%lf",&n,&w,&l);
		for(int i=0;i<n;i++){ scanf("%lf",&a[i]);id[i]=i; }
		sort(id,id+n,cmp);xb=0.0;p=0;
		while(p<n){
			last=xb;yr=xb=0.0;
			while(p<n && ((yr>eps)?yr+a[pos]<l+eps:yr<l+eps)){
				x[pos]=(last>eps)?last+a[pos]:last;
				y[pos]=(yr>eps)?yr+a[pos]:yr;
				if(x[pos]>w+eps)printf("Error\n");
				xb=max(xb,x[pos]+a[pos]);
				yr=y[pos]+a[pos];
				p++;
			}
		}
		for(int i=0;i<n;i++)printf(" %.2f %.2f",x[i],y[i]);
		printf("\n");
	}
	return 0;
}
