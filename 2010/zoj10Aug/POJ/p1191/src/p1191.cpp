#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define N 8
#define nlim 9
#define maxn 15

int a[nlim][nlim],bit[nlim][nlim],n;
double f[maxn][nlim][nlim][nlim][nlim],ave;

int lowbit(const int &x){ return x&(x^(x-1)); }

void bit_modify(int x,int y,int d){
	for(int i=x;i<=N;i+=lowbit(i))
		for(int j=y;j<=N;j+=lowbit(j))
			bit[i][j]+=d;
}

int bit_sum(int x,int y){
	int res=0;for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			res+=bit[i][j];
	return res;
}

double sqr(const double &x){ return x*x; }

double min (const double &x,const double &y){ return (x<y)?x:y; }

double call(int x0,int y0,int x1,int y1){
	return (double)(bit_sum(x1,y1)+bit_sum(x0-1,y0-1)-bit_sum(x1,y0-1)-bit_sum(x0-1,y1));
}

void work(){
	int i,k,x,y,xx,yy;ave=0;
	memset(bit,0,sizeof(bit));
	memset(f,0x7f,sizeof(f));
	for(x=1;x<=N;x++)
		for(y=1;y<=N;y++){
			scanf("%d",&a[x][y]);
			bit_modify(x,y,a[x][y]);
			ave+=(double)a[x][y];
		}
	ave/=(double)n;
	for(x=1;x<=N;x++)for(y=1;y<=N;y++)
		for(xx=x;xx<=N;xx++)for(yy=y;yy<=N;yy++)
			f[1][x][y][xx][yy]=sqr(call(x,y,xx,yy)-ave);
	for(i=2;i<=n;i++)
		for(x=1;x<=N;x++)for(y=1;y<=N;y++)
			for(xx=x+1;xx<=N;xx++)for(yy=y+1;yy<=N;yy++){
				for(k=x;k+1<=xx;k++){
					f[i][x][y][xx][yy]=min(f[i][x][y][xx][yy],f[i-1][k+1][y][xx][yy]+f[1][x][y][k][yy]);
					f[i][x][y][xx][yy]=min(f[i][x][y][xx][yy],f[1][k+1][y][xx][yy]+f[i-1][x][y][k][yy]);
				}
				for(k=y;k+1<=yy;k++){
					f[i][x][y][xx][yy]=min(f[i][x][y][xx][yy],f[i-1][x][k+1][xx][yy]+f[1][x][y][xx][k]);
					f[i][x][y][xx][yy]=min(f[i][x][y][xx][yy],f[1][x][k+1][xx][yy]+f[i-1][x][y][xx][k]);
				}
			}
	printf("%.3f\n",sqrt(f[n][1][1][N][N]/(double)n));
}

int main(){
	while(scanf("%d",&n)!=EOF)work();
	return 0;
}

