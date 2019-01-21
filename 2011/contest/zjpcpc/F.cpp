#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
using namespace std;

#define maxn 110
#define maxl 30

char s[maxn][maxl],a[maxl];

int main(){
	int t,n,k,i;scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,a);
		for(i=0;i<n;i++){
			scanf("%s",s[i]);
			if(!strcmp(s[i],a))k=i;
		}
		k+=n/2;k%=n;
		printf("%s\n",s[k]);
	}
	return 0;
}
