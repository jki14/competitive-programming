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

lld f(lld x,lld y,lld z){
	if(x<y){
		//printf("Final Call %lld %lld %lld\n",x,y,z);
		return (x==0);
	}
	return f(x-y,y+z,y)+f(x,y+z,y);
}

int main(){
	int t;scanf("%d",&t);
	while(t--){
		lld n;scanf("%I64d",&n);
		printf("%I64d\n",f(n,1LL,1LL));
	}
	return 0;
}

