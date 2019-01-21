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

const int inf=LONG_MAX;
const lld low=-(1LL<<60);

int n,ans;
lld a[maxn],opt;
int head,tail;

int min(const lld &x,const lld &y){ return (x<y)?x:y; }

void work(){
	int i;
	for(i=1;i<=n;i++){ scanf("%lld",&a[i]); }
	a[0]=0;a[n+1]=low;
	head=tail=0;opt=0LL;
	ans=inf;
	while(1){
		while(a[head]-opt==0LL)head++;
		if(head>n)break;
		if(head>tail){
			tail=head;
			opt=0LL;
		}
		while(a[tail]-opt<=a[tail+1]){
			a[++tail]+=opt;
		}
		opt+=min(a[tail]-opt-a[tail+1],a[head]-opt);
		if(ans>tail-head+1)ans=tail-head+1;
	}
	printf("%d\n",ans);
}

int main(){
	int t;scanf("%d",&t);
	while(t--){scanf("%d",&n);
		work();
	}
	return 0;
}

