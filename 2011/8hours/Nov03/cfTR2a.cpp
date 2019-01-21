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

int n;

void work(){
	int k=n / 3;
	if(((k+1)*3-n)<(n-k*3))k=k+1;
	printf("%d %d\n",k/12,k%12);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

