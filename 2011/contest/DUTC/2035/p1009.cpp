#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 21000
#define maxm 1100000


const int inf=LONG_MAX;


int f[maxn],nbs[maxn],rnbs[maxn],n,m,res;

int eu[maxm],ev[maxm],next[maxm],num;
int reu[maxm],rev[maxm],rnext[maxm];

int mk[maxn],rank[maxn],k;
int din[maxn],dout[maxn];

int AddEdge(const int &u,const int &v){
	num++;eu[num]=u;ev[num]=v;
	next[num]=nbs[u];nbs[u]=num;

	num++;reu[num]=v;rev[num]=u;
	rnext[num]=rnbs[v];rnbs[v]=num;

	return 1;
}


void back(const int &v){
	mk[v]=1;f[v]=k;
	for(int i=rnbs[v];i;i=rnext[i]){int u=rev[i];
		if(!mk[u])back(u);
	}
}

void dfs(const int &u){
	mk[u]=1;
	for(int i=nbs[u];i;i=next[i]){int v=ev[i];
		if(!mk[v])dfs(v);
	}
	rank[k--]=u;
}

void work(){
	int i,u,v;
	num=res=0;
	memset(nbs,0,sizeof(nbs));
	memset(rnbs,0,sizeof(rnbs));
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		AddEdge(u,v);
	}
	memset(mk,0,sizeof(mk));k=n;
	for(i=1;i<=n;i++)if(!mk[i])dfs(i);
	memset(mk,0,sizeof(mk));k=0;
	for(i=1;i<=n;i++)if(!mk[rank[i]]){ k++;back(rank[i]);}
	if(k>1){
		memset(din,0,sizeof(din));
		memset(dout,0,sizeof(dout));
		for(i=1;i<=num;i++){u=f[eu[i]];v=f[ev[i]];
			if(u==v)continue;
			dout[u]++;din[v]++;
		}
		u=v=0;
		for(i=1;i<=k;i++){
			if(!dout[i])u++;
			if(!din[i])v++;
		}
		res=max(u,v);
	}
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

