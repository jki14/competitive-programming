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

lld a,b,k,ans;

void work(){
	if(a<b)swap(a,b);	
	if(a>1LL){
		lld i,j=1LL;ans=0LL;
		for(i=a;i<=k;i*=a){
			ans+=k/i*j;
			j=-j;
		}
	}else ans=k;
	printf("%I64d\n",ans);
}

int main(){
	while(scanf("%I64d%I64d%I64d",&a,&b,&k)!=EOF)work();
	return 0;
}

