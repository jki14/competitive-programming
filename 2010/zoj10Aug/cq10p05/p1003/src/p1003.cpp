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

#define int64 long long
#define maxn 1100000
#define rl 0
#define rr 1100000
#define left (i<<1)
#define right ((i<<1)+1)
#define mid ((s+t)>>1)

int timer;
int n,p,k,res;
int a[maxn],f[maxn],r[maxn];
int st[maxn*4];

void update(int i,int x,int y,int s,int t){
	if(x<s || x>t)return;
	if(st[i]>y)st[i]=y;
	if(s==t)return;
	update(left,x,y,s,mid);
	update(right,x,y,mid+1,t);
}

int query(int i,int ss,int tt,int s,int t){
	if(ss>t || tt<s)return LONG_MAX;
	if(ss<=s && t<=tt)return st[i];
	/*if(s==t){
		cout<<"fvck!"<<s<<" "<<t<<" "<<ss<<" "<<tt<<endl;
		return -1;
	}*/
	int l=query(left,ss,tt,s,mid),r=query(right,ss,tt,mid+1,t);
	return (l<r)?l:r;
}

void doit(){
	int i,tmp;res=-1;
	scanf("%d%d%d",&n,&p,&k);
	memset(st,0x7f,sizeof(st));
	memset(f,0,sizeof(f));
	memset(r,0,sizeof(r));
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		r[i]=r[i-1]+a[i];
		f[i]=f[i-1]+r[i]/p;
		r[i]%=p;
	}
	for(i=1;i<=n;i++){
		if(r[i]>k){
			tmp=query(1,r[i]-k,r[i],rl,rr);
			if(tmp!=-1 && res<f[i]-tmp)
				res=f[i]-tmp;
		}else{
			if(res<f[i])res=f[i];
		}
		update(1,r[i],f[i],rl,rr);
	}
	printf("Case %d: %d\n",timer++,res);
}

int main(){
	timer=1;int t;scanf("%d",&t);
	while(t--)doit();
	return 0;
}
