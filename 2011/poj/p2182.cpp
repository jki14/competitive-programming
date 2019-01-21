#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 11000

const int zero=0;

int n;
int a[maxn],r[maxn];
int c[maxn],v[maxn],lowbit[maxn];

void modify(const int &x,const int &d){
	for(int i=x;i<=n;i+=lowbit[i])
		c[i]+=d;
}

int sum(const int &x){
	int ret=0;
	for(int i=x;i>0;i-=lowbit[i])ret+=c[i];
	return ret;
}

int find(const int &x){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(sum(mid)==x && !v[mid])return mid;
		if(sum(mid)>=x)
			r=mid-1;
		else
			l=mid+1;
	}
	//printf("No Result For %d\n",x);
	//for(int i=1;i<=n;i++)printf("%d",v[i]^1);printf("\n");
	return zero/zero;
}

void work(){
	int i;
	//s[0]=0;s[1]=1;a[1]=0;
	//memset(w,0,sizeof(w));
	a[1]=1;
	for(i=2;i<=n;i++){
		scanf("%d",&a[i]);a[i]++;
		/*s[i]=s[a[i]]+1;
		w[a[i]]++;*/
	}
	for(i=1;i<=n;i++)c[i]=lowbit[i]=i&(-i);
	memset(v,0,sizeof(v));
	memset(r,0,sizeof(r));
	for(i=n;i>0;i--){/*if(r[i])continue;
		for(k=i;k;k=a[k]){if(w[k])break;
			r[k]=find(s[k]);
			//printf("r[%d]=%d\n",k,r[k]);
			modify(r[k],-1);
			v[r[k]]=1;
			w[a[k]]--;
		}*/
		r[i]=find(a[i]);
		modify(r[i],-1);
		v[r[i]]=1;
	}
	for(i=1;i<=n;i++)
		printf("%d\n",r[i]);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

