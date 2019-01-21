#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 51000
#define maxm 1000005
#define tar 50000
#define sta 0
#define inf 60000

int nbs[maxn],next[maxm],value[maxn],open[maxn],open1[maxn];
int ev[maxm],ew[maxm],mk[maxn],n,m,num,cur,tail,res;

void BellmanFord(int src){
	int i,t,u,v,p=0;
	for(int i=0;i<=tar;i++){ value[i]=inf; mk[i]=0; }
	value[src]=tail=0; open[0]=src;
	while(++p,tail>=0){
		for(i=0;i<=tail;i++)open1[i]=open[i];
		for(cur=0,t=tail,tail=-1;cur<=t;cur++)
			for(u=open1[cur],i=nbs[u];i;i=next[i]){
				v=ev[i];if(value[u]+ew[i]<value[v]){
					value[v]=value[u]+ew[i];
					if(mk[v]!=p){ open[++tail]=v; mk[v]=p; }
				}
			}
	}
}

void work(){
	num=0;memset(nbs,0,sizeof(nbs));
	for(int i=0;i<tar;i++){
		next[++num]=nbs[i];nbs[i]=num;
		ev[num]=i+1; ew[num]=0;
		next[++num]=nbs[i+1];nbs[i+1]=num;
		ev[num]=i; ew[num]=1;
	}
	for(int i=0;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		next[++num]=nbs[u];nbs[u]=num;
		ev[num]=v+1; ew[num]=-w;
	}
	BellmanFord(sta);
	res=-value[tar];
	printf("%d\n",res);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}
