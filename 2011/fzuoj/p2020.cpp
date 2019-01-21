#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

typedef long long lld;

lld n,m,p,res;

lld inverse(const lld &a,const lld &b){
	lld k;
	lld x1,x2,x3;
	lld y1,y2,y3;
	lld t1,t2,t3;
	if(!a || !b)return 1LL;
	x1=1LL;x2=0LL;x3=a;
	y1=0LL;y2=1LL;y3=b;
	if(x3 < y3)swap(x3,y3);
	for(t3=x3 % y3;t3!=0LL;t3=x3 % y3){
		k=x3/y3;
		t1=x1-k*y1;
		t2=x2-k*y2;
		x1=y1;x2=y2;x3=y3;
		y1=t1;y2=t2;y3=t3;
	}
	if(y3!=1)return 1LL;
	return (y2%b+b)%b;
}

void work(){
	lld i,k;res=1LL;
	for(i=n;i>n-m;i--){ res*=i;res%=p; }
	for(i=2;i<=m;i++){
		k=inverse(i,p);
		//cout<<"k="<<k<<endl;
		res*=k;
		res%=p;
	}
	printf("%lld\n",res%p);
}

int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld",&n,&m,&p);
		work();
	}
	return 0;
}
