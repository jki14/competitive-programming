#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef long long lld;

const int _mod=1000000007;
const lld  mod=1000000007LL;

int n,k;

lld pow2(const int &y){
	lld ret=1LL,x=2LL;
	for(int i=1;i<=y;i<<=1){
		if(y&i)ret=ret*x%mod;
		x=x*x%mod;
		if(i>(y>>1))break;
	}
	return (ret%mod+mod)%mod;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		int ans=0;
		if(n>=k){
			if(n>1 && n!=k){
				int x=n-k+3;
				int y=n-k-2;
				int z=(int)pow2(abs(y));
				//printf("x=%d y=%d z=%d\n",x,y,z);
				if(y<0)
					ans=x/z;
				else ans=(int)(((lld)x*(lld)z)%mod);
			}else ans=1;
		}
		printf("%d\n",(ans%_mod+_mod)%_mod);
	}
}
