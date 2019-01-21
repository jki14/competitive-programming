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

#define maxn 1100000

int n,m;
int ev[maxn],ew[maxn],next[maxn],nbs[maxn],num;
int d[maxn];
int que[maxn],inque[maxn];

void AddEdge(const int &u,const int &v,const int &w){
	
	//printf("Add Edge %d->%d %d\n",u,v,w);
	
	num++;ev[num]=v;ew[num]=w;
	next[num]=nbs[u];nbs[u]=num;
}

void spfa(const int &s){
	int i,u,v,w,l,r;
	l=r=0;que[r++]=s;
	inque[s]=1;d[s]=0;
	while(l<r){
		u=que[l++];inque[u]=0;
		for(i=nbs[u];i;i=next[i]){v=ev[i];w=ew[i];
			if(d[v]<d[u]+w){
				d[v]=d[u]+w;
				//printf(" d[%d] = %d\n ",v,d[v]);
				if(!inque[v]){
					inque[v]=1;
					que[r++]=v;
				}
			}
		}
	}
}

void work(){
	int i,u,v,w;
	memset(nbs,0,sizeof(nbs));num=n=0;
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		AddEdge(u,v+1,w);
		n=max(n,v+1);
	}
	for(i=0;i<n;i++){
		AddEdge(i,i+1,0);
		AddEdge(i+1,i,-1);
	}
	memset(d,0x8f,sizeof(d));
	memset(inque,0,sizeof(inque));
	spfa(0);
	printf("%d\n",d[n]);
}

int main(){
	while(scanf("%d",&m)!=EOF)
		work();
	return 0;
}

