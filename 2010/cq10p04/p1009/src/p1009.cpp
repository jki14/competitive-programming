#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 1000
#define less -5100000
#define dt -20000
#define brk -20000000
#define dl -11000

int timer;

int n,m,e,res,g[maxn][maxn];
int cx[maxn],cy[maxn],sx[maxn],sy[maxn],lx[maxn],ly[maxn];

int path(int u){
	sx[u]=1;for(int v=1;v<=m;v++)if(g[u][v]==lx[u]+ly[v] && !sy[v]){
		sy[v]=1;if(!cy[v] || path(cy[v])){ cx[u]=v;cy[v]=u;return 1; }
	}
	return 0;
}

void doit(){
	int i,j,u,min;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			g[i][j]=brk;
	for(i=0;i<e;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		x++;y++;
		if(z<0)z+=dt;
		g[x][y]=z;
	}
	//cout<<g[2][1]<<endl;
	//KM
	memset(lx,0x8f,sizeof(lx));
	memset(ly,0,sizeof(ly));
	memset(cx,0,sizeof(cx));
	memset(cy,0,sizeof(cy));
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(lx[i]<g[i][j])lx[i]=g[i][j];
	for(res=0,u=1;u<=n;u++)if(!cx[u]){
		memset(sx,0,sizeof(sx));memset(sy,0,sizeof(sy));
		while(!path(u)){
			min=LONG_MAX;
			for(i=1;i<=n;i++)if(sx[i])
				for(j=1;j<=m;j++)if(!sy[j])
					if(lx[i]+ly[j]-g[i][j]<min)min=lx[i]+ly[j]-g[i][j];
			for(i=1;i<=n;i++)if(sx[i]){ lx[i]-=min;sx[i]=0; }
			for(j=1;j<=m;j++)if(sy[j]){ ly[j]+=min;sy[j]=0; }
		};
	}
	for(i=1;i<=n;i++)
		if(g[i][cx[i]]<less){
			res=-1;
			break;
		}
		else{
			res+=g[i][cx[i]];
			if(g[i][cx[i]]<dl)res-=dt;
		}
	//cout<<cx[2]<<endl;
	printf("Case %d: %d\n",timer++,res);
}

int main(){
	timer=1;
	while(scanf("%d%d%d",&n,&m,&e)!=EOF)doit();
	return 0;
}
