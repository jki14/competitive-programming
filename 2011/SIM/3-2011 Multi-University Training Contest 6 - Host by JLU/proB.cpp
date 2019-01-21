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

const int mould=112233;

typedef long long lld;

int n,ans;
lld m,k,path,res;

void work(){m=(lld)(n+1);
	int i;k=1LL;res=0LL;
	for(i=0;i<n;i++){
		scanf("%lld",&path);
		k=(k*m)%mould;
		res=(res+k*i)%mould;
	}
	ans=(int)(res%mould);
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

