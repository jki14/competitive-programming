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

#define maxn 11000

typedef long long lld;

const int inf=0x3fffffff;
const lld low=-(1LL<<60);

typedef long long lld;

int n,ans;
lld a[maxn],det;
int head,tail;

lld min(const lld &x,const lld &y){ return (x<y)?x:y; }

void work(){
	int i;
	for(i=1;i<=n;i++)scanf("%I64d",&a[i]);
	a[0]=0LL;a[n+1]=low;
	head=tail=0;det=0LL;ans=inf;
	while(1){
		while(a[head]-det==0LL)head++;
		if(head>n)break;
		if(tail<head){ tail=head;det=0; }
		while(a[tail]-det<=a[tail+1]){ a[++tail]+=det;while(tail>n){} }
		det+=min(a[tail]-det-a[tail+1],a[head]-det);
		ans=min(ans,tail-head+1);
	}
	printf("%d\n",ans);
}

int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		work();
	}
	return 0;
}

