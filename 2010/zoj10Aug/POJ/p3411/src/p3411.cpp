#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

#define maxn 15
#define maxm 15

const int maxt=1<<maxn;
const int inf=1000000000;

int next[maxm],ev[maxm],er[maxm],ep[maxm],ec[maxm],num;
int nbs[maxn];

int f[maxn][maxt];

vector<int> edge[maxn];

int n,m,res;

void dfs(int u,int t,int p){
	//cout<<" Arrive "<<x<<" T="<<t<<" P="<<p<<endl;
	f[u][t]=p;t|=(1<<u);
	for(int i=nbs[u];i;i=next[i]){int v=ev[i];
		if((t&(1<<ec[i])) && f[v][t]>p+ep[i])dfs(v,t,p+ep[i]);
		if(f[v][t]>p+er[i])dfs(v,t,p+er[i]);
	}
}

void work(){
	int i,u,v,c,p,r;num=0;res=LONG_MAX;
	for(i=1;i<=n;i++)edge[i].clear();
	memset(f,0x3f,sizeof(f));
	memset(nbs,0,sizeof(nbs));
	for(i=0;i<m;i++){
		scanf("%d%d%d%d%d",&u,&v,&c,&p,&r);
		next[++num]=nbs[u];nbs[u]=num;
		ev[num]=v;er[num]=r;ep[num]=p;ec[num]=c;
	}
	dfs(1,0,0);
	for(int i=0;i<maxt;i++)if(res>f[n][i])res=f[n][i];
	if(res>inf)
		printf("impossible\n");
	else
		printf("%d\n",res);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}
