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

int n,m,u,uu,v;
int f[maxn],d[maxn],c[maxn],t[maxn],sum[maxn];
char req[10];

int getf(int x){
	if(f[x]!=x){
		int pnt=0;if(f[x]!=f[f[x]])pnt=f[x];
		f[x]=getf(f[x]);
		if(pnt)t[x]+=t[pnt];
	}
	return f[x];
}

void work(){
	memset(f,0,sizeof(f));
	memset(d,0,sizeof(d));
	memset(c,0,sizeof(c));
	memset(t,0,sizeof(t));
	scanf("%d%d",&n,&m);
	int i,res0,res1,res2;
	for(i=1;i<=n;i++){ f[i]=d[i]=c[i]=i;sum[i]=1; }
	while(m--){
		scanf("%s",req);
		switch(req[0]){
			case 'T':
				scanf("%d%d",&u,&v);
				u=d[getf(u)];v=d[getf(v)];
				if(!c[v]){
					t[c[u]]++;c[v]=c[u];d[c[v]]=v;c[u]=0;
					sum[v]=sum[u];sum[u]=0;
				}else{
					t[c[u]]++;f[c[u]]=c[v];t[c[u]]-=t[c[v]];d[c[u]]=0;c[u]=0;
					sum[v]+=sum[u];sum[u]=0;
				}
				break;
			case 'Q':
				scanf("%d",&v);
				res0=d[getf(v)];res1=sum[res0];
				res2=t[v];if(v!=f[v])res2+=t[f[v]];
				printf("%d %d %d\n",res0,res1,res2);
		}
	}
}

int main(){
	int t;scanf("%d",&t);
	for(int i=1;i<=t;i++){
		printf("Case %d:\n",i);
		work();
	}
}
