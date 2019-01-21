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

#define maxn 260
#define maxm 110000

int T,n,m,ans;
int a[maxn][maxn];

void AddEdge(const int &u,const int &v){
	int i,k;
	a[u][v]=1;
	for(i=1;i<=n;i++)if(a[i][u])a[i][v]=1;
	for(i=1;i<=n;i++){if(!a[v][i])continue;
		a[u][i]=1;
		for(k=1;k<=n;k++)if(a[k][v])a[k][i]=1;
	}
}

void work(){T++;
	int i,u,v;
	memset(a,0,sizeof(a));
	for(ans=i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		if(u==v || a[v][u]){ ans++;continue; }
		if(a[u][v])continue;
		AddEdge(u,v);
	}
	printf("%d. %d\n",T,ans);
}

int main(){T=0;
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))
		work();
	return 0;
}

