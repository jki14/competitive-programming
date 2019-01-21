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
#include<cassert>
using namespace std;

typedef long long lld;

#define min(x,y) (((x)<(y))?(x):(y))

const lld inf=0x3f3f3f3f3f3f3f3fLL;

int eu[21000], ev[21000], be[21000], nx[21000], num;
lld ec[21000], ef[21000];
int nbs[110], cur[110], dis[110], q[110];

int n, a[110];

void AddEdge(const int &u,const int &v,const lld &cc){
    nx[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
    eu[num]=u;ev[num]=v;ec[num]=cc;ef[num]=0LL;
    nx[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
    eu[num]=v;ev[num]=u;ec[num]=0LL;ef[num]=0LL;
}

int bfs(const int &s,const int &t){
    int head,tail,u,v,i;
    head=tail=0;q[tail++]=s;
    memset(dis,0,sizeof(dis));dis[s]=1;
    while(head<tail)
        for(u=q[head++],i=nbs[u];i;i=nx[i]){v=ev[i];
            if(ec[i]-ef[i]>0LL && !dis[v]){
                dis[v]=dis[u]+1;q[tail++]=v;
                if(v==t)return 1;
            }
        }
    return 0;
}

lld Dinic(const int &s,const int &t){
    lld flow=0LL, tmp;
    int i,u,tail;
    while(bfs(s,t)){
        u=s,tail=0;memcpy(cur,nbs,sizeof(nbs));
        while(cur[s]){
            if(u!=t && cur[u] && ec[cur[u]]-ef[cur[u]]>0LL
                    && dis[u] && dis[u]+1==dis[ev[cur[u]]]){
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
                cur[u]=nx[cur[u]];
            }
        }
    }
    return flow;
}

void work(){
    /* HEAD_OF_DINIC_INIT */
    memset(nbs, 0, sizeof(nbs)); num=0;
    /* TAIL_OF_DINIC_INIT */
    lld sum=0LL, bad=0LL;
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        sum+=a[i]*1LL;
    }
    for(int k=1; k<=n; k++){
        if(a[k]>=0)continue;
        bad-=a[k]*1LL;
        AddEdge(0, k, -a[k]*1LL);
        for(int i=k; i<=n; i+=k){
            if(a[i]<=0)continue;
            AddEdge(k, i, inf);
        }
    }
    for(int i=1; i<=n; i++){
        if(a[i]<=0)continue;
        AddEdge(i, n+1, a[i]*1LL);
    }
    assert(num<=20010);
    lld flow=Dinic(0, n+1);
    printf("%lld\n", sum+bad-flow);
    //fprintf(stderr, "sum=%lld dinic=%lld bad=%lld\n", sum, flow, bad);
}

int main(){
    while(scanf("%d", &n)!=EOF)
        work();
    return 0;
}
