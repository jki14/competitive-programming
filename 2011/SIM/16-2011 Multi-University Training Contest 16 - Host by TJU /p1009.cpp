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

#define N 110000

typedef long long lld;

const lld modulo=100000007;


int T;

lld ans,c[N],leflow[N],riglow[N],lefhig[N],righig[N];


int n,a[N],lowbit[N];

void build(){
	for(int i=0;i<N;i++)lowbit[i]=i&(-i);
}

void insert(int x){
	for(;x<=n;x+=lowbit[x])c[x]++;
}

lld querry(int x){
	lld ret=0LL;
	for(;x;x-=lowbit[x])ret+=c[x];
	return ret;
}

void work(){
	memset(c,0,sizeof(c));
	scanf("%d",&n);ans=0LL;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		insert(a[i]);
		leflow[i]=querry(a[i]-1);
		lefhig[i]=i-1-leflow[i];
		riglow[i]=a[i]-1-leflow[i];
		righig[i]=n-i-riglow[i];
	}
	for(int i=1;i<=n;i++){

		//printf("%d: leflow=%lld lefhig=%lld riglow=%lld righig=%lld\n",i,leflow[i],lefhig[i],riglow[i],righig[i]);

		ans = ( ans + ((righig[i]*(righig[i]-1LL))>>1) ) % modulo;	
		ans = ( ans - leflow[i]*righig[i] ) % modulo;
	}
	ans = ( ans % modulo + modulo ) % modulo;
	printf("Case #%d: %lld\n",T,ans);
}

int main(){
	build();
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)
		work();
	return 0;
}

