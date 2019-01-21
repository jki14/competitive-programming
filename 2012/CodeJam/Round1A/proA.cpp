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

#define N 110000

int n,m;
double dn,dm,res;
double a[N],p[N];

double min(const double &x,const double &y){ return x<y?x:y; }

double core(){
	scanf("%d%d",&n,&m);dn=(double)n;dm=(double)m;
	for(int i=1;i<=n;i++)scanf("%lf",&a[i]);p[0]=1.0;
	for(int i=1;i<=n;i++)p[i]=p[i-1]*a[i];
	res=dm+2.0;
	for(int i=0;i<=n;i++){double di=(double)i;
		res=min(res,(dn-di)*2.0+dm-dn+1.0+(1.0-p[i])*(dm+1.0));
	}
	return res;
}

int main(){
	int T;scanf("%d",&T);
	for(int i=1;i<=T;i++){
		printf("Case #%d: %.6f",i,core());
		printf("\n");
	}
	return 0;
}
