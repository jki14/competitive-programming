//============================================================================
// Name        : ConvolutionByFFT
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 原题为HDU4609, 给定一个边长集合，求随机取出三条边可以构成三角形几率
//===========================================================================
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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

#define S 1100000

const double PI = acos(-1.);

struct PDD{ double x,y;PDD(){}PDD(const double &_x,const double &_y){x=_x;y=_y;} };

int n,cap,id;
lld cnt[S],ans,tot;
int a[S],c[S];
PDD P[S],PB[S],tmp[S];

void fill(int s[],const int &m,const int &d){
	if (m == cap)
		P[d] = PDD((double)s[id++],0.0);
    	else {
        	fill(s,m<<1,d);
        	fill(s,m<<1,d+m);
    	}
}

void fill2(const int &m,const int &d){
    	if (m == cap)
		P[d] = tmp[id++];
    	else{
		fill2(m<<1,d);fill2(m<<1,d+m);
    	}
}

inline void FFT(const double &oper){
	for (int d = 0;(1 << d) < cap;++d){
        	int m = (1 << d);
        	double p0 = PI / m * oper;
        	double sinp0 = sin(p0);
        	double cosp0 = cos(p0);
        	for (int i = 0;i < cap;i += (m << 1)){
            		double sinp = 0.0;
            		double cosp = 1.0;
            		for (int j = 0;j < m;++j){
                		double ta = cosp * P[i+j+m].x - sinp*P[i+j+m].y;
                		double tb = cosp * P[i+j+m].y + sinp*P[i+j+m].x;
                		P[i+j+m].x = P[i+j].x - ta;
                		P[i+j+m].y = P[i+j].y - tb;
                		P[i+j].x += ta;
                		P[i+j].y += tb;
                		double tsinp = sinp;
                		sinp = sinp * cosp0 + cosp * sinp0;
                		cosp = cosp * cosp0 -tsinp * sinp0;
            		}
        	}
    	}
}

void Convolution(){
	id=0;fill(c,1,0);FFT(1.0);
	for(int i=0;i<cap;i++)PB[i]=P[i];
	id=0;fill(c,1,0);FFT(1.0);
	for(int i=0;i<cap;i++){
		tmp[i].x=P[i].x*PB[i].x-P[i].y*PB[i].y;
		tmp[i].y=P[i].x*PB[i].y+P[i].y*PB[i].x;
	}
	id=0;fill2( 1,0);FFT(-1.);
	for(int i=0;i<cap;i++)cnt[i]=(lld)(P[i].x/((double)cap)+0.5);
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);ans=tot=((lld)n)*((lld)(n-1))*((lld)(n-2))/6LL;
		for(int i=0;i<n;i++)scanf("%d",&a[i]);

		sort(a,a+n);
		memset(c,0,sizeof(c));for(int i=0;i<n;i++)c[a[i]]++;

		cap=1<<20;while((cap>>2)>a[n-1])cap>>=1;

		Convolution();
		for(int i=0;i<n;i++)cnt[a[i]+a[i]]--;
		for(int i=0;i<cap;i++)cnt[i]>>=1;

		for(int i=0,k=0;i<cap;i++){
			if(cnt[i]){
				//printf("cnt[%d]=%lld\n",i,cnt[i]);
				while(k<n && a[k]<i)++k;
				if(k==n)break;
				ans-=cnt[i]*(n-k);
			}
		}

		printf("%.7f\n",((double)ans)/((double)tot));
	}
	return 0;
}
