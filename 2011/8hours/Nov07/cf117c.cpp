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

#define N 5100

int n,que[N],head,tail,id;
char a[N][N],mk[N];

int dfs(const int &u){
	
	//printf("dfs %d\n",u);
	
	mk[u]=id;que[tail++]=u;
	for(int v=0;v<n;v++){

		//printf("	vst %d\n",v);

		if(a[u][v]=='0')continue;
		if(mk[v]==id){
			while(que[head]!=v)head++;
			return 1;
		}
		if(!mk[v]){
			if(dfs(v))return 1;
		}
	}tail--;mk[u]=-id;
	return 0;
}

void work(){
	for(int i=0;i<n;i++)scanf("%s",a[i]);
	memset(mk,0,sizeof(mk));id=0;
	for(int i=0;i<n;i++)if(!mk[i]){
		head=tail=0;id++;
		dfs(i);
		if(tail-head>=3){	
			while(a[que[tail-1]][que[head+1]]=='1')head++;
			printf("%d %d %d\n",que[tail-1]+1,que[head]+1,que[head+1]+1);
			return;
		}
	}
	printf("-1\n");
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

