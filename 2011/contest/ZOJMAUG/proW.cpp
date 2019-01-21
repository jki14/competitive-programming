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

#define K 8
#define L 21
#define M 110

int n,m;
int a[K];

int eu[M],ev[M],next[M],rev[M],num;
int nbs[K],mk[K],low[K],d[K],r[K];
int bri[M],brinum,color,ti;

char s[L];

void AddEdge(const int &u,const int &v){
	//printf("AddEdge(%d,%d)\n",u,v);
	eu[++num]=u;ev[num]=v;next[num]=nbs[u];nbs[u]=num;rev[num]=0;
	eu[++num]=v;ev[num]=u;next[num]=nbs[v];nbs[v]=num;rev[num]=1;
}

void TarjanBridge(const int &u,const int &p){
	int i,v,s=0;low[u]=d[u]=++ti;mk[u]=-color;
	for(i=nbs[u];i;i=next[i]){v=ev[i];
		if(v==p)continue;
		if(!mk[v]){TarjanBridge(v,u);s++;
			low[u]=min(low[u],low[v]);
			if(low[v]==d[v]){
				brinum++;
				bri[rev[i]?i-1:i]=1;
			}
		}else low[u]=min(low[u],d[v]);
	}
	mk[u]=color;
}

void MarkBridge(){
	memset(bri,0,sizeof(bri));
	memset(mk,0,sizeof(mk));
	color=ti=brinum=0;
	for(int i=0;i<K;i++)if(a[i] && !mk[i]){
		++color;TarjanBridge(i,0);
	}
}

int succ(){
	for(int i=0;i<K;i++)
		if(a[i]<r[i])return 0;
	return 1;
}

void work(){
	int i,j,k;

	memset(a,0,sizeof(a));
	memset(r,0,sizeof(r));

	for(i=0;i<n;i++){
		scanf("%s",s);scanf("%s",s);
		for(k=j=0;s[j];j++){
			k|=(s[j]=='A')?1:(s[j]=='C')?2:4;
		}
		//printf("a[%d]++\n",k);
		a[k]++;
	}
	
	memset(nbs,0,sizeof(nbs));num=0;
	for(i=0;i<K;i++){if(!a[i])continue;
		for(j=i+1;j<K;j++){if(!a[j])continue;
			if(i&j)AddEdge(i,j);
		}
	}
	MarkBridge();
	//printf("color=%d\n",color);


	for(i=1;i<=num;i++){if(rev[i])continue;
		if(!bri[i])r[eu[i]]=r[ev[i]]=1;
	}
	for(i=1;i<=num;i++)if(bri[i]){ r[eu[i]]++;r[ev[i]]++; }

	if(color<2 && succ()){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

