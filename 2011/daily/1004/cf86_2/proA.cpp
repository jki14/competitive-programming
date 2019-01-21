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

#define L 1100

char a[L],b[L];

void work(){
	for(int i=0;i<a[i];i++){
		if(a[i]<'a')a[i]+='a'-'A';
		if(b[i]<'a')b[i]+='a'-'A';
		if(a[i]!=b[i]){
			printf("%d\n",a[i]<b[i]?-1:1);
			return;
		}
	}
	printf("0\n");
}

int main(){
	while(scanf("%s%s",a,b)!=EOF)
		work();
	return 0;
}

