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

#define maxn 110000

typedef long long lld;

const int N = 100001;

lld ANS[maxn];
int n;

void init(){
	ANS[0]=0LL;
	for(int i=1;i<N;i++){
		ANS[i]=ANS[i-1]+((lld)(i>>1));
	}
}

void work(){
	printf("%lld\n",ANS[n]);	
}

int main(){init();
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}


