#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define maxn 5100

vector<int> g[maxn],_g[maxn],res;
map<int,int> a[maxn];

int n,m,list[maxn],f[maxn],num,mark;
int d[maxn],s[maxn],p[maxn],now,mk[maxn];

void back(int u){
	f[u]=mark;int v;for(int i=0;i<(int)_g[u].size();i++)
		if(!f[v=_g[u][i]])back(v);
}

void dfs(int u){
	f[u]=1;int v;for(int i=0;i<(int)g[u].size();i++)
		if(!f[v=g[u][i]])dfs(v);
	list[num--]=u;
}

void add(int u){
	map<int,int>::iterator it;int v;
	now+=p[u];mk[u]=1;
	for(it=a[u].begin();it!=a[u].end();it++){
		v=(*it).first;if(!mk[v])add(v);
	}
}

void work(){
	scanf("%d%d",&n,&m);
	int i,u,v,l,r,best=0;
	map<int,int>::iterator it;
	for(i=1;i<=n;i++){ g[i].clear();_g[i].clear();a[i].clear(); }
	memset(p,0,sizeof(p));
	memset(d,0,sizeof(d));
	for(i=0;i<m;i++){
		scanf("%d%d",&u,&v);u++;v++;
		g[u].push_back(v);_g[v].push_back(u);
	}
	memset(f,0,sizeof(f));num=n;
	for(i=1;i<=n;i++)if(!f[i])dfs(i);
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++)if(!f[mark=list[i]])back(mark);
	for(u=1;u<=n;u++)
		for(i=0;i<(int)g[u].size();i++){
			if(f[u]==f[g[u][i]])continue;
			a[f[g[u][i]]][f[u]]=1;
			//cout<<" link "<<f[u]<<"->"<<f[g[u][i]]<<" "<<endl;
		}
	for(u=1;u<=n;u++)
		for(it=a[u].begin();it!=a[u].end();it++)
			d[(*it).first]++;
	l=r=0;
	for(i=1;i<=n;i++){
		p[f[i]]++;
		//cout<<" f["<<i<<"]="<<f[i]<<endl;
		if(f[i]==i && !d[i])s[r++]=i;
	}
	while(l<r){
		u=s[l++];memset(mk,0,sizeof(mk));now=0;add(u);
		p[u]=now;
		for(it=a[u].begin();it!=a[u].end();it++){
			v=(*it).first;d[v]--;
			if(!d[v])s[r++]=v;
		}
	}
	for(i=1;i<=n;i++)
		if(best<p[i])best=p[i];
	printf("%d\n",best-1);res.clear();
	for(i=1;i<=n;i++)
		if(p[f[i]]==best)res.push_back(i-1);
	for(i=0;i<(int)res.size();i++){
		if(i)printf(" ");
		printf("%d",res[i]);
	}
	printf("\n");
}

int main(){
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case %d: ",i);
		work();
	}
	return 0;
}
