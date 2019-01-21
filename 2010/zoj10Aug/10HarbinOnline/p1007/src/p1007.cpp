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
#define inf 1100000
#define ul 110000

int n,_n,m,k,a,b,maxp;
int c[maxn][maxn],_c[maxn][maxn],lev[maxn];
int f[maxn][maxn],_f[maxn][maxn],pnt[maxn],open[maxn],d[maxn],mk[maxn];

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

int _maxflow(int s,int t){
	int cur,tail,u,v,flow=0;memset(_f,0,sizeof(_f));
	do{ memset(mk,0,sizeof(mk)); memset(d,0,sizeof(d));
		open[0]=s;mk[s]=1;d[s]=inf;
		for(pnt[s]=cur=tail=0;cur<=tail && !mk[t];cur++)
			for(u=open[cur],v=1;v<=_n;v++) if(!mk[v] && _f[u][v]<_c[u][v]){
				mk[v]=1;open[++tail]=v;pnt[v]=u;
				if(d[u]<_c[u][v]-_f[u][v])d[v]=d[u];
					else d[v]=_c[u][v]-_f[u][v];
			}
		if(!mk[t])break;flow+=d[t];
		for(u=t;u!=s;){ v=u;u=pnt[v];_f[u][v]+=d[t];_f[v][u]=-_f[u][v]; }
	}while(d[t]>0);return flow;
}

void doit(){
	int i,j,u,v,s,t,x;
	maxp=0;
	memset(c,0,sizeof(c));
	memset(_c,0,sizeof(_c));
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
			_c[s][j]=c[i][t]=c[i][j];
			_c[i][j]=ul-c[i][j];
		}
	_c[a][b]=inf;_c[b][a]=inf;
	_n=n+2;cout<<"<>"<<_maxflow(s,t)<<endl;
	cout<<"::"<<_f[4][1]<<endl;
	//for(i=1;i<=_n;i++)
		//if(_f[b][i]>0)maxp+=_f[b][i];
	printf("%d\n",maxp);
}

int main(){
	while(scanf("%d%d%d%d%d",&n,&m,&k,&a,&b)!=EOF)doit();
	return 0;
}
