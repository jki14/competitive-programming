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

const int N = 10;

const int f[N]={ 1,2,3,5,8,13,21,34,55,89 };

int ans[89];

int main(){
	memset(ans,0,sizeof(ans));
	for(int sta=0;sta<(1<<N);sta++){
		int val=0;
		for(int i=0;i<N;i++)
			if(sta&(1<<i))val+=f[i];
		if(val>89)continue;
		ans[val]++;
	}
	for(int i=1;i<=89;i++)
		printf("ans[%d]=%d\n",i,ans[i]);
	return 0;
}

