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

#define maxn 510
#define N 500
#define maxnum 1100000
#define NUM 5000

int n;
int mk[maxnum],pri[maxnum],pnum;
int a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int r[maxn],s[maxn],t[maxn];

void init(){
	int i,j,k;pnum=0;memset(mk,0,sizeof(mk));
	for(i=2,k=4;i<=NUM;i++,k+=i+i-1)if(!mk[i]){
		pri[pnum++]=i;
		if(k<=NUM)for(j=i+i;j<=NUM;j+=i)mk[j]=1;
	}
	//printf("Init pnum=%d\n",pnum);
}

void read(int T[maxn][maxn]){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&T[i][j]);
		}
	}
}

void mul(int T[maxn][maxn]){
	int i,j;
	for(i=0;i<n;i++){
		for(r[i]=j=0;j<n;j++){
			r[i]+=s[j]*T[j][i];
		}
	}
	for(i=0;i<n;i++)s[i]=r[i];
}

void work(){
	int i,j;	
	read(a);read(b);read(c);
	
	for(i=0;i<n;i++)s[i]=pri[i];
	mul(a);mul(b);

	for(i=0;i<n;i++){
		for(t[i]=j=0;j<n;j++){
			t[i]+=pri[j]*c[j][i];
		}
	}
	for(i=0;i<n;i++){
		if(s[i]!=t[i]){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main(){
	init();
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

