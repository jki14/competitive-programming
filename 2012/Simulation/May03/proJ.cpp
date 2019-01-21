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

lld inv(lld a,lld b){
	lld r=a%b,x0=1LL,y0=0LL,x1=0LL,y1=1LL;
	while(r){
		lld k=a/b;
		lld dx=x0-k*x1;
		lld dy=y0-k*y1;
		x0=x1;y0=y1;x1=dx;y1=dy;
		a=b;b=r;r=a%b;
	}
	return x1;
}

/*lld inverse(const lld &a,const lld &b){
	lld k;
	lld x1,x2,x3;
	lld y1,y2,y3;
	lld t1,t2,t3;
	//无解情况1
	if(a==0LL || b==0LL)return 1LL;
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
	//无解情况2
	if(y3!=1LL)return 1LL;
	return (y2%b+b)%b;
}*/

int main(){
	int t;scanf("%d",&t);
	while(t--){
		lld a,b;scanf("%lld%lld",&a,&b);
		if(b==1LL){ printf("1\n");continue; }
		lld ret=(inv(a,b)%b+b)%b;
		if(ret*a%b!=1LL)
			printf("Not Exist\n");
		else
			printf("%lld\n",ret);
	}
}
