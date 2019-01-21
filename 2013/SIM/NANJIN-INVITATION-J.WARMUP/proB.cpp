#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define N 61
#define M 31

typedef long long lld;

const lld modulo=55566677;

int n,m,_m;
int bit[M];
int c[N][N],a[N],b[N],vx[N],vy[N];

lld ans,fac[N];

int main(){
	for(int i=0;i<M;i++)bit[i]=1<<i;fac[0]=1LL;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*((lld)i)%modulo;
	while(scanf("%d%d",&n,&_m)!=EOF){
		memset(c,0,sizeof(c));m=0;
		for(int i=0;i<_m;i++){
			int x,y;scanf("%d%d",&x,&y);
			if(!c[x][y]){
				c[x][y]=1;
				a[m]=x;b[m]=y;
				m++;
			}
		}
		ans=fac[n]; //printf("ans=%lld\n",ans);
		memset(vx,0,sizeof(vx));
		memset(vy,0,sizeof(vy));
		int sta=0,cnt=0,flag=0;
		for(int c=1;c<bit[m];c++){
			int i=__builtin_ctz(c);
			sta^=bit[i];
			if(bit[i]&sta){cnt++;
				if(vx[a[i]]==1)flag++;vx[a[i]]++;
				if(vy[b[i]]==1)flag++;vy[b[i]]++;
			}else{cnt--;
				if(vx[a[i]]==2)flag--;vx[a[i]]--;
				if(vy[b[i]]==2)flag--;vy[b[i]]--;
			}
			if(flag)continue;
			if(cnt&1)
				ans=(ans-fac[n-cnt])%modulo;
			else ans=(ans+fac[n-cnt])%modulo;
		}
		ans=(ans%modulo+modulo)%modulo;
		printf("%lld\n",ans);
	}
	return 0;
}
