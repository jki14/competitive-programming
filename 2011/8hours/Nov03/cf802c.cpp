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
#define M 21000

int n,m;
int ev[M],next[M],nbs[N],num;
int mk[N],rmk;

void dfs(const int &u){mk[u]=1;
	for(int i=nbs[u];i;i=next[i]){
		int v=ev[i];if(mk[v])continue;
		dfs(v);
	}
}

void work(){
	memset(nbs,0,sizeof(nbs));num=0;
	memset(mk ,0,sizeof(mk ));
	for(int i=0;i<m;i++){
		int u,v;scanf("%d%d",&u,&v);
		++num;ev[num]=v;
		next[num]=nbs[u];nbs[u]=num;
		++num;ev[num]=u;
		next[num]=nbs[v];nbs[v]=num;
	}
	dfs(1);rmk=1;
	for(int i=1;rmk && i<=n;i++)rmk&=mk[i];
	if(rmk && m==n)
		printf("FHTAGN!\n");
	else
		printf("NO\n");
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

