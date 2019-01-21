#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define N 110000

typedef long long lld;

const lld inf=0x3f3f3f3f3f3f3f3fLL;

int n,ans;
lld a[N],b[N],c[N];
int f[N],g[N],x[N],y[N];

int find1(const int &x){
	int lef=0,rig=n;
	while(lef<=rig){
		int mid=(lef+rig)>>1;
		if(a[b[mid]]<=x){
			if(a[b[mid+1]]>x)return mid;
			lef=mid+1;
		}else rig=mid-1;
	}
	//printf("err!\n");
	return 0;
}

int find2(const int &x){
	int lef=0,rig=n;
	while(lef<=rig){
		int mid=(lef+rig)>>1;
		//printf("	c[%d]=%d,c[%d]=%d,x=%d\n",mid,c[mid],mid+1,c[mid+1],x);
		if(a[c[mid]]>=x){
			if(a[c[mid+1]]<x)return mid;
			lef=mid+1;
		}else rig=mid-1;
	}
	//printf("err!\n");
	return 0;
}

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
		ans=0;a[0]=-inf;a[n+1]=inf;
		b[0]=0;for(int i=1;i<=n;i++)b[i]=n+1;
		c[0]=n+1;for(int i=1;i<=n;i++)c[i]=0;
		for(int i=n;i;i--){
			f[i]=find1(a[i])+1;b[f[i]]=i;
			int patf=b[f[i]-1];
			if(a[i]==a[patf])x[i]=x[patf]+1;else x[i]=1;
			g[i]=find2(a[i])+1;c[g[i]]=i;
			int patg=c[g[i]-1];
			if(a[i]==a[patg])y[i]=y[patg]+1;else y[i]=1;
			//printf("a=%d f=%d g=%d\n",a[i],f[i],g[i]);
			if(ans<f[i]+g[i]-min(x[i],y[i]))ans=f[i]+g[i]-min(x[i],y[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
