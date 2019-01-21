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

int num[K],sum,n;

void work(){	num[0]=num[1]=sum=0;
	for(int i=0;i<n;i++){
		int val;scanf("%d",&val);
		sum+=val;num[val&1]++;
	}
	printf("%d\n",num[sum&1]);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

