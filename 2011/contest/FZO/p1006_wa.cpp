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

#define N 2100
#define K 2

#define nex now^1

const int n=10;

double f[K][N][N],ans[N];

int main(){

	int now=0;

	memset(f,0,sizeof(f));f[now][1][1]=1.0;
	memset(ans,0,sizeof(ans));

	for (int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++){
			for(int k=1;k<=i;k++){
				ans[i]+=f[now][j][k];
				f[nex][j+1][max(k,j+1)]+=f[now][j][k]/2.0;
				f[nex][max(1,j-1)][k  ]+=f[now][j][k]/2.0;
			}
		}
		now=nex;
		memset(f[nex],0,sizeof(f[nex]));
	}

	for(int i=1;i<=n;i++)
		printf("	case %d: %.6f;\n",i,ans[i]);

	return 0;
}
