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

#define maxn 110

#define T que[tail-1]
#define T2 que[tail-2]
#define H que[head]
#define H2 que[head+1]
#define K i-1

const double eps=1e-6;

const int inf=LONG_MAX;

typedef long long lld;

int n,m,base;
int i,j,k;
int a[maxn];
double d[maxn][maxn],f[maxn][maxn];
int que[maxn],head,tail;

int g(){
	return (f[T1][j-1])
}

void work(){
	scanf("%d%d%d",&n,&m,&base);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);for(i=1;i<n;i++)if(a[i]==a[i+1])a[i]=inf;
	sort(a+1,a+n+1);while(n && a[n]==inf)n--;
	for(i=1;i<=n;i++)
		for(j=1;j<i;j++)
			d[i][j]=(log((double)(a[i]-a[j])));

	memset(f,0,sizeof(f));
	for(j=2;j<=n;j++){
		head=tail=0;
		for(i=2;i<j;i++){
			while(head+1<tail && f[T][j-1]+d[i][T]<=f[K][j-1]+d[i][K])tail--;
			que[tail++]=K;
		}
		for(i=j;i<=n;i++){
			while(head+1<tail && f[T][j-1]+d[i][T]<=f[K][j-1]+d[i][K])tail--;que[tail++]=K;
			while(head+1<tail && f[H][j-1]+d[i][H]<=f[H2][j-1]+d[i][H2])head++;
			f[i][j]=f[H][j-1]+d[i][H];
		}
	}
	printf("%lf\n",f[n][m]);
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

