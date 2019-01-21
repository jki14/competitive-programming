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

#define maxn 310
#define len 1100
#define maxm 1100000

const int inf=1<<30;

const int S=200;
const int T=210;

int n,np,nc,m;
int ec[maxm],ef[maxm],eu[maxm],ev[maxm],be[maxm],next[maxm],num;
int nbs[maxn],cur[maxn],dis[maxn],q[maxn];

char info[len];

int min(const int &x,const int &y){ return (x<y)?x:y; }

void AddEdge(const int &u,const int &v,const int &cc){
	next[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
	eu[num]=u;ev[num]=v;ec[num]=cc;ef[num]=0;
	next[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
	eu[num]=v;ev[num]=u;ec[num]=0;ef[num]=0;
}

int bfs(const int &s,const int &t){
	int head,tail,u,v,i;
	head=tail=0;q[tail++]=s;
	memset(dis,0,sizeof(dis));dis[s]=1;
	while(head<tail){
		for(u=q[head++],i=nbs[u];i;i=next[i]){v=ev[i];
			if(ec[i]-ef[i]>0 && !dis[v]){
				dis[v]=dis[u]+1;
				q[tail++]=v;
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
	int i,u,v,c;
	memset(nbs,0,sizeof(nbs));num=0;
	for(i=0;i<m;i++){
		scanf("%s",info);
		sscanf(info,"(%d,%d)%d",&u,&v,&c);
		AddEdge(u,v,c);
	}
	for(i=0;i<np;i++){
		scanf("%s",info);
		sscanf(info,"(%d)%d",&v,&c);
		AddEdge(S,v,c);
	}
	for(i=0;i<nc;i++){
		scanf("%s",info);
		sscanf(info,"(%d)%d",&u,&c);
		AddEdge(u,T,c);
	}
	printf("%d\n",Dinic(S,T));
}

int main(){
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
		work();
	return 0;
}

