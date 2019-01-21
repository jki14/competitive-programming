#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxv 110
#define maxp 11000

const int inf=1100000;

int n,m,sum;
int g[maxv][maxv],d[maxv],c[maxv],mk[maxv];
int f[maxp];

int min(int x,int y){ return (x<y)?x:y; }

void dijkstra(int src){
	int i,j,min,pre=src;
	memset(mk,0,sizeof(mk));mk[src]=1;
	memset(d,0x3f,sizeof(d));
	d[src]=0;
	for(i=0;i<n;i++){
		min=inf;for(j=0;j<=n;j++)
			if(!mk[j] && d[pre]+g[pre][j]<d[j])
				d[j]=d[pre]+g[pre][j];
		for(j=0;j<=n;j++)
			if(!mk[j] && d[j]<min){
				pre=j;min=d[j];
			}
		if(min==inf)break;mk[pre]=1;
	}
}

void work(){
	int i,j,u,v,w,res,sum=0,tot=0,half;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			g[i][j]=inf;
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		g[u][v]=min(g[u][v],w);
		g[v][u]=min(g[v][u],w);
	}
	dijkstra(0);
	for(i=1;i<=n;i++){
		scanf("%d",&c[i]);tot+=c[i];sum+=d[i];
		//cout<<" at point "<<i<<" c="<<c[i]<<" d="<<d[i]<<endl;
	}
	half=(tot-1)>>1;
	//cout<<" half="<<half<<endl;
	//cout<<" sum="<<sum<<endl;
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++)
		for(j=half;j>=0;j--)
			if(j>=c[i])f[j]=max(f[j],f[j-c[i]]+d[i]);
	res=sum-f[half];
	//cout<<" f[half]="<<f[half]<<endl;
	if(res>=inf)
		printf("impossible\n");
	else
		printf("%d\n",res);
}

int main(){
	int t;scanf("%d",&t);
	while(t--){ scanf("%d%d",&n,&m);work(); }
	return 0;
}

