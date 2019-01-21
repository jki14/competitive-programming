//============================================================================
// Name        : GaussianXor
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 高斯消元解异或方程组,POJ1681(十字关灯问题，求最小关灯次数；此题数据较
//弱，正常情况需要枚举自由变元)
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

#define N 20
#define M 500

#define T 499
#define K 5

const int dx[K]={ 0,-1,0,1,0 };
const int dy[K]={ 0,0,1,0,-1 };

int n,m,ret;
int c[N][N];
int a[M][M];
int res[M];

char str[N];

int gaus(){
	int i,j,p,k,ret;

	for(i=j=0;i<m && j<m;){
		p=i;
		for(k=p+1;k<m;k++)
			if(a[p][j]<a[k][j])p=k;
		if(a[p][j]){
			swap(a[i][T],a[p][T]);
			for(k=j;k<m;k++)swap(a[i][k],a[p][k]);

			for(p=i+1;p<m;p++){
				if(!a[p][j])continue;
				a[p][T]^=a[i][T];
				for(k=j;k<m;k++)
					a[p][k]^=a[i][k];
			}
			i++;
		}
		j++;
	}


	for(k=i;k<m;k++)if(a[k][T])return -1;
	ret=a[m-1][T];
	for(i=m-2;i>=0;i--){
		for(j=i+1;j<m;j++)
			a[i][T]^=(a[i][j] && a[j][T]);
		ret+=a[i][T];
	}
	return ret;
}

void work(){
	int i,j,k;

	scanf("%d",&n);m=n*n;
	memset(c,0,sizeof(c));
	memset(a,0,sizeof(a));
	for(i=0;i<n;i++){
		scanf("%s",str);
		for(j=0;j<n;j++)
			if(str[j]=='w')c[i][j]=1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a[i*n+j][T]=c[i][j];
			for(k=0;k<K;k++){
				if(i+dx[k]<0 || i+dx[k]>=n)continue;
				if(j+dy[k]<0 || j+dy[k]>=n)continue;
				a[i*n+j][(i+dx[k])*n+(j+dy[k])]=1;
			}
		}
	}

	ret=gaus();
	if(ret<0)
		printf("inf\n");
	else printf("%d\n",ret);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}
