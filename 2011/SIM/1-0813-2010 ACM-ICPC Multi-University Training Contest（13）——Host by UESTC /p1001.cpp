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

#define maxn 110000

int T;

int n,top;
int a[maxn],f[maxn];
int d[maxn],q[maxn];
int c[maxn],lowbit[maxn];

void used(int x){ for(;x<=n;x+=lowbit[x])c[x]--; }

int que(int x){ int ret=0;for(;x>0;x-=lowbit[x])ret+=c[x];return ret; }

int getk(const int &x){
	//printf("Find %d\n",x);
	int l=1,r=n,mid,val;
	while(l<=r){
		mid=(l+r)>>1;val=que(mid);
		//printf("val[%d]=%d\n",mid,val);
		if(val==x && que(mid-1)<x)return mid;
		if(val>=x)
			r=mid-1;
		else
			l=mid+1;
	}
	for(val=1;val;val*=1);
	return -1;
}

int quek(const int &x){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(q[mid]>x && q[mid-1]<x)return mid;
		if(q[mid]>x)
			r=mid-1;
		else
			l=mid+1;
	}
	int zero=1;zero--;
	return zero/zero;
}

void work(){
	int i,k;
	for(i=0;i<=n;i++)c[i]=lowbit[i];
	for(i=1;i<=n;i++)scanf("%d",&d[i]);
	for(i=n;i;i--){
		k=getk(d[i]+1);
		a[k]=i;used(k);
	}
	memset(q,0x7f,sizeof(q));q[0]=0;
	for(i=1;i<=n;i++){
		k=quek(a[i]);
		q[k]=a[i];
		f[a[i]]=k;
	}
	printf("Case #%d:\n",T);top=0;
	for(i=1;i<=n;i++){
		top=max(top,f[i]);
		printf("%d\n",top);
	}
	printf("\n");
}

void init(){
	for(int i=0;i<maxn;i++)lowbit[i]=i&(-i);
}

int main(){int t;
	init();scanf("%d",&t);
	for(T=1;T<=t;T++){
		scanf("%d",&n);
		work();
	}
	return 0;
}
