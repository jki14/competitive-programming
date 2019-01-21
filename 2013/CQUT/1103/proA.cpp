#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long lld;

#define N 110000

const lld mod=31536000LL;

int n,ans,a[N],b[N],id[N];

int cmp(const int &i,const int &j){ return 
	((lld)a[i])*((lld)b[j])<((lld)a[j])*((lld)b[i]); 
}

int main(){
	while(scanf("%d",&n)!=EOF && n){
		for(int i=0;i<n;i++)scanf("%d%d",&a[i],&b[id[i]=i]);
		sort(id,id+n,cmp);ans=0LL;
		for(int _i=0;_i<n;_i++){int i=id[_i];
			ans=(ans+ans*((lld)b[i])+(lld)a[i])%mod;
		}
		printf("%d\n",(int)((ans%mod+mod)%mod));
	}
	return 0;
}
