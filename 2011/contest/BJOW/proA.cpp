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

#define P 1000000
#define S 1100000
#define K 110

typedef long long lld;

const lld module=100000007LL;

int x,y;
lld prm[S];
int is[S],num;

void getprm(const int &n){num=0;
	int i,j,d;
	int e=(int)(sqrt((double)n)+1.0);
	memset(is,0x7f,sizeof(is));
	prm[num++]=2LL;is[0]=is[1]=0;
	for(i=4;i<=n;i+=2)is[i]=0;
	for(i=3;i<e;i+=2)if(is[i]){
		prm[num++]=(lld)i;d=i<<1;
		for(j=i*i;j<=n;j+=d)is[j]=0;
	}
	for(;i<=n;i+=2)if(is[i])prm[num++]=(lld)i;
}

void work(){
	scanf("%d%d",&x,&y);
	lld ret=1LL % module,q,p;
	p=prm[x];q=p;
	for(;y;y>>=1){
		if(y&1)ret=ret * q % module;
		q=q * q % module;
	}
	
	//printf("p[x]=%lld\n",p);

	printf("%lld\n",ret);
}

int main(){
	int t;scanf("%d",&t);
	getprm(P);
	while(t--)work();
	return 0;
}

