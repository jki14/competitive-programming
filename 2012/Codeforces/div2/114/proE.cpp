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

lld a,b;
lld ret;

int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%I64d%I64d",&a,&b);if(a>b)swap(a,b);ret=0LL;
		while(a!=0LL && b!=0LL){
			ret=ret^(b/a);
			b=b % a;swap(a,b);
		}
		if(ret>0LL)
			printf("First\n");
		else
			printf("Second\n");
	}
	return 0;
}
