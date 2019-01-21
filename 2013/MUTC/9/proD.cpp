#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define N 21
#define S 1048579

char a[N];
int f[S]


void dfs(const int &k){
	if(k==n){ ans++;return; }
	if(a[k]=='-'){
		for(int i=0;i<k;i++){
			if(mrk[i])continue;
			mrk[i]++;dfs(k+1);mrk[i]--;
		}
	}else{
		for(int i=k+1;i<n;i++){
			if(mrk[i])continue;
			mrk[i]++;dfs(k+1);mrk[i]--;
		}
	}
}

int main(){
	memset(mrk,0,sizeof(mrk));
	while(scanf("%s",a)!=EOF){
		n=strlen(a);
		ans=0;dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}
