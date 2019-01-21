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

#define maxn 1100000

#define L (i<<1)+1
#define R (i<<1)+2

const int inf=LONG_MIN;

map<int,int,greater<int> > s;
map<int,int,greater<int> >::iterator it,jt;

int n,m;
int a[maxn],len;
int top[maxn];

int find(const int &i,const int &l,const int &r,const int &x){
	if(top[i]<x)return 0;
	if(l==r){
		len=top[i];
		return r;
	}
	int mid=(l+r)>>1;
	if(top[L]>=x)
		return find(L,l,  mid,x);
	else
		return find(R,mid+1,r,x);
}

void add(const int &i,const int &l,const int &r,const int &x,const int &y){
	
	//if(!i)printf("Add Range At %d len=%d\n",x,y);
	
	if(x<l || x>r)return;
	top[i]=max(top[i],y);
	if(l<r){
		int mid=(l+r)>>1;
		add(L,l,  mid,x,y);
		add(R,mid+1,r,x,y);
	}
}

void clr(const int &i,const int &l,const int &r,const int &x){
	
	//if(!i)printf("Clear Range From %d\n",x);
	
	if(x<l || x>r)return;
	if(l<r){
		int mid=(l+r)>>1;
		clr(L,l,  mid,x);
		clr(R,mid+1,r,x);
		top[i]=max(top[L],top[R]);
	}else
		top[i]=inf;
}

int checkin(const int &x){
	int ret=find(0,1,n,x);
	if(!ret)return ret;
	
	clr(0,1,n,ret);
	it=s.find(ret);
	if(it==s.end()){
		while(1)ret=n;	
	}else s.erase(it);
	a[ret]=0;
	
	if(len-x==0)return ret;

	add(0,1,n,ret+x,len-x);
	s.insert(pair<int,int>(ret+x,1));
	a[ret+x]=len-x;

	return ret;
}

void checkout(const int &u,int v){
	if(v+1<=n && a[v+1])v++;
	it=s.lower_bound(v);jt=s.lower_bound(u);
	
	int head,tail,del=1;

	if(jt==s.end() || (*jt).first+a[(*jt).first]<u){
		head=u;
		//if(jt!=s.begin())jt--;
		del=0;
	}else{
		head=(*jt).first;
	}

	if(it==s.end() || (*it).first+a[(*it).first]-1<v){
		tail=v;
	}else{
		tail=(*it).first+a[(*it).first]-1;
	}
	
	for(;it!=s.end();){
		if(it==jt){if(!del)break;
			clr(0,1,n,(*it).first);
			a[(*it).first]=0;
			s.erase(it);
			break;
		}else{
			clr(0,1,n,(*it).first);
			a[(*it).first]=0;
			s.erase(it++);
		}
	}

	add(0,1,n,head,tail-head+1);
	s.insert(pair<int,int>(head,1));
	a[head]=tail-head+1;
}

void work(){
	int cast,x,y;
	memset(top,0x8f,sizeof(top));s.clear();
	memset(a,0,sizeof(a));a[1]=n;
	add(0,1,n,1,n);s.insert(pair<int,int>(1,1));
	while(m--){scanf("%d",&cast);
		
		//printf("New Cast\n");

		if(cast==1){scanf("%d",&x);
			printf("%d\n",checkin(x));
		}else{scanf("%d%d",&x,&y);
			checkout(x,x+y-1);
		}
	}
}

int main(){
	while(scanf("%d%d",&n,&m)!=EOF)
		work();
	return 0;
}

