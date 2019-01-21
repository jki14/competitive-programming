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

#define maxn 20
#define maxb 1100
#define maxlen 100

typedef long long lld;

const int maxm=1<<17;
const lld MOD=1000000009LL;
const int inf=LONG_MAX;

int n,m,re;
int s[maxn][maxm];
int f[maxm][maxn];
lld a[maxn],rem[maxb],res[maxm][maxn];
int g[maxn][maxn];
lld d[maxn][maxn];
int c[maxn][maxlen];
int len[maxn],rat[maxn],tmp[maxn],path[maxm][maxn];

int bitCount(int x){
	int ret=0;
	for(;x;x>>=1)ret+=x&1;
	return ret;
}

int bitLength(lld x){
	int ret=0;
	for(;x!=0LL;x>>=1)ret++;
	return max(ret,1);
}

void init(){
	m=(1<<n)-1;
	memset(s,0,sizeof(s));
	for(int i=0;i<=m;i++){
		int k=bitCount(i);
		s[k][++s[k][0]]=i;
	}
}

int lldCmp(const lld &i,const lld &j){ return i>j; }

int arrCmp(const int &i,const int &j){
	int x=len[i]-1,y=len[j]-1;
	for(;x>=0 && y>=0;x--,y--){
		if(c[i][x]!=c[j][y])
			return c[i][x]<c[i][y];
	}
	return 0;
}

int same(const int &i,const int &j,const int &k){
	lld z=(1LL<<k)-1LL;
	return (a[i]&z)==(a[j]>>(len[j]-k));
}

int cross(const int &i,const int &j){
	/*int l=0,r=min(len[i],len[j]);
	while(l<=r){
		int mid=(l+r)>>1;
		if(same(i,j,mid)){
			if(!same(i,j,mid+1))return mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}*/
	for(int k=min(len[i],len[j]);k;k--)
		if(same(i,j,k))return k;
	return 0;
}

void work(){
	int i,j,k,kk,p,t;
	lld x,y;
	
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	//printf("      a[]={ ");for(i=0;i<n;i++)printf("%5lld ",a[i]);printf("}\n");
	for(i=0;i<n;i++){
		if(a[i]==-1LL)continue;
		for(j=0;j<n;j++){
			if(a[j]==-1LL)continue;
			if(i==j)continue;
			if(a[i]<a[j])continue;
			y=a[j];
			x=(1LL<<bitLength(y))-1LL;
			
			//printf("Del Test: %lld,%lld\n",x,y);

			for(;bitLength(x)<=bitLength(a[i]);x<<=1,y<<=1){
				if((a[i]&x)==y){
					//printf("	del %lld(%lld) at x=%lld y=%lld\n",a[j],a[i],x,y);
					a[j]=-1LL;
				}
				break;
			}
		}
	}
	sort(a,a+n,lldCmp);while(n && a[n-1]==-1LL)n--;
	for(i=0;i<n;i++){
		len[i]=bitLength(a[i]);
		x=a[i];tmp[i]=i;
		for(j=0;j<len[i];j++){
			c[i][j]=x&1;
			x>>=1;
		}
	}
	sort(tmp,tmp+n,arrCmp);
	for(i=0;i<n;i++)rat[tmp[i]]=i;
	init();
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(i==j)continue;
			k=cross(i,j);
			g[i][j]=len[i]-k;
			d[i][j]=(a[i]>>k)%MOD;
		}

	memset(f,0x7f,sizeof(f));
	memset(path,0x7f,sizeof(path));
	
	/*INIT Test
	printf("New Case:\n");
	printf("      a[]={ ");for(i=0;i<n;i++)printf("%5lld ",a[i]);printf("}\n");
	printf("    len[]={ ");for(i=0;i<n;i++)printf("%5d ",len[i]);printf("}\n");
	printf("    rat[]={ ");for(i=0;i<n;i++)printf("%5d ",rat[i]);printf("}\n");
	printf("    g/d[][]\n          ");
	for(j=0;j<n;j++)printf("%10d",j);printf("\n");
	for(i=0;i<n;i++){printf("%5d     ",i);
		for(j=0;j<n;j++){
			if(i==j){ printf("~~~~~~~~~~");continue; }
			printf("%4d/%4lld ",g[i][j],d[i][j]);
		}
		printf("\n");
	}*/

	for(i=0;i<n;i++){k=1<<i;
		f[k][i]=len[i];
		res[k][i]=a[i]%MOD;
	}
	for(i=1;i<n;i++){
		for(j=1;j<=s[i][0];j++){k=s[i][j];
			for(t=0;t<n;t++){
				if(!(k&(1<<t)))continue;
				for(p=0;p<n;p++){
					if(k&(1<<p))continue;
					kk=k|(1<<p);
					if(f[kk][p]>f[k][t]+g[p][t] || (f[kk][p]==f[k][t]+g[p][t] && path[kk][p]>rat[t])){
						f[kk][p]=f[k][t]+g[p][t];
						path[kk][p]=rat[t];
						//printf("res[%d][%d]=(d[%d][%d](%lld) * rem[f[%d][%d](%d)](%lld) + res[%d][%d](%lld))MOD(%lld)==",kk,p,p,t,d[p][t],k,t,f[k][t],rem[f[k][t]],k,t,res[k][t],MOD);
						res[kk][p]=(d[p][t]*rem[f[k][t]]+res[k][t])%MOD;
						//printf("%lld\n",res[kk][p]);
					}
				}
			}
		}
	}
	re=0;
	for(j=0;j<n;j++){i=tmp[j];
		if(f[m][i]<f[m][re])re=i;
	}
	printf("%lld\n",res[m][re]);
}

int main(){
	rem[0]=1LL%MOD;
	for(int i=1;i<maxb;i++)rem[i]=(rem[i-1]<<1)%MOD;
	while(scanf("%d",&n)!=EOF)work();
	return 0;
}

