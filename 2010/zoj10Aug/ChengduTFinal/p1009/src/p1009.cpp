#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define lld long long
#define maxn 510

const lld inf=1LL<<60;
const lld base=10000000LL;
const lld col=6000000LL;
const lld vmin=-10000;

int n,m,e,TIMER;
lld g[maxn][maxn],lx[maxn],ly[maxn],res;

int cx[maxn],cy[maxn],sx[maxn],sy[maxn];

int path(int u){
	sx[u]=1;for(int v=1;v<=m;v++)if(g[u][v]==lx[u]+ly[v] && !sy[v]){
		sy[v]=1;if(!cy[v] || path(cy[v])){ cx[u]=v;cy[v]=u;return 1; }
	}
	return 0;
}

lld KM(){
	int i,j,u;
	lld min,match;
	memset(lx,0,sizeof(lx));memset(ly,0,sizeof(ly));
	memset(cx,0,sizeof(cx));memset(cy,0,sizeof(cy));
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(lx[i]<g[i][j])lx[i]=g[i][j];
	for(match=0LL,u=1;u<=n;u++)if(!cx[u]){
		memset(sx,0,sizeof(sx));memset(sy,0,sizeof(sy));
		while(!path(u)){
			min=inf;for(i=1;i<=n;i++)if(sx[i])for(j=1;j<=m;j++)if(!sy[j])
				if(lx[i]+ly[j]-g[i][j]<min)min=lx[i]+ly[j]-g[i][j];
			for(i=1;i<=n;i++)if(sx[i]){ lx[i]-=min;sx[i]=0; }
			for(j=1;j<=m;j++)if(sy[j]){ ly[j]+=min;sy[j]=0; }
		}
	}
	for(i=1;i<=n;i++)if(cx[i]){
		if(g[i][cx[i]]>=col+base)match-=col;
		match+=g[i][cx[i]];
	}
	return match;
}

void work(){
	memset(g,0,sizeof(g));
	int u,v,w;while(e--){
		scanf("%d%d%d",&u,&v,&w);u++;v++;g[u][v]=base+(lld)w;
		if(w>=0)g[u][v]+=col;
		//cout<<" Link "<<u<<"->"<<v<<" = "<<g[u][v]<<endl;
	}
	res=KM();//cout<<" res="<<res<<endl;
	res-=base*n;if(res<vmin*n)res=(lld)-1;
	printf("Case %d: %d\n",TIMER,(int)res);
}

int main(){
	for(TIMER=0;scanf("%d%d%d",&n,&m,&e)!=EOF;work())TIMER++;
	return 0;
}
