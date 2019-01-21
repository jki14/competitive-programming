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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

typedef long long lld;
const lld inf= 1e9+7LL;

lld n;

lld f(lld x){
	int ret=0LL;for(;x;x/=10LL)ret+=x%10LL;
	return ret;
}

lld core(){
	lld ret=inf;
	for(lld s=1LL;s<100LL;s+=1LL){
		lld x=(lld)(sqrt(s*s*1.0/4.0+n*1.0)-s*1.0/2.0);
		if(x*x+x*s!=n)continue;
		if(f(x)!=s)continue;
		ret=min(ret,x);
	}
	if(ret==inf)ret=-1LL;
	return ret;
}

int main(){
	while(scanf("%I64d",&n)!=EOF){
		printf("%I64d\n",core());
	}
	return 0;	
}
