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

#define maxn 21
#define maxm 11
#define maxp 1100
#define maxk 1100
#define K 4

#define X xque[head]
#define Y yque[head]

const int dx[K]={ -1,0,1,0 };
const int dy[K]={ 0,1,0,-1 };

const int inf=LONG_MAX;
const int low=LONG_MIN;

int T;

int n,m,ans,id,num,rat;
int a[maxn][maxm],r[maxn][maxm];
int px[maxk][maxn][maxm],py[maxk][maxn][maxm],best;
int mk[maxn][maxm],f[maxn][maxm];
int clox[maxk],cloy[maxk];
int sx,sy,tx,ty;
int head,tail,xque[maxp],yque[maxp];
int del[maxn][maxm];

char c[maxn][maxm];

void update(const int &k){++rat;
	int i,x,y;
	head=tail=0;
	xque[tail]=sx;yque[tail]=sy;tail++;
	mk[X][Y]=rat;f[X][Y]=1;
	while(head<tail){
		for(i=0;i<K;i++){x=X+dx[i];y=Y+dy[i];
			if(mk[x][y]==rat || a[x][y])continue;
			mk[x][y]=rat;
			px[k][x][y]=X;py[k][x][y]=Y;
			if(x==tx && y==ty){
				best=f[X][Y]+1;
				return;
			}
			f[x][y]=f[X][Y]+1;
			xque[tail]=x;yque[tail]=y;tail++;
		}
		head++;
	}
	best=-1;
}

void path(const int &k,int &x,int &y){
	int i=x,j=y;
	x=px[k][i][j];y=py[k][i][j];
}

void dfs(const int &rank){
	int i,x,y;

	update(rank);

	if(best==-1)return;
	if(ans<best){
		ans=best;id=++num;
		for(i=0;i<rank;i++)r[clox[i]][cloy[i]]=id;
	}
	x=tx;y=ty;path(rank,x,y);
	for(;!(x==sx && y==sy);path(rank,x,y)){
		if(del[x][y]<rank)continue;
		a[x][y]=1;
		clox[rank]=x;cloy[rank]=y;
		dfs(rank+1);
		a[x][y]=0;
		del[x][y]=rank;
	}
}

void work(){
	int i,j;
	memset(a,0,sizeof(a));ans=low;
	for(i=0;i<=m+1;i++)a[0][i]=a[n+1][i]=1;
	for(i=0;i<=n+1;i++)a[i][0]=a[i][m+1]=1;
	for(i=1;i<=n;i++){
		scanf("%s",c[i-1]);
		for(j=1;j<=m;j++){
			switch(c[i-1][j-1]){
				case 'S':
					sx=i;sy=j;
					break;
				case 'T':
					tx=i;ty=j;
					break;
				case 'B':
					a[i][j]=1;
			}
		}
	}
	memset(mk,0,sizeof(mk));
	memset(r,0,sizeof(r));
	memset(del,0x7f,sizeof(del));
	num=rat=0;
	dfs(0);
	printf("Case %d: %d\n",T,ans);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(c[i-1][j-1]!='.'){
				printf("%c",c[i-1][j-1]);
				continue;
			}
			if(r[i][j]==id)
				printf("W");
			else
				printf(".");
		}
		printf("\n");
	}
	printf("\n");
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++){
		scanf("%d%d",&n,&m);
		work();
	}
	return 0;
}

