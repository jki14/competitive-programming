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

#define maxlen 1100000

int T;
char c[maxlen],a[maxlen];

void work(){
	int i,j,k;
	scanf("%s",a);
	for(i=j=k=0;a[i];i++){
		if(k && (a[i]=='/' || a[i]==':'))break;
		if(k)c[j++]=a[i];
		if(a[i]==':' && a[i+1]=='/' && a[i+2]=='/'){ i+=2;k=1; }
	}c[j]=0;
	printf("Case #%d: %s\n",T,c);
}

int main(){
	int t;scanf("%d",&t);
	for(T=1;T<=t;T++)work();
	return 0;
}

