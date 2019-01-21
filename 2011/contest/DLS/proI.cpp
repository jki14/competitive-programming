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

typedef long long lld;

const lld modulo=1000000007;

lld stein(lld x,lld y){
	lld k=0LL;
	//if(x<y)swap(x,y);
	while(y>0LL){
		if((x&y&1)==1)x=(x-y)>>1;
		else if(((x^y)&1)==0){ x>>=1;y>>=1;k++; }
		else if((x&1)==0)x>>=1; else y>>=1;
		if(x<y)swap(x,y);
	}
	return x<<k;
}

lld pow4(const lld &x){
	lld ret=x;
	ret = ret * ret % modulo;
	ret = ret * ret % modulo;
	return ret;
}

void work(){
	lld n,ans=0LL;
	scanf("%lld",&n);
	for(lld i=1;i<n;i++){
		//printf("stein(%lld,%lld)=%lld\n",i,n,stein(i,n));
		if(stein(n,i)==1LL)ans=(ans + pow4(i)) % modulo;
	}
	printf("%lld\n",ans);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

