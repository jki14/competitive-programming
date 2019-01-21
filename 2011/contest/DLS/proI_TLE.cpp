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

#define S 30

typedef long long lld;

const lld modulo=1000000007;
const lld I30=233333335;

lld n,ans;
lld fac[S];
int num;

set<lld> s;
set<lld>::iterator it;

lld pow4(const lld &x){
	lld ret = x % modulo;
	ret = ret * ret % modulo;
	ret = ret * ret % modulo;
	return ret;
}

void work(){
	scanf("%lld",&n);s.clear();

	ans = n % modulo;
	ans = ans * ( n + 1 ) % modulo;
	ans = ans * ( n * 2 + 1 ) % modulo;
	ans = ans * ( 3 * n * n % modulo + 3 * n - 1 ) % modulo;
	ans = ans * I30 % modulo;

	num=0;
	lld val=n;
	for(lld k=2LL;k*k <=val;k++){
		if(!(val%k)){
			fac[num++]=k;
			while(!(val%k))val/=k;
		}
	}
	if(val>1LL)fac[num++]=val;

	for(int i=0;i<num;i++){lld k=fac[i];
		for(lld x=k;x<=n;x+=k){
			it=s.find(x);
			if(it!=s.end())continue;
			s.insert(x);
			ans=( ans - pow4(x) ) % modulo;
		}
	}
	ans=(ans % modulo + modulo) % modulo;
	printf("%lld\n",ans);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

