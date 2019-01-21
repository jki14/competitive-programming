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

#define K 2

int a[K],n;

int gcd(int x,int y){ while(y){ int k=x%y;x=y;y=k; } return x; }

void work(){
	for(int k=0;1;k^=1){
		int num=gcd(a[k],n);
		//printf("a[k]=%d n=%d num=%d\n",a[k],n,num);
		if(!n){ printf("%d\n",k^1);break; }
		n-=num;
	}
}

int main(){
	while(scanf("%d%d%d",&a[0],&a[1],&n)!=EOF)
		work();
	return 0;
}

