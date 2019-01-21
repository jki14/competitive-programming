//============================================================================
// Name        : SegTree
// Author      : J.Ki
// Version     : 1.00
// Copyright   : WangZhe (Chongqing University Computer College)
// Description : 线段树：区间加减，区间求最值操作,POJ4047(原题有三种操作1.修改点x值为y,
// 2.交换点x与点y的值 3.求区间[x,y]内和最大的一个连续且长度为k的区间,保证x+k-1<=y)
//============================================================================

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
#include<list>
#include<bitset>
#include<set>
#include<map>
#include<functional>
#include<numeric>
#include<utility>
#include<iomanip>
using namespace std;

#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))

#define L ((i<<1)+1)
#define R ((i<<1)+2)

#define N 210000
#define S 1100000

const int inf=INT_MIN;

int n,m,k;
int a[N],s[N];
int val[S],cov[S];
void build(const int &i,const int &l,const int &r){cov[i]=0;
	if(l==r){
		val[i]=s[l];
	}else{
		int mid=(l+r)>>1;
		build(L,l,  mid);
		build(R,mid+1,r);
		val[i]=max(val[L],val[R]);
	}
}

void modif(const int &i,const int &l,const int &r,const int &u,const int &v,const int &d){
	if(u>r || v<l)return;
	if(u<=l && r<=v){
		cov[i]+=d;
	}else{
		int mid=(l+r)>>1;
		modif(L,l,  mid,u,v,d);
		modif(R,mid+1,r,u,v,d);
		val[i]=max(val[L]+cov[L],val[R]+cov[R]);
	}
}

int  querr(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(u>r || v<l)return inf;
	if(u<=l && r<=v){
		return val[i]+cov[i];
	}else{
		int mid=(l+r)>>1;
		int lefval=querr(L,l,  mid,u,v),
		    rigval=querr(R,mid+1,r,u,v);
		return max(lefval,rigval)+cov[i];
	}
}

void opt0(const int &x,const int &y){
	int d=y-a[x];a[x]=y;
	modif(0,1,n,x-k+1,x,d);
}

void opt1(const int &x,const int &y){
	int valx=a[x],valy=a[y];
	opt0(x,valy);opt0(y,valx);
}

void opt2(const int &x,const int &y){
	printf("%d\n",querr(0,1,n,x,y-k+1));
}

int main(){	//cout<<"inf="<<inf<<endl;
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		s[n+1]=0;for(int i=n;i>0;i--)s[i]=s[i+1]+a[i]-(i+k<=n?a[i+k]:0);
		n=n-k+1;build(0,1,n);
		for(int i=0;i<m;i++){
			int p,x,y;scanf("%d%d%d",&p,&x,&y);
			switch(p){
				case 0:opt0(x,y);break;
				case 1:opt1(x,y);break;
				case 2:opt2(x,y);break;
			}
		}
	}
	return 0;
}
