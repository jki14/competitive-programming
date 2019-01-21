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
#define Q 1100

typedef long long lld;

const lld inf=1LL<<60;

int n,m,q;
int p[Q],id[Q];
lld c[N][N];
lld t[Q];

void work(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			c[i][j]=inf;
	for(int i=0;i<m;i++){
		int u,v;lld val;
		scanf("%d%d%lld",&u,&v,&val);
		c[u][v]=c[v][u]=min(c[u][v],val);
	}
	for(int i=0;i<q;i++){
		id[i]=i;
		scanf("%d%lld",&p[i],&t[i]);
	}
}

