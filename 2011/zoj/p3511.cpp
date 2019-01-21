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

#define L (i<<1)+1
#define R (i<<1)+2

struct Edge{
	int x,y;
	bool operator < (const Edge &a) const{
		if((a.y-a.x) != (y-x))return (a.y-a.x)>(y-x);
		if(a.x != x)return (a.x>x);
		return a.y>y;
	}
};

#define maxn 1100000

int n,m;
int ans;

int cov[maxn],len[maxn];

set<Edge> s;
set<Edge>::iterator it; 

void init(const int &i,const int &l,const int &r){
	cov[i]=0;len[i]=r-l+1;
	if(l<r){
		int mid=(l+r)>>1;
		init(L,l,  mid);
		init(R,mid+1,r);
	}
}

void modify(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(cov[i] || u>r || v<l)return;
	if(u<=l && r<=v){
		cov[i]=1;
		len[i]=0;
		return;
	}
	int mid=(l+r)>>1;
	modify(L,l,  mid,u,v);
	modify(R,mid+1,r,u,v);
	len[i]=len[L]+len[R];
}

int que(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(u>r || v<l)return 0;
	if(u<=l && r<=v)return len[i];
	int mid=(l+r)>>1;
	return que(L,l,  mid,u,v)+que(R,mid+1,r,u,v);
}

void work(){
	int i,x,y;
	Edge e;
	ans=0;s.clear();
	for(i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		if(x==y)continue;
		if(x>y)swap(x,y);
		e.x=x;e.y=y;
		s.insert(e);
	}
	init(0,1,n);
	for(it=s.begin();it!=s.end();it++){e=(*it);x=e.x;y=e.y;
		if(x+1==y)continue;
		//printf("Try Que(%d,%d)=%d\n",x,y,que(0,1,n,x,y));
		ans=max(ans,que(0,1,n,x,y));
		modify(0,1,n,x+1,y-1);
	}
	ans=max(ans,que(0,1,n,1,n));
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)work();
	return 0;
}

