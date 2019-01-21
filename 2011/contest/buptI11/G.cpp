#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 110000

typedef long long lld;

const int inf=LONG_MAX;

int n,m,p;
lld val,c[maxn];
int a[maxn],b[maxn];
int low[maxn],hig[maxn];

int lowbit(const int &x){
	return x&(x^(x-1));
}

void add(const int &x,const lld &d){
	if(x<1 || x>n)return;
	for(int i=x;i<=n;i+=lowbit(i))
		c[i]+=d;
}

lld sum(const int &x){int res=0LL;
	for(int i=x;i>0;i-=lowbit(i))
		res+=c[i];
	return res;
}

lld left(const int &x,const int &d){
	if(x<1 || x>n)return 0LL;
	lld k=sum(x);
	if(d)
		return k;
	return ((lld)x)-k;
}

lld right(const int &x,const int &d){
	if(x<1 || x>n)return 0LL;
	lld k=sum(n)-sum(x-1);
	if(d)
		return k;
	return ((lld)n)-((lld)x)+1LL-k;
}

void work(){
	int i,k,top;val=0LL;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	top=0;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		if(k<p){
			a[i]=1;top=i;low[i]=i-1;
		}else
			low[i]=top;
		
	}
	top=inf;
	for(i=n;i>=1;i--){
		if(a[i]){
			top=i;hig[i]=i+1;
		}else
			hig[i]=top;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if(b[i])add(i,1LL);
	}
	for(i=1;i<=n;i++)val+=left(low[i],b[i]^1);
	for(i=0;i<m;i++){
		scanf("%d",&k);
		if(k){
			printf("%lld\n",val);
		}else{
			scanf("%d",&k);
			val+=left(low[k],b[k])-left(low[k],b[k]^1);
			val+=right(hig[k],b[k])-right(hig[k],b[k]^1);
			b[k]^=1;
			add(k,b[k]?1LL:-1LL);
		}
	}
}

int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&p);
		work();
	}
	return 0;
}

