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

#define N 21
#define S 1100000

int n,T,mk[S],bit[N],tail;
double x[N],y[N],g[N][N],srcx,srcy;
double f[S];

double dist(const double &x0,const double &y0,const double &x1,const double &y1){
	return sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
}

void work(){
	scanf("%lf%lf",&srcx,&srcy);
	scanf("%d",&n);n<<=1;
	for(int i=0;i<n;i++)scanf("%lf%lf",&x[i],&y[i]);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			g[i][j]=dist(x[i],y[i],x[j],y[j])+min(dist(x[i],y[i],srcx,srcy),dist(x[j],y[j],srcx,srcy));
	memset(mk,0,sizeof(mk));f[0]=0.0;mk[0]=1;tail=(1<<n)-1;
	for(int sta=0;sta<tail;sta++){
		if(!mk[sta])continue;
		int u,v;for(u=0;sta&bit[u];)u++;
		for(v=0;v<n;v++){
			if(sta&bit[v] || u==v)continue;
			int newsta=sta|bit[u]|bit[v];
			double val=f[sta]+g[u][v];
			if(!mk[newsta] || val<f[newsta]){ f[newsta]=val;mk[newsta]=1; }
		}
	}
	printf("Case #%d: %.2f\n",T,f[tail]);
}

int main(){
	for(int i=0;i<N;i++)bit[i]=1<<i;
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

