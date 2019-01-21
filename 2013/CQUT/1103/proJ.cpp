#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define N 1100
#define B 2
#define L 21

int n,m,k,p,ans;
int g[N][B],g0[N][N],g1[N][N];

char sx[L],sy[L];

int main(){
	while(scanf("%d%d%d",&n,&m,&k)!=EOF && !(n==0 && m==0 && k==0)){
		memset(g0,0,sizeof(g0));
		memset(g1,0,sizeof(g1));
		memset(g,0,sizeof(g));
		ans=n*m*k;
		scanf("%d",&p);for(int i=0;i<p;i++){int x,y;
			scanf("%s%d%s%d",sx,&x,sy,&y);
			if(sx[0]=='c'){
				if(g0[x][y])continue;g0[x][y]=1;
				ans-=k;g[y][0]++;
			}else{
				if(g1[x][y])continue;g1[x][y]=1;
				ans-=n;g[x][1]++;
			}
		}
		for(int i=1;i<=m;i++)ans+=g[i][0]*g[i][1];
		printf("%d\n",ans);
	}
}
