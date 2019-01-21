//============================================================================
// Name        : TarjanCutvertex
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 无向割点、例为POJ1523
//============================================================================

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
#include<set>
#include<map>
using namespace std;

#define maxn 1100
#define maxm 1100000

int timer;

int n,m;
int s[maxn][maxn];
int eu[maxm],ev[maxm],next[maxm],rev[maxm],num;
int nbs[maxn],mk[maxn],low[maxn],d[maxn];
int cutvnum,cutv[maxn],color,ti;

void AddEdge(int u,int v){
	if(u>v)swap(u,v);
	if(s[u][v])return;
	s[u][v]=1;
	num++;eu[num]=u;ev[num]=v;next[num]=nbs[u];nbs[u]=num;rev[num]=0;
	num++;eu[num]=v;ev[num]=u;next[num]=nbs[v];nbs[v]=num;rev[num]=1;
}

void TarjanCutvertex(const int &u,const int &p){
	int i,v,s=0;low[u]=d[u]=++ti;mk[u]=-color;
	for(i=nbs[u];i;i=next[i]){v=ev[i];
		if(v==p)continue;
		if(!mk[v]){TarjanCutvertex(v,u);s++;
			low[u]=min(low[u],low[v]);
			if((p && low[v]>=d[u])||(!p && s>1)){
				if(!cutv[u])cutvnum++;
				cutv[u]++;
			}
		}else low[u]=min(low[u],d[v]);
	}
	mk[u]=color;
}

void MarkCutvertex(){
	memset(mk,0,sizeof(mk));
	color=ti=cutvnum=0;
	for(int i=1;i<=n;i++)if(!mk[i]){ ++color;TarjanCutvertex(i,0); }
}

int work(){++timer;
	int i,u,v;n=0;
	memset(nbs,0,sizeof(nbs));num=0;
	memset(s,0,sizeof(s));
	while(scanf("%d",&u)!=EOF && u){
		scanf("%d",&v);
		n=max(n,max(u,v));
		AddEdge(u,v);
	}
	if(!num)return 0;
	memset(cutv,0,sizeof(cutv));
	MarkCutvertex();
	printf("Network #%d\n",timer);
	if(cutvnum){
		for(i=1;i<=n;i++)
			if(cutv[i])
				printf("  SPF node %d leaves %d subnets\n",i,cutv[i]+1);
	}else{
		printf("  No SPF nodes\n");
	}
	printf("\n");
	return 1;
}

int main(){
	timer=0;
	while(work());
	return 0;
}
