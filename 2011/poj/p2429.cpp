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

#define K 110

typedef long long lld;

const int mTim=30;

lld gcd,lcm;
lld n,x,y;
lld ansx,ansy;
lld f[K],val[K],ful[K];
int k,m,num[K];

lld randLld(lld x){
	return rand()%(x-1LL)+1LL;
}

lld mutMod(lld a,lld b,lld c){
	lld ret=0LL;
	a%=c;b%=c;
	for(;b;b>>=1){
		if(b&1)ret+=a;
		if(ret>c)ret-=c;
		a<<=1;
		if(a>=c)a-=c;
	}
	return ret;
}

lld powMod(lld a,lld b,lld c){
	if(b==1)return a%c;

	int bit[K],k=0;
	for(;b;b>>=1)bit[k++]=b&1;

	lld ret=1LL;
	for(k=k-1;k>=0;k--){
		ret=mutMod(ret,ret,c);
		if(bit[k])ret=mutMod(ret,a,c);
	}

	return ret;
}

int millerCheck(lld b,lld a,lld x,lld t){
	lld ret=powMod(b,x,a),last=ret;
	for(int i=1;i<=t;i++){
		ret=mutMod(ret,ret,a);
		if(ret==1LL && last!=1LL && last!=a-1LL)return 1;
		last=ret;
	}
	return ret!=1;
}

int millerRobin(lld a,int tim){
	if(a==2LL)return 1;if(!(a&1))return 0;
	
	lld x=a-1,t=0;
	while(!(x&1)){ x>>=1;t++; }
	if(t && (x&1)==1){
		for(int i=0;i<tim;i++){
			lld b=randLld(a);
			if(millerCheck(b,a,x,t))return 0;
		}
	}else return 0;
	return 1;
}

lld stein(lld x,lld y){
	lld k=0LL;
	while(y>0LL){
		if((x&y&1)==1)x=(x-y)>>1;
		else if(((x^y)&1)==0){ x>>=1;y>>=1;k++; }
		else if((x&1)==0)x>>=1; else y>>=1;
		if(x<y)swap(x,y);
	}
	return x<<k;
}

lld PollardRho(lld x,lld c){
	lld i=1LL,x0=randLld(x)-1;
	lld y=x0,k=2LL;
	while(1){
		i++;
		x0=(mutMod(x0,x0,x)+c)%x;
		lld d=stein(y-x0,x);
		if(d!=1LL && d!=x)return d;
		if(y==x0)return x;
		if(i==k){ y=x0;k<<=1; }
	}
}
void getFactor(lld a){

	if(a==1LL)return;

	if(millerRobin(a,mTim)){ f[k++]=a; return; }
	lld p=a;
	while(p>=a)p=PollardRho(p,randLld(a));
	getFactor(p);
	getFactor(a/p);
}

void dfs(const int &k){
	if(k==m){
		if(x>y)return;
		if(ansx==-1LL || ansx+ansy>x+y){
			ansx=x;ansy=y;
		}
		return;
	}
	y*=ful[k];	    dfs(k+1);
	x*=ful[k];y/=ful[k];dfs(k+1);
	x/=ful[k];
}

void work(){
	n=lcm/gcd;k=0;
	getFactor(n);

	sort(f,f+k);m=0;
	for(int i=0;i<k;i++){
		if(m && val[m-1]==f[i]){
			ful[m-1]*=val[m-1];
			num[m-1]++;
			continue;
		}
		val[m]=ful[m]=f[i];num[m++]=1;
	}

	/*for(int i=0;i<m;i++){
		printf("%lld * %d == %lld \n",val[i],num[i],ful[i]);
	}*/

	x=1LL;y=1LL;
	ansx=-1LL;
	dfs(0);

	printf("%lld %lld\n",ansx*gcd,ansy*gcd);
}

int main(){
	srand(2221114);
	while(scanf("%lld%lld",&gcd,&lcm)!=EOF)
		work();
	return 0;
}

