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

#define N 4010
#define K 2
#define pre (now^1)
#define eday 86400

int n,k,now=0;
int a[N],d[N],ans;
int f[K][N];

int max(const int &x,const int &y){ return (x>y)?x:y; }

void work(){
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&d[i]);
	for(int i=n+1;i<=n+n+2;i++)a[i]=eday+1;
	memset(f,0,sizeof(f));ans=a[1]-1;
	for(int i=1;i<=n;i++){now=pre;
		f[now][0]=(a[i]>f[pre][0])?(a[i]+d[i]-1):(f[pre][0]+d[i]);
		ans=max(ans,a[i+k+1]-f[now][0]-1);
		for(int j=1;j<=k && j<=i;j++){
			f[now][j]=min(f[pre][j-1],(a[i]>f[pre][j])?(a[i]+d[i]-1):(f[pre][j]+d[i]));
			ans=max(ans,a[i+k-j+1]-f[now][j]-1);
		}
	}
	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d",&n,&k)!=EOF)
		work();
	return 0;
}
