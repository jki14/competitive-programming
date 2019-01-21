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

#define K 4

const char s[K]={ 'a','b','c','d' };

int n;

void work(){
	for(int i=0;i<n;i++)
		printf("%c",s[i%K]);
	printf("\n");
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

