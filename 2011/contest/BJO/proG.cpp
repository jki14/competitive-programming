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
#include<deque>
#include<set>
#include<map>
using namespace std;

#define N 210000
#define LEN 11

#define L (i<<1)+1
#define R (i<<1)+2

int T;

int n,m;
int c[N];
char a[N];

void build(const int &i,const int &l,const int &r){
	if(l==r){
		c[i]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(L,l,  mid);
	build(R,mid+1,r);
	c[i]=c[L]+c[R];
	if(mid-1>=l && a[mid-1]=='w' && a[mid]=='b' && a[mid+1]=='w')c[i]++;
	if(mid+2<=r && a[mid]=='w' && a[mid+1]=='b' && a[mid+2]=='w')c[i]++;
}

void insert(const int &i,const int &l,const int &r,const int &x,const char &y){
	if(x<l || x>r)return;
	if(l==r){
		a[i]=y;
		return;
	}
	int mid=(l+r)>>1;
	insert(L,l,  mid,x,y);
	insert(R,mid+1,r,x,y);
	c[i]=c[L]+c[R];
	if(mid-1>=l && a[mid-1]=='w' && a[mid]=='b' && a[mid+1]=='w')c[i]++;
	if(mid+2<=r && a[mid]=='w' && a[mid+1]=='b' && a[mid+2]=='w')c[i]++;
}

int querry(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(v<l || u>r)return 0;
	if(u<=l && r<=v)return c[i];
	int mid=(l+r)>>1;
	int ret= querry(L,l,  mid,u,min(mid  ,v))
		+querry(R,mid+1,r,max(mid+1,u),v);
	if(mid-1>=u && a[mid-1]=='w' && a[mid]=='b' && a[mid+1]=='w')ret++;
	if(mid+2<=v && a[mid]=='w' && a[mid+1]=='b' && a[mid+2]=='w')ret++;
	return ret;
}

void work(){
	int opt,u,v;
	char s[LEN];

	memset(c,0,sizeof(c));

	scanf("%d%d",&n,&m);
	scanf("%s",a);
	build(0,0,n-1);

	printf("Case %d:\n",T);
	while(m--){
		scanf("%d",&opt);
		if(opt){
			scanf("%d%s",&u,s);
			if(a[u]==s[0])continue;
			insert(0,0,n-1,u,s[0]);
		}else{
			scanf("%d%d",&u,&v);
			printf("%d\n",querry(0,0,n-1,u,v));
		}
	}


}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

