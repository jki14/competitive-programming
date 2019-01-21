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

#define maxn 21000
#define maxm 51000
#define K 2

int n,m,block,ans;
int f[maxn],mk[maxn],din[maxn],dout[maxn],que[maxn],r,I,O;
int eu[K][maxm],ev[K][maxm],next[K][maxm],nbs[K][maxn],num;

void AddEdge(const int &u,const int &v){
	++num;
	eu[0][num]=u;eu[1][num]=v;
	ev[0][num]=v;ev[1][num]=u;
	next[0][num]=nbs[0][u];
	next[1][num]=nbs[1][v];
	nbs[0][u]=num;nbs[1][v]=num;
}

void dfs(const int &u,const int &pnt,const int &k){
	mk[u]=1;
	for(int i=nbs[k][u],v;i;i=next[k][i]){v=ev[k][i];
		if(mk[v])continue;
		dfs(v,pnt,k);
	}
	if(k)
		que[r--]=u;
	else f[u]=pnt;
}

void work(){
	int i,u,v;

	memset(nbs,0,sizeof(nbs));num=0;
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		AddEdge(u,v);
	}

	for(i=1;i<=n;i++)f[i]=i;

	memset(mk,0,sizeof(mk));r=n;block=0;
	for(i=1;i<=n;i++)if(!mk[i]){
		dfs(i,0,1);
		block++;
	}
	memset(mk,0,sizeof(mk));
	for(i=1;i<=n;i++){
		//printf("que[%d]==%d\n",i,que[i]);
		if(!mk[que[i]])dfs(que[i],que[i],0);
	}
	
	memset( din,0,sizeof( din));
	memset(dout,0,sizeof(dout));
	for(i=1;i<=num;i++){
		if(f[eu[0][i]]==f[ev[0][i]])continue;
		din[ f[ev[0][i]]]++;
		dout[f[eu[0][i]]]++;
	}

	I=O=0;
	if(block>1){
		for(i=1;i<=n;i++){if(f[i]!=i)continue;
			if(! din[i])I++;
			if(!dout[i])O++;
		}
	}

	ans=max(I,O);

	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}

