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
#include<set>
#include<map>
using namespace std;

#define maxn 200

int n,m,r,q,root,ans;
int ev[maxn],next[maxn],nbs[maxn],num;
int que[maxn],f[maxn][maxn],g[maxn][maxn];
int mk[maxn],leaf[maxn],chi[maxn][maxn];

int min(const int &x,const int &y){ return (x<y)?x:y; }

int dfsvisit(const int &u){
	mk[u]=1;que[++r]=u;leaf[u]=1;chi[u][0]=0;
	for(int i=nbs[u];i;i=next[i]){
		if(mk[ev[i]])continue;
		chi[u][++chi[u][0]]=ev[i];
		leaf[u]+=dfsvisit(ev[i]);
	}
	return leaf[u];
}

void work(){m=n-1;
	int i,j,k,sum,u,v;

	memset(nbs,0,sizeof(nbs));num=0;
	memset(mk,0,sizeof(mk));
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);mk[v]=1;
		ev[++num]=v;next[num]=nbs[u];nbs[u]=num;
	}
	for(i=1;i<=n;i++)if(!mk[i]){ root=i;break; }
	memset(mk,0,sizeof(mk));
	r=0;dfsvisit(root);

	memset(f,0x3f,sizeof(f));
	for(;r;r--){u=que[r];
		f[u][0]=1;f[u][leaf[u]]=0;
		memset(g,0x3f,sizeof(g));
		g[0][1]=0;sum=1;
		for(i=1;i<=chi[u][0];i++){v=chi[u][i];
			for(j=1;j<=sum && j<=q;j++)
				for(k=0;k<=leaf[v] && j+k<=q;k++)
					g[i][j+k]=min(g[i][j+k],g[i-1][j]+f[v][k]);
			sum+=leaf[v];
		}
		/*memset(g,0x3f,sizeof(g));
		g[0][1]=1;sum=1;
		for(i=1;i<=chi[u][0];i++){
			for(k=1;k<=sum;k++){
				g[i][k]=min(g[i][k],g[i-1][k]+f[v][0]);
				g[i][k+leaf[v]]=min(g[i][k+leaf[v]],g[i-1][k]+f[v][leaf[v]]);
			}
			sum+=leaf[v];
		}*/
		//printf("sum=%d\n",sum);
		for(i=0;i<=sum;i++){
			f[u][i]=min(f[u][i],g[chi[u][0]][i]);
			//printf("f[%d][%d]=%d\n",u,i,f[u][i]);
		}
	}

	ans=f[root][q];
	for(i=1;i<=n;i++){
		ans=min(ans,f[i][q]+1);
	}

	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&q)!=EOF)work();
	return 0;
}

