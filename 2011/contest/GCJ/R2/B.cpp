#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

typedef long long lld;

int T;
lld k,n;
int N;
int maxval,minval;

/*lld gcd(lld a,lld b){
　　if(a<b){
　　	lld temp = a;
　　	a = b;
　　	b=temp;
　　}
　　if(0LL==b)
　　	return a;
　　if(a%2LL==0LL && b%2LL ==0LL)
　　	return 2LL*gcd(a/2LL,b/2LL);
　　if ( a%2LL == 0)
　　	return gcd(a/2LL,b);
　　if ( b%2LL==0LL )
　　	return gcd(a,b/2LL);
　　return gcd((a+b)/2LL,(a-b)/2LL);
}*/

lld gcd(lld a,lld b){
	if(a<b)swap(a,b);

	if(b==0LL)return a;
	if(a%2LL==0LL && b%2LL==0LL)
		return 2LL*gcd(a/2LL,b/2LL);
	if(a%2LL==0)
		return gcd(a/2LL,b);
	if(b%2LL==0)
		return gcd(a,b/2LL);

	return gcd((a+b)/2LL,(a-b)/2LL);
}

void work(){
	scanf("%d",&N);n=(lld)N;
	maxval=minval=0;
	lld i,tmp;
	k=1LL;
	for(i=2;i<=n;i=i+1LL){
		if((k%i)==0)continue;
		tmp=gcd(k,i);k=k*i;k=k/tmp;
		maxval++;
	}
	k=n;
	for(i=n-1;i>=1;i=i-1LL){
		if((k%i)==0)continue;
		tmp=gcd(k,i);k=k*i;k=k/tmp;
		minval++;
	}
	cout<<"maxval="<<maxval<<" minval="<<minval;
	printf("Case #%d: %d\n",T,maxval-minval);
}

int main(){
	freopen("B.in","r",stdin);//freopen("B.out","w",stdout);
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	fclose(stdin);//fclose(stdout);
}

