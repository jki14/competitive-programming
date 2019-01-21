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

#define T 1100000
#define maxn 30

int n,ans,r;
int a[maxn][maxn];
int que[T],f[T];
int bit[maxn];

int max(const int &x,const int &y){ return (x>y)?x:y;  }

void work(){
	int i,j,k,Ori;
	int cost,x;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	memset(f,0x8f,sizeof(f));Ori=f[0];
	r=0;que[r++]=0;f[0]=0;
	for(i=0;i<r;i++){
		for(j=0;j<n;j++){
			if(i&bit[j])continue;
			k=i|bit[j];if(f[k]!=Ori)continue;
			for(cost=x=0;x<n;x++){
				if(i&bit[x])
					cost-=a[j][x];
				else
					cost+=a[j][x];
			}
			if(f[k]==Ori)que[r++]=k;
			f[k]=max(f[k],f[i]+cost);
			ans=max(ans,f[k]);
			//printf("f[%d]=%d\n",k,f[k]);
		}
	}
	printf("%d\n",ans);
}

int main(){
	for(int i=0;i<=20;i++)bit[i]=1<<i;
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

