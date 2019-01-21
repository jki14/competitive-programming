#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 510

int n,m;
int nx,ny,g[maxn][maxn],sy[maxn],cx[maxn],cy[maxn];

int path(int u){
	for(int v=1;v<=ny;v++)if(g[u][v] && !sy[v]){ sy[v]=1;
	if(!cy[v] || path(cy[v])) { cx[u]=v; cy[v]=u; return 1; }
	}return 0;
}

void work(){
	int res=0;
	int i,u,v;
	nx=ny=n;
	memset(g,0,sizeof(g));
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		g[u][v]=1;
	}
	memset(cx,0,sizeof(cx));
	memset(cy,0,sizeof(cy));
	for(i=1;i<=nx;i++)if(!cx[i]){
		memset(sy,0,sizeof(sy));
		res+=path(i);
	}
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}
