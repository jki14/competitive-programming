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

#define N 1100000

typedef long long lld;

inline lld getabs(const lld &x){ return (x<0LL)?-x:x; }

lld a[N],ans;

int main(){
	int n;while(scanf("%d",&n)!=EOF && n){ans=0LL;
		for(int i=0;i<n;i++)scanf("%lld",&a[i]);
		for(int i=0;i<n;i++){
			ans+=getabs(a[i]);
			a[i+1]+=a[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
