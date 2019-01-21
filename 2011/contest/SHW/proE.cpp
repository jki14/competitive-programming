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

int main(){
	for(int i=0;i<30;i++){
		for(int j=0;j+1<30;j++)
			printf("%d %d %d %d 10000\n",j,i,j+1,i);
	}
	for(int i=0;i+1<30;i++){
		printf("%d %d %d %d 10000\n",29,i,0,i+1);
	}
}


