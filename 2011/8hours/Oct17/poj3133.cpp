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

#define N 210
#define M 2100
#define K 4

const int inf=0x3ffffff;

const int src=2108;
const int tar=2109;

const int dx[K] = { -1,0,1,0 };
const int dy[K] = { 0,1,0,-1 };

int n,m,c[N][N];
int ec[M],ef[M],ew[M],eu[M],ev[M],next[M],be[M];
int dis[N],nbs[N],vis[N],num,flow,cost;
vector<int> path;

inline int min (const int &x,const int &y){ return (x<y)?x:y; }

void clr(){ memset(vis,0,sizeof(vis));path.clear(); }

void AddEdge(int u,int v,int cc,int ww){
	next[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
	eu[num]=u;ev[num]=v;ec[num]=cc;ef[num]=0;ew[num]=ww;
	next[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
	eu[num]=v;ev[num]=u;ec[num]=0;ef[num]=0;ew[num]=-ww;
}

int getflow(int u,int s,int t,int k){
	if(u==t){ cost+=k*dis[s];flow+=k; return k; }vis[u]=1;path.push_back(u);
	int minflow,v;for(int i=nbs[u];i;i=next[i]){v=ev[i];
		if(ec[i]-ef[i] && !vis[v] && ew[i]+dis[v]==dis[u]){
			minflow=min(k,ec[i]-ef[i]);
			if(int d=getflow(v,s,t,minflow)){
				ef[i]+=d;ef[be[i]]-=d;
				return d;
			}
		}
	}
	return 0;
}

int renumber(){
	int adds=inf,i,u,v;
	for(i=1;i<num;i++)if(vis[u=eu[i]] && ec[i]-ef[i] && !vis[v=ev[i]])
		adds=min(adds,dis[v]-dis[u]+ew[i]);
	if(adds==inf)return 0;
	for(i=0;i<(int)path.size();i++)dis[path[i]]+=adds;
	return 1;
}

void mcflow(int s,int t){
	cost=flow=0;memset(dis,0,sizeof(dis));
	for(clr();getflow(s,s,t,inf) || renumber();clr());
}

inline pos2num(const int &x,const int &y,const int &k){ return k*n*m+x*m+y; }

void work(){
	memset(nbs,0,sizeof(nbs));num=0;
	
	int n2,n3;n2=n3=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&c[i][j]);
			if(!c[i][j])continue;
			if(c[i][j]==2){
				if(n2)
					AddEdge(pos2num(i,j,0),tar,1,0);
				else{
					AddEdge(src,pos2num(i,j,0),1,0);
					n2=1;
				}
			}

		}
	}

	for(int x=0;x<n;x++)
		for(int y=0;y<m;y++){
			AddEdge(pos2num(x,y,0),pos2num(x,y,1),1,1);
			for(int k=0;k<n;k++){
				int xx=x+dx[k],yy=y+dy[k];
				if(xx<0 || xx>=n)continue;
				if(yy<0 || yy>=m)continue;
				AddEdge(pos2num(x,y,1),pos2num(xx,yy,0),1,0);
			}
		}
}

