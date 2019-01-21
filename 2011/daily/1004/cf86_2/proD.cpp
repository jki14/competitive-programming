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

#define N 110000
#define M 110000
#define K 100001

int n,ans;
int a[N],hig[M];
int prm[N],is[N],num;
int fac[K],top[K],k;
int val,sta,low;

void getprm(const int &n){num=0;
	int i,j,d;
	int e=(int)(sqrt((double)n)+1.0);
	memset(is,0x7f,sizeof(is));
	prm[num++]=2;is[0]=is[1]=0;
	for(i=4;i<=n;i+=2)is[i]=0;
	for(i=3;i<e;i+=2)if(is[i]){
		prm[num++]=i;d=i<<1;
		for(j=i*i;j<=n;j+=d)is[j]=0;
	}
	for(;i<=n;i+=2)if(is[i])prm[num++]=i;
}

void dfs(const int &x){
	if(x==k){
		
		//printf("update hig[%d]=%d (low=%d)\n",val,hig[val],low);
		
		if(hig[val]<low)ans++;
		hig[val]=sta;
		return;
	}
	for(int i=0;i<=top[x];i++){
		if(i)val*=fac[x];
		dfs(x+1);
	}
	for(int i=1;i<=top[x];i++)val/=fac[x];
}

void work(){
	memset(hig,0,sizeof(hig));

	for(sta=1;sta<=n;sta++){ans=0;
		scanf("%d%d",&a[sta],&low);low=sta-low;
		int value=a[sta];k=0;
		for(int i=0;i<num && prm[i]*prm[i]<=value;i++){
			if(!(value%prm[i])){
				fac[k]=prm[i];top[k]=0;
				while(!(value%fac[k])){
					top[k]++;
					value/=fac[k];
				}
				k++;
			}
		}
		if(value>1){ fac[k]=value;top[k]=1;k++; }
		val=1;dfs(0);
		printf("%d\n",ans);
	}
}

int main(){getprm(K);
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

