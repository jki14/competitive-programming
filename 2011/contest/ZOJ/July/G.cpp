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

#define maxn 11000
#define maxm 110000
#define K 3

int n,m;
int ev[maxm],next[maxm],num;
int val[maxn],a[maxn][3],nbs[maxn];

void AddEdge(const int &u,const int &v){
	num++;ev[num]=v;next[num]=nbs[u];nbs[u]=num;
}

void update(const int &x,const int &y){
	int i,j;
	for(i=0;i<K;i++){
		if(y>=a[x][i]){
			for(j=K-1;j>i;j--)a[x][j]=a[x][j-1];
			a[x][i]=y;
			return;
		}
	}
}

void dfs(const int &u){
	int i,j,v;
	update(u,val[u]);
	for(i=nbs[u];i;i=next[i]){v=ev[i];
		dfs(v);
		for(j=0;j<K;j++)
			update(u,a[v][j]);
	}
}

void work(){
	int i,k;
	memset(nbs,0,sizeof(nbs));num=0;
	memset(a,0x8f,sizeof(a));
	scanf("%d",&val[0]);
	for(i=1;i<n;i++){
		scanf("%d%d",&k,&val[i]);
		AddEdge(k,i);
	}
	dfs(0);
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&k);
		if(a[k][2]<0){
			printf("-1\n");
			continue;
		}
		printf("%d %d %d\n",a[k][0],a[k][1],a[k][2]);
	}
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}


