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

	template<class T> inline T _mmod(T x,T y,T m){ return (T)((((lld)x)*((lld)y)%((lld)m)+((lld)m))%((lld)m)); }
	template<class T> inline T _pmod(T x,T y,T m){
		if(y==0)return 1%m;else if((y&1)==0){ 
			T z=_pmod(x,y>>1,m);return _mmod(z,z,m); 
		}else return _mmod(_pmod(x,y^1,m),x,m);
	}

#define K 2
#define N 1100

const int modulo=2012;
const int _n=300;

int f[N][K],g[N],n,ans;

int main(){
	f[1][0]=1;f[1][1]=1;
	for(int i=2;i<_n;i++){
		f[i][0]=(f[i-1][1]+f[i-1][0])%modulo;
		f[i][1]=f[i-1][0];
	}
	g[0]=1%modulo;
	for(int i=1;i<_n;i++){
		g[i]=_mmod(g[i-1],_pmod(f[i][0]*f[i][0]+f[i][1]*f[i][1],4,modulo),modulo);
	}
	while(scanf("%d",&n)!=EOF){	
		printf("%d\n",g[n>>1]);
	}
	return 0;
}

