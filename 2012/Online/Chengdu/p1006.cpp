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
#define M 1100

int zero;

int n,ans,g[N][N],f[N];
int m,lef[M],rig[M],val[M];

inline int max(const int &x,const int &y){ return x>y?x:y; }
inline int min(const int &x,const int &y){ return x<y?x:y; }

int main(){
	while(scanf("%d",&n)!=EOF){

		memset(g,0,sizeof(g));

		for(int i=0;i<n;i++){
			int x,y;scanf("%d%d",&x,&y);
			if(x+y>=n)continue;
			g[x+1][n-y]++;
		}

		m=0;zero=0;
		for(int j=1;j<=n;j++)
			for(int i=1;i<=n;i++){
				if(i>j)continue;
				g[i][j]=min(g[i][j],j-i+1);
				if(g[i][j]){
					val[++m]=g[i][j];
					lef[m]=i;rig[m]=j;
					if(m>500)zero/=zero;
				}
			}

		memset(f,0,sizeof(f));ans=0;
		for(int i=1;i<=m;i++){
			for(int j=0;j<lef[i];j++)
				f[rig[i]]=max(f[rig[i]],f[j]+val[i]);
			ans=max(ans,f[rig[i]]);
		}


		printf("%d\n",ans);
	
	}

	return 0;
}
