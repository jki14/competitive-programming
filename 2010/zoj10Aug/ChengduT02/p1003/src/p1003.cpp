#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define lld long long
#define maxv 1100

int n;
int g[maxv][maxv],dp[maxv],stk[maxv][maxv],mx;
lld s[maxv];

lld min(lld x,lld y){ return (x<y)?x:y; }

lld labs(lld x){ return (x<0LL)?0LL-x:x; }

lld kgcd(lld a, lld b){
	if(a==0LL)return b;
	if(b==0LL)return a;
	if(!(a&1) && !(b&1))
		return kgcd(a>>1,b>>1)<<1;
	else if(!(b&1))
		return kgcd(a,b>>1);
	else if(!(a&1))
		return kgcd(a>>1,b);
	else return kgcd(labs(a-b),min(a,b));
}

int dfs(int n,int ns,int dep){
	if(0==ns){
		if(dep>mx)mx=dep;
		return 1;
	}
	int i,j,k,p,cnt;
	for(i=0;i<ns;i++){
		k=stk[dep][i];cnt=0;
		if(dep+n-k<=mx)return 0;
		if(dep+dp[k]<=mx)return 0;
		for(j=i+1;j<ns;j++){
			p=stk[dep][j];
			if(g[k][p])stk[dep+1][cnt++]=p;
		}
		dfs(n,cnt,dep+1);
	}
	return 1;
}

int clique(int n){
	int i,j,ns;
	for(mx=0,i=n-1;i>=0;i--){
		for(ns=0,j=i+1;j<n;j++)
			if(g[i][j])stk[1][ns++]=j;
		dfs(n,ns,1);dp[i]=mx;
	}
	return mx;
}

void work(){
	memset(g,0,sizeof(g));
	int i,j;
	for(i=0;i<n;i++)
		scanf("%I64d",&s[i]);
	sort(s,s+n);
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(s[j]%s[i]!=0LL)g[i][j]=g[j][i]=1;
	printf("%d\n",clique(n));
}

int main(){
	int t;scanf("%d",&t);
	while(t--){ scanf("%d",&n);work(); }
	return 0;
}
