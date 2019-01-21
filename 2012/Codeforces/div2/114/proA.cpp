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

void core(){
	int nec=ceil(((double)n)/100.0*((double)y));
	if(x<nec)
		printf("%d\n",nec-x);
	else
		printf("0\n");
}

int main(){
	while(scanf("%d%d%d",&n,&x,&y)!=EOF)
		core();
	return 0;
}
