#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define N 1100000

int n,m,w,p;
int nbs[N],nxt[N],dst[N],num;
int mrk[N];

void addEdge(const int &u,const int &v){
	nxt[++num]=nbs[u];nbs[u]=num;dst[num]=v;
}

void dfs(const int &u,const int &_w){
	mrk[u]=1;if(_w>w){ w=_w;p=u; }
	for(int i=nbs[u];i;i=nxt[i]){int v=dst[i];
		if(mrk[v])continue;
		dfs(v,_w+1);
	}
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		memset(nbs,0,sizeof(nbs));num=0;
		for(int i=1;i<n;i++){
			int u,v;scanf("%d%d",&u,&v);
			addEdge(u,v);addEdge(v,u);
		}
		w=p=1;
		memset(mrk,0,sizeof(mrk));
		dfs(1,1);
		memset(mrk,0,sizeof(mrk));
		dfs(p,1);
		for(int i=0;i<m;i++){
			int k;scanf("%d",&k);
			//printf("w=%d k=%d\n",w,k);
			if(k<=w){
				printf("%d\n",k-1);
			}else printf("%d\n",k+k-w-1);
		}
	}
	return 0;
}
