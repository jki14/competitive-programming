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

#define N 5100
#define M 2100000
#define K 2

int n,m,ans;
int eu[K][M],ev[K][M],next[K][M],nbs[K][N],num;
int sccnum,mk[N],que[N],f[N],tail;
int din[N],dout[N],numin,numout;

void AddEdge(const int &u,const int &v){++num;
	eu[0][num]=u;ev[0][num]=v;next[0][num]=nbs[0][u];nbs[0][u]=num;
	eu[1][num]=v;ev[1][num]=u;next[1][num]=nbs[1][v];nbs[1][v]=num;
}

void dfs(const int &u,const int &k){
	mk[u]=1;
	for(int i=nbs[k][u];i;i=next[k][i]){int v=ev[k][i];
		if(mk[v])continue;
		dfs(v,k);
	}
	if(k)f[u]=sccnum;else que[tail--]=u;
}

void SCC(){
	memset(mk,0,sizeof(mk));tail=n;
	for(int i=1;i<=n;i++)if(!mk[i])dfs(i,0);
	memset(mk,0,sizeof(mk));sccnum=0;
	for(int I=1;I<=n;I++){int i=que[I];
		if(!mk[i]){ ++sccnum;dfs(i,1);	}
	}
}

void work(){
	int i,u,v;
	scanf("%d%d",&n,&m);
	memset(nbs,0,sizeof(nbs));num=0;
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		AddEdge(u,v);
	}
	SCC();C();
	memset(din,0,sizeof(din));
	memset(dout,0,sizeof(dout));
	for(i=1;i<=num;i++){
		if(f[eu[0][i]]==f[ev[0][i]])continue;
		dout[f[eu[0][i]]]++;
		din [f[ev[0][i]]]++;
	}
	for(numin=numout=0,i=1;i<=sccnum;i++){
		if(din[i]==0)numin++;
		if(dout[i]==0)numout++;
	}
	ans=numin+numout-cnum;
	printf("%d\n",ans);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

