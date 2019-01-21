#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define N 110000
#define K 15

typedef long long lld;
const lld mod=1e9+7;

int n;
char b[N],*a;
lld c[K],ans;

inline void ttm(lld &x){ lld k=x;for(int i=1;i<10;i++)x=x*k%mod; }
inline void mmd(lld &x, const lld &y){ x=x*y%mod; }

int main(){
	c[0]=1LL;for(int i=1;i<K;i++)c[i]=c[i-1]*2LL%mod;
	while(scanf("%s",b)!=EOF){
		int n=strlen(b);
		for(int i=n-1;i>=0;i--){
			if(b[i]>'0'){
				b[i]--;
				break;
			}b[i]='9';
		}
		for(a=b;(*a)=='0' && a!=b+n;)a++;
		ans=1LL;
		for(;a!=b+n;a++){
			ttm(ans);
			mmd(ans,c[(*a)-'0']);
		}
		printf("%d\n",(int)((ans%mod+mod)%mod));
	}
	return 0;
}
