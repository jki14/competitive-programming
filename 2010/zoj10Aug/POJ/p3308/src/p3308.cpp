#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxv 210
#define maxe 11000

#define half 100

#define src 0
#define tar 201

const double inf = 0x7fffffff;

int n,m,l;

double c[maxe],f[maxe],d[maxv];
int ev[maxe],be[maxe],next[maxe],num;
int nbs[maxv],pnt[maxv],open[maxv],mk[maxv];

double log2(double x){ return log(x)/log(2); }

void AddEdge(int u,int v,double cc){
	next[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
	ev[num]=v;c[num]=cc;f[num]=0;
	next[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
	ev[num]=u;c[num]=0;f[num]=0;
}

double MaxFlow(int n,int s,int t){
	int cur,tail,j,u,v;
	double flow=0;
	do{memset(mk,0,sizeof(mk)); memset(d,0,sizeof(d));
		open[0]=s;mk[s]=1;d[s]=inf;
		for(pnt[s]=cur=tail=0;cur<=tail && !mk[t];cur++)
			for(u=open[cur],j=nbs[u];j;j=next[j]){v=ev[j];
				if(!mk[v]&&f[j]<c[j]){
					mk[v]=1;open[++tail]=v;pnt[v]=j;
					if(d[u]<c[j]-f[j])d[v]=d[u];else d[v]=c[j]-f[j];
				}
			}
		if(!mk[t])break;flow+=d[t];
		for(u=t;u!=s;u=ev[be[j]]){j=pnt[u];f[j]+=d[t];f[be[j]]=-f[j];}
	}while(d[t]>0);return flow;
}

void work(){
	memset(nbs,0,sizeof(nbs));num=0;
	scanf("%d%d%d",&m,&n,&l);
	double x,res;int u,v;
	for(v=1;v<=m;v++){
		scanf("%lf",&x);
		AddEdge(src,v,log2(x));
	}
	for(u=1;u<=n;u++){
		scanf("%lf",&x);
		AddEdge(u+half,tar,log2(x));
	}
	while(l--){
		scanf("%d%d",&u,&v);v+=half;
		AddEdge(u,v,inf);
	}
	res=pow(2,MaxFlow(tar,src,tar));
	printf("%.4f\n",res);
}

int main(){
	int t;scanf("%d",&t);while(t--)work();
	return 0;
}
