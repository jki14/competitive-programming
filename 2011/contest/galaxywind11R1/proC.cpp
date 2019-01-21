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

#define N 110000

typedef long long lld;

int T,top,bot,n,m;
lld key,a[N];

void work(){
	scanf("%d%d",&n,&m);key=(1LL<<m)-1LL;
	top=bot=0;//printf("key=%lld\n",key);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		a[i]=max(a[i],a[i]^key);
	}
	for(int i=0;i<n;i++){
		//printf("a[%d]=%lld\n",i,a[i]);
		if(a[i]>a[top])top=i;
		if(a[i]<a[bot])bot=i;
	}
	lld ans=a[top]-a[bot];
	printf("Case #%d: %lld\n",T,ans);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

