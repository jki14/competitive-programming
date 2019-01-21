#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 110
#define maxm 110000
#define maxl 110

int n,m,np,nc;
int c[maxm],f[maxm],ev[maxm],be[maxm],next[maxm],num;
int nbs[maxn],pnt[maxn],open[maxn],oldque[maxn],d[maxn],mk[maxn];
char str[maxl];

void AddEdge(int u,int v,int cc){
	next[++num]=nbs[u]; nbs[u]=num; be[num]=num+1;
	ev[num]=v; c[num]=cc; f[num]=0;
	next[++num]=nbs[v]; nbs[v]=num; be[num]=num-1;
	ev[num]=u; c[num]=0; f[num]=0;
}

int maxflow(int n,int s,int t){
	int cur,tail,j,u,v,flow=0;
	do{ memset(mk,0,sizeof(mk)); memset(d,0,sizeof(d));
		open[0]=s; mk[s]=1; d[s]=0x3fffffff;
		for(pnt[s]=cur=tail=0;cur<=tail && !mk[t]; cur++)
			for(u=open[cur],j=nbs[u];j;j=next[j]){ v=ev[j];
				if(!mk[v] && f[j]<c[j]){
					mk[v]=1; open[++tail]=v; pnt[v]=j;
					if(d[u]<c[j]-f[j]) d[v]=d[u]; else d[v]=c[j]-f[j];
				}
			}
		if(!mk[t])break; flow+=d[t];
		for(u=t;u!=s;u=ev[be[j]]){ j=pnt[u];f[j]+=d[t];f[be[j]]=-f[j]; }
	}while(d[t]>0); return flow;
}

void work(){
	memset(nbs,0,sizeof(nbs));num=0;
	int i,x,y,cc;n+=2;
	for(i=0;i<m;i++){
		scanf("%s",str);
		sscanf(str,"(%d,%d)%d",&x,&y,&cc);
		AddEdge(x+1,y+1,cc);
	}
	for(i=0;i<np;i++){
		scanf("%s",str);
		sscanf(str,"(%d)%d",&y,&cc);
		AddEdge(n-1,y+1,cc);
	}
	for(i=0;i<nc;i++){
		scanf("%s",str);
		sscanf(str,"(%d)%d",&x,&cc);
		AddEdge(x+1,n,cc);
	}
	printf("%d\n",maxflow(n,n-1,n));
}

int main(){
	while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
		work();
	return 0;
}
