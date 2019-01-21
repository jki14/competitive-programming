#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

#define maxv 1000000
#define maxn 11000

#define rr 100000
#define ll 1

map<int,int> s;
map<int,int>::iterator it;

int n;
int cc[maxv],vis[maxn],l[maxn],r[maxn];

void update(int ii,int s,int t,int ss,int tt,int k){
	if(s>tt || t<ss)return;
	if(s>=ss && t<=tt){	cc[ii]=k; return; }
	int mid=(s+t)>>1;
	if(cc[ii]>0){
		update(ii*2,s,mid,ll,rr,cc[ii]);
		update(ii*2+1,mid+1,t,ll,rr,cc[ii]);
	}
	update(ii*2,s,mid,ss,tt,k);
	update(ii*2+1,mid+1,t,ss,tt,k);
	cc[ii]=-1;
}

void query(int ii,int s,int t,int ss,int tt){
	if(s>tt || t<ss)return;
	if(s>=ss && t<=tt && cc[ii]!=-1){vis[cc[ii]]=1;return;}
	int mid=(s+t)>>1;
	query(ii*2,s,mid,ss,tt);
	query(ii*2+1,mid+1,t,ss,tt);
}

void work(){
	int i,res=0;
	memset(cc,0,sizeof(cc));
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);s.clear();
	for(i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
		s.insert(pair<int,int>(l[i],0));
		s.insert(pair<int,int>(r[i],0));
	}
	for(it=s.begin(),i=1;it!=s.end();it++,i++)(*it).second=i;
	for(i=1;i<=n;i++)
		update(1,ll,rr,s[l[i]],s[r[i]],i);
	query(1,ll,rr,ll,rr);
	for(i=1;i<=n;i++)if(vis[i])res++;
	printf("%d\n",res);
}

int main(){
	int t;scanf("%d",&t);while(t--)work();
	return 0;
}
