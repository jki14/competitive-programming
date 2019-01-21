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

#define K 30

typedef long long lld;

const lld I30=233333335;
const lld modulo=1000000007;

int T;

lld n,ans;
lld fac[K];
int k;

lld fsum(const lld &x){
	lld res = x % modulo;
	res = res * ( x + 1 ) % modulo;
	res = res * ( x * 2 + 1 ) % modulo;
	res = res * ( 3 * x * x % modulo + 3 * x -1 ) % modulo;
	res = res * I30 % modulo;

	//printf("fsum(%lld)=%lld\n",x,res);

	return res;
}

lld f(const lld &x){
	lld res = x % modulo;
	res = res * res % modulo;
	res = res * res % modulo;
	return res;
}

void work(){
	scanf("%lld",&n);
	ans=fsum(n);k=0;

	//printf("ans=%lld\n",ans);

	lld val=n;
	for(lld i=2LL;i*i<=val;i++){
		if(!(val%i)){
			fac[k]=i;
			while(!(val%fac[k]))val/=fac[k];
			k++;
		}
	}
	if(val>1LL)fac[k++]=val;
	int tail=1<<k;
	for(int sta=1;sta<tail;sta++){
		int num=0;
		lld val=1LL;
		for(int i=0;i<k;i++){
			if(sta&(1<<i)){
				val*=fac[i];
				num++;
			}
		}
		
		//printf("val=%lld num=%d sta=%d\n",val,num,sta);

		if(num&1)
			ans=(ans-f(val)*fsum(n/val)) % modulo;
		else
			ans=(ans+f(val)*fsum(n/val)) % modulo;
	}
	ans = ( ans % modulo + modulo ) % modulo;
	printf("%lld\n",ans);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

