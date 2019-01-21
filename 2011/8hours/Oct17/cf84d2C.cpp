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

const int a=7,b=4;

int n;

int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1;y=0;
		return a;
	}
	int d=exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-(a/b)*y;
	return d;
}

void work(){
	int x,y,d;
	d=exgcd(a,b,x,y);
	if(n%d){
		printf("-1\n");
	}else{
		int t=y*n/a;
		int X=x*n/d+b/d*t;
		int Y=y*n/d-a/d*t;
		if(X<0 || Y<0)
			printf("-1\n");
		else{
			for(int i=0;i<Y;i++)printf("4");
			for(int i=0;i<X;i++)printf("7");
			printf("\n");
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

