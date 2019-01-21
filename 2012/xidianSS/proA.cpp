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

#define N 1100000
#define K 4

const int n = 1000000;
const int modulo = 1000000007;

int f[N][K];

int main(){
	int T;scanf("%d",&T);
	memset(f,0,sizeof(f));f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int k=0;k<K;k++){
			for(int j=0;j<K;j++){
				if(j==k)continue;
				f[i][k]=(f[i][k]+f[i-1][j])%modulo;
			}
		}
	}
	while(T--){
		int a;scanf("%d",&a);
		printf("%d\n",f[a][0]);
	}
	return 0;
}
