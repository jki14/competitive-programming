//============================================================================
// Name        : ConnectivityDP-MultiCircle
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 插头DP，多回路(含单回路)完全遍历方案数,例为hdu1693
//============================================================================

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

#define N 12
#define S 11000

typedef long long lld;

int T;

int n,m;
lld f[N][N][S];
char a[N][N];

void work(){
	/* Init */
	scanf("%d%d",&n,&m);
	int len=1<<m,len2=1<<m<<1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int k;scanf("%d",&k);
			if(k)a[i][j]=1;else a[i][j]=0;
		}
	/* Core */
	memset(f,0,sizeof(f));f[0][m][0]=1LL;
	for(int i=1;i<=n;i++){

		for(int j=0;j<len;j++)
			f[i][0][j<<1]=f[i-1][m][j];

		for(int j=1;j<=m;j++){
			for(int k=0;k<len2;k++){

				int p=1<<j,q=p>>1;
				int x=(p&k)>0,y=(q&k)>0;

				if(a[i][j]){
					f[i][j][k]=f[i][j-1][k^p^q];
					if(x!=y)f[i][j][k]+=f[i][j-1][k];
				}else if(!x && !y)f[i][j][k]=f[i][j-1][k];
			}
		}

	}
	/* Output */
	printf("Case %d: There are %I64d ways to eat the trees.\n",T,f[n][m][0]);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

