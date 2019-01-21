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

#define N 110
#define M 11000000

const lld inf=9223372036854775807LL;
const int s=10000000;

int prm[M],is[M],m;
lld n,k,res;
lld c[N];
lld a,b,num,sum,tot;

void getprm(const int &n){m=0;
	int i,j,d;
	int e=(int)(sqrt((double)n)+1.0);
	memset(is,0x7f,sizeof(is));
	prm[m++]=2;is[0]=is[1]=0;
	for(i=4;i<=n;i+=2)is[i]=0;
	for(i=3;i<e;i+=2)if(is[i]){
		prm[m++]=i;d=i<<1;
		for(j=i*i;j<=n;j+=d)is[j]=0;
	}
	for(;i<=n;i+=2)if(is[i])prm[m++]=i;
	printf("m=%d\n",m);
}

int main(){
	getprm(s);
	printf("{ ");
	for(int i=0;i<m;i++){
		if(i)printf(",");
		printf("%d",prm[i]);
	}
	printf(" }\n");
	return 0;
}
