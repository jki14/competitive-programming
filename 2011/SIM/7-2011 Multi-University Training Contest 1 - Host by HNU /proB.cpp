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

#define maxn 1100

int x,y,n,ans;
int d[maxn],c[maxn],t[maxn];
int g[maxn][maxn],mk[maxn],pnt[maxn];

char str[maxn];

int dfs(int u){
	mk[u]=1;for(int v=0;v<n;v++)if(g[u][v] && !mk[v]){mk[v]=1;
		if(pnt[v]<0 || dfs(pnt[v])){
			pnt[v]=u;
			return 1;
		}
	}
	return 0;
}

void work(){
	int i,j;
	for(i=0;i<n;i++){
		scanf("%s",str);
		if(str[0]=='C'){
			t[i]=0;
			sscanf(str,"C%d",&c[i]);
			scanf("%s",str);
			sscanf(str,"D%d",&d[i]);
		}else{
			t[i]=1;
			sscanf(str,"D%d",&d[i]);
			scanf("%s",str);
			sscanf(str,"C%d",&c[i]);
		}
	}
	
	memset(g,0,sizeof(g));
	for(i=0;i<n;i++){
		if(t[i])continue;
		for(j=0;j<n;j++){
			if(!t[j])continue;
			g[i][j]=(c[i]==c[j])||(d[i]==d[j]);
		}
	}

	ans=n;
	memset(pnt,0x8f,sizeof(pnt));
	for(i=0;i<n;i++){
		memset(mk,0,sizeof(mk));
		if(dfs(i))ans--;
	}

	printf("%d\n",ans);
}

int main(){
	while(scanf("%d%d%d",&x,&y,&n)!=EOF)work();
	return 0;
}

