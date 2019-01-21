#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

const int maxn = 1100000;

int n,m;
int root[maxn],fa[maxn],l[maxn],r[maxn];

void left(int v){
	int u=r[v];r[v]=l[u];fa[r[v]]=v;l[u]=v;
	if(v==l[fa[v]])
		l[fa[v]]=u;
	else
		if(v==r[fa[v]])r[fa[v]]=u;
	fa[u]=fa[v];fa[v]=u;
	root[u]=root[v]^root[u];
	root[v]=root[v]^root[u];
}

void right(int v){
	int u=l[v];l[v]=r[u];fa[l[v]]=v;r[u]=v;
	if(v==l[fa[v]])
		l[fa[v]]=u;
	else
		if(v==r[fa[v]])r[fa[v]]=u;
	fa[u]=fa[v];fa[v]=u;
	root[u]=root[v]^root[u];
	root[v]=root[v]^root[u];
}

void splay(int v){
	while(!root[v]){
		//cout<<"    Splay Maybe Error"<<endl;
		if(v==l[fa[v]]) right(fa[v]); else left(fa[v]);
	}
}

void access(int v){
	splay(v);while(fa[fa[v]]){
		//cout<<"    Access Maybe Error"<<endl;
		splay(fa[v]);int u=fa[v];
		root[r[u]]=1;root[v]=0;
		r[u]=v;splay(v);
	}
}

/*void access(int v){
	int u=v;v=0;
	do{
		splay(u);
		fa[r[u]]=u;
		r[u]=v;
		fa[v]=0;
		v=u;
		u=fa[u];
	}while(u!=0);
}

int find_root(int v){
	access(v);splay(v);
	while(l[v]!=0)v=l[v];
	splay(v);
	return v;
}

void cut(int v){
	access(v);l[v]=0;
}

void join(int v,int w){
	access(v);
	fa[v]=w;
	access(v);
}*/

void work(){
	cout<<"-New Case-"<<endl;
	int u,v,i;
	char str[10];
	memset(fa,0,sizeof(fa));
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	memset(root,1,sizeof(root));
	for(i=1;i<=n;i++){ scanf("%d",&fa[i]);if(!fa[i])fa[i]=0; }
	scanf("%d",&m);while(m--){
		scanf("%s",str);
		switch(str[0]){
			case 'Q':
				scanf("%d",&u);
				cout<<"  Query "<<u<<endl;
				access(u);
				printf("%d\n",(fa[u])?fa[u]:u);
				break;
			case 'M':
				scanf("%d%d",&u,&v);if(!v)v=0;
				cout<<"  Move "<<u<<"->"<<v<<endl;
				splay(u);
				fa[l[u]]=fa[u];
				root[l[u]]=1;l[u]=0;
				fa[u]=v;
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF)work();
	return 0;
}
