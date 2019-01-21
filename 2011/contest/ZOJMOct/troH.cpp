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
#include<set>
#include<map>
using namespace std;

#define K 10

int n,k,ans;
int e,vis,s[K];

void dfs(const int &x){
	if(x==k){
		int tmp=e-1;
		for(int i=0;i<k;i++)tmp&=s[i];
		if(!tmp)ans++;
		return;
	}
	for(s[x]=0;s[x]<e;s[x]++){
		dfs(x+1);
	}
}

int main(){
	for(n=1;n<=5;n++){e=1<<n;
		for(k=1;k<=n;k++){
			ans=vis=0;
			dfs(0);
			printf(" %5d",ans);
		}
		printf("\n");
	}
}


