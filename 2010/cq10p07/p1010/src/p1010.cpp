#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define lld long long
#define v u^1
#define p s[h]
#define p2 s[h+1]
#define q s[t-1]
#define q2 s[t-2]
#define maxn 51000

const lld inf = 1LL<<60;

int n,m,k;
int s[maxn];
lld f[2][maxn];
lld ans;

struct item{
	int w,h;
	bool operator < (const item x) const{
		return (w==x.w)?(h<x.h):(w>x.w);
	}
}a[maxn];

void work(){
	int i,j,h,t,u;ans=inf;
	for(i=1;i<=m;i++)
		scanf("%d%d",&a[i].w,&a[i].h);
	sort(a+1,a+m+1);n=1;
	for(i=2;i<=m;i++){
		if(a[n-1].h>=a[i].h)continue;
		a[++n]=a[i];
	}
	if(k>n)k=n;
	memset(f,0x7f,sizeof(f));f[0][0]=0;f[1][0]=0;u=0;
	for(j=1;j<=k;j++){
		h=t=0;
		for(i=1;i<=n;i++){
			/* (f[u][q-1]-f[u][i-1])/(a[q].w-a[i].w) >= (f[u][q2-1]-f[u][q-1])/(a[q2].w-a[q].w) */
			while(h+1<t && (f[u][q-1]-f[u][i-1])*(a[q2].w-a[q].w)>=(f[u][q2-1]-f[u][q-1])*(a[q].w-a[i].w))t--;
			s[t++]=i;
			/* f[u][p-1]+a[p].w*a[i].h>=f[u][p2-1]+a[p2].w*a[i].h */
			while(h+1<t && (f[u][p-1]-f[u][p2-1])>=(lld)(-a[i].h)*(a[p].w-a[p2].w))h++;
			f[v][i]=f[u][p-1]+(lld)a[p].w*(lld)a[i].h;
		}
		u=v;
		if(ans>f[u][n])ans=f[u][n];
	}
	printf("%lld\n",ans);
}

int main(){
	while(scanf("%d%d",&m,&k)!=EOF)
		work();
	return 0;
}
