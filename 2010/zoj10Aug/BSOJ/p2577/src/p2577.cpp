#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 2100

#define u i
#define v i+l-1

#define wf(x,y) (sf[y]-sf[x-1])
#define wg(x,y) (sg[y]-sg[x-1])

const int inf=LONG_MAX;

int n;
int a[maxn],df[maxn][maxn],dg[maxn][maxn];
int f[maxn][maxn],g[maxn][maxn],sf[maxn],sg[maxn],ans1,ans2;

void work(){
	int i,k,l;
	memset(sf,0,sizeof(sf));
	memset(sg,0,sizeof(sg));
	memset(f,0x7f,sizeof(f));
	memset(g,0x7f,sizeof(g));
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sf[i]=sf[i-1]+a[i];
		sg[i]=sg[i-1]-a[i];
		f[i][i]=g[i][i]=0;
		df[i][i]=dg[i][i]=i;
	}
	for(i=n+1;i<=n*2;i++){
		a[i]=a[i-n];
		sf[i]=sf[i-1]+a[i];
		sg[i]=sg[i-1]-a[i];
		f[i][i]=g[i][i]=0;
		df[i][i]=dg[i][i]=i;
	}
	for(l=2;l<=n;l++)
		for(u=1;v<n*2;u++){
			for(k=df[u][v-1];k<=df[u+1][v] && k<v;k++){
				if(f[u][v]>f[u][k]+f[k+1][v]+wf(u,v)){
					f[u][v]=f[u][k]+f[k+1][v]+wf(u,v);
					df[u][v]=k;
				}
			}
			/*for(k=dg[u][v-1];k<=dg[u+1][v] && k<v;k++){
				if(g[u][v]>g[u][k]+g[k+1][v]+wg(u,v)){
					g[u][v]=g[u][k]+g[k+1][v]+wg(u,v);
					dg[u][v]=k;
				}
			}*/
			g[u][v]=g[u+1][v]+wg(u,v);if(g[u][v]>g[u][v-1]+wg(u,v))g[u][v]=g[u][v-1]+wg(u,v);
		}
	ans1=inf;ans2=-inf;
	for(u=1,l=n;v<n*2;u++){
		if(ans1>f[u][v])ans1=f[u][v];
		if(ans2<-g[u][v])ans2=-g[u][v];
	}
	printf("%d\n%d\n",ans1,ans2);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}
