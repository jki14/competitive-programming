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
#include<set>
#include<map>
using namespace std;

#define maxn 1100
#define maxm 1100
#define maxl 1100

int n,m,L;
int a[maxn],s[maxn];
int f[maxn][maxm];
int d[maxn][maxn],x[maxn],y[maxn];

int sum(const int &u,const int &v){
	return s[v]-s[u-1];
}

void work(){
	int i,j,k,t;
	memset(f,0,sizeof(f));
	memset(s,0,sizeof(s));
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
		f[i][0]=s[i];
	}
	l=r=0;
	for(i=1;i<=n;i++)
		for(j=0;j<=i;j++){f[i][j]=max(f[i][j],f[i-1][j]);
		k=i-j;
		while(l<r && f[i-d[k][r-1]][j-d[k][r-1]]<f[i-j][0])r--;
		while(l<r && d[k][l]<L)l++;
		d[k][r++]=j;
		//for(k=L;k<=j;k++)
		if(l<r)f[i][j]=max(f[i][j],f[i-d[k][l]][j-d[k][l]]);
	}
	printf("%d\n",f[n][m]);
}

int main(){
	while(scanf())
}

