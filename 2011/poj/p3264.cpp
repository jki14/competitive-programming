#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 1100000

const int inf=LONG_MAX;
const int lmt=LONG_MIN;

int n,m;
int maxval,minval;
int top[maxn],low[maxn];

void modify(const int &i,const int &l,const int &r,const int &x,const int &val){
	if(x<l || x>r)return;
	top[i]=max(top[i],val);
	low[i]=min(low[i],val);
	if(l!=r){
		int mid=(l+r)>>1;
		modify((i<<1)+1,l,mid  ,x,val);
		modify((i<<1)+2,mid+1,r,x,val);
	}
}

void que(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(u>r || v<l)return;
	if(u<=l && r<=v){
		maxval=max(maxval,top[i]);
		minval=min(minval,low[i]);
	}else{
		int mid=(l+r)>>1;
		que((i<<1)+1,l,mid  ,u,v);
		que((i<<1)+2,mid+1,r,u,v);
	}
}

void work(){
	memset(top,0x8f,sizeof(top));
	memset(low,0x7f,sizeof(low));
	int i,val,s,t;
	for(i=1;i<=n;i++){
		scanf("%d",&val);
		modify(0,1,n,i,val);
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&s,&t);
		maxval=lmt;
		minval=inf;
		que(0,1,n,s,t);
		printf("%d\n",maxval-minval);
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}
