#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

#define maxv 110
#define maxn 5100
#define maxm 1000000

#define ii i+vecx[k]
#define jj j+vecy[k]

const int inf=0x3fffffff;

const int vecx[4]={ -1,1,0,0 };
const int vecy[4]={ 0,0,-1,1 };

const int src=0;
const int tai=5000;

int ec[maxm],ef[maxm],eu[maxm],ev[maxm],be[maxm],next[maxm],num=0;
int nbs[maxn],cur[maxn],dis[maxn],q[maxn];

int n,m,kk,sum,res;
int a[maxv][maxv];

int cnum(int i,int j){ return i*m+j+1; }

int bels(int i,int j){ return ((i+j)&1); }

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

int allow(int x,int y){
	if(x<0 || x>=n)return 0;
	if(y<0 || y>=m)return 0;
	return 1;
}

void work(){
	memset(nbs,0,sizeof(nbs));sum=num=0;
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			sum+=a[i][j];
		}
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			if(bels(i,j)){
				AddEdge(src,cnum(i,j),a[i][j]);
				for(k=0;k<4;k++)
					if(allow(ii,jj)){
						AddEdge(cnum(i,j),cnum(ii,jj),2*(a[i][j]&a[ii][jj]));
					}
			}
			else
				AddEdge(cnum(i,j),tai,a[i][j]);
		}
	for(k=0;k<kk;k++){
		scanf("%d%d",&i,&j);i--;j--;
		if(bels(i,j))
			AddEdge(src,cnum(i,j),inf);
		else
			AddEdge(cnum(i,j),tai,inf);
	}
	res=sum-Dinic(src,tai);
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d%d",&n,&m,&kk)!=EOF)
		work();
	return 0;
}
