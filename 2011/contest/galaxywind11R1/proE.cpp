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

#define N 11000
#define M 1100000
#define K 2

const int inf=0x3fffffff;

int T;

int n,m,x;
int ev[M],ew[M],next[M],nbs[M],num;
int d[N],mk[N],que[N],head,tail,size;

int f[N],g[N];

void AddEdge(const int &u,const int &v,const int &w){
	++num;ev[num]=v;ew[num]=w;
	next[num]=nbs[u];nbs[u]=num;
}

int nPos(int &x){ return x=(x+1)%N; }

void spfa(const int &src){
	memset(mk,0,sizeof(mk));
	memset(d,0xff,sizeof(d));
	
	d[src]=0;mk[src]=1;
	head=tail=0;size=1;
	que[nPos(tail)]=src;

	while(size){size--;
		int u=que[nPos(head)];mk[u]=0;
		for(int i=nbs[u];i;i=next[i]){int v=ev[i];
			if(d[v]<0 || d[v]>(d[u]|ew[i])){
				d[v]=d[u]|ew[i];
				if(!mk[v]){
					que[nPos(tail)]=v;
					mk[v]=1;size++;
				}
			}
		}
	}
}

void work(){
	int src,tai;
	scanf("%d%d%d%d",&n,&m,&src,&tai);
	memset(nbs,0,sizeof(nbs));num=0;
	for(int i=0;i<m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		AddEdge(u,v,w);AddEdge(v,u,w);
	}
	spfa(src);for(int i=1;i<=n;i++)f[i]=d[i];
	spfa(tai);for(int i=1;i<=n;i++)g[i]=d[i];
	int ans=0x7fffffff;
	for(int i=1;i<=n;i++)ans=min(ans,f[i]|g[i]);
	printf("Case #%d: %d\n",T,ans);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)
		work();
	return 0;
}

