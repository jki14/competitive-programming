#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<ctime>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

#define maxn 110000

#define maxm 1100000

#define U s[u]
#define V s[v-1]

typedef long long lld;

const lld inf=1LL<<60LL;

int n;
lld f[maxn],a[maxn];
lld s[maxn];
int c[maxm];

void ins(const int &i,const int &u,const int &v,const int &x){
	if(x<u || x>v)return;
	//update [c]
	if(c[i]==-1 || a[c[i]]<a[x] || (a[c[i]]==a[x] && c[i]<x))c[i]=x;
	if(u==v)return;
	int mid=(u+v)>>1;
	ins(i<<1,u,mid,x);
	ins((i<<1)+1,mid+1,v,x);
}

int que(const int &i,const int &u,const int &v,const int &s,const int &t){
	if(s>v || t<u || t<s)return -1;
	if(s<=u && v<=t)return c[i];
	int mid=(u+v)>>1,k,tmp;
	k=que(i<<1,u,mid,s,t);
	tmp=que((i<<1)+1,mid+1,v,s,t);
	if(k==-1 || a[k]<a[tmp] || (a[k]==a[tmp] && k<tmp))k=tmp;
	return k;
}

void work(){
	int i,j;
	int u,v,p,q;
	lld top,cost;
	for(i=0;i<=n;i++){
		scanf("%lld",&a[i]);
		f[i]=inf;
	}f[0]=0LL;
	if(0){
		for(i=1;i<=n;i++){top=-inf;
			for(j=i-1;j>=0;j--){
				if((top>=a[i] && top>=a[j])|| a[j]<i-j ){
					top=max(top,a[j]);
					continue;
				}
				if(a[j]>a[i])
					cost=0;
				else
					cost=a[i]-a[j];
				f[i]=min(f[i],f[j]+cost);
				top=max(top,a[j]);
			}
		}
	}else{
		//init segTree
		memset(c,-1,sizeof(c));
		for(i=0;i<=n;i++)ins(1,0,n,i);
		/*for(i=0;i<=n;i++)
			for(j=i;j<=n;j++)
				printf("que(%d,%d)=%d\n",i,j,que(1,0,n,i,j));*/
		//DP-work
		u=v=0;s[v++]=0;
		for(i=1;i<=n;i++){
			while(u<v && a[U]<i-U)u++;
			p=U;
			q=que(1,0,n,p+1,i-1);
			if(q!=-1 && a[q]>=a[p] && a[q]>=a[i])p=q;
			if(a[p]>a[i])
				cost=0;
			else
				cost=a[i]-a[p];
			f[i]=min(f[i],f[p]+cost);
			while(u<v && a[V]<=a[i])v--;
			s[v++]=i;
		}
	}
	printf("%lld\n",f[n]);
}

int main(){
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

