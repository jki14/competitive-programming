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

#define N 11000

int n,ms,mt,ans;
char a[N],s[N],t[N];

int check(const int &u,const int &v){
	for(int i=u;i<u+ms;i++){
		if(a[i]!=s[i-u])return 0;
	}
	for(int i=v-mt;i<v;i++){
		if(a[i]!=s[i-v+mt])return 0;
	}
	return 1;
}

void work(){ans=0;
	n =strlen(a);
	ms=strlen(s);
	mt=strlen(t);

	for(int len=max(ms,mt)-1;len<n;len++){
		for(int i=0;i+len<n;i++){
			if(check(i,i+len))ans++;
		}
	}

	printf("%d\n",ans);
}

int main(){
	while(scanf("%s%s%s",a,s,t)!=EOF)
		work();
	return 0;
}

