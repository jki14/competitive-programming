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

#define N 1100
#define M 21
#define F 7
#define P 8
#define LEN 110

const int m=11;

const int inf=0x3fffffff;

const string nam[F]={ "A","B","C","D","E","F","China" };

const int table[F][P]={ {1,2,1,1,2,1,1,2},
			{1,2,1,1,3,1,1,1},
			{1,2,1,1,3,0,0,3},
			{1,3,0,0,3,1,1,2},
			{1,3,0,0,4,1,1,1},
			{1,3,1,1,3,0,0,2},
			{1,4,1,1,3,0,0,1}};

int n;
int a[N][P], g[M][N];
int rat[F],top;

int ret;
int cx[N],cy[N],sx[N],sy[N],lx[N],ly[N];

char cstr[LEN];

int path(const int &u){sx[u]=1;
	for(int v=1;v<=n;v++)if(g[u][v]==lx[u]+ly[v] && !sy[v]){
		sy[v]=1;if(!cy[v] || path(cy[v])){ cx[u]=v; cy[v]=u; return 1; }
	} return 0;
}

void KuhnMunkres(){
	memset(lx,0,sizeof(lx));memset(ly,0,sizeof(ly));
	memset(cx,0,sizeof(cx));memset(cy,0,sizeof(cy));
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)lx[i]=max(lx[i],g[i][j]);
	for(int u=1;u<=m;u++)if(!cx[u]){
		memset(sx,0,sizeof(sx));memset(sy,0,sizeof(sy));
		while(!path(u)){
			int cha=inf;
			for(int i=1;i<=m;i++)if(sx[i]){
				//printf("Try x=%d\n",i);
				for(int j=1;j<=n;j++)if(!sy[j]){
					//printf("	Try y=%d\n",j);
					//printf("path=%d\n",lx[i]+ly[j]-g[i][j]);
					cha=min(cha,lx[i]+ly[j]-g[i][j]);
				}
			}
			//printf("cha=%d\n",cha);
			for(int i=1;i<=m;i++)if(sx[i]){ lx[i]-=cha;sx[i]=0; }
			for(int j=1;j<=n;j++)if(sy[j]){ ly[j]+=cha;sy[j]=0; }
		}
	}

	ret=0;for(int i=1;i<=m;i++)ret+=g[i][cx[i]];
}

void work(){
	for(int i=1;i<=n;i++){scanf("%s",cstr);
		for(int j=0;j<P;j++)scanf("%d",&a[i][j]);
	}

	for(int k=0;k<F;k++){int cnt=0;
		memset(g,0,sizeof(g));
		for(int i=0;i<P;i++){
			for(int j=0;j<table[k][i];j++){++cnt;
				for(int player=1;player<=n;player++)
					g[cnt][player]=a[player][i];
			}
		}
		KuhnMunkres();rat[k]=ret;
	}

	top=0;for(int k=1;k<F;k++)if(rat[top]<rat[k])top=k;
	for(int k=0;k<F;k++)if(rat[k]==rat[top])
		printf("Formation %s has the highest points %d.\n",nam[k].c_str(),rat[k]);
	printf("\n");
}

int main(){
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

