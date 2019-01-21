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

#define N 1100
#define K 2

int n,ans;
int x[N],y[N];
int a[K],b[K],s[K];
int f[N][N];

inline int max(const int &x,const int &y){ return x>y?x:y; }

int main(){
	while(scanf("%d",&n)!=EOF){ans=0;
		for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
		for(int i=0;i<K;i++)scanf("%d%d%d",&s[i],&a[i],&b[i]);
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++){
			for(int k=0;k<=i;k++){
				if(k>s[0] || (i-k)>s[1])continue;
				if(k!=0)f[i][k]=max(f[i][k],f[i-1][k-1]+x[i]*a[0]+y[i]*b[0]);
				if(k!=i)f[i][k]=max(f[i][k],f[i-1][k  ]+x[i]*a[1]+y[i]*b[1]);
				if(i==n)ans=max(ans,f[i][k]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
