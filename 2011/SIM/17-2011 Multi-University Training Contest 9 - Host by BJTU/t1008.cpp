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

const int N = 5;

int vis[125];
int a[N][N],mk[30]={ 0 };

int check(){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<N;i++){
		int val0=0,val1=0;
		for(int j=0;j<N;j++){ val0+=a[i][j];val1+=a[j][i]; }
		if(vis[val0])return 0;vis[val0]=1;
		if(vis[val1])return 0;vis[val1]=1;
	}
	int val0=0,val1=0;
	for(int i=0;i<N;i++){
		val0+=a[i][i];
		val1+=a[i][N-i-1];
	}
	if(vis[val0])return 0;vis[val0]=1;
	if(vis[val1])return 0;vis[val1]=1;
	return 1;
}

int dfs(const int &i,const int &j){
	if(i==N)return check();
	for(a[i][j]=1;a[i][j]<25;a[i][j]++){
		if(mk[a[i][j]])continue;mk[a[i][j]]=1;
		if(dfs((j==N-1)?i+1:i,(j==N-1)?0:j+1))return 1;
		mk[a[i][j]]=0;
	}
	return 0;
}

int main(){
	dfs(0,0);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			printf("%3d",a[i][j]);
		printf("\n");
	}
	return 0;
}

