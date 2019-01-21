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

#define K 1100000

typedef long long lld;

set<lld> s;

int m,k;
lld n,a[K];

lld p(const int &x){
	lld val,sta,p;
	p=(lld)x;val=0LL;sta=1LL;
	for(int i=0;i<=k;i++){
		val=(val+sta*a[i]%n)%n;
		sta=sta*p%n;
	}
	//printf("val=%lld\n",val);
	if(val<0LL)while(1);	
	return val%n;
}

void work(){
	n=n+1LL;s.clear();
	scanf("%d",&k);
	for(int i=0;i<=k;i++)scanf("%lld",&a[i]);
	for(int i=0;i<=m;i++)s.insert(p(i));
	int ans=s.size();
	printf("%d\n",ans);
}

int main(){
	while(scanf("%lld%d",&n,&m)!=EOF && (n!=0LL || m))
		work();
	return 0;
}

