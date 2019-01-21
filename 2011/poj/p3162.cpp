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

#define maxn 2100000

int n,m,ans;
int a[maxn];
int ev[maxn],ew[maxn],nbs[maxn],next[maxn],num;
int fir[maxn],sec[maxn],pat[maxn],mk[maxn];

int tque[maxn],tl,tr;
int bque[maxn],bl,br;

void AddEdge(const int &u,const int &v,const int &w){
	num++;ev[num]=v;ew[num]=w;next[num]=nbs[u];nbs[u]=num;
	num++;ev[num]=u;ew[num]=w;next[num]=nbs[v];nbs[v]=num;
}

int mark(const int &u){

	//printf("Mar %d\n",u);

	int i,v,d;
	mk[u]=1;
	for(i=nbs[u];i;i=next[i]){v=ev[i];
		if(mk[v])continue;

		//printf("Try %d ",v);

		d=mark(v)+ew[i];

		//printf("d=%d\n",d);

		if(d>=fir[u]){
			sec[u]=fir[u];
			fir[u]=d;
			pat[u]=v;
			continue;
		}
		if(d>sec[u]) sec[u]=d;
	}
	return fir[u];	
}

void dfs(const int &u,const int &path){
	int i,v;
	mk[u]=1;
	if(path>=fir[u]){
		a[u]=path;
		pat[u]=0;
	}else a[u]=fir[u];
	for(i=nbs[u];i;i=next[i]){v=ev[i];
		if(mk[v])continue;
		if(v==pat[u]){
			dfs(v,max(path,sec[u])+ew[i]);
			continue;
		}
		dfs(v,a[u]+ew[i]);
	}
}

void work(){
	int i,v,k,left;ans=0;
	memset(nbs,0,sizeof(nbs));num=0;
	for(i=2;i<=n;i++){
		scanf("%d%d",&v,&k);
		AddEdge(i,v,k);
	}
	memset(fir,0,sizeof(fir));
	memset(sec,0,sizeof(sec));
	memset(pat,0,sizeof(pat));
	memset(mk,0,sizeof(mk));
	for(i=1;i<=n;i++){
		if(mk[i])continue;
		mark(i);
	}
	memset(mk,0,sizeof(mk));
	for(i=1;i<=n;i++){
		if(mk[i])continue;
		dfs(i,0);
	}

	//for(i=1;i<=n;i++)printf(" %d",a[i]);

	tl=tr=bl=br=0;
	for(i=1;i<=n;i++){
		while(tl<tr && a[tque[tl]]-a[i]>m){ left=max(left,tque[tl]+1);tl++; }
		while(bl<br && a[i]-a[bque[bl]]>m){ left=max(left,bque[bl]+1);bl++; }
		if(tl==tr || bl==br){
			left=i;
			ans=max(ans,1);
		}else{
			ans=max(ans,i-left+1);
		}
		while(tl<tr && a[tque[tr-1]]<=a[i])tr--;
		while(bl<br && a[bque[br-1]]>=a[i])br--;
		tque[tr++]=bque[br++]=i;
	}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

