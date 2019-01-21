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

#define N 110000
#define M 210000

int n,r,tim;
int ev[M],next[M],nbs[N],num;
int lowbit[M],c[M];
int x[N],y[N],mk[N];

void Add(int x){
	for(;x<=tim;x+=lowbit[x])c[x]++;
}

int Que(int x){int ret=0;
	for(;x>0;x-=lowbit[x])ret+=c[x];
	return ret;
}

int Sum(int u,int v){
	return Que(v)-Que(u-1);
}

void init(){
	for(int i=0;i<M;i++)lowbit[i]=i&(-i);
}

void AddEdge(int u,int v){
	ev[++num]=v;next[num]=nbs[u];nbs[u]=num;
	ev[++num]=u;next[num]=nbs[v];nbs[v]=num;
}

void dfs(int u){
	x[u]=++tim;mk[u]=1;
	for(int i=nbs[u];i;i=next[i]){int v=ev[i];
		if(mk[v])continue;
		dfs(v);
	}
	y[u]=++tim;
}

void work(){
	int i,u,v;

	memset(nbs,0,sizeof(nbs));num=0;
	for(i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		AddEdge(u,v);
	}

	memset(c,0,sizeof(c));
	memset(mk,0,sizeof(mk));
	tim=0;dfs(r);

	for(i=1;i<=n;i++){
		//printf("Node %d  %d->%d\n",i,x[i],y[i]);
		if(i>1)printf(" ");
		printf("%d",Sum(x[i],y[i]));
		Add(x[i]);
	}
	printf("\n");
}

int main(){init();
	while(scanf("%d%d",&n,&r)!=EOF && !(n==0 && r==0))
		work();
	return 0;
}

