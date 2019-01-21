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

#define N 110

int m,n,ans,res;
int g[N][N],num;
int fir[N],sec[N],vis[N];

void dfs(const int &u){
	if(vis[u])return;vis[u]=++num;
	for(int v=1;v<=n;v++){
		if(!g[u][v] || vis[v])continue;
		dfs(v);
	}
	/* Core */
	for(int v=1;v<=n;v++){
		if(!g[u][v] || vis[v]<=vis[u])continue;
		int len=fir[v]+1;
		if(len<0)len=1;
		
		if(len>fir[u]){
			sec[u]=fir[u];
			fir[u]=len;
		}else{
			if(len>sec[u])sec[u]=len;
		}
	}
	
	/* update */
	//printf("fir[%d]=%d sec[%d]=%d\n",u,fir[u],u,sec[u]);
	res=max(res,max(0,fir[u])+max(0,sec[u]));
}

void work(){
	ans=0;
	for(int k=0;k<m;k++){
		res=num=0;scanf("%d",&n);
		memset(g,0,sizeof(g));
		memset(fir,0x8f,sizeof(fir));
		memset(sec,0x8f,sizeof(sec));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<n;i++){
			int u,v;scanf("%d%d",&u,&v);
			g[u][v]=g[v][u]=1;
		}
		dfs(1);ans+=res;
	}
	printf("%d\n",ans);
}

int main(){
	freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	while(scanf("%d",&m)!=EOF)
		work();
	fclose(stdin);fclose(stdout);
	return 0;
}


