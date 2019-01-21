#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 11000
#define maxm 51000

struct node{
	int val;
	struct node *next;
}*g[maxn],*_g[maxn],*p;

int n,m,vtx,num,mark;
int mk[maxn],f[maxn],s[maxn],list[maxn],d[maxn];

void dfs(int u){
	mk[u]=1;
	struct node *p=g[u];while(p){
		int v=p->val;
		if(!mk[v])dfs(v);
		p=p->next;
	}
	list[num--]=u;
}

void _dfs(int u){
	f[u]=vtx;
	struct node *p=_g[u];while(p){
		int v=p->val;
		if(!f[v])_dfs(v);
		p=p->next;
	}
}

void getd(const int x){
	struct node *p=g[x];while(p){
		int v=p->val;
		if(f[v]!=f[x])d[f[x]]++;
		p=p->next;
	}
}

void work(){
	memset(s,0,sizeof(s));
	int i,u,v,d0=0,res=0;for(i=1;i<=n;i++){g[i]=_g[i]=NULL;}
	while(m--){
		scanf("%d%d",&u,&v);
		p=new node;p->val=v;p->next=g[u];g[u]=p;
		p=new node;p->val=u;p->next=_g[v];_g[v]=p;
	}
	memset(mk,0,sizeof(mk));memset(f,0,sizeof(f));num=n;
	for(i=1;i<=n;i++)if(!mk[i])dfs(i);
	for(i=1;i<=n;i++)if(!f[list[i]]){ vtx=list[i];_dfs(vtx); }
	memset(d,0,sizeof(d));memset(mk,0,sizeof(mk));
	for(i=1;i<=n;i++)getd(i);
	for(i=1;i<=n;i++)if(!mk[f[i]] && !d[f[i]]){ mk[f[i]]=1;d0++;vtx=f[i]; };
	if(d0==1)for(i=1;i<=n;i++)
		if(f[i]==vtx)res++;
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}
