#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

#define maxn 2100
#define maxm 1100000

const int inf=0x3fffffff;

//变量申明:
int ec[maxm],ef[maxm],eu[maxm],ev[maxm],be[maxm],next[maxm],num=0;
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

int n,m,c;
int oq[500],low[maxm];

#define src 0
#define tai 2010
#define _src 2011
#define _tai 2012

#define girl(x) x+500
#define day(x) x+100

void work(){
	memset(nbs,0,sizeof(nbs));num=0;
	int i,val,l,r,k,res,sum=0;
	for(i=1;i<=m;i++){
		scanf("%d",&val);
		AddEdge(girl(i),tai,inf-val);
		AddEdge(_src,tai,val);sum+=val;
		AddEdge(girl(i),_tai,val);
	}
	for(i=1;i<=n;i++){
		scanf("%d%d",&k,&val);
		AddEdge(src,day(i),val);
		AddEdge(_src,day(i),0);
		AddEdge(src,_tai,0);
		while(k--){
			scanf("%d%d%d",&val,&l,&r);val++;
			AddEdge(day(i),girl(val),r-l);
			low[num-1]=l;
			AddEdge(_src,girl(val),l);sum+=l;
			AddEdge(day(i),_tai,l);
		}
	}
	int oldnbssrc=nbs[src];
	int oldnbstai=nbs[tai];
	AddEdge(src,tai,inf);AddEdge(tai,src,inf);
	//cout<<" sum="<<sum<<" flow="<<sap(_src,_tai)<<endl;
	if(Dinic(_src,_tai)<sum){
		res=-1;printf("%d\n\n",res);return;
	}else{
		nbs[src]=oldnbssrc;
		nbs[tai]=oldnbstai;
		Dinic(src,tai);res=0;
		for(i=nbs[src];i;i=next[i])
			if(ef[i]>0)res+=ef[i];
	}
	printf("%d\n",res);
	for(i=1;i<=n;i++){
		//cout<<" Begin To Print Day"<<i<<endl;
		r=0;for(k=nbs[day(i)];k;k=next[k]){
			if(ev[k]<500 || ev[k]>2000 )continue;
			oq[r++]=ef[k]+low[k];
		}
		while(r){
			printf("%d\n",oq[--r]);
		}
	}
	printf("\n");
}

int main(){
	//test();bsoj2132();
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}
