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

//============================================================================
// Name        : Dinic
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 最大流
//============================================================================

#define L 300

#define maxn 11000
#define maxm 11000

#define src 2000
#define des 2001

#define peo(x) (x+0)
#define foo(x) (x+200)
#define dri(x) (x+400)

#define det 1000

const int inf = 0x3fffffff;

//变量申明:
int ec[maxm],ef[maxm],eu[maxm],ev[maxm],be[maxm],next[maxm],num;
int nbs[maxn],cur[maxn],dis[maxn],q[maxn];

//功能函数:
int min(int x,int y){ return (x<y)?x:y; }

void AddEdge(int u,int v,int cc){
	next[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
	eu[num]=u;ev[num]=v;ec[num]=cc;ef[num]=0;
	next[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
	eu[num]=v;ev[num]=u;ec[num]=0;ef[num]=0;
}

int bfs(int s,int t){
	int head,tail,u,v,i;
    	head=tail=0;q[tail++]=s;
   	memset(dis,0,sizeof(dis));dis[s]=1;
    	while(head<tail)
    	for(u=q[head++],i=nbs[u];i;i=next[i]){v=ev[i];
		if(ec[i]-ef[i]>0 && !dis[v]){
                	dis[v]=dis[u]+1;q[tail++]=v;
                	if(v==t)return 1;
            	}
    	}
    return 0;
}

int Dinic(int s,int t){
    int flow=0,tmp,i,u,tail;
    while(bfs(s,t)){
        u=s,tail= 0;memcpy(cur,nbs,sizeof(nbs));
        while(cur[s])
            if(u!=t && cur[u] && ec[cur[u]]-ef[cur[u]]>0 && dis[u] && dis[u]+1==dis[ev[cur[u]]]){
            	q[tail++]=cur[u];u=ev[cur[u]];
            }
            else if(u==t){
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
    return flow;
}

/*
初始化:
memset(nbs,0,sizeof(nbs));num=0;

连续求不同源汇时清空ef[]
求上下界限制流时不可清除
*/

char sat[L];

int main(){int n,f,d;
	while(scanf("%d%d%d",&n,&f,&d)!=EOF){
		
		memset(nbs,0,sizeof(nbs));num=0;
		
		for(int i=1;i<=n;i++){
			//int val;scanf("%d",&val);
			AddEdge(peo(i),peo(i)+det,1);
		}	
		for(int i=1;i<=f;i++){
			int val;scanf("%d",&val);
			//AddEdge(foo(i),foo(i)+det,val);
			AddEdge(src,foo(i),val);
		}	
		for(int i=1;i<=d;i++){
			int val;scanf("%d",&val);
			//AddEdge(dri(i),dri(i)+det,val);
			AddEdge(dri(i),des,val);
		}

		for(int i=1;i<=n;i++){
			scanf("%s",sat);
			for(int j=1;j<=f;j++)
				if(sat[j-1]=='Y')AddEdge(foo(j),peo(i),1);
		}
		
		for(int i=1;i<=n;i++){
			scanf("%s",sat);
			for(int j=1;j<=d;j++)
				if(sat[j-1]=='Y')AddEdge(peo(i)+det,dri(j),1);
		}

		printf("%d\n",Dinic(src,des));
	}

	printf("\n\n");

	return 0;
}

