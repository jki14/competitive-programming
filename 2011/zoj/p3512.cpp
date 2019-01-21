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

#define maxn 110000
#define maxd 20

typedef long long lld;

const lld inf=1LL<<60;
const lld low=-inf;

int n;
lld ans;
lld a[maxn],b[maxn],s[maxn];
lld c[maxd][maxn];
int f[maxn],r[maxn];
int F[maxd][maxn];

int find(const int &x){ if(f[x]!=x)f[x]=find(f[x]); return f[x]; }

void build(const int &d,const int &l,const int &r){
	if(l==r)return;
	int i,mid=(l+r)>>1,p=l,q=mid+1,equal=0;
	for(i=mid;i>=l && s[i]==s[mid];i--)equal++;
	for(i=l;i<=r;i++){
		if(i>l)F[d][i]=F[d][i-1];else F[d][i]=0;
		if(c[d][i]<s[mid] || (c[d][i]==s[mid] && equal && equal--)){
			c[d+1][p++]=c[d][i];
			F[d][i]++;
		}else{
			c[d+1][q++]=c[d][i];
		}
	}
	build(d+1,l,  mid);
	build(d+1,mid+1,r);
}

lld que(int u,int v){
	if(u==v)return a[u];
	int k=((u+v)>>1)-u+1,l=1,r=n,d=0;
	
	//printf("%d-%d %d",u,v,k);

	int fl,fr,mid;
	while(u!=v){
		if(u>l)fl=F[d][u-1];else fl=0;
		fr=F[d][v];
		mid=(l+r)>>1;
		if(k<=fr-fl){
			u=l+fl;v=l+fr-1;
			d++;r=mid;
		}else{
			u=mid+1+u-l-fl;
			v=mid+1+v-l-fr;
			k-=fr-fl;
			d++;l=mid+1;
		}
	}

	//printf("=%lld\n",c[d][u]);

	return c[d][u];
}

lld labs(const lld &x){
	if(x<0LL)return -x;
	return x;
}

void work(){
	int i;
	for(i=1;i<=n;i++){ scanf("%lld",&a[i]);c[0][i]=s[i]=a[i]; }
	a[0]=low;a[n+1]=inf;ans=0LL;
	for(i=0;i<=n+1;i++)f[i]=i;
	sort(s+1,s+n+1);build(0,1,n);
	for(i=1;i<=n;i++){
		if(a[i]>=que(f[i-1],i-1))continue;
		f[i]=find(i-1);
		while(que(find(i),i)<que(find(f[i]-1),f[i]-1)){
			f[find(i)]=find(f[i]-1);
		}
	}
	for(i=1;i<=n;i++){ r[find(i)]=i;/*printf("f[%d]=%d\n",i,f[i]);*/ }
	for(i=1;i<=n;i++){if(f[i]!=i)continue;
		b[i]=que(i,r[i]);
	}
	for(i=1;i<=n;i++){
		ans+=labs(a[i]-b[f[i]]);
		//printf(" %lld",b[f[i]]);
	}
	//printf("\n");
	printf("%lld\n",ans);
}

int main(){
	while(scanf("%d",&n)!=EOF && n)work();
	return 0;
}

