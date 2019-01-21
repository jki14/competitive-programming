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

const lld inf=1LL<<60;

lld k,t;

lld pow(int x){
	lld ret=1LL,tmp=k;
	for(;x;x>>=1){
		if(x&1)ret*=tmp;
		tmp*=tmp;
	}
	return ret;
}

int find(){
	int l=1,r=log((double)inf)/log((double)k);
	while(l<=r){
		int mid=(l+r)>>1;
		lld key=pow(mid);
		if(key==t)return mid;
		if(key>t)
			r=mid-1;
		else
			l=mid+1;
	}
	return -1;
}

void work(){
	int res=find()-1;
	if(res>=0)
		printf("YES\n%d\n",res);
	else
		printf("NO\n");
}

int main(){
	while(scanf("%lld%lld",&k,&t)!=EOF)
		work();
	return 0;
}

