//============================================================================
// Name        : Polya
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : POJ1286(旋转+翻转)
//============================================================================

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

#define N 110

typedef long long lld;

int n,m=3;
lld p[N];

int gcd(int x,int y){ return y? gcd(y,x%y):x; }

lld polya(int clr,int len){

	if(!len)return 0;

	int i;p[0]=1LL;
	for(i=1;i<=len;i++)p[i]=p[i-1]*clr;

	lld turn = len&1 ? len * p[(len>>1) + 1] : (len>>1)*(p[(len>>1)]+p[(len>>1)+1]);

	lld rota = 0LL;
	for(i=1;i<=len;i++){
		rota+=p[gcd(i,len)];
	}

	//printf("%lld %lld\n",rota,turn);
	lld ret =(rota+turn)/(len<<1);

	return ret;
}

void work(){
	printf("%lld\n",polya(m,n));
}

int main(){
	while(scanf("%d",&n) && n!=-1LL)
		work();
	return 0;
}
