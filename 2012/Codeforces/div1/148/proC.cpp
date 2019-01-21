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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

#define N 5000
#define M 1100000

const int inf=0x3fffffff;

int n,m,mk[M],pas,cut,ans,now;
int /*eu[M],*/ev[M],next[M],nbs[M],num;
int c[N][N];
int lis[M],k,f[M]/*,g[N]*/;
int vis[M],top,pre[M];

void AddEdge(const int &u,const int &v){
	ev[++num]=v;next[num]=nbs[u];nbs[u]=num;
	ev[++num]=u;next[num]=nbs[v];nbs[v]=num;
}

void makelist(const int &u){mk[u]=pas;
	for(int i=nbs[u];i;i=next[i]){
		if(i==cut || i-1==cut)continue;
		int v=ev[i];
		if(mk[v]!=pas){
			pre[v]=u;
			makelist(v);
		}
	}
	lis[k++]=u;
}

void findbest(){++top;

	//printf("cut==%d\n",cut);

	for(int i=0;i<k;i++){int u=lis[i];
		vis[u]=top;f[u]=0;
		for(int i=nbs[u];i;i=next[i]){
			if(i==cut || i-1==cut)continue;
			int v=ev[i];
			if(vis[v]!=top)continue;
			f[u]+=f[v];//g[u]+=g[v];
			if(!c[u][v])f[u]++;
		}
	}
	int best=f[lis[k-1]];

	//printf("best=f[%d]=%d\n",lis[k-1],best);

	for(int i=k-2;i>=0;i--){int u=lis[i];

		//g[u]+=g[pre[u]]+(c[pre[u]][u]?0:1);
		//int tmp=(f[pre[u]]-f[u]-(c[pre[u]][u]?0:1))+(c[pre[u]][u]?1:0);

		//printf("f[%d]=%d g[%d]=%d pre=%d c=%d val=%d\n",u,f[u],u,g[u],pre[u],c[pre[u]][u],f[u]+tmp);

		f[u]+=f[pre[u]]-(f[u]+(c[pre[u]][u]?0:1))+(c[u][pre[u]]?0:1);


		//printf("f[%d]=%d f[pre[%d]==%d]=%d\n",u,f[u],u,pre[u],f[pre[u]]);

		best=min(best,f[u]);

	}

	//printf("--------------------\n");

	now+=best;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		if(n==1){ printf("0\n");continue; }
		m=n-1;ans=inf;
		memset(nbs,0,sizeof(nbs));num=0;
		memset(c,0,sizeof(c));
		for(int i=0;i<m;i++){
			int u,v;scanf("%d%d",&u,&v);
			c[u][v]=1;AddEdge(u,v);
		}
		memset(mk,0,sizeof(mk));
		memset(vis,0,sizeof(vis));
		pas=top=0;
		for(cut=1;cut<=num;cut+=2){++pas;now=0;
			k=0;makelist(1);findbest();
			for(int i=1;i<=n;i++){
				if(mk[i]==pas)continue;
				k=0;makelist(i);findbest();
				break;
			}
			ans=min(ans,now);
			//printf("cut ==%d ans=%d\n",cut,ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
