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

#define N 11000
#define S 1100

const int maxn=10000;

int n,ans[N];
int f[S][S],top;

void build(){
	memset(ans,0,sizeof(ans));int k=2;
	ans[1]=2;top=1;f[1][1]=f[2][1]=1;
	while(top<=maxn){
		int j=ans[top];
		for(int i=1;i<=j;i++)f[j+1][i]=f[i][j]=++top;
		for(;k<top;k++)ans[k]=j;ans[k++]=j+1;
	}
	//printf("top=%d\n",top);
}

void work(){
	printf("%d\n",ans[n]);
	for(int i=1;i<=ans[n];i++){
		printf("%d",f[i][1]);
		for(int j=2;j<ans[n];j++)printf(" %d",f[i][j]);
		printf("\n");
	}
}

int main(){
	build();
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

