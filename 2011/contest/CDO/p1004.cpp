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

#define N 110

int T;

int n,ret;
int c[N][N];
int mk[N][N];

void work(){
	int i,j,k;

	scanf("%d",&n);ret=n*(n-1);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&c[i][j]);

	memset(mk,0,sizeof(mk));
	for(k=0;k<n && ret>=0;k++){
		for(i=0;i<n && ret>=0;i++){
			if(i==k)continue;
			for(j=0;j<n && ret>=0;j++){
				if(j==i || j==k)continue;
				if(c[i][j]>c[i][k]+c[k][j]){
					ret=-1;
					break;
				}
				if(mk[i][j]==0 && c[i][j]==c[i][k]+c[k][j]){
					ret--;
					mk[i][j]=1;
				}
			}
		}
	}

	if(ret<0)
		printf("Case %d: impossible\n",T);
	else
		printf("Case %d: %d\n",T,ret);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	printf("\n");
	return 0;
}

