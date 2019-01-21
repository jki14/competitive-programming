#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <set>
using namespace std;

#define PII pair<int,int>

#define maxv 110000
#define maxe 310000

#define pntu f[u]
#define pntv f[v]
#define pnti f[i]

int n,m,cp,cg;
int f[maxv],g[maxv],cir[maxv],mk[maxv];
int que[maxv],rank[maxv],deg[maxv];

void find(const int &i){
	if(f[i]==f[f[i]])return;
	int r=0,v;
	for(v=i;v!=f[v];v=f[v]){
		que[r++]=v;
	}
	for(;r>0;r--)f[que[r-1]]=v;
}

void work(){
	memset(cir,0,sizeof(cir));memcpy(f,g,sizeof(g));memset(rank,0,sizeof(rank));memset(deg,0,sizeof(deg));memset(mk,0,sizeof(mk));
	int i,u,v;
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);find(u);find(v);
		deg[u]++;deg[v]++;
		if(rank[pntu]>rank[pntv]){ f[pntv]=pntu;rank[pntu]++; }
		else{
			f[pntu]=pntv;
			if(rank[pntu]==rank[pntv])rank[pntv]++;
		}
	}
	for (i=0;i<n;i++){
		find(i);
		if (deg[i]==2) if (!mk[pnti]) mk[pnti]=1;
		if (deg[i]!=2) mk[pnti]=-1;
	}
	for (i=cp=cg=0;i<n;i++){
		if (mk[i]) cp++;
		if (mk[i]==1) cg++;
	}
	printf("%d %d\n",cp,cg);
}

int main(){
	for(int i=0;i<maxv;i++)g[i]=i;
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))work();
	return 0;
}
