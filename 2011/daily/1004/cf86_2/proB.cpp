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

int n,x,y;
int K,T;

void work(){
	K=n>>1;T=K+1;
	if( (x==K || x==T) && (y==K || y==T) )
		printf("NO\n");
	else
		printf("YES\n");
}

int main(){
	while(scanf("%d%d%d",&n,&x,&y)!=EOF)
		work();
	return 0;
}


