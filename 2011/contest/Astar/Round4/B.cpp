#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<ctime>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define maxw 3100
#define maxh 3100

int c[maxw][maxh],res;
int w,h,a,b,s,t,p,q;
int ww,hh;

int suit(const int &x,const int &y){
	int i,j;
	
	for(i=1;i<=a;i++)
		for(j=1;j<=hh;j++)
			if(c[x+i-1][y+j-1])return 0;
	
	for(j=2*a+b+1;j<=3*a+b;j++){
		for(i=a+1;i<=a+b;i++)
			if(c[x+i-1][y+j-1])return 0;

		for(i=6*a+b+1;i<=6*a+2*b;i++)
			if(c[x+i-1][y+j-1])return 0;
	}

	for(j=2*a+2*b+1;j<=hh;j++){
		for(i=a+1;i<=a+b;i++)
			if(c[x+i-1][y+j-1])return 0;

		for(i=6*a+b+1;i<=6*a+2*b;i++)
			if(c[x+i-1][y+j-1])return 0;
		
		for(i=9*a+2*b+1;i<=9*a+3*b;i++)
			if(c[x+i-1][y+j-1])return 0;	
	}
	
	for(j=a+b+1;j<=hh;j++){
		for(i=a+b+1;i<=2*a+b;i++)
			if(c[x+i-1][y+j-1])return 0;

		for(i=3*a+b+1;i<=4*a+b;i++)
			if(c[x+i-1][y+j-1])return 0;

		for(i=5*a+b+1;i<=6*a+b;i++)
			if(c[x+i-1][y+j-1])return 0;

		for(i=8*a+2*b+1;i<=9*a+2*b;i++)
			if(c[x+i-1][y+j-1])return 0;

		for(i=9*a+3*b+1;i<=ww;i++)
			if(c[x+i-1][y+j-1])return 0;
	}

	for(i=3*a+b+1;i<=4*a+b;i++)
		for(j=b-a+1;j<=b;j++)
			if(c[x+i-1][y+j-1])return 0;

	for(i=6*a+2*b+1;i<=7*a+2*b;i++)
		for(j=1;j<=hh;j++)
			if(c[x+i-1][y+j-1])return 0;
		
	return 1;
}

void work(){
	int i,j,res;res=0;
	memset(c,0,sizeof(c));
	for(i=s;i<=s+p-1;i++)
		for(j=t;j<=t+q-1;j++)
			c[i][j]=1;
	ww=10*a+3*b;
	hh=3*a+2*b;
	for(i=0;i+ww-1<=w;i++)
		for(j=0;j+hh-1<=h;j++)
			if(suit(i,j))res++;
	printf("%d\n",res);
}

int main(){
	while(scanf("%d%d%d%d%d%d%d%d",&w,&h,&a,&b,&s,&t,&p,&q)!=EOF)
		work();
	return 0;
}

