#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<ctime>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int n;
char s[10];

void work(){
	for(int i=0;i<n;i++)
		scanf("%s",s);
	printf("%d\n",n);
}

int main(){
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

