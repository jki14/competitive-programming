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

#define maxn 11000

typedef long long lld;

const lld moudel=1000000007;

int T;

int n,m;
lld N,M,ans;
lld p[maxn],inv2;

lld inverse(const lld &a,const lld &b){
	
	//printf("Inverse(%lld,%lld)==",a,b);

	lld k;
	lld x1,x2,x3;
	lld y1,y2,y3;
	lld t1,t2,t3;
	if(a==0LL || b==0LL)return 1LL;
	x1=1LL;x2=0LL;x3=a;
	y1=0LL;y2=1LL;y3=b;
	if(x3<y3)swap(x3,y3);
	for(t3=x3 % y3;t3!=0LL;t3=x3 % y3){
		k=x3 / y3;
		t1=x1-k*y1;
		t2=x2-k*y2;
		x1=y1;x2=y2;x3=y3;
		y1=t1;y2=t2;y3=t3;
	}
	if(y3!=1LL)return 1;

	//printf("%lld\n",( y2 % b + b) % b);

	return ( y2 % b + b ) % b;
}

int stein(int x,int y){

	//if(x<y)swap(x,y);
	//printf("STEIN(%d,%d)==",x,y);

	int k=0;
	while(y>0){
		if((x&y&1)==1)x=(x-y)>>1;
		else if(((x^y)&1)==0){ x>>=1;y>>=1;k++; }
		else if((x&1)==0)x>>=1;else y>>=1;
		if(x<y)swap(x,y);
	}

	//printf("%d\n",x<<k);

	return x<<k;
}

void work(){
	int i;
	scanf("%d%d",&n,&m);
	N=(lld)n;M=(lld)m;
	p[0]=1LL;
	for(i=1;i<=m;i++)p[i]=(p[i-1]*N)%moudel;
	ans=(m&1)?(M*p[(m>>1)+1])%moudel:(M/2LL*(p[(m>>1)]+p[(m>>1)+1]))%moudel;
	for(i=1;i<=m;i++)ans=(ans+p[stein(i,m)])%moudel;
	ans=(ans*inverse(2LL*M,moudel))%moudel;
	printf("Case #%d: %d\n",T,(int)ans);
}

int main(){
	int t;scanf("%d",&t);
	inv2=inverse(2,moudel);
	for(T=1;T<=t;T++)work();
	return 0;
}


