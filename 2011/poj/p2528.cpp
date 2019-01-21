#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<map>
using namespace std;

#define maxm 110000

#define L (i<<1)+1
#define R (i<<1)+2

map<int,int> s;
map<int,int>::iterator it;

int n,m,res;
int c[maxm];
int u[maxm],v[maxm];

int insert(const int &i,const int &l,const int &r,const int &u,const int &v){
	if(v<l || u>r)return 0;
	if(c[i])return 0;
	if(u<=l && r<=v){
		c[i]=1;
		return 1;
	}
	int mid=(l+r)>>1,ret=0;
	if(insert(L,l,mid  ,u,v))ret=1;
	if(insert(R,mid+1,r,u,v))ret=1;
	if(c[L] && c[R])c[i]=1;
	return ret;
}

void work(){
	int i;
	s.clear();res=m=0;
	for(i=0;i<n;i++){
		scanf("%d%d",&u[i],&v[i]);
		s.insert(pair<int,int>(u[i],0));
		s.insert(pair<int,int>(v[i],0));
	}
	for(it=s.begin();it!=s.end();it++){
		(*it).second=++m;
	}
	memset(c,0,sizeof(c));
	for(i=n-1;i>=0;i--){
		u[i]=s[u[i]];v[i]=s[v[i]];
		if(insert(0,1,m,u[i],v[i]))res++;
	}
	printf("%d\n",res);
}

int main(){
	int q;scanf("%d",&q);
	while(q--){scanf("%d",&n);
		work();
	}
	return 0;
}
