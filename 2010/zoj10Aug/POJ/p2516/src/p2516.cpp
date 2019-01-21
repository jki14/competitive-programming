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

#define maxn 110

#define maxv 1100
#define maxe 1000000

#define lmtw 5

#define src 0
#define tar 1010
#define half 500

const int inf=0x3fffffff;

int ec[maxe],ef[maxe],ew[maxe],eu[maxe],ev[maxe],next[maxe],be[maxe];
int dis[maxv],nbs[maxv],vis[maxv],num,flow,cost;
vector<int> path;

int n,m,k,sum,res;
int ck[maxn][maxn],sk[maxn][maxn];

int min(const int &x,const int &y){ return(x<y)?x:y; }

void clr(){ memset(vis,0,sizeof(vis));path.clear(); }

void AddEdge(int u,int v,int cc,int ww){
	//cout<<" AddEdge "<<u<<"->"<<v<<" c="<<cc<<" w="<<ww<<endl;
	next[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
	eu[num]=u;ev[num]=v;ec[num]=cc;ef[num]=0;ew[num]=ww;
	next[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
	eu[num]=v;ev[num]=u;ec[num]=0;ef[num]=0;ew[num]=-ww;
}

int getflow(int u,int s,int t,int k)
{
	if(u==t){cost+=k*dis[s];flow+=k;return k;}vis[u]=1;path.push_back(u);
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

bool renumber()
{
	int adds=inf,i,u,v;
	for(i=1;i<num;i++)if(vis[u=eu[i]] && ec[i]-ef[i] && !vis[v=ev[i]])
		adds=min(adds,dis[v]-dis[u]+ew[i]);
	if(adds==inf)return 0;
	for(i=0;i<(int)path.size();i++)dis[path[i]]+=adds;
	return 1;
}

void mcflow(int s,int t){
	cost=flow=0;memset(dis,0,sizeof(dis));
	for(clr();getflow(s,s,t,inf)||renumber();clr());
}

void work(){
	int i,j,kk,v,cnt=1;res=0;
	for(i=0;i<n;i++)
		for(j=0;j<k;j++)
			scanf("%d",&ck[i][j]);
	for(i=0;i<m;i++)
		for(j=0;j<k;j++)
			scanf("%d",&sk[i][j]);
	for(kk=0;kk<k;kk++){
		memset(nbs,0,sizeof(nbs));num=sum=0;
		for(i=0;i<n;i++){ AddEdge(half+i,tar,ck[i][kk],0);sum+=ck[i][kk]; }
		for(i=0;i<m;i++)AddEdge(src,1+i,sk[i][kk],0);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++){
				scanf("%d",&v);
				AddEdge(1+j,half+i,lmtw,v);
			}
		if(cnt){
			mcflow(src,tar);
			if(flow<sum){
				cnt=0;
				res=-1;
			}else res+=cost;
		}
	}
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF && !(n==0 && m==0 && k==0))
		work();
	return 0;
}
