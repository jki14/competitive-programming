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

typedef long long lld;

lld n,m;

lld gcd(lld x,lld y){
	while(y){
		lld k=x%y;
		x=y;y=k;
	}
	return x;
}

void work(){
	lld a,b;
	b=gcd(n,m);
	a=n*m/b/b;
	printf("%lld\n",a);
}

int main(){
	while(scanf("%lld%lld",&n,&m)!=EOF && !(n==0LL && m==0LL))
		work();
	return 0;
}

