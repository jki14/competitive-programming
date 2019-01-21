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
using namespace std;/

#define W 50
#define H 50
#define N 1000
#define M 11000
#define K 4

//typedef long long lld;

int w,h,n,src,des;
int g[W][H],f[W][H],num;
int dex[N],dey[N];

int ew[M],d[N],tim[N];
int ev[M],next[M],nbs[M],m;
int mk[N],que[N],hig[N],head,tail,size;

const int dx[K] = { -1,0,1,0 };
const int dy[K] = { 0,1,0,-1 };

//const lld inf=1LL<<60;
const int inf=0x3fffffff;

inline int pos2num(const int &x,const int &y){
	return x*h+y;
}

inline int allow(const int &x,const int &y){
	if(x<0 || x>=w)return 0;
	if(y<0 || y>=h)return 0;
	return 1;
}

int nPos(int &x){ return x=(x+1)%N; }

void AddEdge(const int &u,const int &v,const int &w){
	++m;
	ev[m]=v;ew[m]=w;
	next[m]=nbs[u];nbs[u]=m;
}

void build(){
	memset(nbs,0,sizeof(nbs));m=0;

	n=w*h;src=0;des=w*h-1;
	for(int i=0;i<w;i++){
		for(int j=0;j<h;j++){
			if(g[i][j])continue;
			if(i==w-1 && j==h-1)continue;
			if(f[i][j]){
				AddEdge(pos2num(i,j),pos2num(dex[f[i][j]],dey[f[i][j]]),tim[f[i][j]]);
			}else{
				//printf("%d,%d is not\n",i,j);
				for(int k=0;k<K;k++){
					int x=i+dx[k],y=j+dy[k];
					if(!allow(x,y) || g[x][y])continue;
					AddEdge(pos2num(i,j),pos2num(x,y),1);
				}
			}
		}
	}
}

int spfa(const int &k){
	memset(mk,0,sizeof(mk));
	memset(hig,0,sizeof(hig));
	for(int i=0;i<n;i++)d[i]=inf;

	d[src]=0;mk[src]=1;
	head=tail=0;size=1;
	que[nPos(tail)]=src;
	hig[src]++;

	while(size){size--;
		int u=que[nPos(head)];mk[u]=0;
		for(int i=nbs[u];i;i=next[i]){int v=ev[i];
			if(d[v]>d[u]+(k?max(0,ew[i]):ew[i])){
				if(k){
					d[v]=d[u]+max(0,ew[i]);
				}else
					d[v]=d[u]+ew[i];
				if(!mk[v]){
					que[nPos(tail)]=v;
					mk[v]=1;size++;
					hig[v]++;if(hig[v]>n)return 0;
				}
			}
		}
	}

	return 1;
}

void work(){

	//printf("w=%d h=%d\n",w,h);

	memset(f,0,sizeof(f));memset(g,0,sizeof(g));
	
	scanf("%d",&num);//printf("num=%d\n",num);
	for(int i=1;i<=num;i++){
		int x,y;scanf("%d%d",&x,&y);
		g[x][y]=1;
	}

	scanf("%d",&num);//printf("num=%d\n",num);
	for(int i=1;i<=num;i++){
		int x,y;scanf("%d%d%d%d%d",&x,&y,&dex[i],&dey[i],&tim[i]);
		f[x][y]=i;
	}

	//printf("began to build\n");
	build();//printf("build successful\n");
	if(!spfa(0)){
		/* spfa(1);
		if(d[des]==inf){
			printf("Impossible\n");
		}else */printf("Never\n");
	}else{
		if(d[des]<inf)
			printf("%d\n",d[des]);
		else
			printf("Impossible\n");
	}
}

int main(){
	while(scanf("%d%d",&w,&h)!=EOF && (w || h))
		work();
	return 0;
}

