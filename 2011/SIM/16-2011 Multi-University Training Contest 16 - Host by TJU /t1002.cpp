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

#define T 10

int main(){
	srand(time(NULL));
	printf("%d\n",T);
	for(int t=0;t<T;t++){
		int n=10;
		printf("%d\n",n);
		for(int i=0;i<n;i++)printf("%d ",(int)(random()%20));
		printf("\n");
		for(int i=0;i<n;i++)printf("%d ",(int)(random()%20));
		printf("\n");

	}
}
