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

#define N 1100

const int low = LONG_MIN;

int n,m,l;
int a[N],s[N];
int f[N][N],g[N][N];

inline int max(const int &x,const int &y){ return (x>y)?x:y; }

void work(){
	a[0]=s[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i];
	}

	memset(f,0x8f,sizeof(f));f[0][0]=0;
	memset(g,0x8f,sizeof(g));g[0][0]=0;
	for(int i=1;i<=n;i++){
		f[i][0]=(i>=l)?s[i]:0;
		g[i][0]=f[i][0];
		for(int j=1;j<=i && j<=m;j++){
			g[i][j]=max(g[i-1][j]+a[i],(i>=l)?f[i-l][j]+s[i]-s[i-l]:low);
			f[i][j]=max(f[i-1][j-1],g[i][j]);
			/*for(int k=l;k<=i-j;k++)
				f[i][j]=max(f[i][j],f[i-k][j]+s[i]-s[i-k]);*/
		}
	}
	printf("%d\n",f[n][m]);
}

int main(){
	while(scanf("%d%d%d",&n,&m,&l)!=EOF)
		work();
	return 0;
}

