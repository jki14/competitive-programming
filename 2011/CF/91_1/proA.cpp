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

#define S 11000
#define K 9

typedef long long lld;

/*int lowbit[S];
lld c[S],lef,rig;*/

int num=0;;

lld s[S],val=0LL;
lld lef,rig,ans;

void build(const int &k){
	if(k)
		s[num++]=val;
	/*else
		for(int i=0;i<S;i++)lowbit[i]=i&(-i);*/
	if(k>K)return;
	val*=10LL;val+=4LL;
	build(k+1);val/=10LL;
	val*=10LL;val+=7LL;
	build(k+1);val/=10LL;
}

/*void add(int x,const lld &val){ for(;x<S;x++)c[x]+=val; }
lld  que(int x){ lld ret=0LL;
	for(;x;x-=lowbit[x])ret+=c[x];
	return ret;
}*/

int find(const lld &x){

	if(x>rig)return -1;

	int l=0,r=num-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(s[mid]>=x){
			if(s[mid-1]<x)return mid;
			r=mid-1;
		}else
			l=mid+1;
	}
	return -1;
}

/*lld gpos(const int &x,lld l,lld r){
	while(l<=r){
		lld mid=(l+r)>>1;
		int tmp=find(mid);
		if(tmp==x){
			if(find(mid+1)!=x)return mid;
			l=mid+1;continue;
		}
		if(tmp> x)
			r=mid-1;
		else
			l=mid+1;
	}
	return -1;
}*/

void work(){
	ans=0LL;
	for(lld i=lef;i<=rig;){
		int k=find(i);
		//lld t=gpos(k,i,rig);
		lld t = min(s[k],rig);
		ans += s[k]*(t-i+1LL);
		i=t+1;
	}
	/*printf("%lld\n",ans);*/
	cout<<ans<<endl;
}

int main(){
	build(0);sort(s,s+num);
	/*for(int i=1;i<=num;i++)add(i,s[i-1]);*/
	while(cin>>lef>>rig)
		work();
	return 0;
}

