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
#include<set>
#include<map>
using namespace std;

typedef long long lld;
const lld modulo=1000000007;

lld m,n,ans;

void work(){
	/* Track */
	if(n==1LL){
		printf("1\n");
		return;
	}
	/* Init */
	ans=1LL;
	lld tmp=2LL;
	/* FirCore */
	for(;n;n>>=1){
		if(n&1){
			ans = ans * tmp % modulo;
		}
		tmp = tmp * tmp % modulo;
	}
	/* SecCore */
	tmp = ans - 1LL; ans = 1LL;
	for(;m;m>>=1){
		if(m&1){
			ans = ans * tmp % modulo;
		}
		tmp = tmp * tmp % modulo;
	}
	/* Output */
	ans = ( ans % modulo +modulo ) % modulo;
	printf("%lld\n",ans);
}

int main(){
	while(scanf("%lld%lld",&m,&n)!=EOF)
		work();
	return 0;
}

