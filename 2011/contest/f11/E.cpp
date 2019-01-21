#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

#define maxn 20

int a[maxn],n,res;
char s[maxn];

int succ(){
	int i,k;
	for(i=k=0;i<n;i++){
		if(a[i])k++;else k--;
		if(k<0)return 0;
	}
	return (int)(k==0);
}

void dfs(const int &x){
	if(x>=n){
		if(succ())res++;
		return;
	}
	if(s[x]=='?'){
		for(a[x]=0;a[x]<2;a[x]++)
			dfs(x+1);
	}else{
		a[x]=(s[x]=='(')?1:0;
		dfs(x+1);
	}
}

void work(){
	n=strlen(s);res=0;
	dfs(0);
	printf("%d\n",res);
}

int main(){
	while(scanf("%s",s)!=EOF)work();
	return 0;
}

