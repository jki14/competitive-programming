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

#define maxn 110000

typedef long long lld;

int n,T;
lld x,y,ans;
lld a[maxn];

void work(){
	int i;
	scanf("%d%lld%lld",&n,&x,&y);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);a[0]=a[1]-1LL;ans=0LL;
	for(i=1;i<=n;i++){
		//printf("a[%d]=%lld a[%d]=%lld  ",i,a[i],i-1,a[i-1]);
		ans+=min((a[i]-a[i-1])*y,x*2LL+y);
		//printf("ans=%lld\n",ans);
	}
	ans+=x*2LL;
	printf("Case #%d: %I64d\n",T,ans);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

