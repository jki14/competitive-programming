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
#define M 31

int T;

int n,m,rat;
int a[N],bit[M];
int g[N][N],mk[N],f[N];

void init(){ for(int i=0;i<M;i++)bit[i]=1<<i; }

int get(const int &u){
	for(int v=1;v<=n;v++){
		if(!g[u][v])continue;
		if(mk[v])continue;
		mk[v]=1;
		if(f[v]==0 || get(f[v])){
			f[v]=u;
			return 1;
		}
	}
	return 0;
}

void work(){
	int i,j,k;
	
	scanf("%d%d",&n,&m);rat=n;
	
	for(i=1;i<=n;i++){a[i]=0;
		scanf("%d",&j);
		while(j--){
			scanf("%d",&k);
			a[i]|=bit[k-1];
		}
		//printf("a[%d]=%d\n",i,a[i]);
	}

	memset(g,0,sizeof(g));
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++){
			if(i==j)continue;
			//printf("a[i]=%d a[j]=%d\n",a[i],a[j]);
			if(!(a[i]&a[j])){
				g[i][j]=1;
				//printf("%d->%d\n",i,j);
			}
		}
	
	memset(f,0,sizeof(f));
	for(i=1;i<=n;i++){
		memset(mk,0,sizeof(mk));
		if(get(i))rat--;
	}

	//printf("f[]={ ");
	//for(i=1;i<=n;i++)printf("%d ",f[i]);printf("}\n");

	//printf("rat=%d\n",rat);

	if(rat)
		printf("Case %d: No\n",T);
	else
		printf("Case %d: Yes\n",T);
}

int main(){init();
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

