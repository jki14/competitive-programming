#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<ctime>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define maxn 1100
#define maxm 2100

int a[maxn];
int r[maxn];
int c[maxm][maxn];
int n,P,s,x;
int res,lmt;

int ipow(const int &x,const int &y){
	return c[x-s][y];
}

int check(){
	int i,j,k;
	for(i=s;i<s+n;i++){k=0;
		for(j=0;j<n;j++){ k+=a[j]*ipow(i,j);k%=P; }
		if(r[i-s]!=k)return 0;
	}
	return 1;
}

int dfs(const int &k){
	if(k==n){
		if(check()){
			int i,j,k;
			//for(i=0;i<n;i++)printf("%d ",a[i]);
			//printf("\n");
			for(i=s+n;i<s+n+x;i++){k=0;
				for(j=0;j<n;j++){ k+=a[j]*ipow(i,j);k%=P; }
				if(i!=s+n)printf(" ");
				printf("%d",k%P);
			}
			return 1;
		}
		return 0;
	}
	for(a[k]=0;a[k]<lmt;a[k]++)
		if(dfs(k+1))return 1;
	return 0;
}

void work(){int i,j;
	scanf("%d%d%d",&P,&s,&x);
	for(i=s;i<s+n+x;i++){c[i-s][0]=1;
		for(j=1;j<n;j++){ c[i-s][j]=c[i-s][j-1]*i;c[i-s][j]%=P; }
	}
	for(i=0;i<n;i++)scanf("%d",&r[i]);
	lmt = 10;
	dfs(0);
	printf("\n");
}

int main(){
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

