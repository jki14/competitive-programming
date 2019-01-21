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

#define N 210

const double eps = 1e-8;

int n,m,imp[N];
double f[N][N],c;

void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%lf",&f[i][j]);
			if(fabs(f[i][j]-0.0)<eps)f[i][j]=eps;
			f[i][j]=1.0/(f[i][j]/100.0);
			//printf("f[%d][%d]=%.7f\n",i,j,f[i][j]);
		}
	}
	scanf("%d",&m);memset(imp,0,sizeof(imp));
	while(m--){ int p;scanf("%d",&p);imp[p]=1; }
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]*f[k][j]);
	for(int k=1;k<=n;k++){
		if(!imp[k])continue;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	}
	scanf("%lf",&c);
	printf("%.7f\n",f[1][2]*c+eps);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)
		work();
	return 0;
}

