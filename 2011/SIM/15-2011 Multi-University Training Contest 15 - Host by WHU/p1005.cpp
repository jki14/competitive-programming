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
#define M 1100000

const int inf=0x3fffffff;

int n,m,len,num;
int ev[M],ew[M],be[M],next[M],nbs[N];
int dist[N],route[N],rtway[N],mk[N];
int ps[N],heap[N];

void update(int r){
	int q=ps[r],p=q>>1;
	while(p && dist[heap[p]]>dist[r]){
		ps[heap[p]]=q;heap[q]=heap[p];
		q=p;p=q>>1;
	}
	heap[q]=r;ps[r]=q;
}

int getmin(){
	int ret=heap[1],p=1,q=2,r=heap[len--];
	while(q<=len){
		if(p<len && dist[heap[q+1]]<dist[heap[q]])q++;
		if(dist[heap[q]]<dist[r]){
			ps[heap[q]]=p;heap[p]=heap[q];
			p=q;q=p<<1;
		}else break;
	}
	heap[p]=r;ps[r]=p;
	return ret;
}

struct Path{
	int x,f;
	Path() { }
	Path(const int &a,const int &b) { x=a;f=b; }
	bool operator < (const Path &a) const{
		return a.f+dist[a.x]<f+dist[x];
	}
};

void AddEdge(const int &u,const int &v,const int &w){
	num++;ev[num]=v;ew[num]=w;be[num]=num+1;next[num]=nbs[u];nbs[u]=num;
	num++;ev[num]=u;ew[num]=w;be[num]=num-1;next[num]=nbs[v];nbs[v]=num;
}

void GetDist(int src,int record,int del){
	int i,u,v;
	memset(mk,0,sizeof(mk));memset(ps,0,sizeof(ps));
	memset(dist,0x3f,sizeof(dist));dist[src]=0;
	heap[len=1]=src;ps[src]=1;
	while(1){
		if(!len)return;
		u=getmin();mk[u]=1;
		for(i=nbs[u];i;i=next[i]){
			if(i==del || be[i]==del)continue;v=ev[i];
			if(!mk[v] && dist[u]+ew[i]<dist[v]){
				if(!ps[v]){ heap[++len]=v;ps[v]=len; }
				dist[v]=dist[u]+ew[i];update(v);
				if(record){ route[v]=u;rtway[v]=i; }
			}
		}
	}
}

/*int aStar(int src,int dst,int w){
	InitDist(dst);
	int u,v,i,f;
	priority_queue<Path> pq;
	memset(mk,0,sizeof(mk));pq.push(Path(src,0));
	while(!pq.empty()){
		u=pq.top().x;f=pq.top().f;pq.pop();
		mk[u]++;if(mk[u]>=w)return f+dist[u];
		for(i=nbs[u];i;i=next[i]){
			v=ev[i];
			pq.push(Path(v,f+ew[i]));
		}
	}
	return -1;
}*/

void work(){
	scanf("%d%d",&n,&m);
	memset(nbs,0,sizeof(nbs));num=0;

	for(int i=0;i<m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		AddEdge(u,v,w);
	}

	GetDist(1,1,0);
	int res=dist[n];
	for(int i=n;i!=1;i=route[i]){
		GetDist(1,0,rtway[i]);
		res=max(res,dist[n]);
	}

	if(res>=dist[N-1])res=-1;
	printf("%d\n",res);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

