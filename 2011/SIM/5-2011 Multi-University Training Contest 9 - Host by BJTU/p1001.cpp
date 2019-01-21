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

#define maxn 51

const double inf=(double)LONG_MAX;
const double eps=1e-6;

int T;

int n,m;
double ans,dis[maxn][maxn];
int px[maxn],py[maxn],mk[maxn];

int cx[maxn],cy[maxn],sx[maxn],sy[maxn];
double g[maxn][maxn],lx[maxn],ly[maxn];;

double max(const double &x,const double &y){ return (x>y)?x:y; }

double min(const double &x,const double &y){ return (x<y)?x:y; }

int equal(const double &x,const double &y){ return fabs(x-y)<eps; }

int path(const int &u){
	sx[u]=1;for(int v=1;v<=m;v++)if(equal(g[u][v],lx[u]+ly[v]) && !sy[v]){
		sy[v]=1;if(!cy[v] || path(cy[v])){ cx[u]=v;cy[v]=u;return 1; }
	}return 0;
}

void KM(){
	int i,j,u;
	double dlt;
	memset(lx,0,sizeof(lx));memset(ly,0,sizeof(ly));
	memset(cx,0,sizeof(cx));memset(cy,0,sizeof(cy));
	for(i=1;i<=m;i++)
		for(lx[i]=g[i][j=1];j<=m;j++)lx[i]=max(lx[i],g[i][j]);
	for(ans=0.0,u=1;u<=m;u++)if(!cx[u]){
		memset(sx,0,sizeof(sx));memset(sy,0,sizeof(sy));
		while(!path(u)){
			dlt=inf;
			for(i=1;i<=m;i++)if(!sx[i])
				for(j=1;j<=m;j++)if(sy[j])
					dlt=min(dlt,lx[i]+ly[j]-g[i][j]);
			for(i=1;i<=m;i++)if(sx[i]){ lx[i]-=dlt;sx[i]=0; }
			for(j=1;j<=m;j++)if(sy[j]){ ly[j]+=dlt;sy[j]=0; }
		}
	}
	for(i=1;i<=m;i++)ans+=g[cy[i]][i];
	ans=-ans/2.0;
}

void work(){m=n*2;
	int i,j;
	for(i=1;i<=m;i++)scanf("%d%d",&px[i],&py[i]);
	for(i=0;i<=m;i++)
		for(j=0;j<=m;j++)
			dis[i][j]=sqrt(((double)((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j])))+eps);
	for(i=1;i<=m;i++)
		for(j=1;j<=m;j++){
			if(i==j){ g[i][j]=-inf;continue; }
			g[i][j]=-(dis[i][j]+min(dis[0][i],dis[0][j]));
		}
	KM();
	printf("Case #%d: %.2f\n",T,ans+eps);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++){
		scanf("%d%d%d",&px[0],&py[0],&n);
		work();
	}
	return 0;
}

