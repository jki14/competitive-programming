#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 40
#define maxm 30

#define N 36
#define M 20

const int inf=1000000000;

int n,m,f[maxn][maxn][maxm];

int min(int x,int y){ return (x<y)?x:y; }

void init(){
	memset(f,0x3f,sizeof(f));
	int i,j,k,x;
	for(i=1;i<=N;i++){
		for(j=1;j<=i;j++)
			f[i][j][0]=1;
		for(k=0;k<=M;k++)
			f[i][0][k]=0;
	}
	for(k=0;k<=m;k++)f[0][0][k]=0;
	for(k=1;k<=M;k++)
		for(i=1;i<=N;i++)
			for(j=1;j<=i;j++){
				f[i][j][k]=min(f[i][j][k],f[i][j*2][k-1]+1);
				for(x=1;x<j;x++){
					f[i][j][k]=min(f[i][j][k],f[i][x][k]+f[i-x][j-x][k]);
				}
			}
}

void work(){
	int res=f[n][1][m];
	if(res>inf)res=-1;
	printf("%d\n",res);
}

int main(){
	init();while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))work();
	return 0;
}
