#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int main(){
	int t,x,y;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&x,&y);
		if(!(x==1 && y==1))
			printf("Bob\n");
		else
			printf("Alice\n");
	}
	return 0;
}

