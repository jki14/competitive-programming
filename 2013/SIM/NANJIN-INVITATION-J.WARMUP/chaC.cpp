#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define N 110

int v[N]={ 0 };
int n,ans;

void dfs(const int &k){
	if(k==n)ans++;
	for(int i=0;i<n;i++){
		if(v[i])continue;
		if(i==k || i+1==k)continue;
		if(i==n-1 && k==0)continue;
		v[i]++;dfs(k+1);v[i]--;
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		ans=0;dfs(0);
		printf("ans[%d]=%d\n",n,ans);
	}
	return 0;
}
