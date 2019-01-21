//============================================================================
// Name        : SPFA
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : POJ3268(单原最短路)
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
#include<queue>
#include<deque>
#include<set>
#include<map>
using namespace std;

#define N 1100
#define M 110000
#define K 2

const int inf=0x3fffffff;

int n,m,x;
int ev[M],ew[M],next[M],nbs[M],num;
int d[N],mk[N],que[N],head,tail,size;

int pos[K][M],tim[M],ret[N],ans;

void AddEdge(const int &u,const int &v,const int &w){
	++num;
	ev[num]=v;ew[num]=w;
	next[num]=nbs[u];nbs[u]=num;
}

int nPos(int &x){ return x=(x+1)%N; }

void spfa(const int &src){
	memset(mk,0,sizeof(mk));
	memset(d,0x3f,sizeof(d));

	d[src]=0;mk[src]=1;
	head=tail=0;size=1;
	que[nPos(tail)]=src;

	while(size){size--;
		int u=que[nPos(head)];mk[u]=0;
		for(int i=nbs[u];i;i=next[i]){int v=ev[i];
			if(d[v]>d[u]+ew[i]){
				d[v]=d[u]+ew[i];
				if(!mk[v]){
					que[nPos(tail)]=v;
					mk[v]=1;size++;
				}
			}
		}
	}
}

void work(){
	for(int i=0;i<m;i++)scanf("%d%d%d",&pos[0][i],&pos[1][i],&tim[i]);

	memset(ret,0,sizeof(ret));
	for(int k=0;k<2;k++){
		memset(nbs,0,sizeof(nbs));num=0;
		for(int i=0;i<m;i++)AddEdge(pos[k][i],pos[k^1][i],tim[i]);
		spfa(x);
		for(int i=1;i<=n;i++)ret[i]+=d[i];
	}

	ans=-inf;
	for(int i=1;i<=n;i++)ans=max(ans,ret[i]);

	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d%d",&n,&m,&x)!=EOF)
		work();
	return 0;
}
