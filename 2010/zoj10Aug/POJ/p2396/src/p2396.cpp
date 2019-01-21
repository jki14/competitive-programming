#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxv 510
#define maxe 1000000

#define src 0
#define tai 501

#define _src 502
#define _tai 503

const int inf=1<<29;

int n,m,k,allow;

int matc[maxv][maxv],matb[maxv][maxv],res[maxv][maxv];

int c[maxe],f[maxe],eu[maxe],ev[maxe],be[maxe],next[maxe],num;
int nbs[maxv],pnt[maxv],open[maxv],d[maxv],mk[maxv];

char str[5];

int max(int x,int y){ return (x>y)?x:y; }
int min(int x,int y){ return (x<y)?x:y; }

void AddEdge(int u,int v,int cc){
	//cout<<" addEdge "<<u<<"->"<<v<<" "<<cc<<endl;
	next[++num]=nbs[u]; nbs[u]=num; be[num]=num+1;
	eu[num]=u;ev[num]=v; c[num]=cc; f[num]=0;
	next[++num]=nbs[v]; nbs[v]=num; be[num]=num-1;
	eu[num]=v;ev[num]=u; c[num]=0; f[num]=0;
}

int maxflow(int s,int t){
	int cur,tail,j,u,v,flow=0;
	do{ memset(mk,0,sizeof(mk)); memset(d,0,sizeof(d));
		open[0]=s; mk[s]=1; d[s]=inf;
		for(pnt[s]=cur=tail=0;cur<=tail && !mk[t]; cur++)
			for(u=open[cur],j=nbs[u];j;j=next[j]){ v=ev[j];
				if(!mk[v] && f[j]<c[j]){
					mk[v]=1;open[++tail]=v;pnt[v]=j;
					if(d[u]<c[j]-f[j])d[v]=d[u];else d[v]=c[j]-f[j];
				}
			}
		if(!mk[v])break; flow+=d[t];
		for(u=t;u!=s;u=ev[be[j]]){j=pnt[u];f[j]+=d[t];f[be[j]]=-f[j];}
	}while(d[t]>0); return flow;
}

void UpdateMat(int u,int v,char x,int val){
	//cout<<" UpdateMat "<<u<<"->"<<v<<" "<<x<<" "<<val<<endl;
	switch(x){
		case '=':
			if(matc[u][v]<val)allow=0;
			if(matb[u][v]>val)allow=0;
			matc[u][v]=matb[u][v]=val;
			break;
		case '>':
			matb[u][v]=max(matb[u][v],val+1);
			break;
		case '<':
			matc[u][v]=min(matc[u][v],val-1);
			break;
	}
}

void work(){
	scanf("%d%d",&n,&m);
	int i,u,v,val,sumb=0;
	int nbssrc,nbstai;
	char x;
	num=0;allow=1;
	memset(res,0,sizeof(res));
	memset(nbs,0,sizeof(nbs));
	memset(matc,0x7f,sizeof(matc));
	memset(matb,0,sizeof(matb));
	for(i=1;i<=n;i++){
		scanf("%d",&val);
		//src->i < val
		AddEdge(src,i,val);
		AddEdge(_src,i,0);
		AddEdge(src,_tai,0);
		sumb+=0;
	}
	for(i=n+1;i<=n+m;i++){
		scanf("%d",&val);
		//n+i->tai < val;
		AddEdge(i,tai,val);
		AddEdge(_src,tai,0);
		AddEdge(i,_tai,0);
		sumb+=0;
	}
	scanf("%d",&k);
	for(i=0;i<k;i++){
		scanf("%d%d%s%d",&u,&v,str,&val);v+=n;
		sscanf(str,"%c",&x);
		if(u==0 && v==n){
			for(u=1;u<=n;u++)
				for(v=n+1;v<=n+m;v++)
					UpdateMat(u,v,x,val);
		}else{
			if(u==0){
				for(u=1;u<=n;u++)
					UpdateMat(u,v,x,val);
			}else{
				if(v==n){
					for(v=n+1;v<=n+m;v++)
						UpdateMat(u,v,x,val);
				}else
					UpdateMat(u,v,x,val);
			}
		}
	}
	for(u=1;u<=n;u++)
		for(v=n+1;v<=n+m;v++){
			if(matb[u][v]>matc[u][v])allow=0;
			matc[u][v]=min(matc[u][v],inf);
			//u->v > matb[u][v] & u->v <matc[u][v]
			//cout<<" Edge "<<u<<"->"<<v<<" ("<<matb[u][v]<<","<<matc[u][v]<<")"<<endl;
			AddEdge(u,v,matc[u][v]-matb[u][v]);
			AddEdge(_src,v,matb[u][v]);
			AddEdge(u,_tai,matb[u][v]);
			sumb+=matb[u][v];
			res[u][v]+=matb[u][v];
		}
	if(!allow){ printf("IMPOSSIBLE\n\n");return; }
	//Add Temp Edge
	nbssrc=nbs[src];nbstai=nbs[tai];
	AddEdge(src,tai,inf);AddEdge(tai,src,inf);
	if(maxflow(_src,_tai)<sumb){ printf("IMPOSSIBLE\n\n");return; }
	//Del Temp Edge
	nbs[src]=nbssrc;nbs[tai]=nbstai;num-=2;
	maxflow(src,tai);
	for(i=1;i<=num;i++)if(f[i]>=0)
		res[eu[i]][ev[i]]+=f[i];
	for(u=1;u<=n;u++){
		for(v=n+1;v<n+m;v++)printf("%d ",res[u][v]);
		printf("%d\n",res[u][v]);
	}
	printf("\n");
}

int main(){
	int t;scanf("%d",&t);while(t--)work();
	return 0;
}
