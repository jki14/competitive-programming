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

#define N 60

const double eps=1e-4;

int n,m,k,s;
double f[N][N][N];
int res;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&k,&s);res=1;
		memset(f,0,sizeof(f));f[0][0][s]=1.0;
		for(int i=0;i<m;i++){
			int u,v;scanf("%d%d",&u,&v);
			for(int j=0;j<=k;j++){
				for(int p=1;p<=n;p++){
					//printf("f[%d][%d][%d]=%d\n",i,j,p,f[i][j][p]);
					if(!f[i][j][p])continue;
					f[i+1][j+1][(p==u)?v:((p==v)?u:p)]+=f[i][j][p];
					f[i+1][j][p]+=f[i][j][p];
				}
			}
		}
		for(int p=2;p<=n;p++)if(f[m][k][p]>f[m][k][res]+eps){ res=p; }
		printf("%d\n",res);

		//for(int p=1;p<=n;p++)printf("%.6f\n",f[m][k][p]);

	}
	return 0;
}
