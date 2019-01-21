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

#define maxn 1100000

typedef long long lld;

int n,m;
lld x,y,z;
double maxval,tmp;
int q[maxn];
lld a[maxn],c[maxn];

lld sum(const int &i,const int &j){
	if(i)return c[j]-c[i-1];
	return c[j];
}

lld gcd(const lld &x,const int &y){
	lld a=x,b=y,tmp;
	while(b){
		tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}

void work(){
	int i,s,t,head;
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	c[0]=a[0];
	for(i=1;i<n;i++)c[i]=c[i-1]+a[i];
	s=t=0;head=0;
	maxval=-1.0;
	for(i=m-1;i<n;i++){
		while(s<t && 
			((double)sum(head,q[s])/(double)(q[s]-head+1))<(((double)sum(head,i))/((double)(i-head+1)))){
			head=q[s]+1;s++;
		}
		tmp=(((double)sum(head,i))/((double)(i-head+1)));
		if(maxval<tmp){
			maxval=tmp;
			x=sum(head,i);y=(lld)(i-head+1);
		}
		q[t++]=i-m+1;
		while(s+1<t &&
			((double)sum(q[t-1],i+1)/(double)(i+1-q[t-1]+1))>=(((double)sum(q[t],i+1))/((double)(i+1-q[t]+1))))t--;
		
	}
	if(x%y==0){
		printf("%lld\n",x/y);
	}else{
		z=gcd(x,y);
		x/=z;y/=z;
		printf("%lld/%lld\n",x,y);	
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF && !(n==0 && m==0))
		work();
	return 0;
}

