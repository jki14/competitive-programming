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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

typedef long long lld;

const lld mod=1e9+7LL;

#define N 110
#define K 11000
#define S 2

#define m1 ((m%n)>=i?1:0)

lld n,m,k;
lld c[N][N];
lld p[N][S];
lld f[N][K],ans;

lld pow(lld x,lld y){
	lld ret = 1LL, now = x % mod;
	for(;y;y>>=1){
		if(y&1)ret = ret * now % mod;
		now = now * now % mod;
	}
	return ret % mod;
}

int main(){
	while(cin>>n>>m>>k){
		/* INIT */
		for(int i=0;i<=n;i++)c[i][i]=c[i][0]=1LL;
		for(int i=2;i<=n;i++)
			for(int j=1;j<i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		for(int i=0;i<=n;i++){
			p[i][0]=pow(c[n][i],m/n);
			p[i][1]=p[i][0]*c[n][i]%mod;
		}
		/* CORE */
		memset(f,0,sizeof(f));
		for(int i=1,j=0;j<=n;j++) f[1][j]=p[j][m1];
		for(int i=2;i<=n;i++){
			for(int j=0;j<=k;j++){
				for(int r=0;r<=n && r<=j;r++){
					f[i][j]=(f[i][j]+f[i-1][j-r]*p[r][m1])%mod;	
				}
			}
		}
		ans=f[n][k];ans=(ans%mod+mod)%mod;
		cout<<ans<<endl;
	}
	return 0;
}
