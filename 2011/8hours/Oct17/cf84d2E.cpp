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

#define N 110000
#define M 1100000

typedef long long lld;

int n;
int ev[M],next[M],d[M],num;
int nbs[N],mk[N];
int f[N],g[N],pnt[N],sim[N];
int que[N],tail;

int check(int val){
	for(;val;val/=10){
		int k=val%10;
		if(k!=4 && k!=7)return 0;
	}
	return 1;
}

void AddEdge(const int &u,const int &v,const int &k){
	num++;ev[num]=v;d[num]=k;next[num]=nbs[u];nbs[u]=num;
	num++;ev[num]=u;d[num]=k;next[num]=nbs[v];nbs[v]=num;

}

void dfs(const int &u,const int &f,const int k){
	if(mk[u])return;
	mk[u]=1;pnt[u]=f;sim[u]=k;
	que[++tail]=u;
	for(int i=nbs[u];i;i=next[i]){
		dfs(ev[i],u,d[i]);
	}
}

void work(){
	memset(nbs,0,sizeof(nbs));num=0;
	for(int i=0;i<n-1;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		AddEdge(u,v,check(w));
	}

	/* Core */
	memset(mk,0,sizeof(mk));
	tail=0;dfs(1,1,0);

	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	memset(mk,0,sizeof(mk));
	for(;tail;tail--){
		int u=que[tail];
		for(int i=nbs[u];i;i=next[i]){
			int v=ev[i];if(!mk[v])continue;
			g[u]+=g[v]+1;
			if(d[i])
				f[u]+=g[v]+1;
			else
				f[u]+=f[v];
		}
		mk[u]=1;
	}

	for(int i=1;i<=n;i++){int u=que[i];
		if(sim[u]){
			f[u]=f[u]+g[pnt[u]]-g[u];
			g[u]=g[pnt[u]];
		}else{
			f[u]=f[pnt[u]];
			g[u]=g[pnt[u]];
		}
	}

	/* Result */
	lld ans=0LL;
	for(int i=1;i<=n;i++){
		if(f[i]<2)continue;
		ans=ans + ((lld)f[i])*((lld)(f[i]-1));
	}

	cout<<ans<<endl;
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}


