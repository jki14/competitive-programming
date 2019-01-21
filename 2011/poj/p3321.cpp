#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 1100000
#define maxm 1100000
#define maxl 11

int n,m,q;
int nbs[maxn],next[maxm],ev[maxm],num;
int s[maxn],t[maxn];
int c[maxn],a[maxn],mk[maxn];
int lowbit[maxn];

char cast[maxl];

//int lowbit(const int &x){ return x&(x^(x-1)); }

void AddEdge(const int &u,const int &v){
	num++;ev[num]=v;next[num]=nbs[u];nbs[u]=num;
	num++;ev[num]=u;next[num]=nbs[v];nbs[v]=num;
}

void mark(const int &u){
	if(mk[u])return;mk[u]=1;
	s[u]=++m;
	int i,v;
	for(i=nbs[u];i;i=next[i]){v=ev[i];
		mark(v);
	}
	t[u]=++m;
}

void modify(int x,const int &d){  for(;x<=m;x+=lowbit[x])c[x]+=d;  }

int sum(int x){ int ret=0;for(;x>0;x-=lowbit[x])ret+=c[x];return ret; }

void change(const int &x){
	if(x<1 || x>n)return;
	a[x]^=1;
	modify(s[x],a[x]-(a[x]^1));
	modify(t[x],a[x]-(a[x]^1));
}

int que(const int &x){
	if(x<1 || x>n)return 0;
	return (sum(t[x])-sum(s[x]-1))>>1;
}

void work(){
	int i,u,v;m=0;
	memset(nbs,0,sizeof(nbs));num=0;
	for(i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		AddEdge(u,v);
	}
	memset(mk,0,sizeof(mk));
	mark(1);
	//memset(a,0,sizeof(a));
	//for(i=1;i<=n;i++)change(i);
	for(i=1;i<=m;i++){
		lowbit[i]=i&(-i);
		a[i]=1;
		c[i]=lowbit[i];
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%s%d",cast,&v);
		if(cast[0]=='C'){
			change(v);
		}else{
			printf("%d\n",que(v));
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

