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

#define L 30

char b[L],g[L],x[L];

int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%s%s%s",b,g,x);
		printf("%s will survive\n",g);
	}
	return 0;
}
