#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
#include <algorithm>
using namespace std;

#define maxn 1100000

char s[maxn];
int fail[maxn];

void makefail(char *s,int len){
	for(int i=0,j=-1;i<=len;i++,j++){
		fail[i]=j;
		while(j!=-1 && s[i]!=s[j])j=fail[j];
	}
}

void work(){
	int n=strlen(s);
	makefail(s,n);
	if(fail[n]>0 && n%(n-fail[n])==0)
		printf("%d\n",(int)n/(n-fail[n]));
	else
		printf("1\n");
}

int main(){
	while(scanf("%s",s)!=EOF && s[0]!='.')work();
	return 0;
}
