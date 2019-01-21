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

#define N 55005 
#define M 320005

#define S 0
#define T 55004

const int inf=0x3fffffff;

int n,m,ans;
int er[M],eu[M],ev[M],be[M],next[M],num;
int nbs[N],cur[N],dis[N],q[N];

void AddEdge(int u,int v,int cc){
	next[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
	eu[num]=u;ev[num]=v;er[num]=cc;
	next[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
	eu[num]=v;ev[num]=u;er[num]=0;
}

int bfs(int s,int t){
	int head,tail,u,v,i;
	head=tail=0;q[tail++]=s;
	memset(dis,0,sizeof(dis));dis[s]=1;
	while(head<tail)
		for(u=q[head++],i=nbs[u];i;i=next[i]){v=ev[i];
			if(er[i]>0 && !dis[v]){
				dis[v]=dis[u]+1;q[tail++]=v;
				if(v==t)return 1;
			}
		}
	return 0;
}

int Dinic(int s,int t){
	int flow=0,tmp,i,u,tail;
	while(bfs(s,t)){
		u=s,tail=0;memcpy(cur,nbs,sizeof(nbs));
		while(cur[s]){
			if(u!=t && cur[u] && er[cur[u]]>0 && dis[u] && dis[u]+1==dis[ev[cur[u]]]){
				q[tail++]=cur[u];u=ev[cur[u]];
			}else if(u==t){
				for(tmp=inf,i=tail-1;i>=0;i--)tmp=min(tmp,er[q[i]]);
				for(flow+=tmp,i=tail-1;i>=0;i--){
					er[q[i]]-=tmp;
					er[be[q[i]]]+=tmp;
					if(!er[q[i]])tail=i;
				}
				u=eu[q[tail]];
			}else{
				while(tail>0 && u!=s && !cur[u])u=eu[q[--tail]];
				cur[u]=next[cur[u]];
			}
		}
	}
	return flow;
}

void work(){
	int i,val,u,v;ans=0;

	memset(nbs,0,sizeof(nbs));num=0;
	for(i=1;i<=n;i++){
		scanf("%d",&val);
		AddEdge(S,i,val);
	}
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&val);ans+=val;
		AddEdge(n+i,T,val);
		AddEdge(u,n+i,inf);
		AddEdge(v,n+i,inf);
	}

	ans-=Dinic(S,T);

	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

