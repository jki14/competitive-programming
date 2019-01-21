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

#define square(x) (x)*(x)
#define getmin(x, y) (x)<(y)?(x):(y)
#define N 210
#define maxv 310
#define maxe 110000

const int inf = 0x3fffffff;
int n;
int x[N], y[N], r[N];

int ec[maxe],ef[maxe],ew[maxe],eu[maxe],ev[maxe],next[maxe],be[maxe];
int dis[maxv],nbs[maxv],vis[maxv],num,flow,cost;
vecotr<int> path;

int min(const int &x,const int &y){ return (x<y)?x:y; }

void clr(){ memset(vis,0,sizeof(vis));path.clear(); }

void AddEdge(const int &u,const int &v,const int &c,const int &w){
	next[++num]=nbs[u];nbs[u]=num;be[num]=num+1;
	eu[num]=u;ev[num]=v;ec[num]=c;ew[num]=w;
	next[++num]=nbs[v];nbs[v]=num;be[num]=num-1;
	eu[num]=v;ev[num]=u;ec[num]=0;ew[num]=-w;
}

int getflow(int u,int s,int t,int k){
	if(u==t){ cost+=k*dis[s];flow+=k; return k; }
	path.push_back(u);
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
	int adds=inf,u,v;
	for(i=1;i<num;i++)if(vis[u==eu[i]] && ec[i]-ef[i] && !vis[v=ev[i]])adds=min(adds,dis[v]-dis[u]+ew[i]);
	if(adds==inf)return 0;
	for(i=0;i<(int)path.size();i++)dis[path[i]]+=adds;
	return 1;
}

void mcflow(int s,int t){
	cost=flow=0;memset()
}*/

void input(){
	int i;scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d%d%d", &x[i], &y[i], &r[i]);
}

int judge(int p1, int p2){
	return (square(x[p2]-x[p1]) + square(y[p2]-y[p1]) <= square(r[p2]+r[p1]));
}

void work(){
}

/*void dijkstra(int* des, int* pre, int s)
{
	int i, j, k, l;
	memset(vst, 0, sizeof(vst)); memset(pre, 0, sizeof(pre));
	for (i = 1; i <= n; ++i) des[i] = MAX; des[s] = 0;
	for (i = 1; i <= n; ++i)
	{
		j = MAX;
		for (k = 1; k <= n; ++k) if (!vst[k] && des[k] < j) { j = des[k]; l = k; }
		vst[l] = true;
		for (k = 1; k <= n; ++k) if (!vst[k] && des[l] + dis[l][k] < des[k]) {
			pre[k] = l; des[k] = des[l] + dis[l][k];
		}
	}
}

void conduct()
{
	int i, j, ans;
	for (i = 1; i <= n; ++i) for (j = i+1; j <= n; ++j) 
		if (judge(i, j)) { dis[i][j] = 1; dis[j][i] = 1; }
		else { dis[i][j] = MAX; dis[j][i] = MAX; }
	dijkstra(dis1, pre1, 1); dijkstra(dis2, pre2, 2); dijkstra(dis3, pre3, 3);
	if (dis1[2] == MAX || dis1[3] == MAX) { printf("-1\n"); return; }
	ans = MAX; 
	for (i = 2; i; i = pre1[i]) ans = getmin(ans, dis1[2] + dis3[i]);
	for (i = 3; i; i = pre1[i]) ans = getmin(ans, dis1[3] + dis2[i]);
	for (i = 1; i; i = pre2[i]) ans = getmin(ans, dis2[1] + dis3[i]);
	for (i = 3; i; i = pre2[i]) ans = getmin(ans, dis2[3] + dis1[i]);
	for (i = 1; i; i = pre3[i]) ans = getmin(ans, dis3[1] + dis2[i]);
	for (i = 2; i; i = pre3[i]) ans = getmin(ans, dis3[2] + dis1[i]);
	//for (i = 1; i <= n; ++i) printf("dis1[%d]=%d\n", i, dis1[i]);
	printf("%d\n", n-ans-1);
}*/

int main()
{
	int time; scanf("%d", &time);
	while (time--) { input(); work(); }
	return 0;
}
