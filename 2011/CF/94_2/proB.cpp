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

#define N 110

typedef long long lld;

int n,m,ans;
int g[N][N],v[N],r[N];

void work(){
	memset(g,0,sizeof(g));ans=0;
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
	}
	memset(v,0,sizeof(v));
	for(int opt=1;;opt++){int del=0;
		for(int i=1;i<=n;i++){
			int d=0;
			for(int j=1;j<=n;j++)if(g[i][j]){ d++;r[i]=j; }
			if(d==1){del=1;v[i]=opt; }
		}
		if(!del)break;ans++;
		for(int i=1;i<=n;i++)if(v[i]==opt){ g[i][r[i]]=g[r[i]][i]=0; }
	}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

