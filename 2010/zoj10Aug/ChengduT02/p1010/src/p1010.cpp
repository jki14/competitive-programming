#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxv 1100

int mk[maxv],g[maxv][maxv];

int n,m;

int dfs(int u,int x){
	mk[u]=1;if(u==x)return 1;
	for(int v=0;v<n;v++)if(!mk[v] && g[u][v]){
		if(dfs(v,x))return 1;
	}
	return 0;
}

void work(){
	memset(g,0,sizeof(g));int u,v,res=1;
	while(m--){
		scanf("%d%d",&u,&v);
		memset(mk,0,sizeof(mk));
		if(dfs(u,v))res=0;
		g[v][u]=1;
	}
	if(res)
		printf("YES\n");
	else
		printf("NO\n");
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0))work();
	return 0;
}
