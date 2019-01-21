#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

#define maxn 11000
#define maxm 1100000

const int inf=0x3fffffff;

int ew[maxm],er[maxm],eu[maxm],ev[maxm],next[maxm],be[maxm];
int dis[maxn],nbs[maxn],vis[maxn],num,flow,cost;
vector<int> path;

int min(const int &x,const int &y){ return(x<y)?x:y; }

void clr(){ memset(vis,0,sizeof(vis));path.clear(); }

void AddEdge(int u,int v,int cc,int ww){
	//cout<<" AddEdge "<<u<<"->"<<v<<" c="<<cc<<" w="<<ww<<endl;
	next[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
	eu[num]=u;ev[num]=v;er[num]=cc;ew[num]=ww;
	next[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
	eu[num]=v;ev[num]=u;er[num]=0;ew[num]=-ww;
}

int getflow(int u,int s,int t,int k)
{
	if(u==t){cost+=k*dis[s];flow+=k;return k;}vis[u]=1;path.push_back(u);
	int minflow,v;for(int i=nbs[u];i;i=next[i]){v=ev[i];
		if(er[i] && !vis[v] && ew[i]+dis[v]==dis[u]){
			minflow=min(k,er[i]);
			if(int d=getflow(v,s,t,minflow)){
				er[i]-=d;er[be[i]]+=d;
				return d;
			}
		}
	}
	return 0;
}

bool renumber()
{
	int adds=inf,i,u,v;
	for(i=1;i<num;i++)if(vis[u=eu[i]] && er[i] && !vis[v=ev[i]])
		adds=min(adds,dis[v]-dis[u]+ew[i]);
	if(adds==inf)return 0;
	for(i=0;i<(int)path.size();i++)dis[path[i]]+=adds;
	return 1;
}

void mcflow(int src,int tai){
	cost=flow=0;memset(dis,0,sizeof(dis));
	for(clr();getflow(src,src,tai,inf)||renumber();clr());
}

void test(){
	memset(nbs,0,sizeof(nbs));num=0;
	AddEdge(0,5,3,1);
	AddEdge(0,3,2,5);
	AddEdge(5,3,1,2);
	AddEdge(3,10,2,3);
	AddEdge(5,10,2,1);
	mcflow(0,10);
	cout<<" Test Result: cost="<<cost<<"  flow="<<flow<<endl;
}

int n,m,sx[maxn],sy[maxn],tx[maxn],ty[maxn];
char str[maxn];

int cnum(const int &x,const int &y){ return x*m+y+1; }

int dist(const int &x,const int &y,const int &xx,const int &yy){
	//cout<<" Dist ^ "<<x<<","<<y<<"  <-> "<<xx<<","<<yy<<endl;
	return abs(x-xx)+abs(y-yy);
}

void work(){
	memset(nbs,0,sizeof(nbs));num=0;
	int i,j,k,ss,tt,src=0,tai=10010;
	ss=tt=0;
	for(i=0;i<n;i++){
		scanf("%s",str);
		for(j=0;j<m;j++)
			if(str[j]!='.'){
				k=cnum(i,j);
				if(str[j]=='m'){
					sx[ss]=i;sy[ss++]=j;
					AddEdge(src,k,1,0);
				}else{
					tx[tt]=i;ty[tt++]=j;
					AddEdge(k,tai,1,0);
				}
			}
	}
	for(i=0;i<ss;i++)
		for(j=0;j<tt;j++)
			AddEdge(cnum(sx[i],sy[i]),cnum(tx[j],ty[j]),1,dist(sx[i],sy[i],tx[j],ty[j]));
	mcflow(src,tai);
	printf("%d\n",cost);
}

int main(){
	//test();
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))work();
	return 0;
}
