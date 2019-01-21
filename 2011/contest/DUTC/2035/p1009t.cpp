#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 11000
#define maxm 1100000

int n,m,k;
int ev[maxm],next[maxm],num;
int rev[maxm],rnext[maxm],rnum;
int nbs[maxn],rnbs[maxn];
int mk[maxn],rank[maxn];

void AddEdge(const int &u,const int &v){
	ev[++num]=v;next[num]=nbs[u];nbs[u]=num;
	rev[++rnum]=u;rnext[rnum]=rnbs[v];rnbs[v]=rnum;
}

void back(const int &v){
	mk[v]=1;cout<<v<<" ";
	for(int i=rnbs[v];i;i=rnext[i]){int u=rev[i];
			if(!mk[u])back(u);
	}
}

void dfs(const int &u){
	mk[u]=1;
	for(int i=nbs[u];i;i=next[i]){int v=ev[i];
		if(!mk[v])dfs(v);
	}
	rank[k--]=u;
}

void work(){
	memset(nbs,0,sizeof(nbs));num=0;
	memset(rnbs,0,sizeof(rnbs));rnum=0;
	int i,u,v;
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		AddEdge(u,v);
	}
	memset(mk,0,sizeof(mk));k=n;
	for(i=1;i<=n;i++)if(!mk[i])dfs(i);
	memset(mk,0,sizeof(mk));
	for(i=1;i<=n;i++)if(!mk[rank[i]]){
		back(rank[i]);
		cout<<endl;
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

