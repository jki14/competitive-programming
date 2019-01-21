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

#define N 51000
#define S 110000
#define K 510

typedef long long lld;

int n,m;
int fat[N],list[N];
int ev[S],next[S],nbs[N],num;

lld f[N][K],g[N][K],ans;

int max(const int &x,const int &y){ return (x>y)?x:y; }
int min(const int &x,const int &y){ return (x<y)?x:y; }

void AddEdge(const int &u,const int &v){
	ev[++num]=v;next[num]=nbs[u];nbs[u]=num;
	ev[++num]=u;next[num]=nbs[v];nbs[v]=num;
}

/*int mark(const int &u){
	if(vis[u])return 0;
	vis[u]=++num;list[num]=u;
	for(int i=nbs[u];i;i=next[i])if(mark(ev[i]))fat[ev[i]]=u;
	return 1;
}*/

void mark(){
	int l,r;l=r=0;list[r++]=1;fat[1]=-1;
	for(;l<r;l++){int u=list[l];
		for(int i=nbs[u];i;i=next[i]){int v=ev[i];
			if(fat[ev[i]])continue;
			fat[v]=u;list[r++]=v;
		}
	}
}

void work(){

	//printf("n=%d m=%d\n",n,m);

	memset(nbs,0,sizeof(nbs));num=0;
	for(int i=1;i<n;i++){ int u,v;scanf("%d%d",&u,&v);AddEdge(u,v); }
	memset(fat,0,sizeof(fat));
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	num=0;mark();ans=0LL;
	for(int i=n-1;i>=0;i--){int u=list[i];
		f[u][0]=1LL;
		for(int k=0;k<m;k++)f[fat[u]][k+1]+=f[u][k];
	}
	for(int i=0;i<n;i++){int u=list[i];
		if(fat[u]<0)continue;
		int r=fat[u];g[u][1]=1LL;
		for(int k=1;k<m;k++){ g[u][k+1]+=f[r][k]-f[u][k-1]+g[r][k]; }
	}
	for(int i=1;i<=n;i++)ans+=f[i][m]+g[i][m];ans/=2;
	//cout<<ans<<endl;
	printf("%I64d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}
