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

int T,n;

void work(){T++;
	printf("%d. ",T);
	int a,b,c,d;
	a=n*3;
	if(a&1){
		printf("odd ");
		a++;
	}else printf("even ");
	b=a/2;c=3*b;d=c/9;
	printf("%d\n",d);
}

int main(){T=0;
	while(scanf("%d",&n)!=EOF && n)
		work();
	return 0;
}

