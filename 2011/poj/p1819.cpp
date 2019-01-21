#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

struct SPoint{
	double x,y;
};

typedef struct SPoint TPoint;

#define maxn 1100
 
const double eps=1e-7;
const double pi=acos(-1.0);

int n,m,p;
int path[maxn];
int mk[maxn];
double r[maxn];
TPoint core[maxn];

double sqr(const double &x){ return x*x; }

void work(){
	int i,j;
	double x,y,k;
	for(i=0;i<n;i++)scanf("%lf",&r[i]);
	core[0].x=core[0].y=r[0];m=0;
	memset(path,-1,sizeof(path));
	for(i=1;i<n;i++){x=y=r[i];
		for(j=0;j<i;j++){
			k=sqrt(sqr(r[i]+r[j])-sqr(r[i]-r[j]));
			k+=core[j].y;
			if(k>y+eps){
				y=k;
				path[i]=j;
			}
		}
		core[i].x=x;core[i].y=y;
		if(core[m].y+r[m]+eps<core[i].y+r[i])m=i;
	}
	memset(mk,0,sizeof(mk));p=n;
	for(i=m;i!=-1;i=path[i]){
		mk[i]=1;p--;
	}
	printf("%d\n",p);
	for(i=0;i<n;i++)
		if(!mk[i])printf("%d\n",i+1);
}

int main(){
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}
