#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

const int maxn=55,maxm=110;

int n,sh,ss,sp,sm;
int f[maxn][maxn][maxm];
int ms[maxn],mp[maxn],mm[maxn];
bool d[maxn][maxn][maxm];

void output(const int &x,const int &y,const int &z){
	if(!x)return;
	output(x-1,(d[x][y][z])?y-1:y,(d[x][y][z])?z+mm[x-1]:z);
	if(d[x][y][z])printf("E");else printf("D");
	if(x==n)printf("\n");
}

void doit(){
	int i,j,k,dem;
	memset(f,0,sizeof(f));
	f[0][0][sm]=sh;
	for(i=0;i<n;i++)
		scanf("%d%d%d",&ms[i],&mp[i],&mm[i]);
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
			for(k=0;k<maxm;k++)
				if(f[i][j][k]){
					if(ss+i-j>=ms[i]){
						dem=ms[i]*2-(ss+i-j);if(dem<0)dem=0;
						if(f[i+1][j][k]<f[i][j][k]-dem){
							f[i+1][j][k]=f[i][j][k]-dem;
							d[i+1][j][k]=0;
						}
					}
					if(sp+j>=mp[i] && k>=mm[i] && f[i+1][j+1][k-mm[i]]<f[i][j][k]){
						f[i+1][j+1][k-mm[i]]=f[i][j][k];
						d[i+1][j+1][k-mm[i]]=1;
					}
				}
	for(j=0;j<=n;j++)
		for(k=0;k<maxm;k++)
			if(f[n][j][k]){
				output(n,j,k);
				return;
			}
	printf("UNLUCKY\n");
}

int main(){
	while(scanf("%d%d%d%d%d",&n,&sh,&ss,&sp,&sm)!=EOF)
		doit();
	return 0;
}
