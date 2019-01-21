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

#define S 1600
#define N 1510

int T,n;
double f[S],d,ii;

void init(){
	memset(f,0,sizeof(f));
	f[1]=1.0;d=0.5;
	for(int i=2;i<=N;i+=2){ii=(double)i;
		f[i]=f[i-1]+d;
		f[i+1]=f[i]+d;
		d*=(ii+1.0)/(ii+2.0);
	}
}

void work(){
	scanf("%d",&n);
	printf("Case %d: %.6f\n",T,f[n]);
}

int main(){init();
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

