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

#define K 13

const int inf =0x3fffffff;

const int a[K] = { 1  ,2  ,3  ,4  ,5  ,6  ,7  ,8  ,9  ,10 ,10 ,10 ,10  };
const int b[K] = { 11 ,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf };

int n;

void work(){
	int ret=0;
	for(int i=0;i<K;i++){
		if(10+a[i]==n || 10+b[i]==n){
			if(i==11)
				ret+=3;
			else ret+=4;
		}
	}
	printf("%d\n",ret);
}

int main(){
	while(scanf("%d",&n)!=EOF)
		work();
	return 0;
}

