#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 100

int n,m;
int g[maxn][maxn];
int d[maxn];
int vis[maxn];

void work(){
	memset(g,0x7f,sizeof(g));
	int i,j,b,v,l;
	for(i=0;i<n;i++){
		scanf("%d%d",&m,&b);
		if(b)g[i][n]=0;
		for(j=0;j<m;j++){
			scanf("%d%d",&v,&l);
			if(g[i][v]>l)g[i][v]=l;
		}
	}
	memset(vis,0,sizeof(vis));
	vis[0]=1;for(i=0;i<=n;i++)d[i]=g[0][i];
	for(j=0;j<n;j++){
		l=0x3fffffff;
		for(i=0;i<=n;i++)
			if(!vis[i] && l>d[i]){
				l=d[i];v=i;
			}
		vis[v]=1;
		for(i=0;i<=n;i++)
			if(d[i]>d[v]+g[v][i])
				d[i]=d[v]+g[v][i];
	}
	printf("%d\n",d[n]);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}
