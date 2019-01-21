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

#define N 3100
#define M 1100000

const int inf=0x3fffffff;

const int src=3008;
const int tar=3009;

int a[N],f[N],n,res;

int ec[M],ef[M],eu[M],ev[M],be[M],next[M],num;
int nbs[N],cur[N],dis[N],q[N];

inline int min(const int &x,const int &y){ return (x<y)?x:y; }
inline int max(const int &x,const int &y){ return (x>y)?x:y; }

void AddEdge(const int &u,const int &v,const int &c){
	++num;eu[num]=u;ev[num]=v;ec[num]=c;ef[num]=0;
	next[num]=nbs[u];nbs[u]=num;be[num]=num+1;
	++num;eu[num]=v;ev[num]=u;ec[num]=0;ef[num]=0;
	next[num]=nbs[v];nbs[v]=num;be[num]=num-1;
}

int bfs(const int &s,const int &t){
	int head,tail;
	head=tail=0;q[tail++]=s;
	memset(dis,0,sizeof(dis));dis[s]=1;
	for(;head<tail;head++){int u=q[head];
		for(int i=nbs[u];i;i=next[i]){int v=ev[i];
			if(ec[i]-ef[i]>0 && !dis[v]){
				dis[v]=dis[u]+1;q[tail++]=v;
				if(v==t)return 1;
			}
		}
	}
	return 0;
}

int Dinic(const int &s,const int &t){
	int flow=0,tmp,i,u,tail;
	while(bfs(s,t)){
		u=s,tail=0;memcpy(cur,nbs,sizeof(nbs));
		while(cur[s]){
			if(u!=t && cur[u] && ec[cur[u]]-ef[cur[u]]>0 && dis[u] && dis[u]+1==dis[ev[cur[u]]]){
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

void work(){
	/* Init  */
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);a[0]=inf;
	/* DP-Core  */
	f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=1;
		for(int j=1;j<i;j++)if(a[i]>a[j])f[i]=max(f[i],f[j]+1);
	}
	res=num=0;
	for(int i=1;i<=n;i++)res=max(res,f[i]);
	printf("%d\n",res);
	/* MF-Core  */
	memset(nbs,0,sizeof(nbs));num=0;
	for(int i=1;i<=n;i++){
		AddEdge(i,n+i,1);
		if(f[i]==1)AddEdge(src,i,1);
		if(f[i]==res)AddEdge(n+i,tar,1);
		if(f[i]>1){
			for(int j=1;j<i;j++)if(f[j]+1==f[i] && a[j]<a[i])
				AddEdge(n+j,i,1);
		}
	}
	printf("%d\n",Dinic(src,tar));
}

int main(){
	while(scanf("%d",&n)!=EOF){
		if(n>1000)while(1);
		work();
	}
	return 0;
}


