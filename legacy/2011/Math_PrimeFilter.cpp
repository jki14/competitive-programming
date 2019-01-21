//============================================================================
// Name        : PrimeFilter
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : POJ2689(求[L,R]区间相邻素数中差值最小配对和最大配对
//，0<=L,R<=2147483647,R-L<=1000000)
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

#define M 46341
#define S 1100000

const int inf=LONG_MAX;

int l,r;
int f[S],g[S],k;
int prm[S],is[S],num;
int ret1,ret2,ans1,ans2;

void getprm(const int &n){num=0;
	int i,j,d;
	int e=(int)(sqrt((double)n)+1.0);
	memset(is,0x7f,sizeof(is));
	prm[num++]=2;is[0]=is[1]=0;
	for(i=4;i<=n;i+=2)is[i]=0;
	for(i=3;i<e;i+=2)if(is[i]){
		prm[num++]=i;d=i<<1;
		for(j=i*i;j<=n;j+=d)is[j]=0;
	}
	for(;i<=n;i+=2)if(is[i])prm[num++]=i;
}

void prmfilter(int l,const int &r){

	if(l<2)l=2;
	if(r<2)return;

	k=0;

	int i,j,d;
	int e=(int)(sqrt((double)r)+1.0);
	memset(f,0x7f,sizeof(f));

	i=l;if(i<inf && (i&1))i++;if(i==2)i+=2;
	while(i<=r){
		f[i-l]=0;
		if(i>r-2)break;/* for RE; */
		i+=2;
	}

	for(i=3;i<e;i+=2)if(is[i]){
		d=i<<1;j=i*i;
		if(j<l){
			j=(l-j)/d;
			j=j*d+i*i;
			if(j<l){
				if(j>inf-d)continue;/* for RE; */
				j+=d;
			}
		}
		while(j<=r){
			f[j-l]=0;
			if(j>r-d)break;/* for RE */
			j+=d;
		}
	}

	for(i=l;i<=r;){
		if(f[i-l])g[k++]=i;
		if(i>r-1)break;
		i++;
	}
}

void work(){
	prmfilter(l,r);
	if(k<2){
		printf("There are no adjacent primes.\n");
		return;
	}
	ans1=inf;ans2=0;
	ret1=0;ret2=inf;
	for(int i=1;i<k;i++){
		if(g[i]-g[i-1]<ret2-ret1){
			ret2=g[i];
			ret1=g[i-1];
		}
		if(g[i]-g[i-1]>ans2-ans1){
			ans2=g[i];
			ans1=g[i-1];
		}
	}
	printf("%d,%d are closest, %d,%d are most distant.\n",ret1,ret2,ans1,ans2);
}

int main(){
	getprm(M);
	while(scanf("%d%d",&l,&r)!=EOF)
		work();
	return 0;
}
