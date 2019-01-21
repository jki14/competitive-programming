//============================================================================
// Name        : Dijkstra+Heap
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : POJ3268(单原最短路)
//============================================================================

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

#define N 1100
#define M 110000
#define K 2

const int inf=0x3fffffff;

int n,m,x;
int ev[M],ew[M],next[M],nbs[M],num;
int d[N],mk[N],ps[N],heap[N],len;

int pos[K][M],tim[M],ret[N],ans;

void AddEdge(const int &u,const int &v,const int &w){
	++num;
	ev[num]=v;ew[num]=w;
	next[num]=nbs[u];nbs[u]=num;
}

void update(const int &r){
	int q=ps[r],p=q>>1;
	while(p && d[heap[p]]>d[r]){
		ps[heap[p]]=q; heap[q]=heap[p];
		q=p; p=q>>1;
	}
	heap[q]=r;ps[r]=q;
}

int getmin(){
	int ret=heap[1],p=1,q=2,r=heap[len--];
	while(q<=len){
		if(q<len && d[heap[q+1]]<d[heap[q]])q++;
		if(d[heap[q]]<d[r]){
			ps[heap[q]]=p;heap[p]=heap[q];
			p=q;q=p<<1;
		}else break;
	}
	heap[p]=r;ps[r]=p;
	return ret;
}

void dijkstra(const int &src){
	int i,j,u,v;
	for(i=1;i<=n;i++){ d[i]=inf;mk[i]=ps[i]=0; }
	d[src]=0;heap[len=1]=src;ps[src]=1;
	while(true){
		if(len==0)return;
		u=getmin();mk[u]=1;
		for(j=nbs[u];j;j=next[j]){v=ev[j];
			if(!mk[v] && d[u]+ew[j]<d[v]){
				if(!ps[v]){ heap[++len]=v;ps[v]=len; }
				d[v]=d[u]+ew[j];update(v);
			}
		}
	}
}

void work(){
	for(int i=0;i<m;i++)scanf("%d%d%d",&pos[0][i],&pos[1][i],&tim[i]);

	memset(ret,0,sizeof(ret));
	for(int k=0;k<2;k++){
		memset(nbs,0,sizeof(nbs));num=0;
		for(int i=0;i<m;i++)AddEdge(pos[k][i],pos[k^1][i],tim[i]);
		dijkstra(x);
		for(int i=1;i<=n;i++)ret[i]+=d[i];
	}

	ans=-inf;
	for(int i=1;i<=n;i++)ans=max(ans,ret[i]);

	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d%d",&n,&m,&x)!=EOF)
		work();
	return 0;
}
