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

#define N 110
#define S 110

int n;
int g[N][N],pos;
int f[N],stk[N][N];

char str[S];

int dfs(const int &top,const int &dep){
	if(!top){
		pos=max(pos,dep);
		return 1;
	}
	
	for(int i=0;i<top;i++){
		int k=stk[dep][i],cnt=0;
		if(dep + n - k <= pos)return 0;
		if(dep + f[k]  <= pos)return 0;
		for(int j=i+1;j<top;j++){
			int p=stk[dep][j];
			if(g[k][p])stk[dep+1][cnt++]=p;
		}
		dfs(cnt, dep+1);
	}
	return 1;
}

int clique(){
	pos=0;

	memset(f,0,sizeof(f));
	memset(stk,0,sizeof(stk));

	for(int i=n-1;i>=0;i--){int top=0;
		for(int j=i+1;j<n;j++)
			if(g[i][j])stk[1][top++]=j;
		dfs(top, 1);f[i]=pos;
	}
	return pos;
}

void work(){

	memset(g,0,sizeof(g));

	for(int i=0;i<n;i++){
		scanf("%s",str);
		for(int j=2;str[j];j++)
			g[str[0]-'A'][str[j]-'A']=1;
	}
	
	int ret=clique();
	if(ret>1)
		printf("%d channels needed.\n",ret);
	else
		printf("%d channel needed.\n",ret);
}

int main(){
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

