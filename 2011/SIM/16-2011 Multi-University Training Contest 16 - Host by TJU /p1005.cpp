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

#define N 3300
#define M 1100000

typedef long long lld;

const lld inf=1LL<<60;

const int src=3208;
const int tar=3209;

const int nm=30;

lld ec[M],ef[M],sum;

int eu[M],ev[M],be[M],next[M],num;
int nbs[N],cur[N],dis[N],q[N];

inline int min(const int &x,const int &y){ return (x<y)?x:y; }
inline int max(const int &x,const int &y){ return (x>y)?x:y; }

inline lld min(const lld &x,const lld &y){ return (x<y)?x:y; }
inline lld max(const lld &x,const lld &y){ return (x>y)?x:y; }

void AddEdge(const int &u,const int &v,const lld &c){
	++num;eu[num]=u;ev[num]=v;ec[num]=c  ;ef[num]=0LL;
	next[num]=nbs[u];nbs[u]=num;be[num]=num+1;
	++num;eu[num]=v;ev[num]=u;ec[num]=0LL;ef[num]=0LL;
	next[num]=nbs[v];nbs[v]=num;be[num]=num-1;
}

int bfs(const int &s,const int &t){
	int head,tail;
	head=tail=0;q[tail++]=s;
	memset(dis,0,sizeof(dis));dis[s]=1;
	for(;head<tail;head++){int u=q[head];
		for(int i=nbs[u];i;i=next[i]){int v=ev[i];
			if(ec[i]-ef[i]>0LL && !dis[v]){
				dis[v]=dis[u]+1;q[tail++]=v;
				if(v==t)return 1;
			}
		}
	}
	return 0;
}

lld Dinic(const int &s,const int &t){
	int i,u,tail;
	lld flow=0LL,tmp;
	while(bfs(s,t)){
		u=s,tail=0;memcpy(cur,nbs,sizeof(nbs));
		while(cur[s]){
			if(u!=t && cur[u] && ec[cur[u]]-ef[cur[u]]>0LL && dis[u] && dis[u]+1==dis[ev[cur[u]]]){
				q[tail++]=cur[u];u=ev[cur[u]];
			}else if(u==t){
				for(tmp=inf,i=tail-1;i>=0;i--)tmp=min(tmp,ec[q[i]]-ef[q[i]]);
				for(flow+=tmp,i=tail-1;i>=0;i--){
					ef[q[i]]+=tmp;
					ef[be[q[i]]]-=tmp;
					if(!(ec[q[i]]-ef[q[i]]))tail=i;
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

int T;

void work(){
	/* Init  */
	int m;scanf("%d",&m);sum=0LL;
	memset(nbs,0,sizeof(nbs));num=0;
	for(int i=1;i<=m;i++){
		int n;scanf("%d",&n);
		for(int j=1;j<=n;j++){
			lld x,y;scanf("%lld%lld",&x,&y);

			sum+=y;
			AddEdge(src,i*nm+j,y);
			AddEdge(i*nm+j,tar,x);

			int k;scanf("%d",&k);
			while(k--){
				int x,y;scanf("%d%d",&x,&y);
				AddEdge(i*nm+j,x*nm+y,inf);
			}
		}
	}
	/* MF-Core  */
	printf("Case #%d: %lld\n",T,sum-Dinic(src,tar));
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)
		work();	
	return 0;
}


