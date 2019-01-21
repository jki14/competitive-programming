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

#define N 1100
#define M 1100

const int inf=0x3fffffff;

int n,m,cnt;
int ev[M],ew[M],next[M],nbs[N],num;
int src[N],tar[N];

void work(){
	memset(nbs,0,sizeof(nbs));num=0;

	memset(src,0,sizeof(src));
	memset(tar,0,sizeof(tar));

	for(int i=0;i<m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		num++;ev[num]=v;ew[num]=w;
		next[num]=nbs[u];nbs[u]=num;
		src[u]=1;tar[v]=1;
	}

	cnt=0;
	for(int i=1;i<=n;i++)if(src[i] && !tar[i])cnt++;

	printf("%d\n",cnt);

	for(int i=1;i<=n;i++){
		if(src[i] && !tar[i]){
			printf("%d ",i);
			int p,flow=inf;
			for(p=i;nbs[p];p=ev[nbs[p]])
				flow=min(flow,ew[nbs[p]]);
			printf("%d %d\n",p,flow);
		}
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

