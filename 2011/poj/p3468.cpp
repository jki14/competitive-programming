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
#define maxl 11

#define L (i<<1)+1
#define R (i<<1)+2

typedef long long lld;

int n,m;
lld sum[maxn],inc[maxn];
char cast[maxl];

lld cross(const int &l1,const int &r1,const int &l2,const int &r2){
	int l,r;
	l=max(l1,l2);r=min(r1,r2);
	return (lld)(r-l+1);
}

void modify(const int &i,const int &l,const int &r,const int &s,const int &t,const lld &d){
	if(s>r || t<l)return;
	if(s<=l && r<=t){
		inc[i]+=d;
	}else{int mid=(l+r)>>1;
		if(inc[i]!=0LL){
			sum[i]+=inc[i]*((lld)(r-l+1));
			modify(L,l,mid  ,1,n,inc[i]);
			modify(R,mid+1,r,1,n,inc[i]);
			inc[i]=0LL;
		}
		sum[i]+=d*cross(l,r,s,t);
		modify(L,l,mid  ,s,t,d);
		modify(R,mid+1,r,s,t,d);
	}
}

lld que(const int &i,const int &l,const int &r,const int &s,const int &t){
	//printf("QUE info:\n");
	//printf("	%d->%d sum=%d inc=%d",l,r,sum[i],inc[i]);

	if(s>r || t<l)return 0;
	if(s<=l && r<=t){
		return sum[i]+inc[i]*((lld)(r-l+1));
	}else{int mid=(l+r)>>1;
		if(inc[i]!=0LL){
			sum[i]+=inc[i]*((lld)(r-l+1));
			modify(L,l,mid  ,1,n,inc[i]);
			modify(R,mid+1,r,1,n,inc[i]);
			inc[i]=0LL;
		}
		return que(L,l,mid  ,s,t)+que(R,mid+1,r,s,t);
	}
}

void work(){
	int i,val,s,t;
	memset(sum,0,sizeof(sum));
	memset(inc,0,sizeof(inc));
	for(i=1;i<=n;i++){
		scanf("%d",&val);
		modify(0,1,n,i,i,(lld)val);
	}
	for(i=0;i<m;i++){
		scanf("%s",cast);
		if(cast[0]=='Q'){
			scanf("%d%d",&s,&t);
			printf("%lld\n",que(0,1,n,s,t));
		}else{
			scanf("%d%d%d",&s,&t,&val);
			modify(0,1,n,s,t,(lld)val);
		}
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}
