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

#define N 110

int main(){
	int n;scanf("%d",&n);
	int tar=1,res[N];
	for(int i=1;i<=n;i++){
		int val;scanf("%d",&val);
		if(val==tar)res[tar++]=2000+i;
	}
	printf("%d\n",tar-1);
	for(int i=1;i<tar;i++){
		if(i>1)printf(" ");
		printf("%d",res[i]);
	}
	printf("\n");
	return 0;
}

