#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

const int maxn=200,maxm=50000,limit=2100000,inf=0x3fffffff;

int n,m,ans;

int c[maxm],f[maxm],w[maxm],ev[maxm],be[maxm],next[maxm];
int value[maxn],nbs[maxn],pnt[maxn],d[maxn],mk[maxn],open[maxn],oldque[maxn];
int num;

void AddEdge(int u,int v,int cc,int ww){
	next[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
	ev[num]=v;c[num]=cc;f[num]=0;w[num]=ww;
	next[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
	ev[num]=u;c[num]=0;f[num]=0;w[num]=-ww;
}

int maxflow(int s,int t){
	int cur,tail,j,u,v,flow=0;
	do{
		memset(mk,0,sizeof(mk));
		memset(d,0,sizeof(d));
		open[0]=s;mk[s]=1;d[s]=0x3fffffff;
		for(pnt[s]=cur=tail=0;cur<=tail&&!mk[t];cur++)
			for(u=open[cur],j=nbs[u];j;j=next[j]){
				v=ev[j];
				if(!mk[v]&&f[j]<c[j]){
					mk[v]=1;open[++tail]=v;pnt[v]=j;
					if(d[u]<c[j]-f[j])d[v]=d[u];else d[v]=c[j]-f[j];
				}
			}
		if(!mk[t])break;flow+=d[t];
		for(u=t;u!=s;u=ev[be[j]]){
			j=pnt[u];f[j]+=d[t];f[be[j]]=-f[j];
		}
	}while(d[t]>0);
	return flow;
}

int mincost(int s,int t){
	int cur,tail,t1,i,j,u,v,flow=0,cost=0;
	do{
		memset(d,0,sizeof(0));
		for(i=1;i<=n;i++)value[i]=inf;
		open[0]=s;d[s]=0x3fffffff;tail=value[s]=0;
		while(tail>=0){
			memset(mk,0,sizeof(mk));
			memcpy(oldque,open,sizeof(open));
			for(t1=tail,pnt[s]=cur=0,tail=-1;cur<=t1;cur++)
				for(u=oldque[cur],j=nbs[u];j;j=next[j]){
					v=ev[j];
					if(f[j]<c[j] && value[u]<inf && value[u]+w[j]<value[v]){
						if(!mk[v]){
							mk[v]=1;open[++tail]=v;
						}
						pnt[v]=j;value[v]=value[u]+w[j];
						if(d[u]<c[j]-f[j])d[v]=d[u];else d[v]=c[j]-f[j];
					}
				}
		}
		if(value[t]==inf)break;
		flow+=d[t];cost+=d[t]*value[t];
		for(u=t;u!=s;u=ev[be[j]]){
			j=pnt[u];f[j]+=d[t];f[be[j]]=-f[j];
		}
	}while(d[t]>0);return cost;
}

void doit(){
	int i,x,y,v,p;n++;
	num=0;memset(nbs,0,sizeof(nbs));
	for(i=2;i<n;i++){
		scanf("%d",&v);
		AddEdge(i,n,limit,-v);
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d%d",&x,&y,&v,&p);
		AddEdge(x,y,v,p);
		AddEdge(y,x,v,p);
	}
	v=maxflow(1,n);
	AddEdge(n+1,1,v,0);
	AddEdge(1,n,v,0);
	memset(f,0,sizeof(f));n++;
	ans=-mincost(n,n-1);
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		doit();
	return 0;
}

