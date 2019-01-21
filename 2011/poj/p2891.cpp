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

#define N 11000000

typedef long long lld;

int n;
lld a[N],r[N];

lld exgcd(lld a,lld b,lld &x,lld &y){
	if(!b){
		x=1LL;y=0LL;
		return a;
	}
	lld d=exgcd(b,a%b,x,y);
	lld t=x;x=y;y=t-(a/b)*y;
	return d;
}

void work(){
	for(int i=0;i<n;i++)scanf("%lld%lld",&a[i],&r[i]);
	if(a[0]<=r[0]){
		printf("-1\n");
		return;
	}
	for(int i=1;i<n;i++){
		if(a[i]<=r[i]){
			printf("-1\n");
			return;
		}
		lld x,y,d,t;
		d=exgcd(a[i-1],a[i],x,y);
		if((r[i]-r[i-1])%d){
			printf("-1\n");
			return;
		}
		t=a[i]/d;
		x=((r[i]-r[i-1])/d*x%t+t)%t;
		r[i]=x*a[i-1]+r[i-1];
		a[i]=a[i]*a[i-1]/d;
		r[i]=(r[i]%a[i]+a[i])%a[i];
	}

	printf("%lld\n",r[n-1]);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

