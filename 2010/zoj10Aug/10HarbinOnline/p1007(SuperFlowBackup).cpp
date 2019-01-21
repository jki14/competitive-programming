#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 1100
#define inf 0x3fffffff
int n,m,k,a,b,maxp;
int c[maxn][maxn],lev[maxn];
int f[maxn][maxn],pnt[maxn],open[maxn],d[maxn],mk[maxn];

int maxflow(int s,int t){
	int cur,tail,u,v,flow=0;memset(f,0,sizeof(f));
	do{ memset(mk,0,sizeof(mk)); memset(d,0,sizeof(d));
		open[0]=s;mk[s]=1;d[s]=inf;
		for(pnt[s]=cur=tail=0;cur<=tail && !mk[t];cur++)
			for(u=open[cur],v=1;v<=n;v++) if(!mk[v] && f[u][v]<c[u][v]){
				mk[v]=1;open[++tail]=v;pnt[v]=u;
				if(d[u]<c[u][v]-f[u][v])d[v]=d[u];
					else d[v]=c[u][v]-f[u][v];
			}
		if(!mk[t])break;flow+=d[t];
		for(u=t;u!=s;){ v=u;u=pnt[v];f[u][v]+=d[t];f[v][u]=-f[u][v]; }
	}while(d[t]>0);return flow;
}

void doit(){
	int i,j,u,v,s,t,x;
	maxp=0;
	memset(c,0,sizeof(c));
	for(i=1;i<=n;i++)
		scanf("%d",&lev[i]);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&x);
		if(lev[u]+1==lev[v]){
			c[u][v]+=x;
			//s[lev[v]]+=x;if(maxp<s[lev[v]])maxp=s[lev[v]];
		}
	}
	printf("%d\n",maxflow(a,b));
	s=n+1;t=n+2;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)if(i!=j && c[i][j]){
			c[s][j]=c[i][t]=c[i][j];
			c[i][j]=inf;
		}
	c[a][b]=inf;c[b][a]=inf;
	printf("%d\n",maxflow(s,t));
}

int main(){
	while(scanf("%d%d%d%d%d",&n,&m,&k,&a,&b)!=EOF)doit();
	return 0;
}
