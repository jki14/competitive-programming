#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 51000

const int maxi = maxn*4;
const int inf = 2000000000;

int n,q;
int maxSt[maxi],minSt[maxi];

int max(int x,int y){ return (x>y)?x:y; }
int min(int x,int y){ return (x<y)?x:y; }

void setSt(int i,int s,int t,int k,int x){
	if(k<s || k>t)return;
	//cout<<" Set i="<<i<<" ("<<s<<"->"<<t<<") at "<<k<<"  = "<<x<<endl;
	maxSt[i]=max(maxSt[i],x);
	minSt[i]=min(minSt[i],x);
	int mid=(s+t)>>1;
	if(s<t){
		setSt((i<<1),s,mid,k,x);
		setSt((i<<1)+1,mid+1,t,k,x);
	}
}

int getMax(int i,int s,int t,int l,int r){
	if(r<s || l>t)return -inf;
	if(l<=s && t<=r)return maxSt[i];
	int mid=(s+t)>>1,x,y;
	x=getMax((i<<1),s,mid,l,r);
	y=getMax((i<<1)+1,mid+1,t,l,r);
	return max(x,y);
}

int getMin(int i,int s,int t,int l,int r){
	if(r<s || l>t)return inf;
	if(l<=s && t<=r)return minSt[i];
	int mid=(s+t)>>1,x,y;
	x=getMin((i<<1),s,mid,l,r);
	y=getMin((i<<1)+1,mid+1,t,l,r);
	return min(x,y);
}

void work(){
	memset(maxSt,0x8f,sizeof(maxSt));
	memset(minSt,0x7f,sizeof(minSt));
	int u,v;for(int i=1;i<=n;i++){
		scanf("%d",&v);
		setSt(1,1,n,i,v);
	}
	while(q--){
		scanf("%d%d",&u,&v);
		printf("%d\n",getMax(1,1,n,u,v)-getMin(1,1,n,u,v));
	}
}

int main(){
	while(scanf("%d%d",&n,&q)!=EOF)work();
	return 0;
}
