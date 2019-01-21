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
#define K 2

#define pre (now^1)

typedef long long lld;

int n,aMax,ans0,ans1;
int a[N],g[K][N],bit[N];

inline int max(const int &x,const int &y){ return x>y?x:y; }

int cmp(const int &x,const int &y){ return x>y; }

int main(){
	ans0=ans1=aMax=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){ scanf("%d",&a[i]);aMax=max(aMax,a[i]); }
	if(aMax<N){ int tmp=aMax;for(aMax=1;tmp>=aMax;)aMax<<=1; }

	if(n<=20){
		int nSta=1<<n;
		for(int i=0;i<n;i++)bit[i]=1<<i;
		for(int sta=0;sta<nSta;sta++){
			int ret=0;for(int i=0;i<n;i++){
				if(sta&bit[i])ret^=a[i];
			}
			if(ret>ans0){
				ans1=ans0;ans0=ret;
			}else if(ret>ans1) ans1=ret;
		}
	}else	if(aMax<N && (((lld)aMax)*((lld)n))<30000000LL){
		memset(g,0,sizeof(g));int now=0;g[now][0]=1;
		for(int i=0;i<n;i++){now=pre;
			for(int j=0;j<=aMax;j++){
				if(!g[pre][j])continue;
				int newval=j^a[i];
				if(newval>ans0){
					ans1=ans0;ans0=newval;
				}else if(newval>ans1) ans1=newval;
				g[now][j]=1;g[now][newval]=1;
			}
		}
	}else{
		int ret=0;for(int i=0;i<n;i++)ret^=a[i];
		sort(a,a+n,cmp);ans0=ret;
		for(int i=0;i<n;i++){
			if((ret^a[i])>ret){
				ret^=a[i];
				if(ret>ans0){
					ans1=ans0;ans0=ret;
				}else if(ret>ans1) ans1=ret;
			}
		}
	}

	printf("%d %d\n",ans0,ans1);
}
