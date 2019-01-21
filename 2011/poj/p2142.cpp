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

int a,b,c;
int rev,retx,rety;
int x,y,d,k1,k2;
int X1,Y1,X2,Y2;

int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1;y=0;
		return a;
	}
	int d=exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-(a/b)*y;
	return d;
}

int better(){
	if(X1+Y1!=X2+Y2)
		return X1+Y1>X2+Y2;
	return X1*a+Y1*b>X2*a+Y2*b;
}

void work(){
	if(a<b){ rev=1;swap(a,b); }else rev=0;
	d=exgcd(a,b,x,y);
	x*=c/d;y*=c/d;
	
	k1=y*d/a;
	if(y<0){k2=k1;k1=k2-1;}else k2=k1+1;

	X1=abs(x+b/d*k1);Y1=abs(y-a/d*k1);
	X2=abs(x+b/d*k2);Y2=abs(y-a/d*k2);
	if(better()){
		swap(X1,X2);
		swap(Y1,Y2);
	}
	if(rev)swap(X1,Y1);
	printf("%d %d\n",X1,Y1);
}

int main(){
	while(scanf("%d%d%d",&a,&b,&c)!=EOF && !(a==0 && b==0 && c==0))
		work();
	return 0;
}

