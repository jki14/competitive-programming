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

#define K 3

int a[K],b[K];

int main(){
	for(int i=0;i<K;i++)scanf("%d",&a[i]);
	for(int i=0;i<K;i++){
		scanf("%d",&b[i]);
		if(!(a[i]^b[i])){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}


