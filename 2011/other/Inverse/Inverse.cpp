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

int x,y;


void inverse(const int &a,const int &b,int &d,int &ar,int &br){
	int k;
	int x1,x2,x3;
	int y1,y2,y3;
	int t1,t2,t3;
	if(!a || !b){
		//No Result
		ar=1;br=1;
		d=(a==0)?b:a;
	}else{
		x1=1;x2=0;x3=a;
		y1=0;y2=1;y3=b;
		if(x3<y3)swap(x3,y3);
		for(t3=x3 % y3;t3!=0;t3=x3 % y3){
			k=x3/y3;
			t1=x1-k*y1;
			t2=x2-k*y2;
			x1=y1;x2=y2;x3=y3;
			y1=t1;y2=t2;y3=t3;
		}
		if(y3==1){
			ar=y2;br=x1;d=1;
		}else{
			//No Result
			ar=1;br=1;d=y3;
		}
	}
	if(ar<0)ar+=b;
	ar%=b;
}

void work(){
	int r,r1,r2;
	inverse(x,y,r,r1,r2);
}

int main(){
	while(scanf("%d%d",&x,&y)!=EOF && y)
		work();
	return 0;
}

