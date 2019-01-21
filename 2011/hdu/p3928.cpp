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

#define N 30
#define M 60

const int inf = 0x3fffffff;

int n,m,T,f[M][M],g[M][M];
int a[M],in[N],ot[N];

int core(const int &x,const int &y){
	if(f[x][y]<inf)return f[x][y];
	if(g[x][y]==1)return f[x][y]=0;
	
	for(int i=1;i<=n;i++){int path=-inf;
		//11
		if(ot[i]>x && ot[i]<=y && g[ot[i]][y])path=max(path,core(ot[i],y)+1);
		//00
		if(in[i]-1<y && in[i]-1>=x && g[x][in[i]-1])path=max(path,core(x,in[i]-1)+1);
		//10
		int lef=max(x,in[i]+1),rig=min(y,ot[i]-1);
		if((lef!=x || rig!=y) && g[lef][rig])path=max(path,core(lef,rig)+1);
		//update
		if(path>=0)f[x][y]=min(f[x][y],path);
	}
	return f[x][y];
}

void work(){
	scanf("%d",&n);m=n<<1;
	memset(f,0x7f,sizeof(f));
	memset(in,0,sizeof(in));
	for(int i=1;i<=m;i++){
		int id;scanf("%d",&id);
		if(in[id]){
			a[i]=-id;ot[id]=i;
		}else{ a[i]=id;in[id]=i; }
	}
	memset(g,0,sizeof(g));
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j++)
			for(int k=i;k<=j;k++)
				if(a[k]<0)g[i][j]++;
	printf("Case #%d: %d\n",T,core(1,m));
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

