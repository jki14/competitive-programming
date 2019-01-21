#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

const int maxn=100,maxd=110000;

int a[maxn][maxn];
int d[maxn];
bool vis[maxn];
int n,m,k;

void doit(){
	scanf("%d",&n);
	int i,j,x,y,p;
	int mind,minp;
	bool add;
	memset(a,0x7f,sizeof(a));
	memset(vis,0,sizeof(vis));
	k=0;
	for(i=0;i<n;i++){
		scanf("%d%d",&x,&p);
		a[0][x]=p-1;
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d%d%d",&x,&y,&p);
		if(a[x][y]>p)a[x][y]=p;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(a[0][i]==a[0][j])
				a[i][j]=0;
	for(i=0;i<=n;i++)
		d[i]=a[0][i];
	vis[0]=true;
	for(j=1;j<=n;j++){
		mind=LONG_MAX;
		for(i=0;i<=n;i++)
			if((!vis[i])&&(mind>d[i]))
				mind=d[i],minp=i;
		vis[minp]=true;
		if(mind>maxd)break;
		for(i=0;i<=n;i++)
			if((a[minp][i]<maxd)&&(d[i]>mind+a[minp][i]))
				d[i]=mind+a[minp][i];
	}
	for(x=1;x<=n;x++,add=1)
		for(i=1;i<n && add;i++)
			for(j=i+1;j<=n && add;j++)
				if((d[x]==d[i]+d[j])&&(x!=i)&&(x!=j))k++,add=0;
	for(i=1;i<=n;i++)
		printf("%d %d\n",i,d[i]);
	printf("%d\n",k);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)doit();
	return 0;
}
