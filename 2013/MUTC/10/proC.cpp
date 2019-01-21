#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

typedef long long lld;

int n;
lld X,Y;
lld amx,amy,ans;

const lld mod=1000000007LL;

lld calc(const lld &x){ return x>0LL?x*(x-1LL)/2LL+x:0LL; }

lld core(const lld &x,const lld &y){
	lld otx=(calc(x-1LL)%mod+calc(X-x)%mod)%mod;
	lld oty=(calc(y-1LL)%mod+calc(Y-y)%mod)%mod;
	lld inx=(amx-otx)%mod,iny=(amy-oty)%mod;
	return ((inx*oty)%mod+(otx*iny)%mod)%mod;
}

int main(){
	ios::sync_with_stdio(false);
	while(cin>>X>>Y>>n){ans=0LL;
		amx=calc(X)%mod;
		amy=calc(Y)%mod;
		for(int i=0;i<n;i++){
			lld x,y;cin>>x>>y;
			ans=(ans+core(x,y))%mod;
		}
		cout<<(ans%mod+mod)%mod<<endl;
	}
	return 0;
}
