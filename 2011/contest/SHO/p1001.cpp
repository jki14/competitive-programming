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

#define N 24
#define M 8

const int vex[M]={ 0,1,2,7,16,21,22,23 };
const int pat[M]={ 3,3,6,6,17,17,20,20 };

int src[N],tar[N];

void work(){
	int i,j;
	for(i=0;i<N;i++)scanf("%d",&src[i]);
	for(i=0;i<N;i++)scanf("%d",&tar[i]);
	for(j=0;j<M;j++){i=vex[j];

		printf("src[i]=%d tar[i]=%d\n",src[i],tar[i]);
		printf("src[pat[j]]=%d tar[pat[j]]=%d\n",src[pat[j]],tar[pat[j]]);

		if((src[i] && tar[i] && src[i]!=tar[i])
		  ||	(src[i]==0 && tar[i] && src[pat[j]]!=tar[i])
		  ||	(src[i] && tar[i]==0 && src[i]!=tar[pat[j]])){
			printf("Y\n");
			return;
		}
	}
	printf("N\n");
}

int main(){
	int t;scanf("%d",&t);
	while(t--)work();
	return 0;
}

