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

#define maxn 10

const int N=3;
const int m=21252;

int timer;

const int a[N]={ 23,28,33 };
int b[N],d;

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

int chinaRem(int n){
	int i,d,x,y,ret,tot,r;
	ret=0;tot=1;for(i=0;i<n;i++)tot*=a[i];
	for(i=0;i<n;i++){
		r=tot/a[i];
		d=exgcd(a[i],r,x,y);
		ret=(ret+y*r*b[i])%tot;
	}
	return (ret%tot+tot)%tot;
}

int work(){
	int i,res;for(i=0;i<N;i++)scanf("%d",&b[i]);
	scanf("%d",&d);
	if(b[0]==-1 && b[1]==-1 &&  b[2]==-1 && d==-1)
		return 0;
	//printf("chinaRem()=%d\n",chinaRem(N));
	res=(chinaRem(N)-d+m)%m;
	if(!res)res=m;
	printf("Case %d: the next triple peak occurs in %d days.\n",++timer,res);
	return 1;
}

int main(){timer=0;
	while(work());
	return 0;
}
