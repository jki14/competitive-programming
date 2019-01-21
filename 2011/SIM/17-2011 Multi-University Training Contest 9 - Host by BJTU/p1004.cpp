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

#define N 11000

typedef long long lld;

const lld modulo = 1000000007;

int T;
lld n,m,p[N];

lld gcd(const lld &x,const lld &y){ return y?gcd(y,x%y):x; }

lld inv(lld a,lld b){
	lld r=a%b,x0=1LL,y0=0LL,x1=0LL,y1=1LL;
	while(r){
		lld k=a/b;
		lld dx=x0-k*x1;
		lld dy=y0-k*y1;
		x0=x1;y0=y1;x1=dx;y1=dy;
		a=b;b=r;r=a%b;
	}
	if(!x1)x1=1LL;
	return x1;
}

lld polya(const lld &clr,const lld &len){
	if(!len)return 1LL;

	p[0]=1LL;
	for(lld i=1LL;i<=len;i++)p[i]=p[i-1]*clr%modulo;

	lld turn = len&1 ? len * p[(len>>1)+1] : (len>>1)*(p[(len>>1)]+p[(len>>1)+1]);
	turn%=modulo;

	lld rota=0LL;
	for(lld i=1LL;i<=len;i++){
		rota+=p[gcd(i,len)];
		rota%=modulo;
	}
	
	lld ret = (rota+turn)*inv(len<<1,modulo);

	ret = (ret%modulo+modulo)%modulo;

	return ret;
}

void work(){
	scanf("%I64d%I64d",&n,&m);
	printf("Case #%d: %I64d\n",T,polya(n,m));
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

