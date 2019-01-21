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
#include<set>
#include<map>
using namespace std;

typedef long long lld;

lld n,k,modulo;
lld ans;

lld inv(lld a, lld b){
	lld r=a%b,x0=1LL,y0=0LL,x1=0LL,y1=1LL;
	while(r){
		lld k=a/b;
		lld dx=x0-k*x1;
		lld dy=y0-k*y1;
		x0=x1;y0=y1;x1=dx;y1=dy;
		a=b;b=r;r=a%b;
	}
	if(!x1)x1=1LL;
	return x1;
}

//count C(a,b) % c ( c is a prime number )
lld com(const lld &a,const lld &b,const lld &c){
	lld ret = 1LL;
	if(c<=b){
		/* Track */
		int acnt,bcnt;acnt=bcnt=0;
		for(lld i=a,j=1LL;j<=b;i--,j++){
			if(!(i%c)){
				lld tmp=i;
				while(!(tmp%c)){
					tmp/=c;acnt++;
				}
			}
			if(!(j%c)){
				lld tmp=j;
				while(!(tmp%c)){
					tmp/=c;bcnt++;
				}
			}
		}
		if(acnt!=bcnt) 
			ret= 0LL;
		else{
			for(lld i=a,j=1LL;j<=b;i--,j++){
				lld tmp = i;while(!(tmp%c))tmp/=c;
				ret = ret * tmp % c;
				tmp = j;while(!(tmp%c))tmp/=c;
				ret = ret * inv(tmp,c) % c;
			}
		}
	}else{
		/* Simple */
		for(lld i=a,j=1LL;j<=b;i--,j++){
			ret = ret * i % c;	
			ret = ret * inv(j,c) % c;
		}
	}

	ret = ( ret % c + c ) % c;

	return ret;
}

void work(){
	/* Zero */
	if((k<<1) > n){
		ans=0LL;	
	}else{
		ans=com(n-k+1LL,k,modulo);
	}
	/* Printout */
	printf("%lld\n",ans);
}

int main(){
	while(scanf("%lld%lld%lld",&n,&k,&modulo)!=EOF)
		work();
	return 0;
}

