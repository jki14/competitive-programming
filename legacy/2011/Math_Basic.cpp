//============================================================================
// Name        : Math Basic Operation
// Author      : J.Ki
// Version     : 1.20
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 基本数论、数学模板
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
#include<set>
#include<map>
using namespace std;

typedef long long lld;

const int inf=LONG_MAX;

const double eps=1e-4;

//欧几里德求最大公约数
int gcd(int x,int y){
	while(y){
		int k=x%y;
		x=y;y=k;
	}
	return x;
}

//Stein求最大公约数
lld stein(lld x,lld y){
	if(x<y)swap(x,y);
	lld k=0LL;
	while(y>0LL){
		if((x&y&1)==1)x=(x-y)>>1;
		else if(((x^y)&1)==0){ x>>=1;y>>=1;k++; }
		else if((x&1)==0)x>>=1; else y>>=1;
		if(x<y)swap(x,y);
	}
	return x<<k;
}

//扩展欧几里德求线性 ax≡c(mod b)
/*
 * 即:ax+by=c
 * d=gcd(a,b),if(c%d==0)有解
 * x,y为基础解，通解为
 * 		X = x+b/d*t;
 * 		Y = y-a/d*t;
 */
// ax+by=exgcd(a,b,x,y);
int exgcd(int a,int b,int &x,int &y){
	//if(a<b)swap(a,b);
	if(!b){
		x=1;y=0;
		return a;
	}
	int d=exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-(a/b)*y;
	return d;
}
// ax≡c(mod b)
int mlcore(int a,int c,int b){
	int d,x,y,e;
	d=exgcd(a,b,x,y);
	if(b%d!=0){
		//无解
		return 0;
	}else{
		//基础解e
		e=x*(c/d)%b;
		return e;
		//其他解for(int i=0;i<d;i++)ret[i]=e+i*(b/d)%b;
	}
}

//扩展欧几里德求 a b逆元(即:a*ret mod b =1)
lld inverse(const lld &a,const lld &b){
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
}

//中国剩余定理(给定两两互质的正整数a1,a2,...,ak, 要求找到最小的正整数 x, 满足x≡bi(mod ai))
int chinaRem(int a[],int b[],int n){
	int i,d,x,y,ret,tot,r;
	ret=0;tot=1;for(i=0;i<n;i++)tot*=a[i];
	for(i=0;i<n;i++){
		r=tot/a[i];
		d=exgcd(a[i],r,x,y);
		ret=(ret+y*r*b[i])%tot;
	}
	return (ret%tot+tot)%tot;
}

/*  欧拉定理:
 * 		若a与m互质，则a^phi(m) mod m = 1;
 *  欧拉函数：
 *  	phi(x)=x*(1-1/p0)*...*(1-1/pk);
 *  		  =(p0^(r0-1))*(p0-1) * (p1^(r1-1))*(p1-1) *...* (pk^(rk-1))*(pk-1);
 *  	(p0..pk为x的质因子 r0..rk为对应因子个数)
 */

//递推求phi 欧拉函数(φ(x)为与x互质且小等于x的正整数个数)
void getPhi(int n){
	int i,j;
	phi[0]=phi[1]=0.0;
	for(i=2;i<=n;i++)phi[i]=(double)i;
	for(i=2;i<=n;i+=2)phi[i]/=2;
	for(i=3;i<=n;i+=2){double di=(double)i;
		if(fabs(phi[i]-di)<eps)
			for(j=i;j<=n;j+=i)
				phi[j]*=1.0-1.0/di;
	}
}

//直接求phi欧拉函数
int phi(int x){
	double res=x;
	for(int i=2;i*i<=x;i++){
		if(!(x%i)){
			res=res*(1.0-1.0/((double)i));
			while(!(x%i))x/=i;
		}
	}
	if(x>1)res=res*(1.0-1.0/((double)x));
	return res;
}
