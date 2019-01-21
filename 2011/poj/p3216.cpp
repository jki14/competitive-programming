#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 30
#define maxm 210

int n,m,res;
int c[maxn][maxn];
int g[maxm][maxm],mk[maxm],pnt[maxm],id;
int p[maxm],t[maxm],d[maxm];

int link(const int &u){
	if(mk[u]==id)return 0;mk[u]=id;
	for(int v=1;v<=m;v++)
		if(g[u][v] && (pnt[v]==0 || link(pnt[v]))){
			pnt[v]=u;
			return 1;
		}
	return 0;
}

void work(){
	int i,j,k;
	memset(c,0x3f,sizeof(c));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			scanf("%d",&k);
			if(k==-1)continue;
			c[i][j]=k;
		}
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
	memset(g,0,sizeof(g));res=m;
	for(i=1;i<=m;i++)scanf("%d%d%d",&p[i],&t[i],&d[i]);
	for(i=1;i<=m;i++)
		for(j=1;j<=m;j++){
			if(i==j)continue;
			if(t[i]+d[i]+c[p[i]][p[j]]<=t[j])
				g[i][j]=1;
		}
	memset(mk,0,sizeof(mk));
	memset(pnt,0,sizeof(pnt));
	for(i=1;i<=m;i++){id=i;
		if(link(i))res--;
	}
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))
		work();
	return 0;
}

