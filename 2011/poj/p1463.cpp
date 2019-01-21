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

#define maxn 11000
#define len 21
#define K 2

const int inf=0x3fffffff;

int n,ans;
int f[maxn][K];
int mk[maxn],q[maxn],p[maxn];
int ev[maxn],next[maxn],nbs[maxn],num;

char str[len];

void dfs(int u){

	//printf("DFS(%d)\n",u);

	int i,v;
	mk[u]=1;
	for(i=nbs[u];i;i=next[i]){v=ev[i];

		//printf("	i=%d v=%d\n",i,v);

		if(mk[v])continue;
		p[v]=u;dfs(v);
	}
	q[num++]=u;
}

void work(){ans=0;
	int i,j,u,v;
	memset(nbs,0,sizeof(nbs));num=0;
	for(i=0;i<n;i++){
		scanf("%s",str);
		sscanf(str,"%d:(%d)",&u,&j);
		while(j--){
			scanf("%d",&v);

			//printf("AddEdge %d->%d\n",u,v);

			num++;ev[num]=v;
			next[num]=nbs[u];nbs[u]=num;

			num++;ev[num]=u;
			next[num]=nbs[v];nbs[v]=num;
		}
	}

	memset(mk,0,sizeof(mk));num=0;
	for(i=0;i<n;i++)if(!mk[i]){
		p[i]=-1;
		dfs(i);
	}

	memset(f,0,sizeof(f));
	for(j=0;j<n;j++){u=q[j];
		
		//printf("Update Info at %d:\n",u);
		f[u][1]=1;
		for(i=nbs[u];i;i=next[i]){v=ev[i];
			f[u][0]+=f[v][1];
			f[u][1]+=min(f[v][0],f[v][1]);
		}


		//printf("	f[0]=%d f[1]=%d f[2]=%d\n",f[u][0],f[u][1],f[u][2]);

		if(p[u]==-1){
			ans+=min(f[u][0],f[u][1]);
		}	
	}

	printf("%d\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

