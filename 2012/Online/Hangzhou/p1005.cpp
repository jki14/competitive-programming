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

#define N 55

int n,a[N][N];
char c[N][N];

int cross(const int &x,const int &y){
	
}

int main(){
	while(scanf("%d",&n)!=EOF && n){
		for(int i=0;i<n;i++)scanf("%s",c[i]);
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i+1][j+1]=(c[i][j]=='#')?1:0;

		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(a[i][j] && cross(i,j))ans++;
		printf("%d\n",ans);
	}
	return 0;
}
